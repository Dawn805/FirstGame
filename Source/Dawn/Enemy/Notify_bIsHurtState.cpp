// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_bIsHurtState.h"

#include "EnemyCharacter.h"
#include "PaperZDAnimInstance.h"
#include "GameFramework/Character.h"

void UNotify_bIsHurtState::OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	
	ACharacter* FCharacter = Cast<ACharacter>(OwningInstance->GetOwningActor());
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(FCharacter);
	if (EnemyCharacter)
	{
		EnemyCharacter->bIsInHurtState = true;
	}
}

