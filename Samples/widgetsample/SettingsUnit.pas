unit SettingsUnit;

interface

uses
  Windows, u_public_intf, u_gui_const, u_gui_intf, u_gui_events, Types;

type
  TSettings = class;

  TControlEvents = class(TInterfacedObject, IMouseClickEvents, IMouseMoveEvents, ITreePaintEvents,
                         INodeChangeEvents, IGuiEvents, IWindowEvents, IPaintEvents, ITimerEvents)
  private
    FSettingsPressed: Boolean;
    function SettingsRect(CellRect: TRect): TRect;
  protected
    //mouse
    procedure Click(sender: IUnknown); safecall;
    procedure DblClick(sender: IUnknown); safecall;
    procedure MouseDown(sender: IUnknown; Button: TMouseButton; Shift: TShiftState; X, Y: Integer); safecall;
    procedure MouseUp(sender: IUnknown; Button: TMouseButton; Shift: TShiftState; X, Y: Integer); safecall;
    procedure UpDownClick(sender: IUnknown; Button: TUDBtnType); safecall;
    procedure MouseMove(sender: IUnknown; Shift: TShiftState; X, Y: Integer); safecall;
    procedure MouseEnter(sender: IUnknown); safecall;
    procedure MouseLeave(sender: IUnknown); safecall;

    //vtv
    procedure AdvancedHeaderDraw(Sender: ITreeHeader; var PaintInfo: THeaderPaintInfo; const Elements: THeaderPaintElements); safecall;
    procedure AfterCellPaint(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex; CellRect: TRect); safecall;
    procedure AfterItemErase(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect); safecall;
    procedure AfterItemPaint(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect); safecall;
    procedure AfterPaint(Sender: IUnknown; TargetCanvas: ICanvas); safecall;
    procedure BeforeCellPaint(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex; CellRect: TRect); safecall;
    procedure BeforeItemErase(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect;
                              var ItemColor: TColor; var EraseAction: TItemEraseAction); safecall;
    procedure BeforeItemPaint(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect; var CustomDraw: BOOL); safecall;
    procedure BeforePaint(Sender: IUnknown; TargetCanvas: ICanvas); safecall;
    procedure HeaderDraw(Sender: ITreeHeader; HeaderCanvas: ICanvas; Column: ITreeColumn;
                         R: TRect; Hover, Pressed: BOOL; DropMark: TVTDropMarkMode); safecall;
    procedure HeaderDrawQueryElements(Sender: ITreeHeader; var PaintInfo: THeaderPaintInfo; const Elements: THeaderPaintElements); safecall;
    procedure PaintBackground(Sender: IUnknown; TargetCanvas: ICanvas; R: TRect; var Handled: BOOL); safecall;
    procedure PaintText(Sender: IUnknown; TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType); safecall;
    procedure NodeChanged(Sender: IUnknown; Node: PVirtualNode); safecall;
    procedure NodeFocusChanged(Sender: IUnknown; Node: PVirtualNode; Column: TColumnIndex); safecall;
    procedure NodeFocusChanging(Sender: IUnknown; OldNode, NewNode: PVirtualNode;
                                OldColumn, NewColumn: TColumnIndex; var Allowed: BOOL); safecall;
    procedure NodeHotChange(Sender: IUnknown; OldNode, NewNode: PVirtualNode); safecall;

    //guievents
    procedure LanguageChanged(NewLangName: IString); safecall;
    procedure SkinChanged(NewSkinName: IString); safecall;
    procedure AntiBossChanged(const Activated: BOOL); safecall;
    procedure FreeNotify(sender: IComponent); safecall;

    //IWindowEvents
    procedure Activated(sender: IUnknown); safecall;
    procedure Closed(sender: IUnknown; var Action: TCloseAction); safecall;
    procedure CloseQuery(sender: IUnknown; var CanClose: BOOL); safecall;
    procedure Created(sender: IUnknown); safecall;
    procedure Destroyed(sender: IUnknown); safecall;
    procedure Deactivated(sender: IUnknown); safecall;
    procedure PropertyChanged(sender: IUnknown; component: IComponent); safecall;

    //IPaintEvents
    procedure Paint(sender: IUnknown); safecall;
    procedure ToolBarAdnvancedCustomDraw(sender: IToolBar; const ARect: TRect; Stage: TCustomDrawStage; var DefaultDraw: BOOL); safecall;
    procedure ToolBarCustomDraw(sender: IToolBar; const ARect: TRect; var DefaultDraw: BOOL); safecall;
    procedure ToolBarCustomDrawButton(sender: IToolBar; Button: IToolButton; State: TCustomDrawState; var DefaultDraw: BOOL); safecall;
    procedure ListDrawItem(Control: IWinControl; Index: Integer; Rect: TRect; State: TOwnerDrawState); safecall;
    procedure MenuItemDrawItem(sender: IUnknown; ACanvas: ICanvas; ARect: TRect; Selected: BOOL); safecall;
    procedure MenuItemAdvancedDrawItem(sender: IUnknown; ACanvas: ICanvas; ARect: TRect; State: TOwnerDrawState); safecall;

    //ITimerEvents
    procedure DidTimer(sender: IUnknown); safecall;
  public
    Owner: TSettings;
  end;

  TCallBack = class (TInterfacedObject, IEventsCallback)
  protected
    procedure SetEvent(Control: IComponent); safecall;
  public
    Event: IUnknown;
  end;

  TSettings = class
  private
    frm: IForm;
    vstTest: IVirtualTree;
    btApply, btClose, btBack: IButton;
    plPages: IPageList;
    pbTestPaint: IPaintBox;
    edTest: IEdit;
    //Page1, Page2: IPage;

    Events: IUnknown;
    FCore: IQIPUtils;
    FGUI: IQIPCoreGUI;
    FThemeServices: IThemeServices;

  public
    constructor Create(GUI: IQIPCoreGUI; Core: IQIPUtils);
    destructor Destroy; override;

    procedure UpdateLanguage;
    procedure UpdateGraphics;

    procedure Show;
    procedure Close;
  end;

