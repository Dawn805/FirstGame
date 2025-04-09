// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/PlayerStateWidget.h"
#include "UI/SettingWidget.h"

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


public:
	// void BroadCastMoveRight(float value);
	// void BroadCastJump();
	// void BroadCastAttack_U();
	// void BroadCastOpenBackpack();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInputAction* MoveRightAction;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInputAction* Attack_UAction;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInputAction* OpenBackpackAction;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInputAction* OpenSettingAction;

	void BroadCastMoveRight(const struct FInputActionInstance& Instance);
	void BroadCastJump(const struct FInputActionInstance& Instance);
	void BroadCastAttack_U(const struct FInputActionInstance& Instance);
	void BroadCastOpenBackpack(const struct FInputActionInstance& Instance);
	void OpenSettingUI(const struct FInputActionInstance& Instance);
	
	


	//PlayerStateUI
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UPlayerStateWidget> PlayerStateWidgetClass;
	//PlayerStateUI实例
	UPROPERTY()
	UPlayerStateWidget* PlayerStateWidgetInstance;


	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class USettingWidget> SettingWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USettingWidget* SettingWidgetInstance;


protected:
	void HandleMoveRight(float Value);
};
