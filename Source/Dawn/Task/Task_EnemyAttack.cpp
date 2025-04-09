// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_EnemyAttack.h"

#include "AIController.h"
#include "AITestsCommon.h"
#include "AITestsCommon.h"
#include "EngineUtils.h"
#include "PaperZDAnimInstance.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Dawn/MyPaperZDCharacter.h"
#include "Dawn/Enemy/EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

UTask_EnemyAttack::UTask_EnemyAttack()
{
	NodeName = "EnemyAttack";
}

EBTNodeResult::Type UTask_EnemyAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) return EBTNodeResult::Failed;
	
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(AIController->GetPawn());
	if (!EnemyCharacter) return EBTNodeResult::Failed;
	
	UPaperZDAnimInstance* AnimInstance = EnemyCharacter->GetAnimInstance();
	if (!AnimInstance) return EBTNodeResult::Failed;
	
	AMyPaperZDCharacter* PlayerActor = nullptr;
	for (TActorIterator<AMyPaperZDCharacter> It(GetWorld());It;++It)
	{
		PlayerActor = *It;
		break;
	}
	if (!PlayerActor) return EBTNodeResult::Failed;
	
	float Distance = FVector::Dist(EnemyCharacter->GetActorLocation(),PlayerActor->GetActorLocation());
	Distance = FMath::Abs(Distance);

	// FVector ToPlayer = PlayerActor->GetActorLocation() - EnemyCharacter->GetActorLocation();
	// ToPlayer.Normalize();
	// FVector Forward = EnemyCharacter->GetActorForwardVector();
	// float Dot = FVector::DotProduct(Forward,ToPlayer);
	
	if (Distance <= AttackRange)
	{
		//UKismetSystemLibrary::PrintString(this,"YesAttack");
		AnimInstance->JumpToNode(AttackAnimNodeName,StateMachineName);
	}else
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::Succeeded;
}

