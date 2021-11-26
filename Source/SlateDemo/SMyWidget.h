// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MainHUD.h"

/**
 * 
 */
class SLATEDEMO_API SMyWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMyWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainHUD>, OwnerHUDArg);
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
    FReply OnPlayClicked() const;
    FReply OnQuitClicked() const;

private:
	TWeakObjectPtr<AMainHUD> OwnerHUD;
};
