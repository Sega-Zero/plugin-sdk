object InfuForm: TInfuForm
  Left = 617
  Top = 288
  Width = 399
  Height = 331
  Caption = '_Settings'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object plPages: TInfuPageList
    Anchors = [akLeft,akTop,akRight,akBottom]
    Left = 5
    Top = 5
    Width = 372
    Height = 285
    ActivePage = InfuPage1
    object InfuPage2: TInfuPage
      Left = 2
      Top = 2
      Width = 368
      Height = 281
      Caption = 'InfuPage2'
      TabOrder = 1
      object pbTestPaint: TPaintBox
	    Anchors = [akLeft,akTop,akRight]
        Left = 8
        Top = 8
        Width = 347
        Height = 57		
      end
      object sbTest: TSpeedButton
        Left = 152
        Top = 176
        Width = 89
        Height = 22
      end
      object btBack: TButton
	    Anchors = [akLeft, akBottom]
        Left = 11
        Top = 242
        Width = 75
        Height = 25
        Caption = 'Back'
        TabOrder = 0
      end
      object btApply: TButton
        Left = 280
        Top = 240
        Width = 75
        Height = 25
        Caption = 'Apply'
        Enabled = False
        TabOrder = 1
      end
      object cbCheck: TCheckBox
        Left = 16
        Top = 80
        Width = 97
        Height = 17
        Caption = 'cbCheck'
        TabOrder = 2
      end
      object RadioButton1: TRadioButton
        Left = 16
        Top = 112
        Width = 113
        Height = 17
        Caption = 'RadioButton1'
        Checked = True
        TabOrder = 3
        TabStop = True
      end
      object RadioButton2: TRadioButton
        Left = 16
        Top = 136
        Width = 113
        Height = 17
        Caption = 'RadioButton2'
        TabOrder = 4
      end
      object RadioGroup1: TRadioGroup
        Left = 128
        Top = 80
        Width = 113
        Height = 73
        Caption = 'RadioGroup1'
        Items.Strings = (
          'item1'
          'item2')
        TabOrder = 5
      end
      object edTest: TEdit
        Left = 16
        Top = 176
        Width = 121
        Height = 21
        TabOrder = 6
        Text = ''
      end
    end
    object InfuPage1: TInfuPage
      Left = 2
      Top = 2
      Width = 368
      Height = 281
      Caption = 'InfuPage1'
      TabOrder = 0
      DesignSize = (
        364
        277)
      object btClose: TButton
	    Anchors = [akBottom, akRight]
        Left = 265
        Top = 244
        Width = 90
        Height = 25
        Caption = 'Close'
        ModalResult = 1
        TabOrder = 0
      end
      object vstTest: TVirtualStringTree
	    Anchors = [akLeft, akTop, akBottom, akRight]
        Left = 10
        Top = 11
        Width = 345
        Height = 222
        Anchors = [akLeft, akTop, akRight, akBottom]
        DefaultNodeHeight = 40
        Header.AutoSizeIndex = 0
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'Tahoma'
        Header.Font.Style = []
        Header.MainColumn = -1
        Header.Options = [hoColumnResize, hoDrag]
        TabOrder = 1
        TabStop = False
        TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toShowButtons, toShowDropmark, toShowHorzGridLines, toThemeAware, toUseBlendedImages, toAlwaysHideSelection]
        TreeOptions.SelectionOptions = [toFullRowSelect]
        Columns = <>
        WideDefaultText = ''
      end
    end
  end
  object Timer1: TTimer
    Left = 327
    Top = 23
  end
end
