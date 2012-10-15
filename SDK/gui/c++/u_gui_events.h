namespace qipns {
	EXTERN_C const IID IID_IShowEvents;
	MIDL_INTERFACE("14690BC7-D6EB-450A-8A9C-08E6354DFF6B")
	IShowEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE DidShow(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE DidHide(IUnknown* Sender) = 0;
	};

	EXTERN_C const IID IID_IMouseClickEvents;
	MIDL_INTERFACE("F14A66EC-E252-48C7-A75B-DD17EDFF1A3A")
	IMouseClickEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Click(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE DblClick(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE MouseDown(IUnknown* Sender, TMouseButton Button, TShiftState Shift, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE MouseUp(IUnknown* Sender, TMouseButton Button, TShiftState Shift, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE UpDownClick(IUnknown* Sender, TUDBtnType Button) = 0;
	};

	EXTERN_C const IID IID_IMouseMoveEvents;
	MIDL_INTERFACE("D140A167-0A85-41C0-9783-EEBDAB0C05A0")
	IMouseMoveEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE MouseMove(IUnknown* Sender, TShiftState Shift, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE MouseEnter(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE MouseLeave(IUnknown* Sender) = 0;
	};

	EXTERN_C const IID IID_IMouseWheelEvents;
	MIDL_INTERFACE("7D359A35-7C7F-4A77-A84A-2FAD29E1D38A")
	IMouseWheelEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE MouseWheel(IUnknown* Sender, TShiftState Shift, int WheelDelta, TPoint MousePos, BOOL& Handled) = 0;
		virtual HRESULT STDMETHODCALLTYPE MouseWheelUp(IUnknown* Sender, TShiftState Shift, TPoint MousePos, BOOL& Handled) = 0;
		virtual HRESULT STDMETHODCALLTYPE MouseWheelDown(IUnknown* Sender, TShiftState Shift, TPoint MousePos, BOOL& Handled) = 0;
		virtual HRESULT STDMETHODCALLTYPE DidScroll(IUnknown* Sender, int DeltaX, int DeltaY) = 0;
	};

	EXTERN_C const IID IID_IKeyboardEvents;
	MIDL_INTERFACE("A6C4ADAD-84A1-4ABF-8054-B18FCBE34625")
	IKeyboardEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE DidEnter(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE DidExit(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE KeyUp(IUnknown* Sender, Word& Key, TShiftState Shift) = 0;
		virtual HRESULT STDMETHODCALLTYPE KeyDown(IUnknown* Sender, Word& Key, TShiftState Shift) = 0;
		virtual HRESULT STDMETHODCALLTYPE KeyPress(IUnknown* Sender, char& Key) = 0;
	};

	EXTERN_C const IID IID_ISizeMoveEvents;
	MIDL_INTERFACE("5A3B8000-CAF9-45EA-88D8-0CB3711E77BC")
	ISizeMoveEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE CanResize(IUnknown* Sender, int& NewWidth, int& NewHeight, BOOL& Resize) = 0;
		virtual HRESULT STDMETHODCALLTYPE Resized(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE Moved(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE AlignControls(IUnknown* Sender, IControl* Control, int& NewLeft, int& NewTop, int& NewWidth, int& NewHeight, TRect& AlignRect) = 0;
	};

	EXTERN_C const IID IID_IWindowEvents;
	MIDL_INTERFACE("BAAEDC05-A20B-4384-8AF0-91619971D913")
	IWindowEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Activated(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE Closed(IUnknown* Sender, TCloseAction& Action) = 0;
		virtual HRESULT STDMETHODCALLTYPE CloseQuery(IUnknown* Sender, BOOL& CanClose) = 0;
		virtual HRESULT STDMETHODCALLTYPE Created(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE Destroyed(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE Deactivated(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE PropertyChanged(IUnknown* Sender, IComponent* component) = 0;
	};

	EXTERN_C const IID IID_IPaintEvents;
	MIDL_INTERFACE("82B1CCF9-289D-44C3-80A3-1452BBE66CA9")
	IPaintEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Paint(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE ToolBarCustomDraw(IToolBar* Sender, TRect ARect, BOOL& DefaultDraw) = 0;
		virtual HRESULT STDMETHODCALLTYPE ToolBarCustomDrawButton(IToolBar* Sender, IToolButton* Button, TCustomDrawState State, BOOL& DefaultDraw) = 0;
		virtual HRESULT STDMETHODCALLTYPE ListDrawItem(IWinControl* Control, int Index, TRect Rect, TOwnerDrawState State, BOOL& DefaultDraw) = 0;
		virtual HRESULT STDMETHODCALLTYPE MenuItemDrawItem(IUnknown* Sender, ICanvas* ACanvas, TRect ARect, TOwnerDrawState State, BOOL& DefaultDraw) = 0;
	};

	EXTERN_C const IID IID_IChangeEvents;
	MIDL_INTERFACE("F671DA01-9D73-400D-9F4D-AFA58535FEFC")
	IChangeEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE Changed(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE Changing(IUnknown* Sender, BOOL& AllowChange) = 0;
		virtual HRESULT STDMETHODCALLTYPE ChangingEx(IUnknown* Sender, BOOL& AllowChange, SmallInt NewValue, TUpDownDirection Direction) = 0;
		virtual HRESULT STDMETHODCALLTYPE SelectionChange(IUnknown* Sender) = 0;
	};

	EXTERN_C const IID IID_ITimerEvents;
	MIDL_INTERFACE("DA8209ED-90E7-4969-827A-2CA92686A932")
	ITimerEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE DidTimer(IUnknown* Sender) = 0;
	};
  
	EXTERN_C const IID IID_IListEvents;
	MIDL_INTERFACE("F7A3548E-E7B9-4F43-8517-F1EA155EAA0E")
	IListEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE ListSelect(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE DropDown(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE CloseUp(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE MeasureItem(IWinControl* Control, int Index, int& Height) = 0;
	};

	EXTERN_C const IID IID_IMenuEvents;
	MIDL_INTERFACE("439ECB64-AC07-49EB-B7A7-E6F6DE8836F2")
	IMenuEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE DidPopup(IUnknown* Sender) = 0;
		virtual HRESULT STDMETHODCALLTYPE ContextPopup(IUnknown* Sender, TPoint MousePos, BOOL& Handled) = 0;
		virtual HRESULT STDMETHODCALLTYPE MeasureItem(IUnknown* Sender, ICanvas* ACanvas, int& Width, int& Height) = 0;
	};

	EXTERN_C const IID IID_IGuiEvents;
	MIDL_INTERFACE("F82FE796-2C24-40A9-BBF3-E749F091FD41")
	IGuiEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE LanguageChanged(IString* NewLangName) = 0;
		virtual HRESULT STDMETHODCALLTYPE SkinChanged(IString* NewSkinName) = 0;
		virtual HRESULT STDMETHODCALLTYPE AntiBossChanged(BOOL Activated) = 0;
		virtual HRESULT STDMETHODCALLTYPE FreeNotify(IComponent* Sender) = 0;
	};

	EXTERN_C const IID IID_ITreePaintEvents;
	MIDL_INTERFACE("74305798-08D2-4247-9657-7ED85E67E944")
	ITreePaintEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE AdvancedHeaderDraw(ITreeHeader* Sender, THeaderPaintInfo& PaintInfo, THeaderPaintElements Elements) = 0;
    //after draw
		virtual HRESULT STDMETHODCALLTYPE AfterCellPaint(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TColumnIndex Column, TRect CellRect) = 0;
		virtual HRESULT STDMETHODCALLTYPE AfterItemErase(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TRect ItemRect) = 0;
		virtual HRESULT STDMETHODCALLTYPE AfterItemPaint(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TRect ItemRect) = 0;
		virtual HRESULT STDMETHODCALLTYPE AfterPaint(IUnknown* Sender, ICanvas* TargetCanvas) = 0;
    //before draw
		virtual HRESULT STDMETHODCALLTYPE BeforeCellPaint(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TColumnIndex Column, TRect CellRect) = 0;
		virtual HRESULT STDMETHODCALLTYPE BeforeItemErase(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TRect ItemRect, TColor& ItemColor, TItemEraseAction& EraseAction) = 0;
		virtual HRESULT STDMETHODCALLTYPE BeforeItemPaint(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TRect ItemRect, BOOL& CustomDraw) = 0;
		virtual HRESULT STDMETHODCALLTYPE BeforePaint(IUnknown* Sender, ICanvas* TargetCanvas) = 0;
    //header drawing
		virtual HRESULT STDMETHODCALLTYPE HeaderDraw(ITreeHeader* Sender, ICanvas* HeaderCanvas, ITreeColumn* Column, TRect R, BOOL Hover, BOOL Pressed, TVTDropMarkMode DropMark) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderDrawQueryElements(ITreeHeader* Sender, THeaderPaintInfo& PaintInfo, THeaderPaintElements Elements) = 0;
    //tree painting
		virtual HRESULT STDMETHODCALLTYPE PaintBackground(IUnknown* Sender, ICanvas* TargetCanvas, TRect R, BOOL& Handled) = 0;
		virtual HRESULT STDMETHODCALLTYPE PaintText(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType) = 0;
	};

	EXTERN_C const IID IID_ITreeEditingEvents;
	MIDL_INTERFACE("94AE8409-112A-49A4-89B5-5988FD8913DB")
	ITreeEditingEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE DidNewText(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column, IString* NewText) = 0;
		virtual HRESULT STDMETHODCALLTYPE EditCancelled(IUnknown* Sender, TColumnIndex Column) = 0;
		virtual HRESULT STDMETHODCALLTYPE Edited(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column) = 0;
		virtual HRESULT STDMETHODCALLTYPE Editing(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column, BOOL& Allowed) = 0;
	};

	EXTERN_C const IID IID_INodeStateEvents;
	MIDL_INTERFACE("95843979-501F-4E0D-B10E-BBD74FFDBF48")
	INodeStateEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE NodeChecked(IUnknown* Sender, PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeChecking(IUnknown* Sender, PVirtualNode Node, TCheckState& NewState, BOOL& Allowed) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeCollapsed(IUnknown* Sender, PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeCollapsing(IUnknown* Sender, PVirtualNode Node, BOOL& Allowed) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeExpanded(IUnknown* Sender, PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeExpanding(IUnknown* Sender, PVirtualNode Node, BOOL& Allowed) = 0;
	};

	EXTERN_C const IID IID_INodeChangeEvents;
	MIDL_INTERFACE("0D2CED26-FB58-4C03-B9FD-BEC9595C53DE")
	INodeChangeEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE NodeChanged(IUnknown* Sender, PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeFocusChanged(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeFocusChanging(IUnknown* Sender, PVirtualNode OldNode, PVirtualNode NewNode, TColumnIndex OldColumn, TColumnIndex NewColumn, BOOL& Allowed) = 0;
		virtual HRESULT STDMETHODCALLTYPE NodeHotChange(IUnknown* Sender, PVirtualNode OldNode, PVirtualNode NewNode) = 0;
	};

	EXTERN_C const IID IID_INodeControlEvents;
	MIDL_INTERFACE("2EB783D9-A3BB-434E-9F0F-FB82DFD0CD42")
	INodeControlEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE CompareNodes(IUnknown* Sender, PVirtualNode Node1, PVirtualNode Node2, TColumnIndex Column, int& Result) = 0;
		virtual HRESULT STDMETHODCALLTYPE DidInitNode(IUnknown* Sender, PVirtualNode Node, TVirtualNodeInitStates& InitialStates) = 0;
		virtual HRESULT STDMETHODCALLTYPE DidFreeNode(IUnknown* Sender, PVirtualNode Node) = 0;
		virtual HRESULT STDMETHODCALLTYPE IncrementalSearch(IUnknown* Sender, PVirtualNode Node, IString* SearchText, int& Result, BOOL& Handled) = 0;

		virtual HRESULT STDMETHODCALLTYPE NodeMeasureItem(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, int& NodeHeight) = 0;

		virtual HRESULT STDMETHODCALLTYPE ShortenString(IUnknown* Sender, ICanvas* TargetCanvas, PVirtualNode Node, TColumnIndex Column, IString* S, int TextSpace, IString*& Result, BOOL& Done) = 0;
	};

	EXTERN_C const IID IID_ITreeColumnEvents;
	MIDL_INTERFACE("615CC572-247D-4FA5-B048-2EAE63CFED84")
	ITreeColumnEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE ColumnClicked(IUnknown* Sender, TColumnIndex Column, TShiftState Shift) = 0;
		virtual HRESULT STDMETHODCALLTYPE ColumnDblClicked(IUnknown* Sender, TColumnIndex Column, TShiftState Shift) = 0;
		virtual HRESULT STDMETHODCALLTYPE ColumnResized(ITreeHeader* Sender, TColumnIndex Column) = 0;
	};

	EXTERN_C const IID IID_ITreeHeaderEvents;
	MIDL_INTERFACE("B5E66C19-3AF0-4415-8A8A-90C56A6B5941")
	ITreeHeaderEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE HeaderClicked(ITreeHeader* Sender, TColumnIndex Column, TMouseButton Button, TShiftState Shift, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderDblClicked(ITreeHeader* Sender, TColumnIndex Column, TMouseButton Button, TShiftState Shift, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderDragged(ITreeHeader* Sender, TColumnIndex Column, int OldPosition) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderDraggedOut(ITreeHeader* Sender, TColumnIndex Column, TPoint DropPosition) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderDragging(ITreeHeader* Sender, TColumnIndex Column, BOOL& Allowed) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderMouseDown(ITreeHeader* Sender, TMouseButton Button, TShiftState Shift, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderMouseMove(ITreeHeader* Sender, TShiftState Shift, int X, int Y) = 0;
		virtual HRESULT STDMETHODCALLTYPE HeaderMouseUp(ITreeHeader* Sender, TMouseButton Button, TShiftState Shift, int X, int Y) = 0;
	};

    EXTERN_C const IID IID_ITreeGetEvents;
	MIDL_INTERFACE("C69943E0-46AC-4999-83AE-2AFAAF48439A")
	ITreeGetEvents: public IUnknown
	{ public:
		virtual HRESULT STDMETHODCALLTYPE GetCellIsEmpty(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column, BOOL& IsEmpty) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetCursor(IUnknown* Sender, TCursor& Cursor) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHeaderCursor(IUnknown* Sender, HICON& Cursor) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHint(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column, TTooltipLineBreakStyle& LineBreakStyle, IString*& HintText) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetPopupMenu(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column, TPoint* P, BOOL& AskParent, IPopupMenu*& PopupMenu) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetText(IUnknown* Sender, PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType, IString*& Text) = 0;
	};
}
