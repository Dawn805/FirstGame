// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_AITreeBeginAndEnd.h"

#include "EnemyCharacter.h"
#include "PaperZDAnimInstance.h"

void UNotify_AITreeBeginAndEnd::OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;

	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;
	EnemyCharacter->EndAI();
}

void UNotify_AITreeBeginAndEnd::OnNotifyEnd_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;

	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;
	EnemyCharacter->BeginAI();
}
