// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMoveRightEvent,float,value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FJumpEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttack_U);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenBackpack);

/**
 * 
 */
UCLASS()
class DAWN_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	AMyGameMode();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Move")
	FMoveRightEvent MoveRightEvent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Jump")
	FJumpEvent JumpEvent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attack_U")
	FAttack_U Attack_U;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OpenBackpack")
	FOpenBackpack OpenBackpack;
};