implementation

uses
  u_string, u_lang_ids, u_gr_ids, SysUtils, u_gui_graphics, Math;

{$R form.res}

{ TSettings }

procedure TSettings.Close;
begin
  if Assigned(frm) then
    frm.Close;
end;

function ThisModuleFileNameW: WideString;
var
  tempdir: array[0..MAX_PATH] of WideChar;
begin
  Result := '';
  if GetModuleFileNameW(HInstance, @tempdir[0], MAX_PATH + 1) <> 0 then
    Result := tempdir;
end;

constructor TSettings.Create(GUI: IQIPCoreGUI; Core: IQIPUtils);
var
  CallBackClass: TCallBack;
  evnts: TControlEvents;
  //rb: IRadioButton;
begin
  inherited Create;

  FCore := Core;
  FGUI  := GUI;
  FGUI.CreateObject(IThemeServices, FThemeServices, nil);

  evnts := TControlEvents.Create;
  evnts.Owner := Self;
  evnts.FSettingsPressed := False;

  CallBackClass := TCallBack.Create;
  CallBackClass.Event := evnts;

  Events := evnts;
  frm := GUI.CreateControls(GetIString('res://' + ThisModuleFileNameW + ',main'), CallBackClass) as IForm;
  frm.ShowOnTaskbar := True;

  btApply := frm.FindComponent(GetIString('btApply')) as IButton;
  btClose := frm.FindComponent(GetIString('btClose')) as IButton;
  btBack  := frm.FindComponent(GetIString('btBack')) as IButton;

  vstTest := frm.FindComponent(GetIString('vstTest')) as IVirtualTree;
  plPages := frm.FindComponent(GetIString('plPages')) as IPageList;
  pbTestPaint := frm.FindComponent(GetIString('pbTestPaint')) as IPaintBox;

  edTest := frm.FindComponent(GetIString('edTest')) as IEdit;

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

  edTest.TextHint := GetIString('Hint');
  edTest.HintAlignLeft          := True;
  edTest.ClearHintOnPaste       := True;
  edTest.KeepTextHintAfterFocus := False;

  vstTest.AddChild(nil);
  plPages.ActivePage := plPages.Pages[0];

  UpdateLanguage;
  UpdateGraphics;
