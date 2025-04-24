// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "LevelJump.generated.h"

UCLASS()
class DAWN_API ALevelJump : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Sets default values for this actor's properties
	ALevelJump();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperSpriteComponent* SpriteComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UBoxComponent* BoxComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName JumpLevelName = "No";
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName OldLevelName = "No";
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector NewLocation;
};
