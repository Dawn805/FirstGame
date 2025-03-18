// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimNotify.h"
#include "Notify_BoxAttack.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UNotify_BoxAttack : public UPaperZDAnimNotify
{
	GENERATED_BODY()

public:
	UNotify_BoxAttack();
	void OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance = nullptr) const;

protected:
	//伤害
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float AttackDamage = 1.0f;

	//攻击范围
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector BoxExtent = FVector(10.0f, 10.0f, 10.0f);

	//Box框框颜色
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FColor BoxColor = FColor::Red;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName SocketName = "No";
};
