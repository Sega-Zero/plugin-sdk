namespace qipns {
	interface IComponent;
	interface IControl;
	interface IWinControl;
	interface IListener;
	interface IFont;
	interface IBrush;
	interface ICanvas;
	interface IPopupMenu;
	interface IParaAttributes;
	interface ITextAttributes;
	interface IPageControl;
	interface IMenuItems;
	interface IVirtualTreeOptions;
	interface ITreeColumns;
	interface ITreeColumn;
	interface ITreeHeader;
	interface IVTColors;
	interface IPageList;
	interface IToolBar;

	struct THeaderPaintInfo {
		ICanvas* TargetCanvas;
		ITreeColumn* Column;
		TRect PaintRectangle;
		TRect TextRectangle;
		Boolean IsHoverIndex;
		Boolean IsDownIndex;
		Boolean IsEnabled;
		Boolean ShowHeaderGlyph;
		Boolean ShowSortGlyph;
		Boolean ShowRightBorder;
		TVTDropMarkMode DropMark;
		TPoint GlyphPos;
		TPoint SortGlyphPos;
	};

	__interface IEventsCallback: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE SetEvent(IComponent* Component) = 0;
	};

  	EXTERN_C const IID IID_IQIPCoreGUI;
	MIDL_INTERFACE("3A3345AE-E21A-4ACA-89B1-4E8434D9B947")
	IQIPCoreGUI: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE CreateControls(IString* Description, IEventsCallback* EventsCallback, IComponent*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE CreateControl(IComponent* Owner, GUID iid, void**, IUnknown* EventHandler) = 0;
	};

	EXTERN_C const IID IID_IObject;
	MIDL_INTERFACE("1777C481-4604-4CCA-B42C-7D87E449D833")
	IObject: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAccess(int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEvents(IUnknown*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetObjectName(IString*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEvents(IUnknown*) = 0;
		virtual HRESULT STDMETHODCALLTYPE Core(IQIPCoreGUI*&) = 0;
	};

	EXTERN_C const IID IID_IComponent;
	MIDL_INTERFACE("CE30FFF1-2289-4B4C-A4FD-C7ED2D774D61")
	IComponent: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE ComponentCount(int&) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetComponent(int, IComponent*&) = 0;
		virtual HRESULT STDMETHODCALLTYPE FindComponent(IString*, IComponent*&) = 0;
		virtual HRESULT STDMETHODCALLTYPE RemoveComponent(IComponent*) = 0;
		virtual HRESULT STDMETHODCALLTYPE Owner(IComponent*&) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTag(int&) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTag(int) = 0;
	};

	EXTERN_C const IID IID_IControl;
	MIDL_INTERFACE("E27C7804-F2D2-43EE-A295-7873A49EA09A")
	IControl: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE BringToFront() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClientToScreen(TPoint Point, TPoint& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE Hide() = 0;
		virtual HRESULT STDMETHODCALLTYPE Invalidate() = 0;
		virtual HRESULT STDMETHODCALLTYPE Refresh() = 0;
		virtual HRESULT STDMETHODCALLTYPE Repaint() = 0;
		virtual HRESULT STDMETHODCALLTYPE ScreenToClient(TPoint Point, TPoint& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE SendToBack() = 0;
		virtual HRESULT STDMETHODCALLTYPE Show() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlign(TAlign& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAnchors(TAnchors& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBoundsRect(TRect& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetClientHeight(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetClientRect(TRect& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetClientWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCursor(TCursor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEnabled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFont(IFont*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeight(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLeft(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetName(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParent(IWinControl*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPopupMenu(IPopupMenu*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowHint(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTop(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVisible(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlign(TAlign Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAnchors(TAnchors Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBoundsRect(TRect Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetClientHeight(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetClientWidth(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCursor(TCursor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEnabled(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFont(IFont* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeight(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLeft(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetParent(IWinControl* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPopupMenu(IPopupMenu* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShowHint(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTop(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetVisible(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWidth(int Value) = 0;

	};
	
	EXTERN_C const IID IID_IWinControl;
	MIDL_INTERFACE("27C7084A-C62F-49B9-ABED-67009979A414")
	IWinControl: public IControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE AlignControls(IControl* AControl, TRect Rect) = 0;
		virtual HRESULT STDMETHODCALLTYPE CanFocus(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE ContainsControl(IControl* Ctrl, BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE ControlAtPos(TPoint Pos, BOOL AllowDisabled, BOOL AllowWinControls, IControl*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE CreateHandle() = 0;
		virtual HRESULT STDMETHODCALLTYPE CreateParams(TCreateParams Params) = 0;
		virtual HRESULT STDMETHODCALLTYPE DisableAlign() = 0;
		virtual HRESULT STDMETHODCALLTYPE EnableAlign() = 0;
		virtual HRESULT STDMETHODCALLTYPE Focused(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE HandleAllocated(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE HandleNeeded() = 0;
		virtual HRESULT STDMETHODCALLTYPE InsertControl(IControl* AControl) = 0;
		virtual HRESULT STDMETHODCALLTYPE PaintTo(HDC DC, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE PaintTo(ICanvas* Canvas, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE Realign() = 0;
		virtual HRESULT STDMETHODCALLTYPE RecreateWnd() = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFocus() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlignDisabled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelEdges(TBevelEdges& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelInner(TBevelCut& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelKind(TBevelKind& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelOuter(TBevelCut& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelWidth(TBevelWidth& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderWidth(TBorderWidth& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBrush(IBrush*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetControlCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetControl(int Index, IControl*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCtl3D(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HWnd& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParentWindow(HWnd& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowing(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabOrder(TTabOrder& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabStop(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevelEdges(TBevelEdges Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevelKind(TBevelKind Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevelCut(TBevelCut Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevelWidth(TBevelWidth Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderWidth(TBorderWidth Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCtl3D(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetParentWindow(HWnd Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabOrder(TTabOrder Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabStop(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IForm;
	MIDL_INTERFACE("7F17572B-8FEF-4BDA-AEFC-5E2B26FAB615")
	IForm: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Close() = 0;
		virtual HRESULT STDMETHODCALLTYPE Release2() = 0;
		virtual HRESULT STDMETHODCALLTYPE ShowModal(int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetActive(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetActiveControl(IWinControl*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlphaBlend(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlphaBlendValue(Byte& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAntiBoss(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderIcons(TBorderIcons& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderStyle(TFormBorderStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFormState(TFormState& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetGlassed(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIconURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetKeyPreview(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetListener(IListener*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetModalResult(TModalResult& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPopupMenu(IPopupMenu*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPosition(TPosition& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetScaled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetScreenSnap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowOnTaskbar(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSnapBuffer(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTransparentColor(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTransparentColorValue(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWindowState(TWindowState& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetActiveControl(IWinControl* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlphaBlend(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlphaBlendValue(Byte Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAntiBoss(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderIcons(TBorderIcons Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderStyle(TFormBorderStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetGlassed(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIconURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetKeyPreview(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetModalResult(TModalResult Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPopupMenu(IPopupMenu* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPosition(TPosition Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetScaled(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetScreenSnap(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShowOnTaskbar(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSnapBuffer(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTransparentColor(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTransparentColorValue(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWindowState(TWindowState Value) = 0;

	};
	
	EXTERN_C const IID IID_IFont;
	MIDL_INTERFACE("784DB137-44A8-4B1C-9661-BABBD3AF92CD")
	IFont: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE HandleAllocated(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCharset(TFontCharset& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HFont& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeight(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetName(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPitch(TFontPitch& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPixelsPerInch(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSize(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TFontStyles& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCharset(TFontCharset Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHandle(HFont Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeight(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetName(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPitch(TFontPitch Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPixelsPerInch(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSize(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TFontStyles Value) = 0;

	};
	
	EXTERN_C const IID IID_IBrush;
	MIDL_INTERFACE("B684FF1F-3560-4515-92DF-6D35CE1EB03A")
	IBrush: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE HandleAllocated(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HBrush& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TBrushStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHandle(HBrush Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TBrushStyle Value) = 0;

	};
	
	EXTERN_C const IID IID_IPen;
	MIDL_INTERFACE("C81A4656-BAAC-4525-85D4-CEF9A1D5FCD0")
	IPen: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE HandleAllocated(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HPen& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMode(TPenMode& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TPenStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHandle(HPen Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMode(TPenMode Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TPenStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWidth(int Value) = 0;

	};
	
	EXTERN_C const IID IID_ICanvas;
	MIDL_INTERFACE("E77AC998-8CB3-4D41-9769-A6713CC8E7DB")
	ICanvas: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4) = 0;
		virtual HRESULT STDMETHODCALLTYPE Chord(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4) = 0;
		virtual HRESULT STDMETHODCALLTYPE CopyRect(TRect Dest, ICanvas* Canvas, TRect Source) = 0;
		virtual HRESULT STDMETHODCALLTYPE Draw(int X, int Y, IString* Graphic) = 0;
		virtual HRESULT STDMETHODCALLTYPE DrawFocusRect(TRect Rect) = 0;
		virtual HRESULT STDMETHODCALLTYPE Ellipse(int X1, int Y1, int X2, int Y2) = 0;
		virtual HRESULT STDMETHODCALLTYPE Ellipse(TRect Rect) = 0;
		virtual HRESULT STDMETHODCALLTYPE FillRect(TRect Rect) = 0;
		virtual HRESULT STDMETHODCALLTYPE FloodFill(int X, int Y, TColor Color, TFillStyle FillStyle) = 0;
		virtual HRESULT STDMETHODCALLTYPE FrameRect(TRect Rect) = 0;
		virtual HRESULT STDMETHODCALLTYPE HandleAllocated(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE LineTo(int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE Lock() = 0;
		virtual HRESULT STDMETHODCALLTYPE MoveTo(int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4) = 0;
		virtual HRESULT STDMETHODCALLTYPE PolyBezier(PPoint Points, int count) = 0;
		virtual HRESULT STDMETHODCALLTYPE PolyBezierTo(PPoint Points, int count) = 0;
		virtual HRESULT STDMETHODCALLTYPE Polygon(PPoint Points, int count) = 0;
		virtual HRESULT STDMETHODCALLTYPE Polyline(PPoint Points, int count) = 0;
		virtual HRESULT STDMETHODCALLTYPE Rectangle(TRect Rect) = 0;
		virtual HRESULT STDMETHODCALLTYPE Refresh() = 0;
		virtual HRESULT STDMETHODCALLTYPE RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3) = 0;
		virtual HRESULT STDMETHODCALLTYPE StretchDraw(TRect Rect, IString* Graphic, TScaleMetod Scale) = 0;
		virtual HRESULT STDMETHODCALLTYPE TextExtent(IString* Text, TSize& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE TextHeight(IString* Text, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE TextOut(int X, int Y, IString* Text) = 0;
		virtual HRESULT STDMETHODCALLTYPE TextRect(TRect Rect, int X, int Y, IString* Text) = 0;
		virtual HRESULT STDMETHODCALLTYPE TextWidth(IString* Text, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE TryLock(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE Unlock() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBrush(IBrush*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvasOrientation(TCanvasOrientation& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetClipRect(TRect& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCopyMode(TCopyMode& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFont(IFont*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HDC& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLockCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPen(IPen*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPenPos(TPoint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPixel(int X, int Y, TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTextFlags(Longint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBrush(IBrush* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCopyMode(TCopyMode Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFont(IFont* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHandle(HDC Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPen(IPen* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPenPos(TPoint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPixel(int X, int Y, TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTextFlags(Longint Value) = 0;

	};
	
	EXTERN_C const IID IID_ILabel;
	MIDL_INTERFACE("0FA4966F-846E-4EAB-B232-45663949353B")
	ILabel: public IControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE AdjustBounds() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoSize(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLayout(TTextLayout& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowAccelChar(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTransparent(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWordWrap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSize(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLayout(TTextLayout Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShowAccelChar(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTransparent(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWordWrap(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IStaticText;
	MIDL_INTERFACE("CCDA5BAD-AAE6-46D0-AD02-5FFC05373B95")
	IStaticText: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoSize(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderStyle(TStaticBorderStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEndEllipsis(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowAccelChar(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTransparent(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSize(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderStyle(TStaticBorderStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEndEllipsis(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShowAccelChar(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTransparent(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IProgressBar;
	MIDL_INTERFACE("58675583-56AD-451F-92C6-6FD1E308B619")
	IProgressBar: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE StepBy(int Delta) = 0;
		virtual HRESULT STDMETHODCALLTYPE StepIt() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMax(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMin(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOrientation(TProgressBarOrientation& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPosition(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSmooth(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStep(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMax(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMin(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOrientation(TProgressBarOrientation Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPosition(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSmooth(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStep(int Value) = 0;

	};
	
	EXTERN_C const IID IID_ITrackBar;
	MIDL_INTERFACE("436AA9F3-6C16-481D-959F-9CCC9917335E")
	ITrackBar: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE SetTick(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFrequency(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLineSize(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMax(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMin(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOrientation(TTrackBarOrientation& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageSize(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPosition(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelEnd(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelStart(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSliderVisible(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetThumbLength(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTickMarks(TTickMark& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTickStyle(TTickStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFrequency(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLineSize(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMax(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMin(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOrientation(TTrackBarOrientation Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPageSize(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPosition(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelEnd(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelStart(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSliderVisible(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetThumbLength(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTickMarks(TTickMark Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTickStyle(TTickStyle Value) = 0;

	};
	
	EXTERN_C const IID IID_IToolButton;
	MIDL_INTERFACE("D822E946-1A3D-4099-AE4B-E43C1D21396A")
	IToolButton: public IControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Click() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAllowAllUp(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoSize(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDown(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDropdownMenu(IPopupMenu*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetGrouped(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetImageURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIndeterminate(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMarked(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TToolButtonStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetToolBar(IToolBar*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWrap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAllowAllUp(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSize(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDown(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDropdownMenu(IPopupMenu* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetGrouped(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetImageURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIndeterminate(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMarked(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TToolButtonStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetToolBar(IToolBar* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWrap(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IToolBar;
	MIDL_INTERFACE("27183EFC-0E8F-4918-9C33-613AE8B941B2")
	IToolBar: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAutoSize(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetButtonCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetButtonHeight(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetButtonWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetButton(int Index, IToolButton*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEdgeBorders(TEdgeBorders& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEdgeInner(TEdgeStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEdgeOuter(TEdgeStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFlat(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHideClippedButtons(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIndent(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetList(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowCaptions(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTransparent(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWrapable(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSize(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetButtonHeight(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetButtonWidth(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEdgeBorders(TEdgeBorders Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEdgeInner(TEdgeStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEdgeOuter(TEdgeStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFlat(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHideClippedButtons(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIndent(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetList(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShowCaptions(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTransparent(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWrapable(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IUpDown;
	MIDL_INTERFACE("47D92A22-48D9-4317-977D-3C649AD1EE54")
	IUpDown: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAlignButton(TUDAlignButton& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetArrowKeys(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAssociate(IWinControl*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIncrement(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMax(SmallInt& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMin(SmallInt& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOrientation(TUDOrientation& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetThousands(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWrap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignButton(TUDAlignButton Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetArrowKeys(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAssociate(IWinControl* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIncrement(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMax(SmallInt Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMin(SmallInt Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOrientation(TUDOrientation Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetThousands(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWrap(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IButton;
	MIDL_INTERFACE("33A124B7-4A9C-465E-A23D-1ECAF800EB0E")
	IButton: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Click() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDefault(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetImgURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLayout(TButtonLayout& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMargin(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetModalResult(TModalResult& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSpacing(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWordWrap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDefault(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetImgURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLayout(TButtonLayout Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMargin(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetModalResult(TModalResult Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSpacing(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWordWrap(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_ISpeedButton;
	MIDL_INTERFACE("AED80E85-5B4F-4858-A4FE-011FBA003435")
	ISpeedButton: public IControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Click() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAllowAllUp(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDown(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFlat(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFrameOnMouse(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetGroupIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetImgURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLayout(TButtonLayout& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMargin(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowDropArrow(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSpacing(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetThemeFlat(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTransparent(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAllowAllUp(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDown(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFlat(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFrameOnMouse(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetGroupIndex(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetImgURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLayout(TButtonLayout Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMargin(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShowDropArrow(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSpacing(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetThemeFlat(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTransparent(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IRadioButton;
	MIDL_INTERFACE("C1BFF325-3339-4D8F-98DF-92467D6FDD13")
	IRadioButton: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetChecked(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWordWrap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetChecked(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWordWrap(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_ICheckBox;
	MIDL_INTERFACE("82363584-B929-474B-9501-3AE30F244D4C")
	ICheckBox: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Click() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TLeftRight& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAllowGrayed(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetChecked(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetState(TCheckBoxState& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTransparent(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWordWrap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TLeftRight Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAllowGrayed(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetChecked(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetState(TCheckBoxState Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTransparent(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWordWrap(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IEdit;
	MIDL_INTERFACE("B7A09905-96CF-4C0B-898C-009FAA3CD050")
	IEdit: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClearSelection() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClearUndo() = 0;
		virtual HRESULT STDMETHODCALLTYPE CopyToClipboard() = 0;
		virtual HRESULT STDMETHODCALLTYPE CutToClipboard() = 0;
		virtual HRESULT STDMETHODCALLTYPE PasteFromClipboard() = 0;
		virtual HRESULT STDMETHODCALLTYPE SelectAll() = 0;
		virtual HRESULT STDMETHODCALLTYPE Undo() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoSelect(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoSize(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderStyle(TBorderStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanUndo(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCharCase(TEditCharCase& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHideSelection(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMaxLength(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetModified(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOEMConvert(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPasswordChar(WideChar& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetReadOnly(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelLength(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelStart(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTextHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTextHintOptions(TTextHintOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSelect(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSize(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderStyle(TBorderStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCharCase(TEditCharCase Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHideSelection(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMaxLength(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetModified(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOEMConvert(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPasswordChar(WideChar Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetReadOnly(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelLength(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelStart(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTextHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTextHintOptions(TTextHintOptions Value) = 0;

	};
	
	EXTERN_C const IID IID_IMemo;
	MIDL_INTERFACE("27FA3632-2E38-4F11-A915-9C6118460869")
	IMemo: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClearSelection() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClearUndo() = 0;
		virtual HRESULT STDMETHODCALLTYPE CopyToClipboard() = 0;
		virtual HRESULT STDMETHODCALLTYPE CutToClipboard() = 0;
		virtual HRESULT STDMETHODCALLTYPE PasteFromClipboard() = 0;
		virtual HRESULT STDMETHODCALLTYPE SelectAll() = 0;
		virtual HRESULT STDMETHODCALLTYPE Undo() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderStyle(TBorderStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanUndo(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaretPos(TPoint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHideSelection(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLines(IStringList*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMaxLength(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetModified(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOEMConvert(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetReadOnly(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetScrollBars(TScrollStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelLength(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelStart(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWantReturns(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWantTabs(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWordWrap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderStyle(TBorderStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaretPos(TPoint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHideSelection(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLines(IStringList* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMaxLength(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetModified(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOEMConvert(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetReadOnly(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetScrollBars(TScrollStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelLength(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelStart(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWantReturns(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWantTabs(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWordWrap(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IRichEdit;
	MIDL_INTERFACE("CBC854DC-7C6A-40D4-80AA-1055666D82E2")
	IRichEdit: public IMemo
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE FindText(IString* SearchStr, int StartPos, int Length, TSearchTypes Options, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDefAttributes(ITextAttributes*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHideScrollBars(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHideSelection(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageRect(TRect& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParagraph(IParaAttributes*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFormattedText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelAttributes(ITextAttributes*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDefAttributes(ITextAttributes* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHideScrollBars(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHideSelection(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPageRect(TRect Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFormattedText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelAttributes(ITextAttributes* Value) = 0;

	};
	
	EXTERN_C const IID IID_IListControl;
	MIDL_INTERFACE("6842816A-5CF6-49FD-BEA0-7D0836EF698C")
	IListControl: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE AddItem(IString* Item, TObject AObject) = 0;
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClearSelection() = 0;
		virtual HRESULT STDMETHODCALLTYPE SelectAll() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItemIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItemIndex(int Value) = 0;

	};
	
	EXTERN_C const IID IID_IComboBox;
	MIDL_INTERFACE("82B26652-146A-48F5-91D2-A265C55F6F34")
	IComboBox: public IListControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE AddItem(IString* Item, TObject AObject) = 0;
		virtual HRESULT STDMETHODCALLTYPE DropDown() = 0;
		virtual HRESULT STDMETHODCALLTYPE Focused(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSmartDropWidth(int AddLen) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoComplete(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoDropDown(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDropDownCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDroppedDown(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEditHandle(HWnd& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItemHt(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItems(IStringList*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMaxLength(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelLength(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelStart(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSorted(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TComboBoxStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoComplete(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoDropDown(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDropDownCount(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDroppedDown(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItemHeight(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItems(IStringList* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMaxLength(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelLength(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelStart(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSorted(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TComboBoxStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetText(IString* Value) = 0;

	};
	
	EXTERN_C const IID IID_IListBox;
	MIDL_INTERFACE("A189B36C-F135-47F8-92A5-152C7ED45393")
	IListBox: public IListControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE AddItem(IString* Item, TObject AObject) = 0;
		virtual HRESULT STDMETHODCALLTYPE DeleteSelected() = 0;
		virtual HRESULT STDMETHODCALLTYPE ItemAtPos(TPoint Pos, BOOL Existing, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE ItemRect(int Index, TRect& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoComplete(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColumns(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetExtendedSelect(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIntegralHeight(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItemHeight(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItems(IStringList*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMultiSelect(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetScrollWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelected(int Index, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSorted(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TListBoxStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTopIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoComplete(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColumns(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCount(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetExtendedSelect(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIntegralHeight(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItemHeight(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItems(IStringList* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMultiSelect(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetScrollWidth(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelected(int Index, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSorted(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TListBoxStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabWidth(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTopIndex(int Value) = 0;

	};
	
	EXTERN_C const IID IID_IMenuItem;
	MIDL_INTERFACE("14A51322-AE67-48D7-A7BD-2359E61FE4BB")
	IMenuItem: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Add(IMenuItem* Item) = 0;
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE Click() = 0;
		virtual HRESULT STDMETHODCALLTYPE Delete(int Index) = 0;
		virtual HRESULT STDMETHODCALLTYPE Find(IString* ACaption, IMenuItem*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE HasParent(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE IndexOf(IMenuItem* Item, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE Insert(int Index, IMenuItem* Item) = 0;
		virtual HRESULT STDMETHODCALLTYPE IsLine(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE Remove(IMenuItem* Item) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAltCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAltColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAltSize(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoCheck(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBreak(TMenuBreak& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetChecked(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCommand(Word& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDefault(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEnabled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetGroupIndex(Byte& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HMENU& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeadColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeadFontColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeadFrameColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeadGradColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeaderItem(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetImgURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItemID(Word& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItem(int Index, IMenuItem*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMenuIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParent(IMenuItem*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetRadioItem(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetRightImageURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVisible(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAltCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAltColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAltSize(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoCheck(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBreak(TMenuBreak Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetChecked(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDefault(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEnabled(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetGroupIndex(Byte Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeadColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeadFontColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeadFrameColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeadGradColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeaderItem(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetImgURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItemID(Word Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMenuIndex(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetRadioItem(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetRightImageURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetVisible(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IMenu;
	MIDL_INTERFACE("3F06F0D4-687C-45AA-8AAF-C8A6727A030E")
	IMenu: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAutoHotkeys(TMenuAutoFlag& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HMENU& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItems(IMenuItems*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOwnerDraw(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoHotkeys(TMenuAutoFlag Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOwnerDraw(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IMainMenu;
	MIDL_INTERFACE("EE06009B-3174-4D8D-B901-3DDF41348BD6")
	IMainMenu: public IMenu
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Merge(IMainMenu* Menu) = 0;
		virtual HRESULT STDMETHODCALLTYPE Unmerge(IMainMenu* Menu) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoMerge(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoMerge(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IPopupMenu;
	MIDL_INTERFACE("8C9D6068-8DF3-4DEF-9E4C-2E2CFAFEBF43")
	IPopupMenu: public IMenu
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Popup(int X, int Y, DWORD TPM_Flags) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TPopupAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoPopup(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPopupPoint(TPoint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTrackButton(TTrackButton& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TPopupAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoPopup(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTrackButton(TTrackButton Value) = 0;

	};
	
	EXTERN_C const IID IID_IGroupBox;
	MIDL_INTERFACE("D30F6560-D9E8-4546-8A71-1C2AEAA80A1D")
	IGroupBox: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;

	};
	
	EXTERN_C const IID IID_IRadioGroup;
	MIDL_INTERFACE("CEA85243-1D10-423F-8AD5-1F4A6319A57C")
	IRadioGroup: public IGroupBox
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetButtons(int Index, IRadioButton*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColumns(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItemIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItems(IStringList*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColumns(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItemIndex(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItems(IStringList* Value) = 0;

	};
	
	EXTERN_C const IID IID_IBevel;
	MIDL_INTERFACE("5BCEC41D-0F5D-48FB-8984-C147FDDBFC84")
	IBevel: public IControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShape(TBevelShape& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TBevelStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShape(TBevelShape Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TBevelStyle Value) = 0;

	};
	
	EXTERN_C const IID IID_IStatusPanel;
	MIDL_INTERFACE("470F7556-476E-4D36-BDCE-8ACA507B9E0E")
	IStatusPanel: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevel(TStatusPanelBevel& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TStatusPanelStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevel(TStatusPanelBevel Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TStatusPanelStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWidth(int Value) = 0;

	};
	
	EXTERN_C const IID IID_IStatusPanels;
	MIDL_INTERFACE("3A789EC2-FF96-4D86-B94B-D538C7D4478D")
	IStatusPanels: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Add(IStatusPanel*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE AddItem(IStatusPanel* Item, int Index, IStatusPanel*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE BeginUpdate() = 0;
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE Delete(int Index) = 0;
		virtual HRESULT STDMETHODCALLTYPE EndUpdate() = 0;
		virtual HRESULT STDMETHODCALLTYPE Insert(int Index, IStatusPanel*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItem(int Index, IStatusPanel*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItem(int Index, IStatusPanel* Value) = 0;

	};
	
	EXTERN_C const IID IID_IStatusBar;
	MIDL_INTERFACE("4DE089C3-8C77-40A5-B66C-B39F2F86E4FC")
	IStatusBar: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAutoHint(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPanels(IStatusPanels*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSimplePanel(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSimpleText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSizeGrip(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetUseSystemFont(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoHint(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPanels(IStatusPanels* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSimplePanel(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSimpleText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSizeGrip(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetUseSystemFont(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_ISplitter;
	MIDL_INTERFACE("EEA2535A-2131-4D83-BCBC-0C76321252AA")
	ISplitter: public IControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAutoSnap(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBeveled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMinSize(NaturalNumber& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetResizeStyle(TResizeStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSnap(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBeveled(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMinSize(NaturalNumber Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetResizeStyle(TResizeStyle Value) = 0;

	};
	
	EXTERN_C const IID IID_IPanel;
	MIDL_INTERFACE("70554BBE-5EAD-4593-BC70-EBFF6F796F1A")
	IPanel: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelInner(TPanelBevel& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelOuter(TPanelBevel& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBevelWidth(TBevelWidth& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderStyle(TBorderStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderWidth(TBorderWidth& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetErase(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFlatBorder(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFullRepaint(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLocked(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNoBorders(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParentBackground(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParentColor(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevelInner(TPanelBevel Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevelOuter(TPanelBevel Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBevelWidth(TBevelWidth Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderStyle(TBorderStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderWidth(TBorderWidth Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetErase(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFlatBorder(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFullRepaint(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLocked(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetNoBorders(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetParentBackground(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetParentColor(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IParaAttributes;
	MIDL_INTERFACE("46E6605C-9206-430D-AF2C-E9D9CD7966B8")
	IParaAttributes: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirstIndent(Longint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLeftIndent(Longint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNumbering(TNumberingStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetRightIndent(Longint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTab(Byte Index, Longint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFirstIndent(Longint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLeftIndent(Longint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetNumbering(TNumberingStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetRightIndent(Longint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTab(Byte Index, Longint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabCount(int Value) = 0;

	};
	
	EXTERN_C const IID IID_ITextAttributes;
	MIDL_INTERFACE("96A9F0AB-3966-49FB-A9BD-B6B07714F950")
	ITextAttributes: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetConsistentAttributes(TConsistentAttributes& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeight(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetName(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSize(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TFontStyles& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeight(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetName(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSize(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TFontStyles Value) = 0;

	};
	
	EXTERN_C const IID IID_ITabSheet;
	MIDL_INTERFACE("345C3003-E0DC-4092-AF47-E20C63B9BF32")
	ITabSheet: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageControl(IPageControl*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabVisible(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPageControl(IPageControl* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPageIndex(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabVisible(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IBaseTabControl;
	MIDL_INTERFACE("3AADC2F1-C225-4773-A641-8C40D82C497A")
	IBaseTabControl: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetHitTestInfoAt(int X, int Y, THitTests& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE IndexOfTabAt(int X, int Y, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE RowCount(int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE TabRect(int Index, TRect& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDisplayRect(TRect& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHotTrack(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMultiLine(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TTabStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabSize(Smallint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTabPosition(TTabPosition& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHotTrack(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMultiLine(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TTabStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabHeight(Smallint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabIndex(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabPosition(TTabPosition Value) = 0;

	};
	
	EXTERN_C const IID IID_ITabControl;
	MIDL_INTERFACE("EA2555E4-2B35-4551-B5CF-1CE2C00354D7")
	ITabControl: public IBaseTabControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetTabs(IStringList*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTabs(IStringList* Value) = 0;

	};
	
	EXTERN_C const IID IID_IPageControl;
	MIDL_INTERFACE("085A0F44-6C25-416E-9BE5-607BA1C2559F")
	IPageControl: public IBaseTabControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE FindNextPage(ITabSheet* CurPage, BOOL GoForward, BOOL CheckTabVisible, ITabSheet*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE SelectNextPage(BOOL GoForward, BOOL CheckTabVisible) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetActivePage(ITabSheet*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetActivePageIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPage(int Index, ITabSheet*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetActivePage(ITabSheet* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetActivePageIndex(int Value) = 0;

	};
	
	EXTERN_C const IID IID_ITimer;
	MIDL_INTERFACE("78BD461B-F083-48A7-99C5-D8E3A17F78CB")
	ITimer: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetEnabled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetInterval(DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEnabled(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetInterval(DWORD Value) = 0;

	};
	
	EXTERN_C const IID IID_IPaintBox;
	MIDL_INTERFACE("4D001F43-5FB1-41BE-96CE-AC2DAF8F6C74")
	IPaintBox: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;

	};
	
	EXTERN_C const IID IID_IImage;
	MIDL_INTERFACE("2D06DBA3-27D8-401F-922F-4DA323DFE5B7")
	IImage: public IControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Start() = 0;
		virtual HRESULT STDMETHODCALLTYPE Stop() = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAllowAnimation(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoSize(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCanvas(ICanvas*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetImageURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetScale(TScaleMetod& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAllowAnimation(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSize(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetImageURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetScale(TScaleMetod Value) = 0;

	};
	
	EXTERN_C const IID IID_IListener;
	MIDL_INTERFACE("F7934A80-0E8E-4B17-8F65-0F514179E022")
	IListener: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE ApplyChanges() = 0;
		virtual HRESULT STDMETHODCALLTYPE Changed(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE EnumChangedControls(int& Index, IComponent*& AControl, BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE ResetChanges() = 0;
		virtual HRESULT STDMETHODCALLTYPE WatchClear() = 0;
		virtual HRESULT STDMETHODCALLTYPE WatchForProperties(TGUID AComponentClass, IString* PropName) = 0;
		virtual HRESULT STDMETHODCALLTYPE WatchForProperties(IWinControl* AOwner, TGUID ClassGuid, IString* PropName) = 0;
		virtual HRESULT STDMETHODCALLTYPE WatchForProperty(IComponent* AComponent, IString* PropName) = 0;

	};
	
	EXTERN_C const IID IID_IMenuItems;
	MIDL_INTERFACE("06DA3DF7-3575-47F4-99B9-5524E273D13A")
	IMenuItems: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Add(IMenuItem* Item) = 0;
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE Delete(int Index) = 0;
		virtual HRESULT STDMETHODCALLTYPE Find(IString* ACaption, IMenuItem*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE IndexOf(IMenuItem* Item, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE Insert(int Index, IMenuItem* Item) = 0;
		virtual HRESULT STDMETHODCALLTYPE Remove(IMenuItem* Item) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCaption(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEnabled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItem(int Index, IMenuItem*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParent(IMenuItem*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVisible(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCaption(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEnabled(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetVisible(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IVirtualTree;
	MIDL_INTERFACE("11CFC811-931D-4423-9445-EABF83813B9D")
	IVirtualTree: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE AbsoluteIndex(PVirtualNode Node, DWORD& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE AddChild(PVirtualNode Parent, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE BeginUpdate() = 0;
		virtual HRESULT STDMETHODCALLTYPE CanFocus(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE CancelEditNode(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClearChecked() = 0;
		virtual HRESULT STDMETHODCALLTYPE ClearSelection() = 0;
		virtual HRESULT STDMETHODCALLTYPE DeleteChildren(PVirtualNode Node, BOOL ResetHasChildren) = 0;
		virtual HRESULT STDMETHODCALLTYPE DeleteNode(PVirtualNode Node, BOOL Reindex) = 0;
		virtual HRESULT STDMETHODCALLTYPE DeleteSelectedNodes() = 0;
		virtual HRESULT STDMETHODCALLTYPE EditNode(PVirtualNode Node, TColumnIndex Column, BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE EndEditNode(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE EndUpdate() = 0;
		virtual HRESULT STDMETHODCALLTYPE FullCollapse(PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE FullExpand(PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDisplayRect(PVirtualNode Node, TColumnIndex Column, BOOL TextOnly, BOOL Unclipped, TRect& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirst(PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirstChecked(TCheckState State, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirstChild(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirstSelected(PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirstVisible(PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirstVisibleChild(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHitTestInfoAt(int X, int Y, BOOL Relative, THitInfo& HitInfo) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLast(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLastChild(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLastVisible(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLastVisibleChild(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMaxColumnWidth(TColumnIndex Column, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNext(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNextChecked(PVirtualNode Node, TCheckState State, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNextSibling(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNextVisible(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNextVisibleSibling(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNodeAt(int X, int Y, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNodeAt(int X, int Y, BOOL Relative, int NodeTop, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNodeData(PVirtualNode Node, int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNodeLevel(PVirtualNode Node, DWORD& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPrevious(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPreviousSibling(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPreviousVisible(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPreviousVisibleSibling(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTreeRect(TRect& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVisibleParent(PVirtualNode Node, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE InsertNode(PVirtualNode Node, TVTNodeAttachMode Mode, PVirtualNode& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE InvalidateChildren(PVirtualNode Node, BOOL Recursive) = 0;
		virtual HRESULT STDMETHODCALLTYPE InvalidateColumn(TColumnIndex Column) = 0;
		virtual HRESULT STDMETHODCALLTYPE InvalidateNode(PVirtualNode Node, TRect& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE InvalidateToBottom(PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE InvertSelection(BOOL VisibleOnly) = 0;
		virtual HRESULT STDMETHODCALLTYPE IsEditing(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE IsMouseSelecting(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE MoveTo(PVirtualNode Source, PVirtualNode Target, TVTNodeAttachMode Mode, BOOL ChildrenOnly) = 0;
		virtual HRESULT STDMETHODCALLTYPE MoveTo(PVirtualNode Node, IVirtualTree* Tree, TVTNodeAttachMode Mode, BOOL ChildrenOnly) = 0;
		virtual HRESULT STDMETHODCALLTYPE Path(PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType, WideChar Delimiter, IString*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE RepaintNode(PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE SelectAll(BOOL VisibleOnly) = 0;
		virtual HRESULT STDMETHODCALLTYPE Sort(PVirtualNode Node, TColumnIndex Column, TSortDirection Direction) = 0;
		virtual HRESULT STDMETHODCALLTYPE SortTree(TColumnIndex Column, TSortDirection Direction) = 0;
		virtual HRESULT STDMETHODCALLTYPE ToggleNode(PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE ValidateNode(PVirtualNode Node, BOOL Recursive) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoValidateNodes(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCheckState(PVirtualNode Node, TCheckState& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCheckType(PVirtualNode Node, TCheckType& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetChildCount(PVirtualNode Node, DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColors(IVTColors*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDefaultNodeHeight(DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetExpanded(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFocusedColumn(TColumnIndex& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFocusedNode(PVirtualNode& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFullyVisible(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHasChildren(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeader(ITreeHeader*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCurrentHotNode(PVirtualNode& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIsDisabled(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIsVisible(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMultiline(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNodeHeight(PVirtualNode Node, DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNodeParent(PVirtualNode Node, PVirtualNode& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOffsetX(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOffsetXY(TPoint& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOffsetY(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetRoot(PVirtualNode& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelected(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelectionCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNodeText(PVirtualNode Node, TColumnIndex Column, IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTopNode(PVirtualNode& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTotalCount(DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOptions(IVirtualTreeOptions*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStates(TVirtualTreeStates& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetUpdateCount(DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVerticalAlignment(PVirtualNode Node, Byte& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVisibleCount(DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVisiblePath(PVirtualNode Node, BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoValidateNodes(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCheckState(PVirtualNode Node, TCheckState Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetCheckType(PVirtualNode Node, TCheckType Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetChildCount(PVirtualNode Node, DWORD Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColors(IVTColors* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDefaultNodeHeight(DWORD Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetExpanded(PVirtualNode Node, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFocusedColumn(TColumnIndex Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFocusedNode(PVirtualNode Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFullyVisible(PVirtualNode Node, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHasChildren(PVirtualNode Node, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeader(ITreeHeader* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIsDisabled(PVirtualNode Node, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIsVisible(PVirtualNode Node, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMultiline(PVirtualNode Node, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetNodeData(PVirtualNode Node, int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetNodeHeight(PVirtualNode Node, DWORD Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetNodeParent(PVirtualNode Node, PVirtualNode Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOffsetX(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOffsetXY(TPoint Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOffsetY(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelected(PVirtualNode Node, BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetNodeText(PVirtualNode Node, TColumnIndex Column, IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTopNode(PVirtualNode Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOptions(IVirtualTreeOptions* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStates(TVirtualTreeStates Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetVerticalAlignment(PVirtualNode Node, Byte Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetVisiblePath(PVirtualNode Node, BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IVirtualTreeOptions;
	MIDL_INTERFACE("64D2DEC9-C9CC-4A01-9288-7513A4814193")
	IVirtualTreeOptions: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAnimationOptions(TVTAnimationOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAutoOptions(TVTAutoOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMiscOptions(TVTMiscOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPaintOptions(TVTPaintOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelectionOptions(TVTSelectionOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStringOptions(TVTStringOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAnimationOptions(TVTAnimationOptions Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoOptions(TVTAutoOptions Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMiscOptions(TVTMiscOptions Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPaintOptions(TVTPaintOptions Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelectionOptions(TVTSelectionOptions Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStringOptions(TVTStringOptions Value) = 0;

	};
	
	EXTERN_C const IID IID_ITreeHeader;
	MIDL_INTERFACE("D2B25504-6B02-4D10-8368-E869D0AB8F9E")
	ITreeHeader: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetAutoSizeIndex(TColumnIndex& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBackground(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColumns(ITreeColumns*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFont(IFont*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeight(DWORD& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMainColumn(TColumnIndex& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOptions(TVTHeaderOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetParentFont(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPopupMenu(IPopupMenu*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSortColumn(TColumnIndex& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSortDirection(TSortDirection& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStates(THeaderStates& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TVTHeaderStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOwner(IVirtualTree*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetUseColumns(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAutoSizeIndex(TColumnIndex Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBackground(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColumns(ITreeColumns* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFont(IFont* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeight(DWORD Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMainColumn(TColumnIndex Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOptions(TVTHeaderOptions Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetParentFont(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPopUpMenu(IPopupMenu* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSortColumn(TColumnIndex Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSortDirection(TSortDirection Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TVTHeaderStyle Value) = 0;

	};
	
	EXTERN_C const IID IID_ITreeColumns;
	MIDL_INTERFACE("F08FA7FC-DD51-43A7-A727-D113913F8CB7")
	ITreeColumns: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Add(ITreeColumn*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE AnimatedResize(TColumnIndex Column, int NewWidth) = 0;
		virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
		virtual HRESULT STDMETHODCALLTYPE ColumnFromPosition(TPoint P, BOOL Relative, TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE ColumnFromPosition(TColumnPosition PositionIndex, TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColumnBounds(TColumnIndex Column, int Left, int Right) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFirstVisibleColumn(TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLastVisibleColumn(TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNextColumn(TColumnIndex Column, TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetNextVisibleColumn(TColumnIndex Column, TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPreviousColumn(TColumnIndex Column, TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPreviousVisibleColumn(TColumnIndex Column, TColumnIndex& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetVisibleFixedWidth(int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE IsValidColumn(TColumnIndex Column, BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE TotalWidth(int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetClickIndex(TColumnIndex& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeader(ITreeHeader*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetItem(TColumnIndex Index, ITreeColumn*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTrackIndex(TColumnIndex& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetItem(TColumnIndex Index, ITreeColumn* Value) = 0;

	};
	
	EXTERN_C const IID IID_ITreeColumn;
	MIDL_INTERFACE("8F34DD2B-047F-41DD-AF36-D74E7F690CE4")
	ITreeColumn: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetRect(TRect& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetAlignment(TAlignment& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLayout(TVTHeaderColumnLayout& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLeft(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMargin(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMaxWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetMinWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOptions(TVTColumnOptions& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetOwner(ITreeColumns*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPosition(TColumnPosition& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSpacing(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetStyle(TVirtualTreeColumnStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTag(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetText(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWidth(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetAlignment(TAlignment Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLayout(TVTHeaderColumnLayout Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMargin(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMaxWidth(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetMinWidth(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetOptions(TVTColumnOptions Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPosition(TColumnPosition Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSpacing(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetStyle(TVirtualTreeColumnStyle Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTag(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetText(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWidth(int Value) = 0;

	};
	
	EXTERN_C const IID IID_ITrayIcon;
	MIDL_INTERFACE("B57FA15F-CD3D-41C3-9A74-3A6BF1C8B81E")
	ITrayIcon: public IComponent
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetBalloonHintHandle(HWND& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetClientIconPos(int X, int Y, TPoint& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTooltipHandle(HWND& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE HideBalloonHint(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE Popup(int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE PopupAtCursor() = 0;
		virtual HRESULT STDMETHODCALLTYPE Refresh(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFocus(BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE ShowBalloonHint(IString* Title, IString* Text, TBalloonHintIcon IconType, TBalloonHintTimeOut TimeoutSecs, BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetEnabled(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHandle(HWND& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIconGuid(TGUID& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetIconVisible(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetImageURI(IString*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetLeftPopup(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPopupMenu(IPopupMenu*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetShowHint(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetWantEnterExitEvents(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetEnabled(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHint(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIconGuid(TGUID Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetIconVisible(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetImageURI(IString* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetLeftPopup(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPopupMenu(IPopupMenu* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetShowHint(BOOL Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetWantEnterExitEvents(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IVTColors;
	MIDL_INTERFACE("6CC01456-E23D-4423-AFA6-1AD23DBC4FFF")
	IVTColors: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetBorderColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDisabledColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDropMarkColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDropTargetBorderColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetDropTargetColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFocusedSelectionBorderColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetFocusedSelectionColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetGridLineColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeaderHotColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHotColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelectionRectangleBlendColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetSelectionRectangleBorderColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTreeLineColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetUnfocusedSelectionBorderColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetUnfocusedSelectionColor(TColor& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDisabledColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDropMarkColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDropTargetBorderColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDropTargetColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFocusedSelectionBorderColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFocusedSelectionColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetGridLineColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHeaderHotColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetHotColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelectionRectangleBlendColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetSelectionRectangleBorderColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetTreeLineColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetUnfocusedSelectionBorderColor(TColor Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetUnfocusedSelectionColor(TColor Value) = 0;

	};
	
	EXTERN_C const IID IID_IPage;
	MIDL_INTERFACE("B467FD3E-1B4C-43D4-93B3-BEA52B0D9B20")
	IPage: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetPageIndex(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageList(IPageList*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageVisible(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPageIndex(int Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPageList(IPageList* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetPageVisible(BOOL Value) = 0;

	};
	
	EXTERN_C const IID IID_IPageList;
	MIDL_INTERFACE("E9D469A9-873C-4E9D-B098-27E1A22A4F20")
	IPageList: public IWinControl
	{ public:
		virtual HRESULT STDMETHODCALLTYPE FindNextPage(IPage* APage, BOOL GoForward, BOOL CheckTabVisible, IPage*& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE SelectNextPage(BOOL GoForward, BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetActivePage(IPage*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetBorderDrawStyle(TBorderDrawStyle& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPageCount(int& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPage(int Index, IPage*& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetActivePage(IPage* Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetBorderDrawStyle(TBorderDrawStyle Value) = 0;

	};
	
	EXTERN_C const IID IID_IThemeServices;
	MIDL_INTERFACE("{69A9F64E-6FAE-4A96-A02F-2DEBC61326F6}")
	IThemeServices: public IObject
	{ public:
		virtual HRESULT STDMETHODCALLTYPE ContentRect(HDC DC, TThemedElementDetails Details, TRect BoundingRect, TRect& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE DrawEdge(HDC DC, TThemedElementDetails Details, TRect R, DWORD Edge, DWORD Flags, PRect ContentRect) = 0;
		virtual HRESULT STDMETHODCALLTYPE DrawElement(HDC DC, TThemedElementDetails Details, TRect R, PRect ClipRect) = 0;
		virtual HRESULT STDMETHODCALLTYPE DrawParentBackground(HWND Window, HDC Target, PThemedElementDetails Details, Boolean OnlyIfTransparent, PRect Bounds) = 0;
		virtual HRESULT STDMETHODCALLTYPE DrawText(HDC DC, TThemedElementDetails Details, IString* S, TRect R, DWORD Flags, DWORD Flags2) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails1(TThemedButton Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails2(TThemedClock Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails3(TThemedComboBox Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails4(TThemedEdit Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails5(TThemedExplorerBar Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails6(TThemedHeader Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails7(TThemedListView Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails8(TThemedMenu Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails9(TThemedPage Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails10(TThemedProgress Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails11(TThemedRebar Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails12(TThemedScrollBar Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails13(TThemedSpin Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails14(TThemedStartPanel Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails15(TThemedStatus Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails16(TThemedTab Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails17(TThemedTaskBand Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails18(TThemedTaskBar Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails19(TThemedToolBar Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails20(TThemedToolTip Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails21(TThemedTrackBar Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails22(TThemedTrayNotify Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails23(TThemedTreeview Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetElementDetails24(TThemedWindow Detail, TThemedElementDetails& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE HasTransparentParts(TThemedElementDetails Details, BOOL& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetTheme(TThemedElement Element, HTHEME& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetThemesAvailable(BOOL& Value) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetThemesEnabled(BOOL& Value) = 0;

	};
	


}//namespace qipns
