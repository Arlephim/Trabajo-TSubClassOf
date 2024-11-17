// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_CPP_TrabajoGameMode.h"
#include "UTHUB_CPP_TrabajoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUTHUB_CPP_TrabajoGameMode::AUTHUB_CPP_TrabajoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
