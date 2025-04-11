// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperZDCharacter.h"

#include "IDetailTreeNode.h"
#include "MyGameMode.h"
#include "MyPlayerController.h"
#include "PaperFlipbookComponent.h"
#include "AnimSequences/PaperZDAnimSequence.h"
#include "PaperZDAnimInstance.h"
#include "Actor/Item.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AMyPaperZDCharacter::AMyPaperZDCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//订阅虚幻官方的CPP事件->OnComponentBeginOverlap
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyPaperZDCharacter::OnComponentBeginOverlap);
	
	//创建背包组件
	Backpack = CreateDefaultSubobject<UBackpackComponent>("Backpack");


}

// Called when the game starts or when spawned
void AMyPaperZDCharacter::BeginPlay()
{
	Super::BeginPlay();

	bAttack_J.Init(false,2);
	
	AMyGameMode* GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->MoveRightEvent.AddDynamic(this,&AMyPaperZDCharacter::MoveRight);
		GameMode->JumpEvent.AddDynamic(this,&AMyPaperZDCharacter::MoveJump);
		GameMode->Attack_U.AddDynamic(this,&AMyPaperZDCharacter::Attack_U);
		GameMode->OpenBackpack.AddDynamic(this,&AMyPaperZDCharacter::OpenBackpack);
		GameMode->Attack_J.AddDynamic(this,&AMyPaperZDCharacter::Attack_J);
	}
}

// Called every frame
void AMyPaperZDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyPaperZDCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
}

//移动
void AMyPaperZDCharacter::MoveRight(float value)
{
	if (Controller&&value != 0.0f)
	{
		const FRotator Rotator = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotator).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, value);
	}
}

void AMyPaperZDCharacter::MoveJump()
{
	Super::Jump();
}

//人物碰到自动拾取
void AMyPaperZDCharacter::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,
		UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool FromSweep,const FHitResult& SweepResult)
{
	UKismetSystemLibrary::PrintString(this,"yesyouget");

	
	AItem* Items = Cast<AItem>(OtherActor);
	if (Items)
	{
		UKismetSystemLibrary::PrintString(this,"拾取物品!");
		FBackpackItems BackpackItems;
		BackpackItems.ItemName = Items->ItemName;
		BackpackItems.ItemIcon = Items->ItemIcon;
		BackpackItems.ItemQuantity = Items->ItemQuantity;
		Backpack->AddItem(BackpackItems,1);
		Items->Destroy();
	}
}

//打开关闭背包
void AMyPaperZDCharacter::OpenBackpack()
{
	if (!BackpackWidgetInstance)
	{
		BackpackWidgetInstance = CreateWidget<UBackpackWidget>(GetWorld(),BackpackWidgetClass);
		if (BackpackWidgetInstance)
		{
			BackpackWidgetInstance->SetBackpack(this);
			BackpackWidgetInstance->AddToViewport();
		}
	}
	else
	{
		if (BackpackWidgetInstance->IsInViewport())
		{
			BackpackWidgetInstance->RemoveFromParent();
			BackpackWidgetInstance = nullptr; // 释放 UI
		}
	}
}
void AMyPaperZDCharacter::Attack_J()
{
	AMyPlayerController* PlayerController = Cast<AMyPlayerController>(this->GetController());
	if (!PlayerController) return;

	UKismetSystemLibrary::PrintString(this,"Key_J is Ok");
	
	UPaperZDAnimInstance* PaperZdAnimInstance = this->GetAnimInstance();
	if (!PaperZdAnimInstance) return;

	UKismetSystemLibrary::PrintString(this,"PLayerAnim_J is Ok");
	
	if (bAttack_J[1] == true)
	{
		PaperZdAnimInstance->JumpToNode(Attack_J_3AnimNodeName,StateMachineName);
		for (int i = 0 ; i < bAttack_J.Num() ; i++)
		{
			bAttack_J[i] = false;
		}

		UKismetSystemLibrary::PrintString(this,"J_3 is Ok");
		
		return;
	}
	if (bAttack_J[0] == true)
	{
		PaperZdAnimInstance->JumpToNode(Attack_J_2AnimNodeName,StateMachineName);
		bAttack_J[1] = true;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&AMyPaperZDCharacter::ChangebAttack_J_2,2,false);

		UKismetSystemLibrary::PrintString(this,"J_2 is Ok");
	
		return;
	}

	PaperZdAnimInstance->JumpToNode(Attack_J_1AnimNodeName,StateMachineName);
	bAttack_J[0] = true;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&AMyPaperZDCharacter::ChangebAttack_J_1,2,false);

	UKismetSystemLibrary::PrintString(this,"J_1 is Ok");
}








