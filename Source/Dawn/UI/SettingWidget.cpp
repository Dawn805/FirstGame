// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingWidget.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void USettingWidget::ChangeKey(UInputMappingContext* MappingContext, UInputAction* TargetAction, FKey NewKey)
{
	if (!MappingContext || !TargetAction || !GetOwningPlayer()) return;

	ULocalPlayer* LocalPlayer = GetOwningPlayer()->GetLocalPlayer();
	if (!LocalPlayer) return;

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!InputSubsystem) return;

	const TArray<FEnhancedActionKeyMapping>& Mappings = MappingContext->GetMappings();

	TArray<FKey> KeysToRemove;
	
	for (int i = 0 ; i < Mappings.Num() ; i++)
	{
		if (Mappings[i].Action == TargetAction)
		{
			KeysToRemove.Add(Mappings[i].Key);
		}
	}

	for (int i = 0 ; i < KeysToRemove.Num() ; i++)
	{
		MappingContext->UnmapKey(TargetAction,KeysToRemove[i]);
	}

	MappingContext->MapKey(TargetAction,NewKey);

	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(MappingContext,0);
}

