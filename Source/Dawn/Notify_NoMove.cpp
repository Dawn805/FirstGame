// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_NoMove.h"
#include "PaperZDAnimNotify.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperZDAnimInstance.h" 

void UNotify_NoMove::OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;

	ACharacter* Character = Cast<ACharacter>(OwningInstance->GetOwningActor());

	FVector Velocity = Character->GetVelocity();
	
	if (Character && Character->GetCharacterMovement() && Velocity.Z == 0.0f)
	{
		Character->GetCharacterMovement()->DisableMovement();
	}
}

void UNotify_NoMove::OnNotifyEnd_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (!OwningInstance) return;
	
	ACharacter* Character = Cast<ACharacter>(OwningInstance->GetOwningActor());

	FVector Velocity = Character->GetVelocity();
	
	if (Character && Character->GetCharacterMovement() && Velocity.Z == 0.0f)
	{
		Character->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
}