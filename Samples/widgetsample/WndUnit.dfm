object Form1: TForm1
  Left = 617
  Top = 288
  Width = 400
  Height = 331
  Caption = '_Settings'
  Color = clBtnFace
  Constraints.MinHeight = 330
  Constraints.MinWidth = 400
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    384
    293)
  PixelsPerInch = 96
  TextHeight = 13
  object plPages: TInfuPageList
    Left = 5
    Top = 5
    Width = 373
    Height = 285
    ActivePage = InfuPage2
    Anchors = [akLeft, akTop, akRight, akBottom]
    object InfuPage1: TInfuPage
      Left = 2
      Top = 2
      Width = 369
      Height = 281
      Caption = 'InfuPage1'
      TabOrder = 0
      DesignSize = (
        365
        277)
      object btClose: TButton
        Left = 265
        Top = 244
        Width = 90
        Height = 25
        Caption = 'Close'
        ModalResult = 1
        TabOrder = 0
      end
      object vstTest: TVirtualStringTree
        Left = 10
        Top = 11
        Width = 346
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
    object InfuPage2: TInfuPage
      Left = 2
      Top = 2
      Width = 369
      Height = 281
      Caption = 'InfuPage2'
      TabOrder = 1
      DesignSize = (
        365
        277)
      object pbTestPaint: TPaintBox
        Left = 8
        Top = 8
        Width = 348
        Height = 57
        Anchors = [akLeft, akTop, akRight]
      end
      object sbTest: TSpeedButton
        Left = 152
        Top = 176
        Width = 89
        Height = 22
      end
      object btBack: TButton
        Left = 11
        Top = 242
        Width = 75
        Height = 25
        Anchors = [akLeft, akBottom]
        Caption = 'Back'
        TabOrder = 0
      end
      object btApply: TButton
        Left = 281
        Top = 240
        Width = 75
        Height = 25
        Anchors = [akRight, akBottom]
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
      end
    end
  end
  object Timer1: TTimer
    Left = 189
    Top = 141
  end
end
