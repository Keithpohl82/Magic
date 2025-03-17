// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "CrosshairManagerComponent.h"
#include "MPMagicCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AMPMagicCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PrimarySkillAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SecondarySkillAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PrimarySpellAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SecondarySpellAction;
	
public:
	AMPMagicCharacter();

	UPROPERTY(EditAnywhere, Category = Power)
	int PowerMultiplier;
	UPROPERTY(EditAnywhere, Category = Power)
	float Health;
	UPROPERTY(EditAnywhere, Category = Power)
	float Armor;

	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crosshair")
	class UCrosshairManagerComponent* CrosshairManager;
	
	UPROPERTY(EditAnywhere, Category = Movement)
	float DashDistance;
	UPROPERTY(EditAnywhere, Category = Movement)
	float DashSpeed;

	
	UPROPERTY(EditDefaultsOnly, Category = Combat)
	TSubclassOf<class AProjectile> PrimaryProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
	TSubclassOf<class AProjectile> SecondaryProjectileClass;

	
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// Shift key
	void Dash();
	void ResetDash();
	FTimerHandle DashTimerHandle;
	bool bCanDash = true;
	UPROPERTY(EditAnywhere, Category = Dash)
	float DashCooldownTime = 2.0f;
	// Left Mouse Button
	void FirePrimarySkill();
	UPROPERTY(EditAnywhere, Category = Skills)
	float PrimarySkillCooldown = 2.0f;
	//Right Mouse Button
	void FireSecondarySkill();
	UPROPERTY(EditAnywhere, Category = Skills)
	float SecondarySkillCooldown = 2.0f;
	// Q Button
	void CastPrimarySpell();
	UPROPERTY(EditAnywhere, Category = Spells)
	float PrimarySpellCooldown = 2.0f;
	// E Button
	void CastSecondarySpell();
	UPROPERTY(EditAnywhere, Category = Spells)
	float SecondarySpellCooldown = 2.0f;
	

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};







