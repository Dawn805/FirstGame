// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"


// Sets default values
AEnemyAIController::AEnemyAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	RunAI();
	//
	// AActor* Player = Cast<AActor>(GetWorld()->GetFirstPlayerController()->GetPawn());
	// if (Player)
	// {
	// 	MoveToPlayer(Player);
	// }
}

// Called every frame
void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// void AEnemyAIController::MoveToPlayer(AActor* Player)
// {
// 	if (Player)
// 	{
// 		MoveToActor(Player,10.0f);
// 	}
// }

void AEnemyAIController::RunAI()
{
	RunBehaviorTree(BehaviorTree);
}



