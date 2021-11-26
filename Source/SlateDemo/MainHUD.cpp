// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include "SMyWidget.h"
#include "Widgets/SWeakWidget.h"

void AMainHUD::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine && GEngine->GameViewport)
    {
        myWidget = SNew(SMyWidget).OwnerHUDArg(this);
        GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget).PossiblyNullContent(myWidget.ToSharedRef()), 0);

//         APlayerController* PC = UGameplayStatics::GetPlayerController(GetWord(), 0);
//         if (PC)
//         {
//             PC->bShowMouseCursor = true;
//             PC->SetInputMode(FInputModeUIOnly());
//         }
    }
}

void AMainHUD::RemoveMySlate()
{
    if (GEngine && GEngine->GameViewport && WidgetContainer.IsValid())
    {
        // 移除添加视口方法一
        GEngine->GameViewport->RemoveViewportWidgetContent(myWidget.ToSharedRef());

        // 移除添加视口方法三
        GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());
    }
}
