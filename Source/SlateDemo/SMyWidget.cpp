// Fill out your copyright notice in the Description page of Project Settings.


#include "SMyWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Layout/SBackgroundBlur.h"
#include "MainHUD.h"

#define LOCTEXT_NAMESPACE "MyNamespace"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMyWidget::Construct(const FArguments& InArgs)
{

    OwnerHUD = InArgs._OwnerHUDArg;
    const FMargin ContentPadding = FMargin(500.0f, 300.0f);
    const FMargin ButtonPadding = FMargin(10.f);
    // 按钮和标题文本
    const FText TitleText = LOCTEXT("SlateTest", "Just a Slate Test");
    const FText PlayText = LOCTEXT("PlayGame", "Play");
    const FText QuitText = LOCTEXT("QuitGame", "Quit Game");
    //按钮字体及大小设置
    FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
    ButtonTextStyle.Size = 40.f;
    //标题字体及大小设置
    FSlateFontInfo TitleTextStyle = ButtonTextStyle;
    TitleTextStyle.Size = 60.f;
    ChildSlot
        [
            SNew(SOverlay)
            + SOverlay::Slot()
        .HAlign(HAlign_Fill).VAlign(VAlign_Fill)
        [
            SNew(SImage)	// 背景（半透明黑）
            .ColorAndOpacity(FColor(0, 0, 0, 127))
        ]

    + SOverlay::Slot()
        .HAlign(HAlign_Fill).VAlign(VAlign_Fill)
        [
            SNew(SBackgroundBlur) // 高斯模糊
            .BlurStrength(10.0f)
        ]

    + SOverlay::Slot()
        .HAlign(HAlign_Fill).VAlign(VAlign_Fill)
        .Padding(ContentPadding)
        [
            SNew(SVerticalBox)

            // Title Text
        + SVerticalBox::Slot()
        [
            SNew(STextBlock)
            .Font(TitleTextStyle)
        .Text(TitleText)
        .Justification(ETextJustify::Center)
        ]

    // Play Button
    + SVerticalBox::Slot()
        .Padding(ButtonPadding)
        [
            SNew(SButton)
            .OnClicked(this, &SMyWidget::OnPlayClicked)
        [
            SNew(STextBlock)
            .Font(ButtonTextStyle)
        .Text(PlayText)
        .Justification(ETextJustify::Center)
        ]
        ]

    // Quit Button
    + SVerticalBox::Slot()
        .Padding(ButtonPadding)
        [
            SNew(SButton)
            .OnClicked(this, &SMyWidget::OnQuitClicked)
        [
            SNew(STextBlock)
            .Font(ButtonTextStyle)
        .Text(QuitText)
        .Justification(ETextJustify::Center)
        ]
        ]
        ]
        ];
}

FReply SMyWidget::OnPlayClicked() const
{
    if (OwnerHUD.IsValid())
    {
        OwnerHUD->RemoveMySlate();
    }
    return FReply::Handled();
}

FReply SMyWidget::OnQuitClicked() const
{
    if (OwnerHUD.IsValid())
    {
        OwnerHUD->PlayerOwner->ConsoleCommand("quit");
    }
    return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
