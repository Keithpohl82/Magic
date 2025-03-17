// Copyright Epic Games, Inc. All Rights Reserved.

#include "MPMagicGameMode.h"
#include "MPMagicCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMPMagicGameMode::AMPMagicGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMPMagicGameMode::SetCrosshair(int32 CrosshairIndex)
{
	AMPMagicCharacter* Player = Cast<AMPMagicCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player && Player->CrosshairManager)
	{
		Player->CrosshairManager->ChangeCrosshair(CrosshairIndex);
	}
}
