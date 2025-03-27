// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_EnemyNoMove.h"

#include "EnemyCharacter.h"
#include "PaperZDAnimInstance.h"
#include "Dawn/MyPaperZDCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UNotify_EnemyNoMove::OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;
	EnemyCharacter->GetCharacterMovement()->DisableMovement();
}

void UNotify_EnemyNoMove::OnNotifyEnd_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningInstance->GetPaperCharacter());
	if (!EnemyCharacter) return;
	EnemyCharacter->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}

