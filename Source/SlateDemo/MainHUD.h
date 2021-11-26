// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class SLATEDEMO_API AMainHUD : public AHUD
{
	GENERATED_BODY()
	public:
	AMainHUD(){}
	TSharedPtr<class SMyWidget> myWidget;
	void BeginPlay();
	TSharedPtr<SWidget> WidgetContainer;
	void RemoveMySlate();
	
};
