// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_Locked.h"
#include "GameFramework/Character.h"
#include "PaperZDAnimInstance.h"
#include "MyPaperZDCharacter.h"

void UNotify_Locked::OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	ACharacter* Character = Cast<ACharacter>(OwningInstance->GetOwningActor());
	AMyPaperZDCharacter* MyCharacter = Cast<AMyPaperZDCharacter>(Character);
	if (MyCharacter)
	{
		MyCharacter->AnimRight = false;
	}
}

void UNotify_Locked::OnNotifyEnd_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	ACharacter* Character = Cast<ACharacter>(OwningInstance->GetOwningActor());
	AMyPaperZDCharacter* MyCharacter = Cast<AMyPaperZDCharacter>(Character);
	if (Character)
	{
		MyCharacter->AnimRight = true;
	}
	Super::OnNotifyEnd_Implementation(OwningInstance);
}

