// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimNotify.h"

#include "Notify_AIEnd.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UNotify_AIEnd : public UPaperZDAnimNotify
{
	GENERATED_BODY()

public:
	virtual void OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance = nullptr) const override;
	
};
