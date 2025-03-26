// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimNotifyState.h"

#include "Notify_EnemyAttackDamage.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UNotify_EnemyAttackDamage : public UPaperZDAnimNotifyState
{
	GENERATED_BODY()
	
	void OnReceiveNotify_Implementation(UPaperZDAnimInstance* AnimInstance);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackDamge = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector BoxExtent = FVector(10,10,10);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor BoxColor = FColor::Red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SocketName = "No";
};
