unit MainUnit;


interface

uses
  u_plugin_info, u_plugin_msg, u_common, u_BasePlugin, Windows, u_public_intf,
  u_gui_intf, u_gui_events, u_gui_const, u_string, WndUnit, ActiveX;

const
  PLUGIN_VER_MAJOR = 1;
  PLUGIN_VER_MINOR = 0;
  PLUGIN_NAME   : WideString = 'Widget sample';
  PLUGIN_AUTHOR : WideString = 'QIP Team';
  PLUGIN_DESC   : WideString = 'Test plugin to understand widgets';
  PLUGIN_HINT   : WideString = 'This is the test plugin hint.' + #13#10 + 'Multiline hint.';
  
  DefaultOptions: TPluginSpecific = (
    Bool1   : True;  //show in CL
    Bool2   : True;  //show in Msgs
    Bool3   : True;  //not new install
    );

type
  TQipPlugin = class;

  TSampleWidget = class(TWidgetItem, IWidgetDropTarget)
  private
    FPopupMenuVisible: Boolean;
    FThemeServices: IThemeServices;
    FHighlightSettings, FHighlightRefresh: Boolean;
    FSettingsPressed, FRefreshPressed: Boolean;
    FFiles: IStringList;
    function HintSize(const DC: HDC): TSize;
  public
    function GetOptionsRect: TRect;
    function GetRefreshRect: TRect;

    procedure MouseDown   (MousePt: TPoint; Button: TMouseButton; ShiftState: TShiftState); override; safecall;
    procedure MouseUp     (MousePt: TPoint; Button: TMouseButton; ShiftState: TShiftState); override; safecall;
    procedure MouseMove   (MousePt: TPoint; ShiftState: TShiftState); override; safecall;
    procedure MouseEnter  (); override; safecall;
    procedure MouseLeave  (); override; safecall;

    procedure GetHintInfo(const DC: HDC; var W,H: Integer; var HintPos: TWidgetHintPos); override; safecall;

    procedure DrawOptions(Canvas: ICanvas; ARect: TRect);
    procedure Draw    (const DC: HDC; DrawRect: TRect; MousePt: TPoint); override; safecall;
    procedure DrawHint(const DC: HDC; DrawRect: TRect); override; safecall;
  public
    procedure DragOver(const Files: IStringList; DataObject: IDataObject;
      Shift: u_gui_const.TShiftState; Pt: TPoint;
      Mode: u_gui_const.TDropMode; State: u_gui_const.TDragState; 
      var Effect: Integer; var Accept: Boolean);
    procedure DragDrop(const Files: IStringList; DataObject: IDataObject;
      Shift: u_gui_const.TShiftState; Pt: TPoint;
      Mode: u_gui_const.TDropMode; var Effect: Integer);
  public
    constructor Create(AOwner: TCustomBaseQipPlugin; AClass: TWidgetClass; AllowCompact: Boolean);
    destructor Destroy; override;
  end;

  TQipPlugin = class(TBaseQipPlugin)
  private
    FPlugIco: HICON;
    FSettingsMenu: IPopupMenu;
    FCLWidget, FMWWidget: IWidget;

    FSettingsWnd: TSettings;
    FSyncObj: TMainThreadSyncWnd;

    procedure CreateMenu;
    procedure FreeMenu;
    function  CreateMenuItem: IMenuItem;
    procedure RecreateMenu;

    procedure MenuItemClick(Sender: IComponent);
    procedure DoFreeSettings(Sender: TObject);
    procedure FreeSettings(Sender: TObject);
  public
    constructor Create(const PluginService: IQIPPluginService);
    destructor Destroy; override;

    procedure GetPluginInformation(var VersionMajor: Word; var VersionMinor: Word;
                                   var PluginName: PWideChar; var Creator: PWideChar;
                                   var Description: PWideChar; var Hint: PWideChar); override;
    function PluginIcon: HICON; override;
    procedure InitPlugin; override;
    procedure FinalPlugin; override;
    procedure LoadOptions; override;
    procedure CoreLanguageChanged; override;
    procedure OnOptions; override;
  end;

implementation

uses
  u_gui_graphics, u_lang_ids, SysUtils, u_gui_helpers;

{$R icon.Res}

