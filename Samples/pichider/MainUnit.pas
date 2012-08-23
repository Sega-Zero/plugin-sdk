unit MainUnit;

interface

uses
  u_plugin_info, u_plugin_msg, u_common, u_BasePlugin;

const
  PLUGIN_VER_MAJOR = 1;
  PLUGIN_VER_MINOR = 0;
  PLUGIN_NAME      : WideString = 'Picture hider';
  PLUGIN_AUTHOR    : WideString = 'Sega-Zero';
  PLUGIN_DESC      : WideString = 'Adds menuitem for picture hiding';

type
  TQipPlugin = class(TBaseQipPlugin)
  public
    procedure GetPluginInformation(var VersionMajor: Word; var VersionMinor: Word;
                                   var PluginName: PWideChar; var Creator: PWideChar;
                                   var Description: PWideChar; var Hint: PWideChar); override;
    procedure AddMenuItems(const SelectedStr: WideString;
      const SelectedURL: WideString; AddingToPicture: Boolean;
      var Items: TMenuItemsArray); override;
    procedure MenuItemClicked(const SelectedStr: WideString;
      const ItemID: Integer; const ItemData: Integer;
      const PictureID: Integer = 0); override;
  end;

implementation
             
procedure TQipPlugin.AddMenuItems(const SelectedStr,
  SelectedURL: WideString; AddingToPicture: Boolean;
  var Items: TMenuItemsArray);
begin
  inherited;
  if AddingToPicture then
  begin
    SetLength(Items, 1);
    Items[0].ItemID      := 1;
    Items[0].ItemData    := 0;
    Items[0].MenuCaption := 'Clear picture';
    Items[0].Enabled     := True;
  end;
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
  Hint         := PWideChar(PLUGIN_NAME);
  Description  := PWideChar(PLUGIN_DESC);
end;

procedure TQipPlugin.MenuItemClicked(const SelectedStr: WideString;
  const ItemID, ItemData, PictureID: Integer);
var
  AccName, Foo: WideString;
  PH, Subs: Integer;
begin
  GetActiveTab(AccName, PH, Subs, True);

  if (AccName = '') or (PH = 0) then
    GetActiveChatTab(AccName, Foo, Foo, PH);
  ControlMedia(AccName, PH, PictureID, PVC_DROP_CLEAR);
end;

end.