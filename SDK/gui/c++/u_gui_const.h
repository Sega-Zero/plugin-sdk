namespace qipns {

typedef BYTE Byte;
typedef WORD Word;
typedef short Smallint;
typedef short SmallInt;
typedef int Longint;
typedef int LongInt;
typedef wchar_t WideChar;
typedef void* TObject;
typedef void* Pointer;
typedef int NaturalNumber;
typedef GUID TGUID;
typedef unsigned char Boolean;
typedef RECT TRect;
typedef TRect* PRect;

typedef POINT TPoint;
typedef TPoint* PPoint;
typedef HFONT HFont;
typedef HBRUSH HBrush;
typedef HPEN HPen;
typedef SIZE TSize;
typedef HWND HWnd;
typedef DWORD TColor;
typedef short TCursor;
typedef DWORD TBevelWidth;
typedef DWORD TBorderWidth;
typedef WORD TTabOrder;
typedef DWORD TModalResult;
typedef BYTE TFontCharset;
typedef int TCopyMode;
typedef int TColumnIndex;
typedef DWORD TColumnPosition;
typedef BYTE TBalloonHintTimeOut;
typedef DWORD HTHEME;
typedef void* PVirtualNode;

enum TAccessLevel {
  alOwner,
  alLimited
};

enum TAlign {
  alNone,
  alTop,
  alBottom,
  alLeft,
  alRight,
  alClient,
  alCustom
};

enum TAnchorKind {
  akLeft,
  akTop,
  akRight,
  akBottom
};

enum TWindowState {
  wsNormal,
  wsMinimized,
  wsMaximized
};

enum TFontStyle {
  fsBold,
  fsItalic,
  fsUnderline,
  fsStrikeOut
};

enum TFontPitch {
  fpDefault,
  fpVariable,
  fpFixed
};

enum TBevelCut {
  bvNone,
  bvLowered,
  bvRaised,
  bvSpace
};

enum TBevelEdge {
  beLeft,
  beTop,
  beRight,
  beBottom
};

enum TBevelKind {
  bkNone,
  bkTile,
  bkSoft,
  bkFlat
};

enum TBrushStyle {
  bsSolid,
  bsClear,
  bsHorizontal,
  bsVertical,
  bsFDiagonal,
  bsBDiagonal,
  bsCross,
  bsDiagCross
};

enum TPenStyle {
  psSolid,
  psDash,
  psDot,
  psDashDot,
  psDashDotDot,
  psClear,
  psInsideFrame
};

enum TPenMode {
  pmBlack,
  pmWhite,
  pmNop,
  pmNot,
  pmCopy,
  pmNotCopy,
  pmMergePenNot,
  pmMaskPenNot,
  pmMergeNotPen,
  pmMaskNotPen,
  pmMerge,
  pmNotMerge,
  pmMask,
  pmNotMask,
  pmXor,
  pmNotXor
};

enum TFillStyle {
  fsSurface,
  fsBorder
};

enum TFillMode {
  fmAlternate,
  fmWinding
};

enum TCanvasStates {
  csHandleValid,
  csFontValid,
  csPenValid,
  csBrushValid
};

enum TCanvasOrientation {
  coLeftToRight,
  coRightToLeft
};

enum TUpDownDirection {
  updNone,
  updUp,
  updDown
};

enum TMouseButton {
  mbLeft,
  mbRight,
  mbMiddle
};

enum TCloseAction {
  caNone,
  caHide,
  caFree,
  caMinimize
};

enum TUDBtnType {
  btNext,
  btPrev
};

enum TCustomDrawStage {
  cdPrePaint,
  cdPostPaint,
  cdPreErase,
  cdPostErase
};

enum TFormStyle {
  fsNormal,
  fsMDIChild,
  fsMDIForm,
  fsStayOnTop
};

enum TBorderIcon {
  biSystemMenu,
  biMinimize,
  biMaximize,
  biHelp
};

enum TPosition {
  poDesigned,
  poDefault,
  poDefaultPosOnly,
  poDefaultSizeOnly,
  poScreenCenter,
  poDesktopCenter,
  poMainFormCenter,
  poOwnerFormCenter
};

enum TFormBorderStyle {
  fbsNone,
  fbsSingle,
  fbsSizeable,
  fbsDialog,
  fbsToolWindow,
  fbsSizeToolWin
};

enum TAlignment {
  taLeftJustify,
  taRightJustify,
  taCenter
};

enum TTextLayout {
  tlTop,
  tlCenter,
  tlBottom
};

enum TStaticBorderStyle {
  sbsNone,
  sbsSingle,
  sbsSunken
};

enum TProgressBarOrientation {
  pbHorizontal,
  pbVertical
};

enum TTrackBarOrientation {
  trHorizontal,
  trVertical
};

enum TTickMark {
  tmBottomRight,
  tmTopLeft,
  tmBoth
};

enum TTickStyle {
  tsNone,
  tsAuto,
  tsManual
};

enum TToolButtonStyle {
  tbsButton,
  tbsCheck,
  tbsDropDown,
  tbsSeparator,
  tbsDivider
};

enum TEdgeStyle {
  esNone,
  esRaised,
  esLowered
};

enum TEdgeBorder {
  ebLeft,
  ebTop,
  ebRight,
  ebBottom
};

enum TUDAlignButton {
  udLeft,
  udRight
};

enum TUDOrientation {
  udHorizontal,
  udVertical
};

enum TButtonLayout {
  blGlyphLeft,
  blGlyphRight,
  blGlyphTop,
  blGlyphBottom
};

enum TCheckBoxState {
  cbUnchecked,
  cbChecked,
  cbGrayed
};

enum TEditCharCase {
  ecNormal,
  ecUpperCase,
  ecLowerCase
};

enum TScrollStyle {
  ssNone,
  ssHorizontal,
  ssVertical,
  ssBoth
};

enum TSearchType {
  stWholeWord,
  stMatchCase
};

enum TListBoxStyle {
  lbStandard,
  lbOwnerDrawFixed,
  lbOwnerDrawVariable,
  lbVirtual,
  lbVirtualOwnerDraw
};

enum TComboBoxStyle {
  csDropDown,
  csSimple,
  csDropDownList,
  csOwnerDrawFixed,
  csOwnerDrawVariable
};

enum TMenuBreak {
  mbNone,
  mbBreak,
  mbBarBreak
};

enum TPopupAlignment {
  paLeft,
  paRight,
  paCenter
};

enum TTrackButton {
  tbRightButton,
  tbLeftButton
};

enum TBevelShape {
  bsBox,
  bsFrame,
  bsTopLine,
  bsBottomLine,
  bsLeftLine,
  bsRightLine,
  bsSpacer
};

enum TBevelStyle {
  bsLowered,
  bsRaised
};

enum TStatusPanelBevel {
  pbNone,
  pbLowered,
  pbRaised
};

enum TStatusPanelStyle {
  psText,
  psOwnerDraw
};

enum TResizeStyle {
  rsNone,
  rsLine,
  rsUpdate,
  rsPattern
};

enum TNumberingStyle {
  nsNone,
  nsBullet
};

enum TConsistentAttribute {
  caBold,
  caColor,
  caFace,
  caItalic,
  caSize,
  caStrikeOut,
  caUnderline,
  caProtected
};

enum THitTest {
  htAbove,
  htBelow,
  htNowhere,
  htOnItem,
  htOnButton,
  htOnIcon,
  htOnIndent,
  htOnLabel,
  htOnRight,
  htOnStateIcon,
  htToLeft,
  htToRight
};

enum TTabStyle {
  tsTabs,
  tsButtons,
  tsFlatButtons
};

enum TTabPosition {
  tpTop,
  tpBottom,
  tpLeft,
  tpRight
};

enum TScaleMetod {
  smDefault,
  sm0x0,
  smCenter,
  smStretch,
  smZoomIn,
  smZoom
};

enum TMenuItemAutoFlag {
  imaAutomatic,
  imaManual,
  imaParent
};

enum TItemEraseAction {
  eaColor,
  eaDefault,
  eaNone
};

enum TVirtualNodeState {
  vsInitialized,
  vsChecking,
  vsCutOrCopy,
  vsDisabled,
  vsDeleting,
  vsExpanded,
  vsHasChildren,
  vsVisible,
  vsSelected,
  vsInitialUserData,
  vsAllChildrenHidden,
  vsClearing,
  vsMultiline,
  vsHeightMeasured,
  vsToggling
};

enum TCheckState {
  csUncheckedNormal,
  csUncheckedPressed,
  csCheckedNormal,
  csCheckedPressed,
  csMixedNormal,
  csMixedPressed
};

enum TCheckType {
  ctNone,
  ctTriStateCheckBox,
  ctCheckBox,
  ctRadioButton,
  ctButton
};

enum THitPosition {
  hiAbove,
  hiBelow,
  hiNowhere,
  hiOnItem,
  hiOnItemButton,
  hiOnItemCheckbox,
  hiOnItemIndent,
  hiOnItemLabel,
  hiOnItemLeft,
  hiOnItemRight,
  hiOnNormalIcon,
  hiOnStateIcon,
  hiToLeft,
  hiToRight
};

enum TVTNodeAttachMode {
  amNoWhere,
  amInsertBefore,
  amInsertAfter,
  amAddChildFirst,
  amAddChildLast
};

enum TVSTTextType {
  ttNormal,
  ttStatic
};

enum TSortDirection {
  sdAscending,
  sdDescending
};

enum TVTStringOption {
  toSaveCaptions,
  toShowStaticText,
  toAutoAcceptEditChange
};

enum TVTAnimationOption {
  toAnimatedToggle
};

enum TVTAutoOption {
  toAutoDropExpand,
  toAutoExpand,
  toAutoScroll,
  toAutoScrollOnExpand,
  toAutoSort,
  toAutoSpanColumns,
  toAutoTristateTracking,
  toAutoHideButtons,
  toAutoDeleteMovedNodes,
  toDisableAutoscrollOnFocus,
  toAutoChangeScale,
  toAutoFreeOnCollapse,
  toDisableAutoscrollOnEdit,
  toAutoBidiColumnOrdering
};

enum TVTMiscOption {
  toAcceptOLEDrop,
  toCheckSupport,
  toEditable,
  toFullRepaintOnResize,
  toGridExtensions,
  toInitOnSave,
  toReportMode,
  toToggleOnDblClick,
  toWheelPanning,
  toReadOnly,
  toVariableNodeHeight,
  toFullRowDrag
};

enum TVTPaintOption {
  toHideFocusRect,
  toHideSelection,
  toHotTrack,
  toPopupMode,
  toShowBackground,
  toShowButtons,
  toShowDropmark,
  toShowHorzGridLines,
  toShowRoot,
  toShowTreeLines,
  toShowVertGridLines,
  toThemeAware,
  toUseBlendedImages,
  toGhostedIfUnfocused,
  toFullVertGridLines,
  toAlwaysHideSelection,
  toUseBlendedSelection,
  toStaticBackground
};

enum TVTSelectionOption {
  toDisableDrawSelection,
  toExtendedFocus,
  toFullRowSelect,
  toLevelSelectConstraint,
  toMiddleClickSelect,
  toMultiSelect,
  toRightClickSelect,
  toSiblingSelectConstraint,
  toCenterScrollIntoView,
  toSimpleDrawSelection
};

enum TVTHeaderOption {
  hoAutoResize,
  hoColumnResize,
  hoDblClickResize,
  hoDrag,
  hoHotTrack,
  hoOwnerDraw,
  hoRestrictDrag,
  hoShowHint,
  hoShowImages,
  hoShowSortGlyphs,
  hoVisible,
  hoAutoSpring
};

enum THeaderState {
  hsAutoSizing,
  hsDragging,
  hsDragPending,
  hsLoading,
  hsTracking,
  hsTrackPending
};

enum TVTHeaderStyle {
  hsThickButtons,
  hsFlatButtons,
  hsPlates,
  hsXPStyle
};

enum TVTColumnOption {
  coAllowClick,
  coDraggable,
  coEnabled,
  coParentBidiMode,
  coParentColor,
  coResizable,
  coShowDropMark,
  coVisible,
  coAutoSpring,
  coFixed
};

enum TVirtualTreeColumnStyle {
  vsText,
  vsOwnerDraw
};

enum TVirtualNodeInitState {
  ivsDisabled,
  ivsExpanded,
  ivsHasChildren,
  ivsMultiline,
  ivsSelected
};

enum TTooltipLineBreakStyle {
  hlbDefault,
  hlbForceSingleLine,
  hlbForceMultiLine
};

enum TVTDropMarkMode {
  dmmNone,
  dmmLeft,
  dmmRight
};

enum TBalloonHintIcon {
  bitNone,
  bitInfo,
  bitWarning,
  bitError,
  bitCustom
};

enum TBorderDrawStyle {
  bdsNone,
  bdsFlat,
  bdsOutlined
};

enum TThemedElement {
  teButton,
  teClock,
  teComboBox,
  teEdit,
  teExplorerBar,
  teHeader,
  teListView,
  teMenu,
  tePage,
  teProgress,
  teRebar,
  teScrollBar,
  teSpin,
  teStartPanel,
  teStatus,
  teTab,
  teTaskBand,
  teTaskBar,
  teToolBar,
  teToolTip,
  teTrackBar,
  teTrayNotify,
  teTreeview,
  teWindow
};

enum TThemedButton {
  tbButtonDontCare,
  tbButtonRoot,
  tbPushButtonNormal,
  tbPushButtonHot,
  tbPushButtonPressed,
  tbPushButtonDisabled,
  tbPushButtonDefaulted,
  tbRadioButtonUncheckedNormal,
  tbRadioButtonUncheckedHot,
  tbRadioButtonUncheckedPressed,
  tbRadioButtonUncheckedDisabled,
  tbRadioButtonCheckedNormal,
  tbRadioButtonCheckedHot,
  tbRadioButtonCheckedPressed,
  tbRadioButtonCheckedDisabled,
  tbCheckBoxUncheckedNormal,
  tbCheckBoxUncheckedHot,
  tbCheckBoxUncheckedPressed,
  tbCheckBoxUncheckedDisabled,
  tbCheckBoxCheckedNormal,
  tbCheckBoxCheckedHot,
  tbCheckBoxCheckedPressed,
  tbCheckBoxCheckedDisabled,
  tbCheckBoxMixedNormal,
  tbCheckBoxMixedHot,
  tbCheckBoxMixedPressed,
  tbCheckBoxMixedDisabled,
  tbGroupBoxNormal,
  tbGroupBoxDisabled,
  tbUserButton
};

enum TThemedClock {
  tcClockDontCare,
  tcClockRoot,
  tcTimeNormal
};

enum TThemedComboBox {
  tcComboBoxDontCare,
  tcComboBoxRoot,
  tcDropDownButtonNormal,
  tcDropDownButtonHot,
  tcDropDownButtonPressed,
  tcDropDownButtonDisabled
};

enum TThemedEdit {
  teEditDontCare,
  teEditRoot,
  teEditTextNormal,
  teEditTextHot,
  teEditTextSelected,
  teEditTextDisabled,
  teEditTextFocused,
  teEditTextReadOnly,
  teEditTextAssist,
  teEditCaret
};

enum TThemedExplorerBar {
  tebExplorerBarDontCare,
  tebExplorerBarRoot,
  tebHeaderBackgroundNormal,
  tebHeaderBackgroundHot,
  tebHeaderBackgroundPressed,
  tebHeaderCloseNormal,
  tebHeaderCloseHot,
  tebHeaderClosePressed,
  tebHeaderPinNormal,
  tebHeaderPinHot,
  tebHeaderPinPressed,
  tebHeaderPinSelectedNormal,
  tebHeaderPinSelectedHot,
  tebHeaderPinSelectedPressed,
  tebIEBarMenuNormal,
  tebIEBarMenuHot,
  tebIEBarMenuPressed,
  tebNormalGroupBackground,
  tebNormalGroupCollapseNormal,
  tebNormalGroupCollapseHot,
  tebNormalGroupCollapsePressed,
  tebNormalGroupExpandNormal,
  tebNormalGroupExpandHot,
  tebNormalGroupExpandPressed,
  tebNormalGroupHead,
  tebSpecialGroupBackground,
  tebSpecialGroupCollapseSpecial,
  tebSpecialGroupCollapseHot,
  tebSpecialGroupCollapsePressed,
  tebSpecialGroupExpandSpecial,
  tebSpecialGroupExpandHot,
  tebSpecialGroupExpandPressed,
  tebSpecialGroupHead
};

enum TThemedHeader {
  thHeaderDontCare,
  thHeaderRoot,
  thHeaderItemNormal,
  thHeaderItemHot,
  thHeaderItemPressed,
  thHeaderItemLeftNormal,
  thHeaderItemLeftHot,
  thHeaderItemLeftPressed,
  thHeaderItemRightNormal,
  thHeaderItemRightHot,
  thHeaderItemRightPressed,
  thHeaderSortArrowSortedUp,
  thHeaderSortArrowSortedDown
};

enum TThemedListview {
  tlListviewDontCare,
  tlListviewRoot,
  tlListItemNormal,
  tlListItemHot,
  tlListItemSelected,
  tlListItemDisabled,
  tlListItemSelectedNotFocus,
  tlListGroup,
  tlListDetail,
  tlListSortDetail,
  tlEmptyText
};

enum TThemedMenu {
  tmMenuDontCare,
  tmMenuRoot,
  tmMenuItemNormal,
  tmMenuItemSelected,
  tmMenuItemDemoted,
  tmMenuDropDown,
  tmMenuBarItem,
  tmMenuBarDropDown,
  tmChevron,
  tmSeparator
};

enum TThemedPage {
  tpPageDontCare,
  tpPageRoot,
  tpUpNormal,
  tpUpHot,
  tpUpPressed,
  tpUpDisabled,
  tpDownNormal,
  tpDownHot,
  tpDownPressed,
  tpDownDisabled,
  tpUpHorzNormal,
  tpUpHorzHot,
  tpUpHorzPressed,
  tpUpHorzDisabled,
  tpDownHorzNormal,
  tpDownHorzHot,
  tpDownHorzPressed,
  tpDownHorzDisabled
};

enum TThemedProgress {
  tpProgressDontCare,
  tpProgressRoot,
  tpBar,
  tpBarVert,
  tpChunk,
  tpChunkVert
};

enum TThemedRebar {
  trRebarDontCare,
  trRebarRoot,
  trGripper,
  trGripperVert,
  trBandNormal,
  trBandHot,
  trBandPressed,
  trBandDisabled,
  trBandChecked,
  trBandHotChecked,
  trChevronNormal,
  trChevronHot,
  trChevronPressed,
  trChevronDisabled,
  trChevronVertNormal,
  trChevronVertHot,
  trChevronVertPressed,
  trChevronVertDisabled
};

enum TThemedScrollBar {
  tsScrollBarDontCare,
  tsScrollBarRoot,
  tsArrowBtnUpNormal,
  tsArrowBtnUpHot,
  tsArrowBtnUpPressed,
  tsArrowBtnUpDisabled,
  tsArrowBtnDownNormal,
  tsArrowBtnDownHot,
  tsArrowBtnDownPressed,
  tsArrowBtnDownDisabled,
  tsArrowBtnLeftNormal,
  tsArrowBtnLeftHot,
  tsArrowBtnLeftPressed,
  tsArrowBtnLeftDisabled,
  tsArrowBtnRightNormal,
  tsArrowBtnRightHot,
  tsArrowBtnRightPressed,
  tsArrowBtnRightDisabled,
  tsThumbBtnHorzNormal,
  tsThumbBtnHorzHot,
  tsThumbBtnHorzPressed,
  tsThumbBtnHorzDisabled,
  tsThumbBtnVertNormal,
  tsThumbBtnVertHot,
  tsThumbBtnVertPressed,
  tsThumbBtnVertDisabled,
  tsLowerTrackHorzNormal,
  tsLowerTrackHorzHot,
  tsLowerTrackHorzPressed,
  tsLowerTrackHorzDisabled,
  tsUpperTrackHorzNormal,
  tsUpperTrackHorzHot,
  tsUpperTrackHorzPressed,
  tsUpperTrackHorzDisabled,
  tsLowerTrackVertNormal,
  tsLowerTrackVertHot,
  tsLowerTrackVertPressed,
  tsLowerTrackVertDisabled,
  tsUpperTrackVertNormal,
  tsUpperTrackVertHot,
  tsUpperTrackVertPressed,
  tsUpperTrackVertDisabled,
  tsGripperHorzNormal,
  tsGripperHorzHot,
  tsGripperHorzPressed,
  tsGripperHorzDisabled,
  tsGripperVertNormal,
  tsGripperVertHot,
  tsGripperVertPressed,
  tsGripperVertDisabled,
  tsSizeBoxRightAlign,
  tsSizeBoxLeftAlign
};

enum TThemedSpin {
  tsSpinDontCare,
  tsSpinRoot,
  tsUpNormal,
  tsUpHot,
  tsUpPressed,
  tsUpDisabled,
  tsDownNormal,
  tsDownHot,
  tsDownPressed,
  tsDownDisabled,
  tsUpHorzNormal,
  tsUpHorzHot,
  tsUpHorzPressed,
  tsUpHorzDisabled,
  tsDownHorzNormal,
  tsDownHorzHot,
  tsDownHorzPressed,
  tsDownHorzDisabled
};

enum TThemedStartPanel {
  tspStartPanelDontCare,
  tspStartPanelRoot,
  tspUserPane,
  tspMorePrograms,
  tspMoreProgramsArrowNormal,
  tspMoreProgramsArrowHot,
  tspMoreProgramsArrowPressed,
  tspProgList,
  tspProgListSeparator,
  tspPlacesList,
  tspPlacesListSeparator,
  tspLogOff,
  tspLogOffButtonsNormal,
  tspLogOffButtonsHot,
  tspLogOffButtonsPressed,
  tspUserPicture,
  tspPreview
};

enum TThemedStatus {
  tsStatusDontCare,
  tsStatusRoot,
  tsPane,
  tsGripperPane,
  tsGripper
};

enum TThemedTab {
  ttTabDontCare,
  ttTabRoot,
  ttTabItemNormal,
  ttTabItemHot,
  ttTabItemSelected,
  ttTabItemDisabled,
  ttTabItemFocused,
  ttTabItemLeftEdgeNormal,
  ttTabItemLeftEdgeHot,
  ttTabItemLeftEdgeSelected,
  ttTabItemLeftEdgeDisabled,
  ttTabItemLeftEdgeFocused,
  ttTabItemRightEdgeNormal,
  ttTabItemRightEdgeHot,
  ttTabItemRightEdgeSelected,
  ttTabItemRightEdgeDisabled,
  ttTabItemRightEdgeFocused,
  ttTabItemBothEdgeNormal,
  ttTabItemBothEdgeHot,
  ttTabItemBothEdgeSelected,
  ttTabItemBothEdgeDisabled,
  ttTabItemBothEdgeFocused,
  ttTopTabItemNormal,
  ttTopTabItemHot,
  ttTopTabItemSelected,
  ttTopTabItemDisabled,
  ttTopTabItemFocused,
  ttTopTabItemLeftEdgeNormal,
  ttTopTabItemLeftEdgeHot,
  ttTopTabItemLeftEdgeSelected,
  ttTopTabItemLeftEdgeDisabled,
  ttTopTabItemLeftEdgeFocused,
  ttTopTabItemRightEdgeNormal,
  ttTopTabItemRightEdgeHot,
  ttTopTabItemRightEdgeSelected,
  ttTopTabItemRightEdgeDisabled,
  ttTopTabItemRightEdgeFocused,
  ttTopTabItemBothEdgeNormal,
  ttTopTabItemBothEdgeHot,
  ttTopTabItemBothEdgeSelected,
  ttTopTabItemBothEdgeDisabled,
  ttTopTabItemBothEdgeFocused,
  ttPane,
  ttBody
};

enum TThemedTaskBand {
  ttbTaskBandDontCare,
  ttbTaskBandRoot,
  ttbGroupCount,
  ttbFlashButton,
  ttpFlashButtonGroupMenu
};

enum TThemedTaskBar {
  ttTaskBarDontCare,
  ttTaskBarRoot,
  ttbTimeNormal
};

enum TThemedToolBar {
  ttbToolBarDontCare,
  ttbToolBarRoot,
  ttbButtonNormal,
  ttbButtonHot,
  ttbButtonPressed,
  ttbButtonDisabled,
  ttbButtonChecked,
  ttbButtonCheckedHot,
  ttbDropDownButtonNormal,
  ttbDropDownButtonHot,
  ttbDropDownButtonPressed,
  ttbDropDownButtonDisabled,
  ttbDropDownButtonChecked,
  ttbDropDownButtonCheckedHot,
  ttbSplitButtonNormal,
  ttbSplitButtonHot,
  ttbSplitButtonPressed,
  ttbSplitButtonDisabled,
  ttbSplitButtonChecked,
  ttbSplitButtonCheckedHot,
  ttbSplitButtonDropDownNormal,
  ttbSplitButtonDropDownHot,
  ttbSplitButtonDropDownPressed,
  ttbSplitButtonDropDownDisabled,
  ttbSplitButtonDropDownChecked,
  ttbSplitButtonDropDownCheckedHot,
  ttbSeparatorNormal,
  ttbSeparatorHot,
  ttbSeparatorPressed,
  ttbSeparatorDisabled,
  ttbSeparatorChecked,
  ttbSeparatorCheckedHot,
  ttbSeparatorVertNormal,
  ttbSeparatorVertHot,
  ttbSeparatorVertPressed,
  ttbSeparatorVertDisabled,
  ttbSeparatorVertChecked,
  ttbSeparatorVertCheckedHot
};

enum TThemedToolTip {
  tttToolTipDontCare,
  tttToolTipRoot,
  tttStandardNormal,
  tttStandardLink,
  tttStandardTitleNormal,
  tttStandardTitleLink,
  tttBaloonNormal,
  tttBaloonLink,
  tttBaloonTitleNormal,
  tttBaloonTitleLink,
  tttCloseNormal,
  tttCloseHot,
  tttClosePressed
};

enum TThemedTrackBar {
  ttbTrackBarDontCare,
  ttbTrackBarRoot,
  ttbTrack,
  ttbTrackVert,
  ttbThumbNormal,
  ttbThumbHot,
  ttbThumbPressed,
  ttbThumbFocused,
  ttbThumbDisabled,
  ttbThumbBottomNormal,
  ttbThumbBottomHot,
  ttbThumbBottomPressed,
  ttbThumbBottomFocused,
  ttbThumbBottomDisabled,
  ttbThumbTopNormal,
  ttbThumbTopHot,
  ttbThumbTopPressed,
  ttbThumbTopFocused,
  ttbThumbTopDisabled,
  ttbThumbVertNormal,
  ttbThumbVertHot,
  ttbThumbVertPressed,
  ttbThumbVertFocused,
  ttbThumbVertDisabled,
  ttbThumbLeftNormal,
  ttbThumbLeftHot,
  ttbThumbLeftPressed,
  ttbThumbLeftFocused,
  ttbThumbLeftDisabled,
  ttbThumbRightNormal,
  ttbThumbRightHot,
  ttbThumbRightPressed,
  ttbThumbRightFocused,
  ttbThumbRightDisabled,
  ttbThumbTics,
  ttbThumbTicsVert
};

enum TThemedTrayNotify {
  ttnTrayNotifyDontCare,
  ttnTrayNotifyRoot,
  ttnBackground,
  ttnAnimBackground
};

enum TThemedTreeview {
  ttTreeviewDontCare,
  ttTreeviewRoot,
  ttItemNormal,
  ttItemHot,
  ttItemSelected,
  ttItemDisabled,
  ttItemSelectedNotFocus,
  ttGlyphClosed,
  ttGlyphOpened,
  ttBranch
};

enum TThemedWindow {
  twWindowDontCare,
  twWindowRoot,
  twCaptionActive,
  twCaptionInactive,
  twCaptionDisabled,
  twSmallCaptionActive,
  twSmallCaptionInactive,
  twSmallCaptionDisabled,
  twMinCaptionActive,
  twMinCaptionInactive,
  twMinCaptionDisabled,
  twSmallMinCaptionActive,
  twSmallMinCaptionInactive,
  twSmallMinCaptionDisabled,
  twMaxCaptionActive,
  twMaxCaptionInactive,
  twMaxCaptionDisabled,
  twSmallMaxCaptionActive,
  twSmallMaxCaptionInactive,
  twSmallMaxCaptionDisabled,
  twFrameLeftActive,
  twFrameLeftInactive,
  twFrameRightActive,
  twFrameRightInactive,
  twFrameBottomActive,
  twFrameBottomInactive,
  twSmallFrameLeftActive,
  twSmallFrameLeftInactive,
  twSmallFrameRightActive,
  twSmallFrameRightInactive,
  twSmallFrameBottomActive,
  twSmallFrameBottomInactive,
  twSysButtonNormal,
  twSysButtonHot,
  twSysButtonPushed,
  twSysButtonDisabled,
  twMDISysButtonNormal,
  twMDISysButtonHot,
  twMDISysButtonPushed,
  twMDISysButtonDisabled,
  twMinButtonNormal,
  twMinButtonHot,
  twMinButtonPushed,
  twMinButtonDisabled,
  twMDIMinButtonNormal,
  twMDIMinButtonHot,
  twMDIMinButtonPushed,
  twMDIMinButtonDisabled,
  twMaxButtonNormal,
  twMaxButtonHot,
  twMaxButtonPushed,
  twMaxButtonDisabled,
  twCloseButtonNormal,
  twCloseButtonHot,
  twCloseButtonPushed,
  twCloseButtonDisabled,
  twSmallCloseButtonNormal,
  twSmallCloseButtonHot,
  twSmallCloseButtonPushed,
  twSmallCloseButtonDisabled,
  twMDICloseButtonNormal,
  twMDICloseButtonHot,
  twMDICloseButtonPushed,
  twMDICloseButtonDisabled,
  twRestoreButtonNormal,
  twRestoreButtonHot,
  twRestoreButtonPushed,
  twRestoreButtonDisabled,
  twMDIRestoreButtonNormal,
  twMDIRestoreButtonHot,
  twMDIRestoreButtonPushed,
  twMDIRestoreButtonDisabled,
  twHelpButtonNormal,
  twHelpButtonHot,
  twHelpButtonPushed,
  twHelpButtonDisabled,
  twMDIHelpButtonNormal,
  twMDIHelpButtonHot,
  twMDIHelpButtonPushed,
  twMDIHelpButtonDisabled,
  twHorzScrollNormal,
  twHorzScrollHot,
  twHorzScrollPushed,
  twHorzScrollDisabled,
  twHorzThumbNormal,
  twHorzThumbHot,
  twHorzThumbPushed,
  twHorzThumbDisabled,
  twVertScrollNormal,
  twVertScrollHot,
  twVertScrollPushed,
  twVertScrollDisabled,
  twVertThumbNormal,
  twVertThumbHot,
  twVertThumbPushed,
  twVertThumbDisabled,
  twDialog,
  twCaptionSizingTemplate,
  twSmallCaptionSizingTemplate,
  twFrameLeftSizingTemplate,
  twSmallFrameLeftSizingTemplate,
  twFrameRightSizingTemplate,
  twSmallFrameRightSizingTemplate,
  twFrameBottomSizingTemplate,
  twSmallFrameBottomSizingTemplate
};

enum TOFNOption {
  ofnReadonly,
  ofnOverwritePrompt,
  ofnHideReadonly,
  ofnNoChangeDir,
  ofnShowHelp,
  ofnNoValidate,
  ofnAllowMultiselect,
  ofnExtensionDifferent,
  ofnPathMustExist,
  ofnFileMustExist,
  ofnCreatePrompt,
  ofnShareAware,
  ofnNoReadonlyReturn,
  ofnNoTestFileCreate,
  ofnNoNetworkButton,
  ofnNoLongnames,
  ofnExplorer,
  ofnNoDereferenceLinks,
  ofnEnableIncludeNotify,
  ofnEnableSizing,
  ofnDontAddToRecent,
  ofnForceShowHidden
};

enum TBIFOption {
  boBrowseForComputer,
  boBrowseForPrinter,
  boDontGoBelowDomain,
  boReturnOnlyFsDirs,
  boReturnFSAncestors,
  boStatusText,
  boBrowseIncludeFiles,
  boBrowseIncludeURLS,
  boNewDialogStyle,
  boEditBox,
  boShareable,
  boUAHint,
  boNoNewButton,
  boNoTranslateTargets
};

enum TDialogPosition {
  dpCustom,
  dpFormCenter,
  dpFormNear,
  dpScreenCenter
};

enum TDialogStyle {
  dsImage,
  dsButtons,
  dsHelp,
  dsHeader,
  dsInfo,
  dsInput,
  dsInput2,
  dsInput3,
  dsCombo
};

enum TDialogBtnStyle {
  bsYes,
  bsOk,
  bsNo,
  bsCancel,
  bsCheck
};

struct TAlignSet {
  bool alNone  : 1;
  bool alTop   : 1;
  bool alBottom: 1;
  bool alLeft  : 1;
  bool alRight : 1;
  bool alClient: 1;
  bool alCustom: 1;
  TAlignSet() { memset(this, 0, sizeof(*this)); }
  TAlignSet(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TAnchors {
  bool akLeft  : 1;
  bool akTop   : 1;
  bool akRight : 1;
  bool akBottom: 1;
  TAnchors() { memset(this, 0, sizeof(*this)); }
  TAnchors(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TFontStyles {
  bool fsBold     : 1;
  bool fsItalic   : 1;
  bool fsUnderline: 1;
  bool fsStrikeOut: 1;
  TFontStyles() { memset(this, 0, sizeof(*this)); }
  TFontStyles(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TBevelEdges {
  bool beLeft  : 1;
  bool beTop   : 1;
  bool beRight : 1;
  bool beBottom: 1;
  TBevelEdges() { memset(this, 0, sizeof(*this)); }
  TBevelEdges(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TCanvasState {
  bool csHandleValid: 1;
  bool csFontValid  : 1;
  bool csPenValid   : 1;
  bool csBrushValid : 1;
  TCanvasState() { memset(this, 0, sizeof(*this)); }
  TCanvasState(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TShiftState {
  bool ssShift : 1;
  bool ssAlt   : 1;
  bool ssCtrl  : 1;
  bool ssLeft  : 1;
  bool ssRight : 1;
  bool ssMiddle: 1;
  bool ssDouble: 1;
  TShiftState() { memset(this, 0, sizeof(*this)); }
  TShiftState(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

enum TShiftStateEnum {
  ssShift,
  ssAlt,
  ssCtrl,
  ssLeft,
  ssRight,
  ssMiddle,
  ssDouble
};

struct TCustomDrawState {
  bool cdsSelected     : 1;
  bool cdsGrayed       : 1;
  bool cdsDisabled     : 1;
  bool cdsChecked      : 1;
  bool cdsFocused      : 1;
  bool cdsDefault      : 1;
  bool cdsHot          : 1;
  bool cdsMarked       : 1;
  bool cdsIndeterminate: 1;
  TCustomDrawState() { memset(this, 0, sizeof(*this)); }
  TCustomDrawState(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

enum TCustomDrawStateEnum {
  cdsSelected,
  cdsGrayed,
  cdsDisabled,
  cdsChecked,
  cdsFocused,
  cdsDefault,
  cdsHot,
  cdsMarked,
  cdsIndeterminate
};

struct TBorderIcons {
  bool biSystemMenu: 1;
  bool biMinimize  : 1;
  bool biMaximize  : 1;
  bool biHelp      : 1;
  TBorderIcons() { memset(this, 0, sizeof(*this)); }
  TBorderIcons(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TFormState {
  bool fsCreating       : 1;
  bool fsVisible        : 1;
  bool fsShowing        : 1;
  bool fsModal          : 1;
  bool fsCreatedMDIChild: 1;
  bool fsActivated      : 1;
  bool fsRsrvd          : 1;
  TFormState() { memset(this, 0, sizeof(*this)); }
  TFormState(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

enum TFormStateEnum {
  fsCreating,
  fsVisible,
  fsShowing,
  fsModal,
  fsCreatedMDIChild,
  fsActivated,
  fsRsrvd
};

struct TEdgeBorders {
  bool ebLeft  : 1;
  bool ebTop   : 1;
  bool ebRight : 1;
  bool ebBottom: 1;
  TEdgeBorders() { memset(this, 0, sizeof(*this)); }
  TEdgeBorders(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TSearchTypes {
  bool stWholeWord: 1;
  bool stMatchCase: 1;
  TSearchTypes() { memset(this, 0, sizeof(*this)); }
  TSearchTypes(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TConsistentAttributes {
  bool caBold     : 1;
  bool caColor    : 1;
  bool caFace     : 1;
  bool caItalic   : 1;
  bool caSize     : 1;
  bool caStrikeOut: 1;
  bool caUnderline: 1;
  bool caProtected: 1;
  TConsistentAttributes() { memset(this, 0, sizeof(*this)); }
  TConsistentAttributes(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct THitTests {
  bool htAbove      : 1;
  bool htBelow      : 1;
  bool htNowhere    : 1;
  bool htOnItem     : 1;
  bool htOnButton   : 1;
  bool htOnIcon     : 1;
  bool htOnIndent   : 1;
  bool htOnLabel    : 1;
  bool htOnRight    : 1;
  bool htOnStateIcon: 1;
  bool htToLeft     : 1;
  bool htToRight    : 1;
  THitTests() { memset(this, 0, sizeof(*this)); }
  THitTests(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TOwnerDrawState {
  bool odSelected    : 1;
  bool odGrayed      : 1;
  bool odDisabled    : 1;
  bool odChecked     : 1;
  bool odFocused     : 1;
  bool odDefault     : 1;
  bool odHotLight    : 1;
  bool odInactive    : 1;
  bool odNoAccel     : 1;
  bool odNoFocusRect : 1;
  bool odReserved1   : 1;
  bool odReserved2   : 1;
  bool odComboBoxEdit: 1;
  TOwnerDrawState() { memset(this, 0, sizeof(*this)); }
  TOwnerDrawState(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

enum TOwnerDrawStateEnum {
  odSelected,
  odGrayed,
  odDisabled,
  odChecked,
  odFocused,
  odDefault,
  odHotLight,
  odInactive,
  odNoAccel,
  odNoFocusRect,
  odReserved1,
  odReserved2,
  odComboBoxEdit
};

struct TVirtualNodeStates {
  bool vsInitialized      : 1;
  bool vsChecking         : 1;
  bool vsCutOrCopy        : 1;
  bool vsDisabled         : 1;
  bool vsDeleting         : 1;
  bool vsExpanded         : 1;
  bool vsHasChildren      : 1;
  bool vsVisible          : 1;
  bool vsSelected         : 1;
  bool vsInitialUserData  : 1;
  bool vsAllChildrenHidden: 1;
  bool vsClearing         : 1;
  bool vsMultiline        : 1;
  bool vsHeightMeasured   : 1;
  bool vsToggling         : 1;
  TVirtualNodeStates() { memset(this, 0, sizeof(*this)); }
  TVirtualNodeStates(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct THitPositions {
  bool hiAbove         : 1;
  bool hiBelow         : 1;
  bool hiNowhere       : 1;
  bool hiOnItem        : 1;
  bool hiOnItemButton  : 1;
  bool hiOnItemCheckbox: 1;
  bool hiOnItemIndent  : 1;
  bool hiOnItemLabel   : 1;
  bool hiOnItemLeft    : 1;
  bool hiOnItemRight   : 1;
  bool hiOnNormalIcon  : 1;
  bool hiOnStateIcon   : 1;
  bool hiToLeft        : 1;
  bool hiToRight       : 1;
  THitPositions() { memset(this, 0, sizeof(*this)); }
  THitPositions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVirtualTreeStates {
  bool tsCancelHintAnimation       : 1;
  bool tsChangePending             : 1;
  bool tsCheckPropagation          : 1;
  bool tsCollapsing                : 1;
  bool tsToggleFocusedSelection    : 1;
  bool tsClearPending              : 1;
  bool tsClipboardFlushing         : 1;
  bool tsCopyPending               : 1;
  bool tsCutPending                : 1;
  bool tsDrawSelPending            : 1;
  bool tsDrawSelecting             : 1;
  bool tsEditing                   : 1;
  bool tsEditPending               : 1;
  bool tsExpanding                 : 1;
  bool tsHint                      : 1;
  bool tsInAnimation               : 1;
  bool tsIncrementalSearching      : 1;
  bool tsIncrementalSearchPending  : 1;
  bool tsIterating                 : 1;
  bool tsKeyCheckPending           : 1;
  bool tsLeftButtonDown            : 1;
  bool tsLeftDblClick              : 1;
  bool tsMouseCheckPending         : 1;
  bool tsMiddleButtonDown          : 1;
  bool tsMiddleDblClick            : 1;
  bool tsNeedScale                 : 1;
  bool tsNeedRootCountUpdate       : 1;
  bool tsOLEDragging               : 1;
  bool tsOLEDragPending            : 1;
  bool tsPainting                  : 1;
  bool tsRightButtonDown           : 1;
  bool tsRightDblClick             : 1;
  bool tsPopupMenuShown            : 1;
  bool tsScrolling                 : 1;
  bool tsScrollPending             : 1;
  bool tsSizing                    : 1;
  bool tsStopValidation            : 1;
  bool tsStructureChangePending    : 1;
  bool tsSynchMode                 : 1;
  bool tsThumbTracking             : 1;
  bool tsUpdateHiddenChildrenNeeded: 1;
  bool tsUpdating                  : 1;
  bool tsUseCache                  : 1;
  bool tsUserDragObject            : 1;
  bool tsUseThemes                 : 1;
  bool tsValidating                : 1;
  bool tsValidationNeeded          : 1;
  bool tsVCLDragging               : 1;
  bool tsVCLDragPending            : 1;
  bool tsWheelPanning              : 1;
  bool tsWheelScrolling            : 1;
  bool tsWindowCreating            : 1;
  TVirtualTreeStates() { memset(this, 0, sizeof(*this)); }
  TVirtualTreeStates(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

enum TVirtualTreeStatesEnum {
  tsCancelHintAnimation,
  tsChangePending,
  tsCheckPropagation,
  tsCollapsing,
  tsToggleFocusedSelection,
  tsClearPending,
  tsClipboardFlushing,
  tsCopyPending,
  tsCutPending,
  tsDrawSelPending,
  tsDrawSelecting,
  tsEditing,
  tsEditPending,
  tsExpanding,
  tsHint,
  tsInAnimation,
  tsIncrementalSearching,
  tsIncrementalSearchPending,
  tsIterating,
  tsKeyCheckPending,
  tsLeftButtonDown,
  tsLeftDblClick,
  tsMouseCheckPending,
  tsMiddleButtonDown,
  tsMiddleDblClick,
  tsNeedScale,
  tsNeedRootCountUpdate,
  tsOLEDragging,
  tsOLEDragPending,
  tsPainting,
  tsRightButtonDown,
  tsRightDblClick,
  tsPopupMenuShown,
  tsScrolling,
  tsScrollPending,
  tsSizing,
  tsStopValidation,
  tsStructureChangePending,
  tsSynchMode,
  tsThumbTracking,
  tsUpdateHiddenChildrenNeeded,
  tsUpdating,
  tsUseCache,
  tsUserDragObject,
  tsUseThemes,
  tsValidating,
  tsValidationNeeded,
  tsVCLDragging,
  tsVCLDragPending,
  tsWheelPanning,
  tsWheelScrolling,
  tsWindowCreating
};

struct TVTStringOptions {
  bool toSaveCaptions        : 1;
  bool toShowStaticText      : 1;
  bool toAutoAcceptEditChange: 1;
  TVTStringOptions() { memset(this, 0, sizeof(*this)); }
  TVTStringOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVTAnimationOptions {
  bool toAnimatedToggle: 1;
  TVTAnimationOptions() { memset(this, 0, sizeof(*this)); }
  TVTAnimationOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVTAutoOptions {
  bool toAutoDropExpand          : 1;
  bool toAutoExpand              : 1;
  bool toAutoScroll              : 1;
  bool toAutoScrollOnExpand      : 1;
  bool toAutoSort                : 1;
  bool toAutoSpanColumns         : 1;
  bool toAutoTristateTracking    : 1;
  bool toAutoHideButtons         : 1;
  bool toAutoDeleteMovedNodes    : 1;
  bool toDisableAutoscrollOnFocus: 1;
  bool toAutoChangeScale         : 1;
  bool toAutoFreeOnCollapse      : 1;
  bool toDisableAutoscrollOnEdit : 1;
  bool toAutoBidiColumnOrdering  : 1;
  TVTAutoOptions() { memset(this, 0, sizeof(*this)); }
  TVTAutoOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVTMiscOptions {
  bool toAcceptOLEDrop      : 1;
  bool toCheckSupport       : 1;
  bool toEditable           : 1;
  bool toFullRepaintOnResize: 1;
  bool toGridExtensions     : 1;
  bool toInitOnSave         : 1;
  bool toReportMode         : 1;
  bool toToggleOnDblClick   : 1;
  bool toWheelPanning       : 1;
  bool toReadOnly           : 1;
  bool toVariableNodeHeight : 1;
  bool toFullRowDrag        : 1;
  TVTMiscOptions() { memset(this, 0, sizeof(*this)); }
  TVTMiscOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVTPaintOptions {
  bool toHideFocusRect      : 1;
  bool toHideSelection      : 1;
  bool toHotTrack           : 1;
  bool toPopupMode          : 1;
  bool toShowBackground     : 1;
  bool toShowButtons        : 1;
  bool toShowDropmark       : 1;
  bool toShowHorzGridLines  : 1;
  bool toShowRoot           : 1;
  bool toShowTreeLines      : 1;
  bool toShowVertGridLines  : 1;
  bool toThemeAware         : 1;
  bool toUseBlendedImages   : 1;
  bool toGhostedIfUnfocused : 1;
  bool toFullVertGridLines  : 1;
  bool toAlwaysHideSelection: 1;
  bool toUseBlendedSelection: 1;
  bool toStaticBackground   : 1;
  TVTPaintOptions() { memset(this, 0, sizeof(*this)); }
  TVTPaintOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVTSelectionOptions {
  bool toDisableDrawSelection   : 1;
  bool toExtendedFocus          : 1;
  bool toFullRowSelect          : 1;
  bool toLevelSelectConstraint  : 1;
  bool toMiddleClickSelect      : 1;
  bool toMultiSelect            : 1;
  bool toRightClickSelect       : 1;
  bool toSiblingSelectConstraint: 1;
  bool toCenterScrollIntoView   : 1;
  bool toSimpleDrawSelection    : 1;
  TVTSelectionOptions() { memset(this, 0, sizeof(*this)); }
  TVTSelectionOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVTHeaderOptions {
  bool hoAutoResize    : 1;
  bool hoColumnResize  : 1;
  bool hoDblClickResize: 1;
  bool hoDrag          : 1;
  bool hoHotTrack      : 1;
  bool hoOwnerDraw     : 1;
  bool hoRestrictDrag  : 1;
  bool hoShowHint      : 1;
  bool hoShowImages    : 1;
  bool hoShowSortGlyphs: 1;
  bool hoVisible       : 1;
  bool hoAutoSpring    : 1;
  TVTHeaderOptions() { memset(this, 0, sizeof(*this)); }
  TVTHeaderOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct THeaderStates {
  bool hsAutoSizing  : 1;
  bool hsDragging    : 1;
  bool hsDragPending : 1;
  bool hsLoading     : 1;
  bool hsTracking    : 1;
  bool hsTrackPending: 1;
  THeaderStates() { memset(this, 0, sizeof(*this)); }
  THeaderStates(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVTColumnOptions {
  bool coAllowClick    : 1;
  bool coDraggable     : 1;
  bool coEnabled       : 1;
  bool coParentBidiMode: 1;
  bool coParentColor   : 1;
  bool coResizable     : 1;
  bool coShowDropMark  : 1;
  bool coVisible       : 1;
  bool coAutoSpring    : 1;
  bool coFixed         : 1;
  TVTColumnOptions() { memset(this, 0, sizeof(*this)); }
  TVTColumnOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TVirtualNodeInitStates {
  bool ivsDisabled   : 1;
  bool ivsExpanded   : 1;
  bool ivsHasChildren: 1;
  bool ivsMultiline  : 1;
  bool ivsSelected   : 1;
  TVirtualNodeInitStates() { memset(this, 0, sizeof(*this)); }
  TVirtualNodeInitStates(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct THeaderPaintElements {
  bool hpeBackground : 1;
  bool hpeDropMark   : 1;
  bool hpeHeaderGlyph: 1;
  bool hpeSortGlyph  : 1;
  bool hpeText       : 1;
  THeaderPaintElements() { memset(this, 0, sizeof(*this)); }
  THeaderPaintElements(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

enum THeaderPaintElementsEnum {
  hpeBackground,
  hpeDropMark,
  hpeHeaderGlyph,
  hpeSortGlyph,
  hpeText
};

struct TOFNOptions {
  bool ofnReadonly           : 1;
  bool ofnOverwritePrompt    : 1;
  bool ofnHideReadonly       : 1;
  bool ofnNoChangeDir        : 1;
  bool ofnShowHelp           : 1;
  bool ofnNoValidate         : 1;
  bool ofnAllowMultiselect   : 1;
  bool ofnExtensionDifferent : 1;
  bool ofnPathMustExist      : 1;
  bool ofnFileMustExist      : 1;
  bool ofnCreatePrompt       : 1;
  bool ofnShareAware         : 1;
  bool ofnNoReadonlyReturn   : 1;
  bool ofnNoTestFileCreate   : 1;
  bool ofnNoNetworkButton    : 1;
  bool ofnNoLongnames        : 1;
  bool ofnExplorer           : 1;
  bool ofnNoDereferenceLinks : 1;
  bool ofnEnableIncludeNotify: 1;
  bool ofnEnableSizing       : 1;
  bool ofnDontAddToRecent    : 1;
  bool ofnForceShowHidden    : 1;
  TOFNOptions() { memset(this, 0, sizeof(*this)); }
  TOFNOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TBIFOptions {
  bool boBrowseForComputer : 1;
  bool boBrowseForPrinter  : 1;
  bool boDontGoBelowDomain : 1;
  bool boReturnOnlyFsDirs  : 1;
  bool boReturnFSAncestors : 1;
  bool boStatusText        : 1;
  bool boBrowseIncludeFiles: 1;
  bool boBrowseIncludeURLS : 1;
  bool boNewDialogStyle    : 1;
  bool boEditBox           : 1;
  bool boShareable         : 1;
  bool boUAHint            : 1;
  bool boNoNewButton       : 1;
  bool boNoTranslateTargets: 1;
  TBIFOptions() { memset(this, 0, sizeof(*this)); }
  TBIFOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TDialogStyles {
  bool dsImage  : 1;
  bool dsButtons: 1;
  bool dsHelp   : 1;
  bool dsHeader : 1;
  bool dsInfo   : 1;
  bool dsInput  : 1;
  bool dsInput2 : 1;
  bool dsInput3 : 1;
  bool dsCombo  : 1;
  TDialogStyles() { memset(this, 0, sizeof(*this)); }
  TDialogStyles(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

struct TDialogBtnStyles {
  bool bsYes   : 1;
  bool bsOk    : 1;
  bool bsNo    : 1;
  bool bsCancel: 1;
  bool bsCheck : 1;
  TDialogBtnStyles() { memset(this, 0, sizeof(*this)); }
  TDialogBtnStyles(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};

enum TMenuAutoFlag {
  maAutomatic,
  maManual
};

enum TBorderStyle {
  bsNone,
  bsSingle
};

enum TTextHintOption {
  hoUseLangID,
  hoLeftAlign,
  hoReverseAlignOnFocus,
  hoFocused,
  hoNotFocused,
  hoEmpty,
  hoNotEmpty
};

struct TTextHintOptions {
  bool hoUseLangID          : 1;
  bool hoLeftAlign          : 1;
  bool hoReverseAlignOnFocus: 1;
  bool hoFocused            : 1;
  bool hoNotFocused         : 1;
  bool hoEmpty              : 1;
  bool hoNotEmpty           : 1;
  TTextHintOptions() { memset(this, 0, sizeof(*this)); }
  TTextHintOptions(DWORD v) { *(DWORD*)this = v; }
  operator DWORD() { return *(DWORD*)this; }
};


typedef TAlignment TLeftRight;
typedef TBevelCut TPanelBevel;
typedef TButtonLayout TVTHeaderColumnLayout;
typedef TThemedListview TThemedListView;

struct TCreateParams {
  PCHAR Caption;
  DWORD Style;
  DWORD ExStyle;
  int X;
  int Y;
  int Width;
  int Height;
  DWORD WndParent;
  WNDCLASS WindowClass;
  void* Param;
  char WinClassName[64];
};

struct THitInfo {
  PVirtualNode HitNode;
  THitPositions HitPositions;
  TColumnIndex HitColumn;
};

struct TThemedElementDetails {
  TThemedElement Element;
  int Part;
  int State;
};
typedef TThemedElementDetails* PThemedElementDetails;

} //namespace qipns
