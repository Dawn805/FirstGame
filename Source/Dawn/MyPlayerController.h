// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/PlayerStateWidget.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

private:
	void BroadCastMoveRight(float value);
	
	void BroadCastJump();

	void BroadCastAttack_U();

	void BroadCastOpenBackpack();

public:
	//PlayerStateUI
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UPlayerStateWidget> PlayerStateWidgetClass;
	//PlayerStateUI实例
	UPROPERTY()
	UPlayerStateWidget* PlayerStateWidgetInstance;

protected:
	void HandleMoveRight(float Value);
};
