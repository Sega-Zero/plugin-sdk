unit WndUnit;

interface

uses
  Windows, Classes, SysUtils, Types,
{$IFDEF DFM_EDITOR}
  Windows, Messages, SysUtils,
  Variants, Classes, Graphics, Controls, Forms,
  Dialogs, VirtualTrees, StdCtrls, ExtCtrls, Buttons, u_PageList,
{$ENDIF}
  u_public_intf, u_gui_const, u_gui_intf, u_gui_events, u_gui_helpers;

{$IFDEF DFM_EDITOR}
type
  TForm1 = class(TForm)
    Timer1: TTimer;
    plPages: TInfuPageList;
    InfuPage1: TInfuPage;
    InfuPage2: TInfuPage;
    sbTest: TSpeedButton;
    pbTestPaint: TPaintBox;
    btBack: TButton;
    btApply: TButton;
    cbCheck: TCheckBox;
    RadioButton1: TRadioButton;
    RadioButton2: TRadioButton;
    RadioGroup1: TRadioGroup;
    edTest: TEdit;
    btClose: TButton;
    vstTest: TVirtualStringTree;
  private
    { Private declarations }
  public
    { Public declarations }
  end;
{$ENDIF}

type
  TSettings = class;

  TForm1Events = class(TCustomWindowEvents)
  protected
    FOwner: TSettings;
    procedure LanguageChanged(NewLangName: IString); override; safecall;
    procedure SkinChanged(NewSkinName: IString); override; safecall;
    procedure AntiBossChanged(const Activated: BOOL); override; safecall;

    procedure OnPropertyChanged(sender: IInterface; component: IComponent);
    procedure OnClose(Sender: IComponent; var Action: TCloseAction);
  public
    constructor Create(Owner: TSettings);
  end;

  TvstTestEvents = class(TCustomTreeViewPaintEvent, IMouseClickEvents, IMouseMoveEvents)
  protected
    FEvClick : IMouseClickEvents;
    FEvMove  : IMouseMoveEvents;
    procedure AfterCellPaint(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex; CellRect: TRect); override; safecall;
  protected
    FOwner: TSettings;
    FSettingsPressed: Boolean;
    function SettingsRect(CellRect: TRect): TRect;

    procedure OnMouseDown(sender: IComponent; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure OnMouseUp(sender: IComponent; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure OnMouseMove(Sender: IComponent; Shift: TShiftState; X, Y: Integer);
  public
    property EvClick : IMouseClickEvents read FEvClick implements IMouseClickEvents;
    property EvMove  : IMouseMoveEvents  read FEvMove  implements IMouseMoveEvents;

    constructor Create(Owner: TSettings);
  end;

  TSettings = class
  private
    frm: IForm;

    Timer1: ITimer;
    plPages: IPageList;
    {InfuPage1: IPage;
    InfuPage2: IPage;}
    sbTest: ISpeedButton;
    pbTestPaint: IPaintBox;
    btBack: IButton;
    btApply: IButton;
    cbCheck: ICheckBox;
    RadioButton1: IRadioButton;
    RadioButton2: IRadioButton;
    RadioGroup1: IRadioGroup;
    edTest: IEdit;
    btClose: IButton;
    vstTest: IVirtualTree;

    FCore: IQIPUtils;
    FGUI: IQIPCoreGUI;
    FThemeServices: IThemeServices;
    FOnFree: TNotifyEvent;
  private
    {IEventsCallback}
    procedure OnSetEvents(Sender: IComponent);
    {Form1}
    procedure OnFreeComponent(Sender: IComponent);
    procedure DoFree();
    {Timer1}
    procedure Timer1Timer(Sender: IComponent);
    {btBack, btApply, btClose, sbTest}
    procedure btApplyClick(Sender: IComponent);
    procedure btCloseClick(Sender: IComponent);
    procedure btBackClick(Sender: IComponent);
    procedure sbTestClick(Sender: IComponent);
    {pbTestPaint}
    procedure pbTestPaintPaint(Sender: IComponent);
    {edTest}
    procedure edTestChanged(Sender: IComponent);
  public
    constructor Create(GUI: IQIPCoreGUI; Core: IQIPUtils; OnFree: TNotifyEvent);
    destructor Destroy; override;

    procedure Show;
  end;

implementation

uses
  u_string, u_lang_ids, u_gr_ids, u_gui_graphics, Math;

{$R form.res}

{$IFDEF DFM_EDITOR}
{$R *.dfm}
{$ENDIF}

procedure DrawGradient(ACanvas: ICanvas; Rect: TRect; Horizontal: Boolean; Colors: array of TColor);
type
  RGBArray = array[0..2] of Byte;
var
  x, y, z, stelle, mx, bis, faColorsh, mass: Integer;
  Faktor: double;
  A: RGBArray;
  B: array of RGBArray;
  merkw: integer;
  merks: TPenStyle;
  merkp: TColor;
begin
  mx := High(Colors);

  if (mx = 0) or ((mx = 1) and (Colors[0] = Colors[1])) then
  begin
    if Colors[0] = clNone then Exit;
    //fast paint
    ACanvas.Brush.Color := Colors[0];
    ACanvas.Brush.Style := bsSolid;
    if Colors[0] <> clNone then
      ACanvas.FillRect(Rect);
    Exit;
  end;
  
  if mx > 0 then
  begin
    if Horizontal then
      mass := Rect.Right - Rect.Left
    else
      mass := Rect.Bottom - Rect.Top;
    SetLength(b, mx + 1);
    for x := 0 to mx do
    begin
      Colors[x] := ColorToRGB(Colors[x]);
      b[x][0] := GetRValue(Colors[x]);
      b[x][1] := GetGValue(Colors[x]);
      b[x][2] := GetBValue(Colors[x]);
    end;
    merkw := ACanvas.Pen.Width;
    merks := ACanvas.Pen.Style;
    merkp := ACanvas.Pen.Color;
    ACanvas.Pen.Width := 1;
    ACanvas.Pen.Style := psSolid;
    faColorsh := Round(mass / mx);
    for y := 0 to mx - 1 do
    begin
      if y = mx - 1 then
        bis := mass - y * faColorsh - 1
      else
        bis := faColorsh;

      for x := 0 to bis do
      begin
        Stelle := x + y * faColorsh;
        if (bis = 0) then bis := 1;
        faktor := x / bis;
        for z := 0 to 3 do
          a[z] := Trunc(b[y][z] + ((b[y + 1][z] - b[y][z]) * Faktor));
        ACanvas.Pen.Color := RGB(a[0], a[1], a[2]);

        if Horizontal then
        begin
          ACanvas.MoveTo(Rect.Left + Stelle, Rect.Top);
          ACanvas.LineTo(Rect.Left + Stelle, Rect.Bottom);
        end
        else
          begin
            ACanvas.MoveTo(Rect.Left, Rect.Top + Stelle);
            ACanvas.LineTo(Rect.Right, Rect.Top + Stelle);
          end;
      end;
    end;
    b := nil;
    ACanvas.Pen.Width := merkw;
    ACanvas.Pen.Style := merks;
    ACanvas.Pen.Color := merkp;
  end;
end;

procedure DrawButton(ThemeServices: IThemeServices; TargetCanvas: ICanvas; ARect: TRect; const BtnText: IString; PtOver, BtDown: Boolean);
var
  R, R1: TRect;
begin
  TargetCanvas.Font.Style := [];
  TargetCanvas.Font.Size  := 8;

  R := ARect;
  InflateRect(R, -1, -((ARect.Bottom - ARect.Top) - 24) div 2);

  if not BtDown then
  begin
    InflateRect(R, 0, -1);

    with ThemeServices do
    if ThemesEnabled then
    begin
      if PtOver then
        DrawElement(TargetCanvas.Handle, GetElementDetails(tbPushButtonHot), R, nil)
      else
        DrawElement(TargetCanvas.Handle, GetElementDetails(tbPushButtonNormal), R, nil)
    end
    else
    begin
      InflateRect(R, -1, -3);
      TargetCanvas.Pen.Color   := clBtnHighlight;
      TargetCanvas.Rectangle(R);

      if PtOver then
        DrawGradient(TargetCanvas, R, False, [clBtnHighlight, clBtnFace, clBtnFace])
      else
        DrawGradient(TargetCanvas, R, False, [clBtnHighlight, clBtnFace]);

      TargetCanvas.Pen.Color   := clBtnShadow;
      TargetCanvas.MoveTo(R.Left, R.Bottom-1);
      TargetCanvas.LineTo(R.Right-1, R.Bottom-1);
      TargetCanvas.LineTo(R.Right-1, R.Top);
    end;

    TargetCanvas.TextOut(R.Left + (R.Right - R.Left) div 2 - TargetCanvas.TextWidth(BtnText) div 2,
                         R.Top + (R.Bottom - R.Top) div 2 - TargetCanvas.TextHeight(BtnText) div 2 -1,
                         BtnText);
  end
  else
  begin
    InflateRect(R, -1, -1);
    if ThemeServices.ThemesEnabled then
    with ThemeServices do
      DrawElement(TargetCanvas.Handle, GetElementDetails(tbPushButtonPressed), R, nil)
    else
    begin
      InflateRect(R, -1, -3);
      TargetCanvas.Pen.Color   := clBtnShadow;
      TargetCanvas.Rectangle(R);
      R1 := Rect(R.Left + 1, R.Top +1, R.Right, R.Bottom);
      if PtOver then
        DrawGradient(TargetCanvas, R1, False, [clBtnHighlight, clBtnFace, clBtnFace])
      else
        DrawGradient(TargetCanvas, R1, False, [clBtnHighlight, clBtnFace]);

      TargetCanvas.Pen.Color   := clBtnHighlight;
      TargetCanvas.MoveTo(R.Left, R.Bottom-1);
      TargetCanvas.LineTo(R.Right-1, R.Bottom-1);
      TargetCanvas.LineTo(R.Right-1, R.Top);
    end;

    TargetCanvas.TextOut(R.Left + (R.Right - R.Left) div 2 - TargetCanvas.TextWidth(BtnText) div 2 + 1,
                         R.Top + (R.Bottom - R.Top) div 2 - TargetCanvas.TextHeight(BtnText) div 2,
                         BtnText);
  end;
end;//DrawButton

{ TSettings }

function ThisModuleFileNameW: WideString;
var
  tempdir: array[0..MAX_PATH] of WideChar;
begin
  Result := '';
  if GetModuleFileNameW(HInstance, @tempdir[0], MAX_PATH + 1) <> 0 then
    Result := tempdir;
end;

constructor TSettings.Create(GUI: IQIPCoreGUI; Core: IQIPUtils; OnFree: TNotifyEvent);
begin
  inherited Create;
  FOnFree := OnFree;

  FCore := Core;
  FGUI  := GUI;
  FGUI.CreateObject(IThemeServices, FThemeServices, nil);

  frm               := GUI.CreateControls(GetIString('res://' + ThisModuleFileNameW + ',main'), TCustomEventsCallback.Create(OnSetEvents)) as IForm;
  frm.ShowOnTaskbar := True;
  frm.Events        := TForm1Events.Create(Self);
  frm.HandleNeeded;
  with frm.Events as IGuiEvents do
  begin
    LanguageChanged(CreateIString(''));
    SkinChanged(CreateIString(''));
  end;

  (* you may also create the same window with that code (approximately)
  GUI.CreateControl(nil, IForm, frm, evnts);
  frm.ShowOnTaskbar := True;
  frm.Width  := 399;
  frm.Height := 382;

  GUI.CreateControl(frm, IPageList, plPages, evnts);
  plPages.Parent := frm;
  plPages.Left := 5;
  plPages.Top  := 5;
  plPages.Width := 389;
  plPages.Height := 372;
  plPages.Anchors := [akLeft, akTop, akRight, akBottom];

  GUI.CreateControl(frm, IPage, Page1, nil);
  Page1.PageList := plPages;

  GUI.CreateControl(frm, IVirtualTree, vstTest, evnts);
  vstTest.Parent := Page1;
  with vstTest do
  begin
    Anchors := [akLeft, akTop, akBottom, akRight];
    Left := 10;
    Top := 11;
    Width := 345;
    Height := 222;
    DefaultNodeHeight := 40;
    TreeOptions.PaintOptions := [toHideFocusRect, toHideSelection, toShowButtons,
                                 toShowDropmark, toShowHorzGridLines, toThemeAware,
                                 toUseBlendedImages, toAlwaysHideSelection];
    TreeOptions.SelectionOptions := [toFullRowSelect];
  end;
    
  GUI.CreateControl(frm, IButton, btClose, evnts);
  btClose.Parent := Page1;
  btClose.Left   := 168;
  btClose.Top    := 248;
  btClose.Anchors := [akRight, akBottom];

  GUI.CreateControl(frm, IPage, Page2, nil);
  Page2.PageList := plPages;
  Page2.Color := clWhite;

  GUI.CreateControl(frm, IEdit, edTest, evnts);
  with edTest do
  begin
    Parent := Page2;
    Left := 16;
    Top := 176;
    Width := 121;
    Height := 21;
  end;

  GUI.CreateControl(frm, IRadioButton, rb, nil);
  rb.Parent := Page2;
  rb.Left   := 15;
  rb.Top    := 50;
  rb.Caption := GetIString('blablablablablablabla');
  GUI.CreateControl(frm, IRadioButton, rb, nil);
  rb.Parent := Page2;
  rb.Left   := 15;
  rb.Top    := 80;
  rb.Checked := True;
  rb.Caption := GetIString('blablablablablablabla2');

  GUI.CreateControl(frm, IButton, btApply, evnts);
  btApply.Parent := Page2;
  btApply.Left   := 280;
  btApply.Top    := 240;
  btApply.Anchors := [akRight, akBottom];
  btApply.Enabled := False;
  btApply.Visible := True;

  GUI.CreateControl(frm, IButton, btBack, evnts);
  btBack.Parent := Page2;
  btBack.Left   := 11;
  btBack.Top    := 240;
  btBack.Anchors := [akRight, akBottom];
  vstTest.AddChild(nil);
  plPages.ActivePage := Page1;

  *)
end;

destructor TSettings.Destroy;
begin
  frm := nil;

  FCore          := nil;
  FGUI           := nil;
  FThemeServices := nil;

  inherited;
end;

procedure TSettings.Show;
begin
  if not frm.Visible then
  begin
    btApply.Click;
    frm.Show;
  end
  else
    begin
      plPages.ActivePage := plPages.Pages[0];
      BringWindowToTop(frm.Handle);
    end;
end;

procedure TSettings.OnSetEvents(Sender: IComponent);
begin
  if Sender.Name.wString = 'Timer1' then
  begin
    Timer1        := Sender as ITimer;
    Timer1.Events := TTimerEvents.Create(Timer1Timer);
  end;

  if Sender.Name.wString = 'sbTest' then
  begin
    sbTest        := Sender as ISpeedButton;
    sbTest.Events := TCustomClickEvent.Create(sbTestClick);
  end;

  if Sender.Name.wString = 'cbCheck' then
  begin
    cbCheck        := Sender as ICheckBox;
    //cbCheck.Events := ;
  end;

  if Sender.Name.wString = 'RadioButton1' then
  begin
    RadioButton1        := Sender as IRadioButton;
    //RadioButton1.Events := ;
  end;

  if Sender.Name.wString = 'RadioButton2' then
  begin
    RadioButton2        := Sender as IRadioButton;
    //RadioButton2.Events := ;
  end;

  if Sender.Name.wString = 'RadioGroup1' then
  begin
    RadioGroup1        := Sender as IRadioGroup;
    //RadioGroup1.Events := ;
  end;

  if Sender.Name.wString = 'btApply' then
  begin
    btApply        := Sender as IButton;
    btApply.Events := TCustomClickEvent.Create(btApplyClick);
  end;

  if Sender.Name.wString = 'btClose' then
  begin
    btClose        := Sender as IButton;
    btClose.Events := TCustomClickEvent.Create(btCloseClick);
  end;

  if Sender.Name.wString = 'btBack' then
  begin
    btBack         := Sender as IButton;
    btBack.Events  := TCustomClickEvent.Create(btBackClick);
  end;

  if Sender.Name.wString = 'vstTest' then
  begin
    vstTest                  := Sender as IVirtualTree;
    vstTest.Events           := TvstTestEvents.Create(Self);
    vstTest.Header.Height    := MulDiv(vstTest.Header.Height, SCREEN_PPI, 96);
    vstTest.Header.Font.Size := MulDiv(vstTest.Header.Font.Size, SCREEN_PPI, 96);
    vstTest.Header.Font.Name := GetIString(SCREEN_FONT_NAME);
    vstTest.AddChild(nil);
  end;

  if Sender.Name.wString = 'plPages' then
  begin
    plPages            := Sender as IPageList;
    plPages.ActivePage := plPages.Pages[0];
  end;

  if Sender.Name.wString = 'pbTestPaint' then
  begin
    pbTestPaint        := Sender as IPaintBox;
    pbTestPaint.Events := TCustomPaintEvent.Create(pbTestPaintPaint);
  end;

  if Sender.Name.wString = 'edTest' then
  begin
    edTest                 := Sender as IEdit;
    edTest.Events          := TCustomChangeEvent.Create(edTestChanged);
    edTest.TextHint        := GetIString('inplace hint');
    edTest.TextHintOptions := edTest.TextHintOptions + [hoLeftAlign];
  end;
end;

procedure TSettings.OnFreeComponent(Sender: IComponent);
begin
  //delete control from window
  if Sender.Name.wString = 'edTest' then
    edTest := nil;

  //etc...
end;

procedure TSettings.Timer1Timer(Sender: IComponent);
begin
  if pbTestPaint.Visible then
    pbTestPaint.Invalidate;
end;

procedure TSettings.btApplyClick(Sender: IComponent);
begin
  btApply.Enabled := False; 
  frm.Listener.WatchClear;
  frm.Listener.WatchForProperties(IRadioButton, GetIString('Checked'));
  frm.Listener.WatchForProperties(ICheckBox, GetIString('Checked'));
  frm.Listener.WatchForProperties(IRadioGroup, GetIString('ItemIndex'));
  frm.Listener.WatchForProperties(IEdit, GetIString('Text'));
end;

procedure TSettings.btBackClick(Sender: IComponent);
begin
  plPages.ActivePage := plPages.Pages[0];
end;

procedure TSettings.btCloseClick(Sender: IComponent);
begin
  frm.Close;
end;

procedure TSettings.sbTestClick(Sender: IComponent);
begin
  if edTest.Parent = nil then
    edTest.Parent := plPages.Pages[1]
  else
    edTest.Parent := nil;
end;

procedure TSettings.pbTestPaintPaint(Sender: IComponent);
var
  r: TRect;
  S: IString;
begin
  if Supports(sender, IPaintBox) then
  with pbTestPaint, Canvas do
  begin
    r           := ClientRect;
    Brush.Color := clBtnFace;
    FillRect(r);

    S       := GetIString('skin://graph,' + IntToStr(GR_DEF_AVATAR));
    r.Right := r.Left + 48;

    StretchDraw(R, S, smZoom);

    R := ClipRect;
    Inc(r.Left, 50);

    S                 := GetIString('TEST DRAWING');
    Canvas.Font.Size  := 32;
    Canvas.Font.Style := [fsBold];
    Canvas.Font.Color := RandomRange(clScrollBar, clMedGray);

    DrawTextW(Handle, S.pString, S.Length, R, DT_SINGLELINE or DT_VCENTER or DT_END_ELLIPSIS)
  end; 
end;

procedure TSettings.edTestChanged(Sender: IComponent);
begin
  {do something}
end;

procedure TSettings.DoFree;
begin
  Assert(Assigned(FOnFree));
  frm.Hide;
  FOnFree(Self);
end;

{ TForm1Events }

constructor TForm1Events.Create(Owner: TSettings);
begin
  FOwner := Owner;
  inherited Create(FOwner.OnFreeComponent, OnClose, OnPropertyChanged);
end;

procedure TForm1Events.AntiBossChanged(const Activated: BOOL);
begin
  inherited;
  FOwner.frm.Visible := not Activated;
end;

procedure TForm1Events.LanguageChanged(NewLangName: IString);
begin
  inherited;
  FOwner.frm.Caption      := GetIString(LI_PREFS_2);
  FOwner.btApply.Caption  := GetIString(LI_APPLY);
  FOwner.btClose.Caption  := GetIString(LI_CLOSE);
  FOwner.btBack.Caption   := GetIString(LI_BACK);
end;

procedure TForm1Events.SkinChanged(NewSkinName: IString);
begin
  inherited;
  FOwner.frm.IconURI    := GetIString('skin://graph,' + IntToStr(GR_PREFS));
  FOwner.btClose.ImgURI := GetIString('skin://graph,' + IntToStr(GR_QIP_CLOSE_ICON));
end;

procedure TForm1Events.OnPropertyChanged(sender: IInterface; component: IComponent);
begin
  FOwner.btApply.Enabled := FOwner.frm.Listener.Changed;
end;

procedure TForm1Events.OnClose(Sender: IComponent; var Action: TCloseAction);
begin
  Action := caNone;
  FOwner.DoFree;
end;

{ TvstTestEvents }

constructor TvstTestEvents.Create(Owner: TSettings);
begin
  inherited Create();
  FOwner   := Owner;
  FEvClick := TCustomClickEvent.Create(nil, OnMouseUp, OnMouseDown);
  FEvMove  := TCustomMoveEvent.Create(OnMouseMove, nil, nil);
  FSettingsPressed := False;
end;

procedure TvstTestEvents.AfterCellPaint(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex;
  CellRect: TRect);
var
  S: IString;
  R, DR: TRect;
  HitInfo: THitInfo;
  Pt: TPoint;
  IsOver: Boolean;
begin
  inherited;

  TargetCanvas.Brush.Style := bsClear;
    
  IsOver := GetCursorPos(Pt);
  Pt := FOwner.vstTest.ScreenToClient(Pt);
  if IsOver then FOwner.vstTest.GetHitTestInfoAt(Pt.X, Pt.Y, True, HitInfo);
  IsOver := (HitInfo.HitNode = Node) and (HitInfo.HitColumn = Column);

  R := CellRect;
  if IsOver or FSettingsPressed then
    R.Right := SettingsRect(R).Left - 4;

  DR := R;
  Inc(DR.Left, 5);
  Inc(DR.Top, 7);
  S := GetIString(LI_INSUFFICIENT_RIGHTS);//lol
  TargetCanvas.Font.Color := clWindowText;
  TargetCanvas.Font.Style := [fsBold];
  DrawTextW(TargetCanvas.Handle, S.pString, S.Length, DR,
            DT_SINGLELINE or DT_LEFT or DT_END_ELLIPSIS or DT_NOPREFIX);

  TargetCanvas.Font.Color := $00888888;
  TargetCanvas.Font.Style := [];
  Inc(DR.Top, TargetCanvas.TextHeight(S) + 2);
  S.SetString(LI_PLUGIN_IN_ISOLATED);//lol too

  DrawTextW(TargetCanvas.Handle, S.pString, S.Length, DR,
            DT_VCENTER or DT_SINGLELINE or DT_LEFT or DT_END_ELLIPSIS or DT_NOPREFIX);

  if IsOver or FSettingsPressed then
  begin
    TargetCanvas.Font.Color := clWindowText;
    DR := SettingsRect(CellRect);
    DrawButton(FOwner.FThemeServices, TargetCanvas, DR, GetIString(LI_SETTINGS), PtInRect(DR, Pt), FSettingsPressed);
  end;
end;

procedure TvstTestEvents.OnMouseMove(Sender: IComponent;
  Shift: TShiftState; X, Y: Integer);
var
  HitInfo: THitInfo;
  DR: TRect;
begin
  if FSettingsPressed then
  begin
    FOwner.vstTest.GetHitTestInfoAt(X, Y, True, HitInfo);
    if (HitInfo.HitNode = nil) then Exit;

    DR := FOwner.vstTest.GetDisplayRect(HitInfo.HitNode, -1, False, False);
    FSettingsPressed := PtInRect(SettingsRect(DR), Point(X, Y));

    FOwner.vstTest.RepaintNode(HitInfo.HitNode);
  end
  else
    FOwner.vstTest.Invalidate;
end;

procedure TvstTestEvents.OnMouseDown(sender: IComponent;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  HitInfo: THitInfo;
  DR: TRect;
begin
  if (Button <> mbLeft) then Exit;

  FOwner.vstTest.GetHitTestInfoAt(X, Y, True, HitInfo);
  if (HitInfo.HitNode = nil) then Exit;

  DR := FOwner.vstTest.GetDisplayRect(HitInfo.HitNode, -1, False, False);
  FSettingsPressed := PtInRect(SettingsRect(DR), Point(X, Y));

  FOwner.vstTest.RepaintNode(HitInfo.HitNode);
end;

procedure TvstTestEvents.OnMouseUp(sender: IComponent;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  HitInfo: THitInfo;
begin
  if (Button <> mbLeft) then Exit;

  FOwner.vstTest.GetHitTestInfoAt(X, Y, True, HitInfo);

  if HitInfo.HitNode = nil then Exit;

  if FSettingsPressed then
  begin
    FSettingsPressed := False;
    FOwner.vstTest.RepaintNode(HitInfo.HitNode);
    FOwner.plPages.ActivePage := FOwner.plPages.Pages[1];
  end;
end;

function TvstTestEvents.SettingsRect(CellRect: TRect): TRect;
begin
  Result := CellRect;

  Dec(Result.Right, 8);
  Inc(Result.Top, 9);
  Dec(Result.Bottom, 10);

  Result.Left  := Result.Right - MulDiv(69, SCREEN_PPI, 96);
end;

end.
