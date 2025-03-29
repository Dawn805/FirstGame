// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_bIsInAttack.h"

#include "EnemyCharacter.h"
#include "PaperZDAnimInstance.h"

void UNotify_bIsInAttack::OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;

	EnemyCharacter->bIsInAttack = true;
}

void UNotify_bIsInAttack::OnNotifyEnd_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;

	EnemyCharacter->bIsInAttack = false;
}

