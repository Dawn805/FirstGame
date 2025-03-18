// Fill out your copyright notice in the Description page of Project Settings.
#include "Notify_BoxAttack.h"
#if WITH_EDITOR
#include "Editor.h"
#endif



#include "DrawDebugHelpers.h"
#include "PaperZDAnimInstance.h"
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
			UKismetSystemLibrary::PrintString(this,"NoSocketName");
		}
		else
		{
			UKismetSystemLibrary::PrintString(this,"YesSocketName");
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
					UGameplayStatics::ApplyDamage(OverlapActor,AttackDamage,OwningActor->GetInstigatorController(),OwningActor,nullptr);
					UKismetSystemLibrary::PrintString(this,"Hit Yes");
				}
				else
				{
					UKismetSystemLibrary::PrintString(this,"Hit No");
				}
			}
		}
	}
















	// //获得攻击位置
	// FVector Location = OwningActor->GetActorLocation();
	// FQuat BoxRotation = FQuat(OwningActor->GetActorRotation());
	//
	// //配置碰撞检测
	// TArray<FOverlapResult> HitResults;
	// FCollisionQueryParams Params;
	// Params.AddIgnoredActor(OwningActor);
	//
	// //进行Box碰撞检测
	// bool bHit = OwningActor->GetWorld()->OverlapMultiByChannel(
	// 	HitResults,
	// 	Location,
	// 	BoxRotation,
	// 	ECC_Pawn,
	// 	FCollisionShape::MakeBox(BoxExtent),
	// 	Params);
	//
	// if (OwningActor == NULL)
	// {
	// 	UWorld* EditorWorld = nullptr;
	// 	EditorWorld = GEditor->GetEditorWorldContext().World();
	// 	DrawDebugBox(EditorWorld,Location,BoxExtent,BoxRotation,BoxColor,true,5.0f,0,2.0f);
	// 	return;
	// }
	//
	// //处理检测结果
	// if (bHit)
	// {
	// 	for (int i = 0; i < HitResults.Num(); i++)
	// 	{
	// 		AActor* HitActor = HitResults[i].GetActor();
	// 		if (HitActor)
	// 		{
	// 			//造成伤害
	// 			UGameplayStatics::ApplyDamage(HitActor,AttackDamage,OwningActor->GetInstigatorController(),OwningActor,nullptr);
	//
	// 			//检测伤害（后面删掉）
	// 			UKismetSystemLibrary::PrintString(this,"Hit Yes");
	// 		}
	// 	}
	// }
	// //这个也是后面删
	// else
	// {
	// 	UKismetSystemLibrary::PrintString(this,"No Hit");
	// }
	//
	// //绘制Debug Box
	// DrawDebugBox(OwningActor->GetWorld(),Location,BoxExtent,BoxRotation,BoxColor,true,5.0f,0,2.0f);
}

