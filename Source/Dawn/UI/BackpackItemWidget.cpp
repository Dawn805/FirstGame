// Fill out your copyright notice in the Description page of Project Settings.


#include "BackpackItemWidget.h"

#include "BackpackWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Dawn/MyPaperZDCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


void UBackpackItemWidget::SetItemWidget(FBackpackItems& Item,UBackpackComponent* InBackpack,UBackpackWidget* InBackpackWidget)
{
	//设置图标
	FSlateBrush Brush;
	Brush.SetResourceObject(Item.ItemIcon);
	ItemIcon->SetBrush(Brush);

	//设置数量
	ItemQuantity->SetText(FText::AsNumber(Item.ItemQuantity));

	FItem = Item;
	FBackpackComponent = InBackpack;
	FBackpackWidget = InBackpackWidget;
		
}

void UBackpackItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (MainButton)
		MainButton->OnClicked.AddDynamic(this,&UBackpackItemWidget::OnMainButtonClicked);
	if (UseButton)
		UseButton->OnClicked.AddDynamic(this,&UBackpackItemWidget::OnUseButtonClicked);
}


void UBackpackItemWidget::OnMainButtonClicked()
{
	if (UseButton)
	{
		UseButton->SetVisibility(ESlateVisibility::Visible);
	}
}

void UBackpackItemWidget::OnUseButtonClicked()
{
	UKismetSystemLibrary::PrintString(this,"11111111");
	if (FBackpackComponent)
	{
		FBackpackComponent->UseItem(FItem,1);
		if (FItem.ItemName == "HP_Potion")
		{
			AMyPaperZDCharacter* FCharacter = Cast<AMyPaperZDCharacter>(UGameplayStatics::GetPlayerPawn(this,0));
			if (FCharacter) FCharacter->HP += 50;
			if (FCharacter->HP > FCharacter->MaxHP) FCharacter->HP = FCharacter->MaxHP;
		}

		FBackpackWidget->RefreshBackpack();
	}
}

