// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_EnemyAttackDamage.h"

#include "EnemyCharacter.h"
#include "PaperZDAnimInstance.h"
#include "Dawn/MyPaperZDCharacter.h"
#include "Kismet/GameplayStatics.h"

void UNotify_EnemyAttackDamage::OnReceiveNotify_Implementation(UPaperZDAnimInstance* AnimInstance) const
{
	if (!AnimInstance)
	{
		FVector Location = SequenceRenderComponent->GetSocketLocation(SocketName);
		if (SocketName == "No") Location = SequenceRenderComponent->GetComponentLocation();
		DrawDebugBox(this->GetWorld(),Location,BoxExtent,BoxColor,true);
	}
	else
	{
		AActor* OwningActor = AnimInstance->GetOwningActor();
		if (!OwningActor) return;
		AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OwningActor);
		if (!EnemyCharacter) return;
 		float FAttackDamge = EnemyCharacter->Attack;

		//2
		FVector Location;
		if (SocketName == "No")
		{
			Location = SequenceRenderComponent->GetComponentLocation();
		}else
		{
			Location = SequenceRenderComponent->GetSocketLocation(SocketName);
		}

		//4
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectType;
		ObjectType.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		//6
		TArray<AActor*> ActorToIgnore;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(),AEnemyCharacter::StaticClass(),ActorToIgnore);

		//7
		TArray<AActor*> Overlaps;
		
		bool bHit = UKismetSystemLibrary::BoxOverlapActors(
			OwningActor->GetWorld(),
			Location,
			BoxExtent,
			ObjectType,
			nullptr,
			ActorToIgnore,
			Overlaps	
			);


		if (bHit)
		{
			for (int i = 0 ; i < Overlaps.Num(); i++)
			{
				AActor* OverlapActor = Overlaps[i];
				if (OverlapActor)
				{
					AMyPaperZDCharacter* PlayerCharacter = Cast<AMyPaperZDCharacter>(OverlapActor);
					if (PlayerCharacter)
					{
						PlayerCharacter->Health -= FAttackDamge * EnemyCharacter->Attack;

						UKismetSystemLibrary::PrintString(this,"wanjia bei da dao le");
					}
				}
			}
		}
	}
}
