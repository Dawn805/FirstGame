// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BackpackComponent.generated.h"


//定义背包物品
USTRUCT(BlueprintType)
struct FBackpackItems
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName ItemName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 ItemQuantity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* ItemIcon;
	
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DAWN_API UBackpackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBackpackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

public:
	//添加物品
	UFUNCTION(BlueprintCallable)
	void AddItem(FBackpackItems NewItem,int32 Number);
	//移除物品
	UFUNCTION(BlueprintCallable)
	void RemoveItem(FBackpackItems NewItem);
	//使用物品
	UFUNCTION(BlueprintCallable)
	void UseItem(FBackpackItems NewItem,int32 Number);
	//检查物品是否存在
	UFUNCTION(BlueprintCallable)
	int32 HasItem(FBackpackItems NewItem);

public:
	//这是背包的数组
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FBackpackItems> Item;
};

