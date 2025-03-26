// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_RandomPatrol.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Dawn/Enemy/EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UTask_RandomPatrol::UTask_RandomPatrol()
{
	NodeName = "Random Patrol";
}

EBTNodeResult::Type UTask_RandomPatrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) return EBTNodeResult::Failed;

	APawn* AIPawn = AIController->GetPawn();
	if (!AIPawn) return EBTNodeResult::Failed;

	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(AIPawn);
	if (EnemyCharacter) EnemyCharacter->GetCharacterMovement()->MaxWalkSpeed = PatrolSpeed;

	FVector EnemyOrigin = EnemyCharacter->GetActorLocation();

	UNavigationSystemV1* Navsys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (!Navsys) return EBTNodeResult::Failed;

	FNavLocation RandomLocation;
	bool bFound = Navsys->GetRandomReachablePointInRadius(EnemyOrigin, PatrolRadius, RandomLocation);

	if (bFound)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(PatrolLoaction.SelectedKeyName,RandomLocation.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;

}