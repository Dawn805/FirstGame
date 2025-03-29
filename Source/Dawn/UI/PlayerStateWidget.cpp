// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerStateWidget.h"

#include "Components/Image.h"
#include "Dawn/MyPaperZDCharacter.h"
#include "Dawn/MyPlayerController.h"

void UPlayerStateWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	Update();
}

void UPlayerStateWidget::Update()
{
	if (!MainPlayerController)
	{
		return;
	}
	
	MainPaperZDCharacter = Cast<AMyPaperZDCharacter>(MainPlayerController->GetCharacter());

	if (!MainPaperZDCharacter)
	{
		return;
	}
	
	if (MainPlayerController)
	{
		//MainPaperZDCharacter = Cast<AMyPaperZDCharacter>(MainPlayerController->GetCharacter());
		
		//HealthProgressBar->SetPercent(MainPaperZDCharacter->HP/MainPaperZDCharacter->MaxHP);
		FVector2D NewSize1 = FVector2D(FMath::Clamp(MainPaperZDCharacter->HP / MainPaperZDCharacter->MaxHP, 0.0f, 1.0f) * MaxHealthBarWidth, HealthImage->GetDesiredSize().Y);
		HealthImage->SetDesiredSizeOverride(NewSize1);

		//MagicProgressBar->SetPercent(MainPaperZDCharacter->MP/MainPaperZDCharacter->MaxMP);
		FVector2D NewSize2 = FVector2D(FMath::Clamp(MainPaperZDCharacter->MP / MainPaperZDCharacter->MaxMP, 0.0f, 1.0f) * MaxMagicBarWidth, MagicImage->GetDesiredSize().Y);
		MagicImage->SetDesiredSizeOverride(NewSize2);
	}
}