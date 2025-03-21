// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Dawn/Component/BackpackComponent.h"
#include "BackpackItemWidget.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class DAWN_API UBackpackItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//物品的图标
	UPROPERTY(meta = (BindWidget))
	UImage* ItemIcon;
	//物品的数量/放在右下角
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemQuantity;

	//设置UI
	UFUNCTION(BlueprintCallable)
	void SetItemWidget(FBackpackItems& Item);
};
