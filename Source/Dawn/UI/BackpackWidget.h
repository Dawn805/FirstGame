// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Component/BackpackComponent.h"
class AMyPaperZDCharacter;

#include "CoreMinimal.h"
#include "BackpackItemWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "BackpackWidget.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UBackpackWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//绑定背包组件
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBackpackComponent* Backpack;

	//引用背包组件
	UFUNCTION(BlueprintCallable)
	void SetBackpack(AMyPaperZDCharacter* Character);

	//这是物品的格子
	UPROPERTY(meta=(BindWidget))
	UUniformGridPanel* GridPanel;

	//生成物品的格子
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<UBackpackItemWidget> ItemWidgetClass;

	//刷新UI
	UFUNCTION(BlueprintCallable)
	void RefreshBackpack();
};
