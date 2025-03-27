// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Task_EnemyAttack.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UTask_EnemyAttack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTask_EnemyAttack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName AttackAnimNodeName = "Attack";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName StateMachineName = "Orc_Locomotion";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackRange = 100.0f;
};
