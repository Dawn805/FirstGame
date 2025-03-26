// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DAWN_API AEnemyCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Health;

	UFUNCTION()
	void MoveJump();


	UFUNCTION(BlueprintCallable,Category="Movement")
	void UpdateWalkSpeed(float NewWalkSpeed);


	UFUNCTION(BlueprintCallable)
	void HealthChange();

	UFUNCTION(BlueprintImplementableEvent)
	void HealthChange_PlayAnimation();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Health_sub;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool AnimRight = true;

	// UPROPERTY(EditAnywhere,BlueprintReadWrite)
	// UPaperFlipbookComponent *Flipbook;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool bIsInHurtState = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Attack = 10.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsAttacking = false;

	// UFUNCTION(BlueprintCallable,Category="Movement")
	// void UpdateFacing();
	//
	// UPROPERTY(BlueprintReadWrite,EditAnywhere)
	// FTimerHandle Time_UpdateFacing;
};
