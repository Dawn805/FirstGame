// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "RestPoint.generated.h"

UCLASS()
class DAWN_API ARestPoint : public AActor
{
	GENERATED_BODY()

public:
	void OnBoxBeginOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult);
	void OnBoxEndOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I);
	// Sets default values for this actor's properties
	ARestPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperSpriteComponent* SpriteComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBoxComponent* BoxComp;

	// UPROPERTY()
	// bool bIsOverlapping = false;
	
};
