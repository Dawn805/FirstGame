// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimNotify.h"
#include "Notify_StopAnimtion.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UNotify_StopAnimtion : public UPaperZDAnimNotify
{
	GENERATED_BODY()

public:
	virtual void OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance = nullptr) const override;
};
