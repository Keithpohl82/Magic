// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MPMagicGameMode.generated.h"

UCLASS(minimalapi)
class AMPMagicGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMPMagicGameMode();

	UFUNCTION(Exec)
	void SetCrosshair(int32 CrosshairIndex);
};



