// Fill out your copyright notice in the Description page of Project Settings.


#include "CrosshairManagerComponent.h"
#include "GameFramework/HUD.h"
#include "Engine/Texture2D.h"


// Sets default values for this component's properties
UCrosshairManagerComponent::UCrosshairManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCrosshairManagerComponent::BeginPlay()
{
	Super::BeginPlay();
    
	if (Crosshairs.Num() > 0)
	{
		CurrentCrosshair = Crosshairs[0];  // Default to the first crosshair
	}
	
}


// Called every frame
void UCrosshairManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCrosshairManagerComponent::ChangeCrosshair(int32 CrosshairIndex)
{
	if (Crosshairs.IsValidIndex(CrosshairIndex))
	{
		CurrentCrosshair = Crosshairs[CrosshairIndex];
		UE_LOG(LogTemp, Warning, TEXT("Crosshair changed to index: %d"), CrosshairIndex);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid crosshair index!"));
	}
}

