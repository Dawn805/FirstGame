// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_AIEnd.h"

#include "EnemyCharacter.h"
#include "PaperZDAnimInstance.h"

void UNotify_AIEnd::OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;

	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;
	EnemyCharacter->EndAI();
}