procedure DrawToolButton(ThemeServices: IThemeServices; TargetCanvas: ICanvas; ARect: TRect; PtOver, BtDown: Boolean);
const
  DownStyles: array[Boolean] of Integer = (BDR_RAISEDINNER, BDR_SUNKENOUTER);
var
  te: TThemedToolBar;
begin
  if ThemeServices.ThemesEnabled then
  begin
    if not PtOver then Exit;

    te := ttbButtonHot;
    if BtDown then
      te := ttbButtonPressed;

    ThemeServices.DrawElement(TargetCanvas.Handle, ThemeServices.GetElementDetails(te), ARect, nil);
  end
  else
    begin
      if PtOver then
        DrawEdge(TargetCanvas.Handle, ARect, DownStyles[BtDown], BF_MIDDLE or BF_RECT)
    end;
end;

procedure TQipPlugin.CoreLanguageChanged;
begin
  inherited;
  FSettingsMenu := nil;
  ReCreateMenu;
end;

constructor TQipPlugin.Create(const PluginService: IQIPPluginService);
begin
  inherited;
  FPlugIco := LoadImageW(HInstance, 'PLUGICO', IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);

  FSettingsMenu := nil;
  FCLWidget     := nil;
  FMWWidget     := nil;
  FSyncObj      := TMainThreadSyncWnd.Create(DoFreeSettings);
end;

procedure TQipPlugin.CreateMenu;
begin
  if CoreGUI = nil then Exit;
  if FSettingsMenu <> nil then Exit;

  CoreGUI.CreateControl(nil, IPopupMenu, FSettingsMenu, nil);
  if FSettingsMenu <> nil then
    FSettingsMenu.AutoHotkeys := maManual;
end;

function TQipPlugin.CreateMenuItem: IMenuItem;
begin
  Result := nil;
  if CoreGUI = nil then Exit;
  if FSettingsMenu = nil then Exit;
  CoreGUI.CreateControl(FSettingsMenu, IMenuItem, Result, TCustomClickEvent.Create(MenuItemClick));
end;

destructor TQipPlugin.Destroy;
begin
  FreeMenu;
  Widgets_Clear;
  FCLWidget := nil;
  FMWWidget := nil;

  FreeAndNil(FSyncObj);
  DeleteObject(FPlugIco);
  FPlugIco := 0;
  inherited;
end;

procedure TQipPlugin.FinalPlugin;
begin
  DoFreeSettings(Self);
  inherited;
end;

procedure TQipPlugin.FreeMenu;
begin
  FSettingsMenu := nil;
end;

procedure TQipPlugin.DoFreeSettings(Sender: TObject);
begin
  if Assigned(FSettingsWnd) then
    FreeAndNil(FSettingsWnd);
end;

procedure TQipPlugin.FreeSettings(Sender: TObject);
begin
  //async free window and TSettings
  PostMessage(FSyncObj.Handle, WM_SYNC, 0, 0);
end;

procedure TQipPlugin.GetPluginInformation(var VersionMajor,
  VersionMinor: Word; var PluginName, Creator, Description,
  Hint: PWideChar);
begin
  inherited;
  VersionMajor := PLUGIN_VER_MAJOR;
  VersionMinor := PLUGIN_VER_MINOR;
  Creator      := PWideChar(PLUGIN_AUTHOR);
  PluginName   := PWideChar(PLUGIN_NAME);
  Hint         := PWideChar(PLUGIN_HINT);
  Description  := PWideChar(PLUGIN_DESC);
end;

procedure TQipPlugin.InitPlugin;
begin
  inherited;
  //note here that without call to CoreUtils all gui methods will fail - CoreUtils has to be created in baseplugin
  if CoreUtils = nil then Exit;
  CreateMenu;
  //you can create your widget wrappers right in InitPlugin, or any time after first InitPlugin call
  FCLWidget := TSampleWidget.Create(Self, wgcCL, True);
  FMWWidget := TSampleWidget.Create(Self, wgcMsg, True);
end;

procedure TQipPlugin.LoadOptions;
begin
  inherited;

  RecreateMenu;
  if not Options.Bool3 then
  begin
    Options := DefaultOptions;
    SaveOptions;
  end;

  //don't forget to clear widgets from core if you re-adding the same widget
  Widgets_Clear;
  if Options.Bool1 then
    Widgets_Add(FCLWidget);
  if Options.Bool2 then
    Widgets_Add(FMWWidget);
