// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Dawn/MyPaperZDCharacter.h"
#include "Dawn/MyPlayerController.h"
#include "Kismet/GameplayStatics.h"


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

	APlayerController *PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
	AMyPlayerController *MyPlayerController = Cast<AMyPlayerController>(PlayerController);
	if (MyPlayerController)
	{
		ACharacter *FCharacter = MyPlayerController->GetCharacter();
		AMyPaperZDCharacter *PlayerCharacter = Cast<AMyPaperZDCharacter>(FCharacter);
		if (PlayerCharacter)
		{
			UBlackboardComponent *BlackboardComponent = GetBlackboardComponent();
			if (BlackboardComponent)
			{
				BlackboardComponent->SetValueAsObject("PlayerCharacter",PlayerCharacter);
			}
		}
	}
	
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



