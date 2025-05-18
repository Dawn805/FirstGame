// Fill out your copyright notice in the Description page of Project Settings.


#include "BackpackComponent.h"

//#include "IDetailTreeNode.h"


// Sets default values for this component's properties
UBackpackComponent::UBackpackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UBackpackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBackpackComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//检查背包物品是否存在图标，是否有收录过
int32 UBackpackComponent::HasItem(FBackpackItems NewItem)
{
	for (int i = 0 ; i < Item.Num() ; i++)
	{
		if (Item[i].ItemName == NewItem.ItemName)
		{
			return i;
		}
	}
	return 114514;
}

//添加物品
void UBackpackComponent::AddItem(FBackpackItems NewItem, int32 Number)
{
	int32 sub = HasItem(NewItem);
	if (sub != 114514)
	{
		Item[sub].ItemQuantity = Item[sub].ItemQuantity + Number;
		return;
	}
	Item.Add(NewItem);
}

//移除物品
void UBackpackComponent::RemoveItem(FBackpackItems NewItem)
{
	int32 sub = HasItem(NewItem);
	if (sub == 114514) return;
	if (Item[sub].ItemQuantity == 0)
	{
		Item.RemoveAt(sub);
	}
}

//使用物品
void UBackpackComponent::UseItem(FBackpackItems NewItem, int32 Number)
{
	int32 sub = HasItem(NewItem);
	if (sub == 114514) return;
	if (Number <= Item[sub].ItemQuantity)
	{
		Item[sub].ItemQuantity = Item[sub].ItemQuantity - Number;
	}
	if (Item[sub].ItemQuantity == 0)
	{
		Item.RemoveAt(sub);
	}
}




