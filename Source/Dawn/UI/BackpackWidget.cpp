// Fill out your copyright notice in the Description page of Project Settings.


#include "BackpackWidget.h"
#include "../MyPaperZDCharacter.h"
#include "IDetailTreeNode.h"

void UBackpackWidget::SetBackpack(AMyPaperZDCharacter* Character)
{
	if (Character)
	{
		Backpack = Character->Backpack;
		RefreshBackpack();
	}
}

void UBackpackWidget::RefreshBackpack()
{
	if (!Backpack || !GridPanel) return;
	GridPanel->ClearChildren();

	int32 h = 0,l = 0;
	
	for (int i = 0 ; i < Backpack->Item.Num() ; i++)
	{
		if (!ItemWidgetClass) return;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		if (ItemWidget)
		{
			//传递物品数据
			ItemWidget->SetItemWidget(Backpack->Item[i],Backpack);
			//添加到网格布局
			GridPanel->AddChildToUniformGrid(ItemWidget,h,l);
			h++;
			if (h >= 6)
			{
				h = 0;
				l++;
			}
		}
	}
}