end;

procedure TQipPlugin.MenuItemClick(Sender: IComponent);
var
  mnu: IMenuItem;
  spec: TPluginSpecific;
begin
  if Supports(Sender, IMenuItem, mnu) then
  case mnu.Tag of
    1: begin
         spec := Options;
         spec.Bool1 := not spec.Bool1;
         Options := spec;
         mnu.Checked := Options.Bool1;

         if Options.Bool1 then
           Widgets_Add(FCLWidget)
         else
           Widgets_Delete(FCLWidget.ID);
       end;
    2: begin
         spec := Options;
         spec.Bool2 := not spec.Bool2;
         Options := spec;
         mnu.Checked := Options.Bool2;

         if Options.Bool2 then
           Widgets_Add(FMWWidget)
         else
           Widgets_Delete(FMWWidget.ID);
       end;
    3: begin
         if not Assigned(FSettingsWnd) then
           FSettingsWnd := TSettings.Create(CoreGUI, CoreUtils, FreeSettings);
         FSettingsWnd.Show;
       end;
  end;
end;

procedure TQipPlugin.OnOptions;
var
  CP: TPoint;
begin
  inherited;
  if GetCursorPos(CP) then
    FSettingsMenu.Popup(CP.X, CP.Y);
end;

function TQipPlugin.PluginIcon: HICON;
begin
  Result := FPlugIco;
end;

procedure TQipPlugin.RecreateMenu;
var
  MI: IMenuItem;
begin
  FreeMenu;
  CreateMenu;

  if FSettingsMenu <> nil then
  begin
    MI         := CreateMenuItem();
    MI.Tag     := 1;
    MI.Caption := GetIString(LI_RADIO_SHOW_IN_CL);
    MI.Checked := Options.Bool1;
    FSettingsMenu.Items.Add(MI);

    MI         := CreateMenuItem();
    MI.Tag     := 2;
    MI.Checked := Options.Bool2;
    MI.Caption := GetIString(LI_RADIO_SHOW_IN_MW);
    FSettingsMenu.Items.Add(MI);

    MI         := CreateMenuItem();
    MI.Caption := GetIString('-');
    FSettingsMenu.Items.Add(MI);

    MI         := CreateMenuItem();
    MI.Tag     := 3;
    MI.Caption := GetIString(LI_SETTINGS);
    FSettingsMenu.Items.Add(MI);
  end;
end;

{ TSampleWidget }

constructor TSampleWidget.Create(AOwner: TCustomBaseQipPlugin;
  AClass: TWidgetClass; AllowCompact: Boolean);
begin
  inherited;
  FHighlightSettings := False;
  FHighlightRefresh  := False;
  FSettingsPressed   := False;
  FRefreshPressed    := False;
  FOwner.CoreGUI.CreateObject(IThemeServices, FThemeServices, nil);
end;

destructor TSampleWidget.Destroy;
begin
  FThemeServices := nil;
  inherited;
end;

procedure TSampleWidget.Draw(const DC: HDC; DrawRect: TRect; MousePt: TPoint);
var
  Canvas: ICanvas;
  S: IString;
  Colors: TQipColors;
  FontName: WideString;
  FontSize: Integer;
  R: TRect;