end;

destructor TSettings.Destroy;
begin
  FCore := nil;
  FGUI := nil;

  Events := nil;
  frm := nil;
  FThemeServices := nil;

  inherited;
end;

procedure TSettings.Show;
begin
  if Assigned(frm) then
  begin
    if not frm.Visible then
    begin
      frm.Listener.WatchClear;

      frm.Listener.WatchForProperties(IRadioButton, GetIString('Checked'));
      frm.Listener.WatchForProperties(ICheckBox, GetIString('Checked'));
      frm.Listener.WatchForProperties(IRadioGroup, GetIString('ItemIndex'));
      frm.Listener.WatchForProperties(IEdit, GetIString('Text'));

      frm.Show;
    end
    else
      begin
        plPages.ActivePage := plPages.Pages[0];
        BringWindowToTop(frm.Handle);
      end;
  end;
end;

procedure TSettings.UpdateGraphics;
begin
  frm.IconURI    := GetIString('skin://graph,' + IntToStr(GR_PREFS));
  btClose.ImgURI := GetIString('skin://graph,' + IntToStr(GR_QIP_CLOSE_ICON));
end;

procedure TSettings.UpdateLanguage;
begin
  frm.Caption      := GetIString(LI_PREFS_2);
  btApply.Caption  := GetIString(LI_APPLY);
  btClose.Caption  := GetIString(LI_CLOSE);
  btBack.Caption   := GetIString(LI_BACK);
end;

{ TControlEvents }

procedure TControlEvents.Activated(sender: IInterface);
begin

end;

procedure TControlEvents.AdvancedHeaderDraw(Sender: ITreeHeader;
  var PaintInfo: THeaderPaintInfo; const Elements: THeaderPaintElements);
begin

end;

function ColorToRGB(Color: TColor): Longint;
begin
  if Color < 0 then
    Result := GetSysColor(Color and $000000FF) else
    Result := Color;
end;

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

procedure TControlEvents.AfterCellPaint(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex;
  CellRect: TRect);
var
  S: IString;
  R, DR: TRect;
  HitInfo: THitInfo;
  Pt: TPoint;
  IsOver: Boolean;

begin

  TargetCanvas.Brush.Style := bsClear;
    
  IsOver := GetCursorPos(Pt);
  Pt := Owner.vstTest.ScreenToClient(Pt);
  if IsOver then Owner.vstTest.GetHitTestInfoAt(Pt.X, Pt.Y, True, HitInfo);
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
    DrawButton(Owner.FThemeServices, TargetCanvas, DR, GetIString(LI_SETTINGS), PtInRect(DR, Pt), FSettingsPressed);
  end;
end;

procedure TControlEvents.AfterItemErase(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect);
begin

end;

procedure TControlEvents.AfterItemPaint(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect);
begin

end;

procedure TControlEvents.AfterPaint(Sender: IInterface;
  TargetCanvas: ICanvas);
begin

end;

procedure TControlEvents.AntiBossChanged(const Activated: BOOL);
begin

end;

procedure TControlEvents.BeforeCellPaint(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex;
  CellRect: TRect);
begin

end;

procedure TControlEvents.BeforeItemErase(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect;
  var ItemColor: TColor; var EraseAction: TItemEraseAction);
begin

end;

