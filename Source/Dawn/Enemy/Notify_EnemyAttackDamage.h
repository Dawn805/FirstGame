// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimNotify.h"

#include "Notify_EnemyAttackDamage.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UNotify_EnemyAttackDamage : public UPaperZDAnimNotify
{
	GENERATED_BODY()
	
	void OnReceiveNotify_Implementation(UPaperZDAnimInstance* AnimInstance) const;

public:
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// float AttackDamge = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector BoxExtent = FVector(10,10,10);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor BoxColor = FColor::Red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SocketName = "No";
};