begin
  inherited;
  TQipPlugin(FOwner).CoreGUI.CreateObject(ICanvas, Canvas, nil);
  if Canvas <> nil then
  try
    Canvas.Handle := DC;
    Canvas.Brush.Style := bsClear;

    {if PtInRect(DrawRect, MousePt) or FPopupMenuVisible then
    begin
      DrawOptions(Canvas, DrawRect);
      Exit;
    end;}
    
    if IsCompact then
      S := GetIString('skin://graph,20')
    else
      S := GetIString('skin://graph,308');

    R := DrawRect;
    if IsCompact then
      InflateRect(R, -1, -1)
    else
      InflateRect(R, -CL_PADDING_X, -CL_PADDING_Y);
    if DrawRect.Bottom - DrawRect.Top < MulDiv(16, SCREEN_PPI, 96)*2 then
    begin
      R.Top    := DrawRect.Top + (DrawRect.Bottom - DrawRect.Top - MulDiv(16, SCREEN_PPI, 96)) div 2;
      R.Bottom := R.Top + MulDiv(16, SCREEN_PPI, 96);
    end;
    if IsCompact then
      R.Right := R.Left + MulDiv(16, SCREEN_PPI, 96)
    else
      R.Right := R.Left + (R.Bottom - R.Top);

    Canvas.StretchDraw(R, S, smZoom);

    if not TQipPlugin(FOwner).GetFontColorSettings(FontName, FontSize, Colors) then
    begin
      FontName     := SCREEN_FONT_NAME;
      FontSize     := SCREEN_FONT_SIZE;
      Colors.Group := $005E5E5E;
    end;
    Canvas.Font.Name  := GetIString(FontName);
    Canvas.Font.Size  := FontSize;
    Canvas.Font.Color := Colors.Group;

    if GetClass = wgcCL then
      S := GetIString('contact-list widget')
    else
      S := GetIString('message window widget');
    if FFiles <> nil then
      S := FFiles.Text;
    FontName := s.wString;

    R.Left   := R.Right + CL_TEXT_PADDING;
    R.Right  := DrawRect.Right;
    R.Top    := DrawRect.Top;
    R.Bottom := DrawRect.Bottom;
    DrawTextW(Canvas.Handle, S.pString, s.Length, R, DT_SINGLELINE or DT_VCENTER or DT_LEFT or DT_END_ELLIPSIS);
  finally
    Canvas.Handle := 0;
    Canvas := nil;
  end;
end;

procedure TSampleWidget.DrawHint(const DC: HDC; DrawRect: TRect);
var
  Canvas: ICanvas;
  S: IString;
begin
  inherited;
  TQipPlugin(FOwner).CoreGUI.CreateObject(ICanvas, Canvas, nil);
  if Canvas <> nil then
  try
    Canvas.Handle := DC;
    Canvas.Brush.Style := bsClear;

    S := GetIString('Test hint Str');
    DrawTextW(Canvas.Handle, S.pString, S.Length, DrawRect, DT_SINGLELINE or DT_VCENTER or DT_CENTER);
  finally
    Canvas.Handle := 0;
    Canvas := nil;
  end;
end;

procedure TSampleWidget.DrawOptions(Canvas: ICanvas; ARect: TRect);
var rct: TRect;
    OptionsRect: TRect;
    RefreshRect: TRect;
begin
  OptionsRect := GetOptionsRect;
  RefreshRect := GetRefreshRect;
  rct := RefreshRect;
  OffsetRect(rct, ARect.Left, ARect.Top);
  DrawToolButton(FThemeServices, Canvas, rct, FHighlightRefresh, FRefreshPressed);
  FOwner.DrawSkinImage(FOwner.GetSkinRes('refresh'), Canvas.Handle, rct);

  rct := OptionsRect;
  OffsetRect(rct, ARect.Left, ARect.Top);
  DrawToolButton(FThemeServices, Canvas, rct, FHighlightSettings, FSettingsPressed);
  FOwner.DrawSkinImage(FOwner.GetSkinRes('settings'), Canvas.Handle, rct);
end;

const
  OPT_WIDTH = 24;
  OPT_HEIGHT = 24;
  REFRESH_WIDTH = 24;
  REFRESH_HEIGHT = 24;

procedure TSampleWidget.GetHintInfo(const DC: HDC; var W, H: Integer;
  var HintPos: TWidgetHintPos);
begin
  inherited;

  if DC <> 0 then
  with HintSize(DC) do
  begin
    W := cx;
    H := cy;
    //you may change here the position of hint
    //if you don't want to cover other widgets - keep default wpLeft
    HintPos := wpBottom;
  end;
end;

function TSampleWidget.GetOptionsRect: TRect;
begin
  Result.Right  := Bounds.Right - Bounds.Left - 5;
  Result.Left   := Result.Right - OPT_WIDTH;
  Result.Top    := (Bounds.Bottom - Bounds.Top - OPT_HEIGHT) div 2;
  Result.Bottom := Result.Top + OPT_HEIGHT;
end;

