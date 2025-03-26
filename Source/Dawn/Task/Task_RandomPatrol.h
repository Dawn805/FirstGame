// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Task_RandomPatrol.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DAWN_API UTask_RandomPatrol : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTask_RandomPatrol();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float PatrolRadius = 1000.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FBlackboardKeySelector PatrolLoaction;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float PatrolSpeed = 10.0f;
};
