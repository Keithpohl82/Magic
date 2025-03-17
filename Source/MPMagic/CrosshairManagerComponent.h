// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CrosshairManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MPMAGIC_API UCrosshairManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCrosshairManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	                           
	UFUNCTION(Exec)
	void ChangeCrosshair(int32 CrosshairIndex);

	UPROPERTY(EditAnywhere, Category = "Crosshair")
	TArray<UTexture2D*> Crosshairs;

	UPROPERTY(EditAnywhere, Category = "Crosshair")
	UTexture2D* CurrentCrosshair;
};
