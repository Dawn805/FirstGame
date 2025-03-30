// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
class AMyPlayerController;
class AMyPaperZDCharacter;
#include "PlayerStateWidget.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UPlayerStateWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//每帧调用
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	//玩家的控制器
	UPROPERTY(Transient)
	AMyPlayerController* MainPlayerController = nullptr;
	//玩家
	UPROPERTY(Transient)
	AMyPaperZDCharacter* MainPaperZDCharacter;

	//血量进度条
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HPBar;

	//蓝
	UPROPERTY(meta = (BindWidget))
	UProgressBar* MPBar;





	

	
	// //生命的背景图片
	// UPROPERTY(BlueprintReadWrite,EditAnywhere,meta = (BindWidget))
	// UImage* HealthBackgroundImage;
	// //生命的图片
	// UPROPERTY(BlueprintReadWrite,EditAnywhere,meta = (BindWidget))
	// UImage* HealthImage;
	// //生命的进度条，ProgressBar->进度条
	// // UPROPERTY(BlueprintReadWrite,EditAnywhere,meta = (BindWidget))
	// // UProgressBar* HealthProgressBar;
	// //设置生命的最大宽度
	// UPROPERTY(BlueprintReadWrite,EditAnywhere)
	// float MaxHealthBarWidth = 200.0f;
	//
	// //蓝的背景图片
	// UPROPERTY(BlueprintReadWrite,EditAnywhere,meta = (BindWidget))
	// UImage* MagicBackgroundImage;
	// //蓝的图片
	// UPROPERTY(BlueprintReadWrite,EditAnywhere,meta = (BindWidget))
	// UImage* MagicImage;
	// //蓝的进度条
	// // UPROPERTY(BlueprintReadWrite,EditAnywhere,meta = (BindWidget))
	// // UProgressBar* MagicProgressBar;
	// //设置蓝的最大宽度
	// UPROPERTY(BlueprintReadWrite,EditAnywhere)
	// float MaxMagicBarWidth = 200.0f;

	//更新
	UFUNCTION(BlueprintCallable)
	void Update();
};
