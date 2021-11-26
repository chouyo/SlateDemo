// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateDemoGameMode.h"
#include "SlateDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASlateDemoGameMode::ASlateDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
