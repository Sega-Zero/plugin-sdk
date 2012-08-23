unit u_gui_graphics;

interface
uses
  Windows, Types, u_gui_const, u_string, u_gui_intf;

type
  TColor = u_gui_const.TColor;

var
  SCREEN_PPI : DWORD = 96; //screen pixels per inch

const
  SCREEN_FONT_NAME : WideString = 'Tahoma'; //default font name
  SCREEN_FONT_SIZE = 8;  //default font size
  SCREEN_ICON      = 16; //small icon
  SCREEN_ICON32    = 32; //big icon

  CL_PADDING_X     = 5; //contact list X padding
  CL_PADDING_Y     = 1; //contact list Y padding
  CL_TEXT_PADDING  = 4; //text padding


const
  SCHEMA_SKIN           : WideString = 'skin:';      //skin://graph,#1,ico
  SCHEMA_SKIN_FILE      : WideString = 'skin-file:'; //загрузка вне очереди (синхронная)

  DEFAULT_SKIN_RESOURCE : WideString = 'skin://graph,%d';
  ICQ_SKIN_RESOURCE     : WideString = 'skin://icq_pics,%d';
  MRA_SKIN_RESOURCE     : WideString = 'skin://mra_pics,%d,ico';
  IRC_SKIN_RESOURCE     : WideString = 'skin://irc_pics,%d,ico';
  JAB_SKIN_RESOURCE     : WideString = 'skin://jabber_pics,%d,#14';
  SOC_SKIN_RESOURCE     : WideString = 'skin://social_pics,%d,#14';

const
  clSystemColor = $FF000000;

  clScrollBar = TColor(clSystemColor or COLOR_SCROLLBAR);
  clBackground = TColor(clSystemColor or COLOR_BACKGROUND);
  clActiveCaption = TColor(clSystemColor or COLOR_ACTIVECAPTION);
  clInactiveCaption = TColor(clSystemColor or COLOR_INACTIVECAPTION);
  clMenu = TColor(clSystemColor or COLOR_MENU);
  clWindow = TColor(clSystemColor or COLOR_WINDOW);
  clWindowFrame = TColor(clSystemColor or COLOR_WINDOWFRAME);
  clMenuText = TColor(clSystemColor or COLOR_MENUTEXT);
  clWindowText = TColor(clSystemColor or COLOR_WINDOWTEXT);
  clCaptionText = TColor(clSystemColor or COLOR_CAPTIONTEXT);
  clActiveBorder = TColor(clSystemColor or COLOR_ACTIVEBORDER);
  clInactiveBorder = TColor(clSystemColor or COLOR_INACTIVEBORDER);
  clAppWorkSpace = TColor(clSystemColor or COLOR_APPWORKSPACE);
  clHighlight = TColor(clSystemColor or COLOR_HIGHLIGHT);
  clHighlightText = TColor(clSystemColor or COLOR_HIGHLIGHTTEXT);
  clBtnFace = TColor(clSystemColor or COLOR_BTNFACE);
  clBtnShadow = TColor(clSystemColor or COLOR_BTNSHADOW);
  clGrayText = TColor(clSystemColor or COLOR_GRAYTEXT);
  clBtnText = TColor(clSystemColor or COLOR_BTNTEXT);
  clInactiveCaptionText = TColor(clSystemColor or COLOR_INACTIVECAPTIONTEXT);
  clBtnHighlight = TColor(clSystemColor or COLOR_BTNHIGHLIGHT);
  cl3DDkShadow = TColor(clSystemColor or COLOR_3DDKSHADOW);
  cl3DLight = TColor(clSystemColor or COLOR_3DLIGHT);
  clInfoText = TColor(clSystemColor or COLOR_INFOTEXT);
  clInfoBk = TColor(clSystemColor or COLOR_INFOBK);
  clHotLight = TColor(clSystemColor or COLOR_HOTLIGHT);
  clGradientActiveCaption = TColor(clSystemColor or COLOR_GRADIENTACTIVECAPTION);
  clGradientInactiveCaption = TColor(clSystemColor or COLOR_GRADIENTINACTIVECAPTION);
  clMenuHighlight = TColor(clSystemColor or COLOR_MENUHILIGHT);
  clMenuBar = TColor(clSystemColor or COLOR_MENUBAR);

  clBlack = TColor($000000);
  clMaroon = TColor($000080);
  clGreen = TColor($008000);
  clOlive = TColor($008080);
  clNavy = TColor($800000);
  clPurple = TColor($800080);
  clTeal = TColor($808000);
  clGray = TColor($808080);
  clSilver = TColor($C0C0C0);
  clRed = TColor($0000FF);
  clLime = TColor($00FF00);
  clYellow = TColor($00FFFF);
  clBlue = TColor($FF0000);
  clFuchsia = TColor($FF00FF);
  clAqua = TColor($FFFF00);
  clLtGray = TColor($C0C0C0);
  clDkGray = TColor($808080);
  clWhite = TColor($FFFFFF);
  StandardColorsCount = 16;

  clMoneyGreen = TColor($C0DCC0);
  clSkyBlue = TColor($F0CAA6);
  clCream = TColor($F0FBFF);
  clMedGray = TColor($A4A0A0);
  ExtendedColorsCount = 4;

  clNone = TColor($1FFFFFFF);
  clDefault = TColor($20000000);

function TextWidth(const Handle: HDC; const Text: WideString): Integer;
function TextHeight(const Handle: HDC; const Text: WideString): Integer;

function ImageURIFromID2(ResID: Integer): IString;
function ImageURIFromID(ResID: Integer): WideString;

function CreateICanvas(GUI: IQIPCoreGUI): ICanvas;

implementation

uses SysUtils;

function TextWidth(const Handle: HDC; const Text: WideString): Integer;
var s: TSize;
begin
  GetTextExtentPoint32W(Handle, PWideChar(Text), Length(Text), s);
  Result := s.cx;
end;

function TextHeight(const Handle: HDC; const Text: WideString): Integer;
var s: TSize;
begin
  GetTextExtentPoint32W(Handle, PWideChar(Text), Length(Text), s);
  Result := s.cy;
end;

function ImageURIFromID(ResID: Integer): WideString;
begin
  Result := WideFormat(DEFAULT_SKIN_RESOURCE, [ResID]);
end;

function ImageURIFromID2(ResID: Integer): IString;
begin
  Result := GetIString(ImageURIFromID(ResID));
end;

function CreateICanvas(GUI: IQIPCoreGUI): ICanvas;
begin
  Result := nil;
  GUI.CreateObject(IID_ICanvas, Result, nil);
end;

function ReadScreenPPI(): Integer;
var
  DC: HDC;
  i, dpi, E: Integer;
  s: String;
const
  pname = '/dpi=';
begin
  DC := GetDC(0);
  Result := GetDeviceCaps(DC, LOGPIXELSY);
  ReleaseDC(0, DC);
  for i := 1 to ParamCount do
  begin
    s := ParamStr(i);
    if Pos(pname, s) = 1 then
    begin
      s := Copy(s, Length(pname) + 1, Length(s) - Length(pname));
      Val(s, dpi, E);
      if (E = 0) and (dpi >= 96 div 2) and (dpi <= 96 * 10) then
      begin
        Result := dpi;
        Exit;
      end;
    end;
  end;
end;

initialization
  SCREEN_PPI := ReadScreenPPI();
end.
