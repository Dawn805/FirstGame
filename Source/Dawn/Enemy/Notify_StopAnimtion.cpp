// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_StopAnimtion.h"

#include "EnemyCharacter.h"
#include "PaperFlipbookComponent.h"
#include "PaperZDAnimInstance.h"

void UNotify_StopAnimtion::OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance)return;

	
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;
	if (!EnemyCharacter->GetSprite()) return;
	EnemyCharacter->GetSprite()->Stop();
}