procedure TControlEvents.BeforeItemPaint(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; ItemRect: TRect;
  var CustomDraw: BOOL);
begin

end;

procedure TControlEvents.BeforePaint(Sender: IInterface;
  TargetCanvas: ICanvas);
begin

end;

procedure TControlEvents.Click(sender: IInterface);
begin
  if Supports(sender, IButton) and ((sender as IButton) = Owner.btClose) then
    Owner.Close;

  if Supports(sender, IButton) and ((sender as IButton) = Owner.btBack) then
    Owner.plPages.ActivePage := Owner.plPages.Pages[0];
     
  if Supports(sender, IButton) and ((sender as IButton) = Owner.btApply) then
  begin
    Owner.btApply.Enabled := False; 
    Owner.frm.Listener.WatchClear;
    Owner.frm.Listener.WatchForProperties(IRadioButton, GetIString('Checked'));
    Owner.frm.Listener.WatchForProperties(ICheckBox, GetIString('Checked'));
    Owner.frm.Listener.WatchForProperties(IRadioGroup, GetIString('ItemIndex'));
    Owner.frm.Listener.WatchForProperties(IEdit, GetIString('Text'));
  end;
end;

procedure TControlEvents.Closed(sender: IInterface;
  var Action: TCloseAction);
begin

end;

procedure TControlEvents.CloseQuery(sender: IInterface;
  var CanClose: BOOL);
begin

end;

procedure TControlEvents.Created(sender: IInterface);
begin

end;

procedure TControlEvents.DblClick(sender: IInterface);
begin

end;

procedure TControlEvents.Deactivated(sender: IInterface);
begin

end;

procedure TControlEvents.Destroyed(sender: IInterface);
begin

end;

procedure TControlEvents.DidTimer(sender: IInterface);
begin
  if Owner.pbTestPaint.Visible then
    Owner.pbTestPaint.Invalidate;
end;

procedure TControlEvents.FreeNotify(sender: IComponent);
begin

end;

procedure TControlEvents.HeaderDraw(Sender: ITreeHeader;
  HeaderCanvas: ICanvas; Column: ITreeColumn; R: TRect; Hover,
  Pressed: BOOL; DropMark: TVTDropMarkMode);
begin

end;

procedure TControlEvents.HeaderDrawQueryElements(Sender: ITreeHeader;
  var PaintInfo: THeaderPaintInfo; const Elements: THeaderPaintElements);
begin

end;

procedure TControlEvents.LanguageChanged(NewLangName: IString);
begin
  Owner.UpdateLanguage;
end;

procedure TControlEvents.ListDrawItem(Control: IWinControl; Index: Integer;
  Rect: TRect; State: TOwnerDrawState);
begin

end;

procedure TControlEvents.MenuItemAdvancedDrawItem(sender: IInterface;
  ACanvas: ICanvas; ARect: TRect; State: TOwnerDrawState);
begin

end;

procedure TControlEvents.MenuItemDrawItem(sender: IInterface;
  ACanvas: ICanvas; ARect: TRect; Selected: BOOL);
begin

end;

