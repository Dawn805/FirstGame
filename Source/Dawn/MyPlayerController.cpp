// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "GameFramework/Pawn.h"
#include "PaperSpriteComponent.h"
#include "MyGameMode.h"
#include "MyPaperZDCharacter.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"


void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!PlayerStateWidgetClass)
	{
		return;
	}
	
	if (!PlayerStateWidgetInstance)
	{
		PlayerStateWidgetInstance = CreateWidget<UPlayerStateWidget>(GetWorld(), PlayerStateWidgetClass);
		if (PlayerStateWidgetInstance) PlayerStateWidgetInstance->AddToViewport();
	}
}

void AMyPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight",this,&AMyPlayerController::BroadCastMoveRight);
	InputComponent->BindAction("MoveJump",IE_Pressed,this,&AMyPlayerController::BroadCastJump);
	InputComponent->BindAction("Attack_U",IE_Pressed,this,&AMyPlayerController::BroadCastAttack_U);
	InputComponent->BindAction("OpenBackpack",IE_Pressed,this,&AMyPlayerController::BroadCastOpenBackpack);
}

void AMyPlayerController::BroadCastMoveRight(float value)
{
	AMyGameMode* GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		if (GameMode->MoveRightEvent.IsBound())
		{
			GameMode->MoveRightEvent.Broadcast(value);
		}
	}

	APawn* MyPawn = GetPawn();

	UPaperFlipbookComponent* SpriteComponent = MyPawn->FindComponentByClass<UPaperFlipbookComponent>();

	if (value > 0.0f && SpriteComponent != nullptr)
	{
		SpriteComponent->SetRelativeRotation(FRotator(0,0,0));
	}

	if (value < 0.0f && SpriteComponent != nullptr)
	{
		SpriteComponent->SetRelativeRotation(FRotator(0,-180,0));
	}
	
	
}

void AMyPlayerController::BroadCastJump()
{
	AMyGameMode* GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		if (GameMode->JumpEvent.IsBound())
		{
			GameMode->JumpEvent.Broadcast();
		}
	}
}

void AMyPlayerController::BroadCastAttack_U()
{
	AMyGameMode* GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());

	AMyPaperZDCharacter* MyCharacter = Cast<AMyPaperZDCharacter>(GetCharacter());
	if (MyCharacter)
	{
		if (MyCharacter->AnimRight == false) return;
	}
	
	if (GameMode)
	{
		if (GameMode->Attack_U.IsBound())
		{
			GameMode->Attack_U.Broadcast();
		}
	}
}

void AMyPlayerController::BroadCastOpenBackpack()
{
	AMyGameMode* GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		if (GameMode->OpenBackpack.IsBound())
		{
			GameMode->OpenBackpack.Broadcast();
		}
	}
}






