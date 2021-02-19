// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstCppGameMode.h"
#include "FirstCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirstCppGameMode::AFirstCppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
