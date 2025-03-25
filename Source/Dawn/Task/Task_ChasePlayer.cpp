// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_ChasePlayer.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Dawn/Enemy/EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UTask_ChasePlayer::UTask_ChasePlayer()
{
	NodeName = "Task_ChasePlayer";
}

EBTNodeResult::Type UTask_ChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AController = OwnerComp.GetAIOwner();
	if (!AController)
	{
		return EBTNodeResult::Failed;
	}

	APawn* AIPawn = AController->GetPawn();
	if (!AIPawn)
	{
		return EBTNodeResult::Failed;
	}

	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(AIPawn);
	if (EnemyCharacter)
	{
		EnemyCharacter->GetCharacterMovement()->MaxWalkSpeed = Velocity;
	}

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent)
	{
		return EBTNodeResult::Failed;
	}

	AActor* PlayerActor = Cast<AActor>(BlackboardComponent->GetValueAsObject("PlayerCharacter"));
	if (!PlayerActor)
	{
		return EBTNodeResult::Failed;
	}

	AController->MoveToActor(PlayerActor);

	return EBTNodeResult::Succeeded;
	
}
