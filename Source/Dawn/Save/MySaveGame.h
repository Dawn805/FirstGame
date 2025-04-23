// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Dawn/Component/BackpackComponent.h"
#include "MySaveGame.generated.h"

/**
 * 
 */



UCLASS()
class DAWN_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator PlayerRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBackpackItems> BackpackItems;
};

class AMyPaperZDCharacter;
void SavePlayerData(AMyPaperZDCharacter* Player);
void LoadPlayerData(AMyPaperZDCharacter* Player);