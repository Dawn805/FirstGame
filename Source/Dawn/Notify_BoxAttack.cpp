// Fill out your copyright notice in the Description page of Project Settings.
#include "Notify_BoxAttack.h"
#if WITH_EDITOR
#include "Editor.h"
#endif



#include "DrawDebugHelpers.h"
#include "MyPaperZDCharacter.h"
#include "PaperZDAnimInstance.h"
#include "PaperZDCharacter.h"
#include "Enemy/EnemyCharacter.h"
#include "Engine/OverlapResult.h"
#include "Kismet/GameplayStatics.h"


UNotify_BoxAttack::UNotify_BoxAttack()
{
	
}

void UNotify_BoxAttack::OnReceiveNotify_Implementation(UPaperZDAnimInstance* AnimInstance) const
{
	if (!AnimInstance)
	{
		FVector Location = SequenceRenderComponent->GetSocketLocation(SocketName);
		if(SocketName == "No") Location = SequenceRenderComponent->GetComponentLocation();
		DrawDebugBox(this->GetWorld(),Location,BoxExtent,BoxColor,true);
	}
	else
	{
		AActor* OwningActor = AnimInstance->GetOwningActor();
		if (!OwningActor)return;

		//获得角色的攻击力：
		float Attack_default = 1.0f;
		AMyPaperZDCharacter* Player = Cast<AMyPaperZDCharacter>(OwningActor);
		if (Player)
		{
			Attack_default = Player->Attack;
		}
		
		

		TArray<AActor*> Overlaps;

		//第4个参数，需要检测的物体类型
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		//第6个参数，忽略的Actor
		TArray<AActor*> ActorToIgnore;
		ActorToIgnore.Add(OwningActor);

		//第2个参数
		FVector Location = SequenceRenderComponent->GetSocketLocation(SocketName);
		if (SocketName == "No")
		{
			Location = SequenceRenderComponent->GetComponentLocation();
			//// UKismetSystemLibrary::PrintString(...);(this,"NoSocketName");
		}
		else
		{
			//// UKismetSystemLibrary::PrintString(...);(this,"YesSocketName");
		}
		bool bHit = UKismetSystemLibrary::BoxOverlapActors(
			//1世界
			OwningActor->GetWorld(),
			//2盒子位置
			Location,
			//3盒子范围
			BoxExtent,
			//4需要检测的物体类型
			ObjectTypes,
			//5不过滤Actor类，传 nullptr.如果你希望过滤特定类型的 Actor，
			//可以传递相应的类（例如 ACharacter::StaticClass()）。如果不进行过滤，可以传递 nullptr。
			nullptr,
			//6忽略的Actor
			ActorToIgnore,
			//7输出的数组
			Overlaps
			);
		if (bHit)
		{
			for (int i = 0 ; i < Overlaps.Num() ; i++)
			{
				AActor* OverlapActor = Overlaps[i];
				if (OverlapActor)
				{
					//UGameplayStatics::ApplyDamage(OverlapActor,AttackDamage,OwningActor->GetInstigatorController(),OwningActor,nullptr);
					//// UKismetSystemLibrary::PrintString(...);(this,"Hit Yes");

					AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(OverlapActor);
					EnemyCharacter->Health -= AttackDamage * Attack_default;

					if (EnemyCharacter->Health <= 0) EnemyCharacter->EndAI();

					// UKismetSystemLibrary::PrintString(...);(this,FString::Printf(TEXT("敌人生命值：%.2f"),EnemyCharacter->Health));
				}
				else
				{
					//// UKismetSystemLibrary::PrintString(...);(this,"Hit No");
				}
			}
		}
	}
}

