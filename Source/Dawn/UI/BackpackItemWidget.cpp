// Fill out your copyright notice in the Description page of Project Settings.


#include "BackpackItemWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"


void UBackpackItemWidget::SetItemWidget(FBackpackItems& Item)
{
		//设置图标
		FSlateBrush Brush;
		Brush.SetResourceObject(Item.ItemIcon);
		ItemIcon->SetBrush(Brush);

		//设置数量
		ItemQuantity->SetText(FText::AsNumber(Item.ItemQuantity));

}
