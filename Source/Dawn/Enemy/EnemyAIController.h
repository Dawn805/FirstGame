// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

UCLASS()
class DAWN_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyAIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// UFUNCTION(BlueprintCallable)
	// void MoveToPlayer(AActor *Player);

	// UFUNCTION(BlueprintImplementableEvent)
	// void Death();


public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	UBehaviorTree* BehaviorTree;

	UFUNCTION()
	void RunAI();
};