procedure TControlEvents.MouseDown(sender: IInterface;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  HitInfo: THitInfo;
  DR: TRect;
begin
  if not Supports(sender, IVirtualTree) then Exit;

  if (Button <> mbLeft) then Exit;

  Owner.vstTest.GetHitTestInfoAt(X, Y, True, HitInfo);
  if (HitInfo.HitNode = nil) then Exit;

  DR := Owner.vstTest.GetDisplayRect(HitInfo.HitNode, -1, False, False);
  FSettingsPressed := PtInRect(SettingsRect(DR), Point(X, Y));

  Owner.vstTest.RepaintNode(HitInfo.HitNode);
end;

procedure TControlEvents.MouseEnter(sender: IInterface);
begin

end;

procedure TControlEvents.MouseLeave(sender: IInterface);
begin

end;

procedure TControlEvents.MouseMove(sender: IInterface; Shift: TShiftState;
  X, Y: Integer);
begin
  if Supports(Sender, IVirtualTree) then
    Owner.vstTest.Invalidate;
end;

procedure TControlEvents.MouseUp(sender: IInterface; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  HitInfo: THitInfo;
begin
  if not Supports(sender, IVirtualTree) then Exit;

  if (Button <> mbLeft) then Exit;

  Owner.vstTest.GetHitTestInfoAt(X, Y, True, HitInfo);

  if HitInfo.HitNode = nil then Exit;

  if FSettingsPressed then
  begin
    FSettingsPressed := False;
    Owner.vstTest.RepaintNode(HitInfo.HitNode);

    Owner.plPages.ActivePage := Owner.plPages.Pages[1];
  end;
end;

procedure TControlEvents.NodeChanged(Sender: IInterface;
  Node: PVirtualNode);
begin

end;

procedure TControlEvents.NodeFocusChanged(Sender: IInterface;
  Node: PVirtualNode; Column: TColumnIndex);
begin

end;

procedure TControlEvents.NodeFocusChanging(Sender: IInterface; OldNode,
  NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
  var Allowed: BOOL);
begin

end;

procedure TControlEvents.NodeHotChange(Sender: IInterface; OldNode,
  NewNode: PVirtualNode);
begin

end;

procedure TControlEvents.Paint(sender: IInterface);
var
  r: TRect;
  S: IString;
begin
  if Supports(sender, IPaintBox) then
  with Owner, pbTestPaint, Canvas do
  begin
    r := ClientRect;
    Brush.Color := clBtnFace;
    FillRect(r);

    S := GetIString('skin://graph,' + IntToStr(GR_DEF_AVATAR));
    r.Right := r.Left + 48;

    StretchDraw(R, S, smZoom);

    R := ClipRect;
    Inc(r.Left, 50);

    S := GetIString('TEST DRAWING');
    Canvas.Font.Size := 32;
    Canvas.Font.Style := [fsBold];
    Canvas.Font.Color := RandomRange(clScrollBar, clMedGray);

    DrawTextW(Handle, S.pString, S.Length, R, DT_SINGLELINE or DT_VCENTER or DT_END_ELLIPSIS)
  end; 
end;

procedure TControlEvents.PaintBackground(Sender: IInterface;
  TargetCanvas: ICanvas; R: TRect; var Handled: BOOL);
begin

end;

procedure TControlEvents.PaintText(Sender: IInterface;
  TargetCanvas: ICanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
begin

end;

procedure TControlEvents.PropertyChanged(sender: IInterface;
  component: IComponent);
begin
  Owner.btApply.Enabled := Owner.frm.Listener.Changed;
end;

function TControlEvents.SettingsRect(CellRect: TRect): TRect;
begin
  Result := CellRect;

  Dec(Result.Right, 8);
  Inc(Result.Top, 9);
  Dec(Result.Bottom, 10);

  Result.Left  := Result.Right - 69;
end;

procedure TControlEvents.SkinChanged(NewSkinName: IString);
begin
  Owner.UpdateGraphics;
end;

procedure TControlEvents.ToolBarAdnvancedCustomDraw(sender: IToolBar;
  const ARect: TRect; Stage: TCustomDrawStage; var DefaultDraw: BOOL);
begin

end;

procedure TControlEvents.ToolBarCustomDraw(sender: IToolBar;
  const ARect: TRect; var DefaultDraw: BOOL);
begin

end;

procedure TControlEvents.ToolBarCustomDrawButton(sender: IToolBar;
  Button: IToolButton; State: TCustomDrawState; var DefaultDraw: BOOL);
begin

end;

procedure TControlEvents.UpDownClick(sender: IInterface;
  Button: TUDBtnType);
begin

end;

{ TCallBack }

procedure TCallBack.SetEvent(Control: IComponent);
begin
  Control.Events := Event;
end;

end.
