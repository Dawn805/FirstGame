// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class DAWN_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName ItemName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 ItemQuantity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* ItemIcon;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperSpriteComponent* ItemSprite;

	
};