function TSampleWidget.GetRefreshRect: TRect;
begin
  Result.Right  := Bounds.Right - Bounds.Left - 5 - OPT_WIDTH - 5;
  Result.Left   := Result.Right - REFRESH_WIDTH;
  Result.Top    := (Bounds.Bottom - Bounds.Top - REFRESH_HEIGHT) div 2;
  Result.Bottom := Result.Top + REFRESH_HEIGHT;
end;

function TSampleWidget.HintSize(const DC: HDC): TSize;
var
  TmpCanv: ICanvas;
  S: IString;
begin
  FOwner.CoreGUI.CreateObject(ICanvas, TmpCanv, nil);
  if TmpCanv <> nil then
  try
    TmpCanv.Handle := DC;

    S := GetIString('Test Hint Str');
    Result.cy := TmpCanv.TextHeight(S) + 10;
    Result.cx := TmpCanv.TextWidth(S) + 20;

  finally
    TmpCanv.Handle := 0;
    TmpCanv := nil;
  end;
end;

procedure TSampleWidget.MouseDown(MousePt: TPoint; Button: TMouseButton;
  ShiftState: TShiftState);
begin
  inherited;
  if Button <> mbLeft then Exit;
  FRefreshPressed  := PtInRect(GetRefreshRect, MousePt);
  FSettingsPressed := PtInRect(GetOptionsRect, MousePt);
  Owner.Widgets_Invalidate(ID);
end;

procedure TSampleWidget.MouseEnter;
begin
  inherited;
  FOwner.Widgets_Invalidate(ID);
  FOwner.Widgets_ShowHint; 
end;

procedure TSampleWidget.MouseLeave;
begin
  inherited;
  FOwner.Widgets_Invalidate(ID);
end;

procedure TSampleWidget.MouseMove(MousePt: TPoint; ShiftState: TShiftState);
begin
  inherited;
  FHighlightRefresh  := PtInRect(GetRefreshRect, MousePt);
  FHighlightSettings := PtInRect(GetOptionsRect, MousePt);
  FOwner.Widgets_Invalidate(ID);
end;

procedure TSampleWidget.MouseUp(MousePt: TPoint; Button: TMouseButton;
  ShiftState: TShiftState);
var
  cp: TPoint;
  rct: TRect;
begin
  inherited;
  if not GetCursorPos(cp) then Exit;

  if PtInRect(GetOptionsRect, MousePt) and FSettingsPressed then
  begin
    FPopupMenuVisible := True;
    TQIPPlugin(FOwner).FSettingsMenu.Popup(cp.X, cp.Y);
    FPopupMenuVisible := False;
  end;

  try
    case Button of 
      mbRight:
        begin
          TQIPPlugin(FOwner).OnOptions;
        end;
      mbLeft:
        begin
          rct        := Bounds;
          rct.Left   := rct.Left + 4 + 4;
          rct.Right  := rct.Left + MulDiv(16, SCREEN_PPI, 96);
          rct.Top    := rct.Top + ((rct.Bottom - rct.Top - MulDiv(16, SCREEN_PPI, 96)) div 2);
          rct.Bottom := rct.Top + MulDiv(16, SCREEN_PPI, 96);
          if PtInRect(rct, cp) or (PtInRect(GetRefreshRect, MousePt) and FRefreshPressed) then
            TQIPPlugin(FOwner).ShowFade('refresh action', 'this is the refresh action', 0, 2);
        end;
    end;
  finally
    FRefreshPressed  := False;
    FSettingsPressed := False;
    Owner.Widgets_Invalidate(ID);
  end;
end;

procedure TSampleWidget.DragDrop(const Files: IStringList; DataObject: IDataObject;
  Shift: u_gui_const.TShiftState; Pt: TPoint;
  Mode: u_gui_const.TDropMode; var Effect: Integer);
begin
  Effect := DROPEFFECT_COPY;
  FFiles := Files;
end;

procedure TSampleWidget.DragOver(const Files: IStringList; DataObject: IDataObject;
  Shift: u_gui_const.TShiftState; Pt: TPoint;
  Mode: u_gui_const.TDropMode; State: u_gui_const.TDragState; 
  var Effect: Integer; var Accept: Boolean);
begin
  FFiles := nil;
  Effect := DROPEFFECT_LINK;
  Accept := True;
end;

end.
