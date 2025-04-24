// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Pawn.h"
#include "PaperSpriteComponent.h"
#include "MyGameMode.h"
#include "MyPaperZDCharacter.h"
#include "PaperFlipbookComponent.h"
#include "PaperZDAnimInstance.h"
#include "DataInterface/NiagaraDataInterfaceActorComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"


void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	

	if (PlayerStateWidgetClass)
	{
		UPlayerStateWidget* Widget = CreateWidget<UPlayerStateWidget>(this, PlayerStateWidgetClass);
		if (Widget)
		{
			Widget->MainPlayerController = this;
			Widget->AddToViewport();
		}
	}

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->ClearAllMappings();
			if (InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext,0);
			}
		}
	}

	
	
	// if (!PlayerStateWidgetInstance)
	// {
	// 	PlayerStateWidgetInstance = CreateWidget<UPlayerStateWidget>(GetWorld(), PlayerStateWidgetClass);
	// 	if (PlayerStateWidgetInstance) PlayerStateWidgetInstance->AddToViewport();
	// }
}

void AMyPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// InputComponent->BindAxis("MoveRight",this,&AMyPlayerController::BroadCastMoveRight);
	// InputComponent->BindAction("MoveJump",IE_Pressed,this,&AMyPlayerController::BroadCastJump);
	// InputComponent->BindAction("Attack_U",IE_Pressed,this,&AMyPlayerController::BroadCastAttack_U);
	// InputComponent->BindAction("OpenBackpack",IE_Pressed,this,&AMyPlayerController::BroadCastOpenBackpack);
	//
	// InputComponent->BindAction("OpenSettingUI",IE_Pressed,this,&AMyPlayerController::OpenSettingUI);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (MoveRightAction)
			EnhancedInput->BindAction(MoveRightAction,ETriggerEvent::Triggered,this,&AMyPlayerController::BroadCastMoveRight);
		if (JumpAction)
			EnhancedInput->BindAction(JumpAction,ETriggerEvent::Started,this,&AMyPlayerController::BroadCastJump);
		
		if (Attack_UAction)
			EnhancedInput->BindAction(Attack_UAction,ETriggerEvent::Started,this,&AMyPlayerController::BroadCastAttack_U);
		if (Attack_JAction)
			EnhancedInput->BindAction(Attack_JAction,ETriggerEvent::Started,this,&AMyPlayerController::BroadCastAttack_J);
		if (Attack_IAction)
			EnhancedInput->BindAction(Attack_IAction,ETriggerEvent::Started,this,&AMyPlayerController::BroadCastAttack_I);
		
		if (OpenBackpackAction)
			EnhancedInput->BindAction(OpenBackpackAction,ETriggerEvent::Started,this,&AMyPlayerController::BroadCastOpenBackpack);
		if (OpenSettingAction)
			EnhancedInput->BindAction(OpenSettingAction,ETriggerEvent::Started,this,&AMyPlayerController::OpenSettingUI);
		if (SaveGameAction)
			EnhancedInput->BindAction(SaveGameAction,ETriggerEvent::Started,this,&AMyPlayerController::SaveGame);
		if (LoadGameAction)
			EnhancedInput->BindAction(LoadGameAction,ETriggerEvent::Started,this,&AMyPlayerController::LoadGame);
	}
}

void AMyPlayerController::BroadCastMoveRight(const FInputActionInstance& Instance)
{

	float value = Instance.GetValue().Get<float>();
	
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

void AMyPlayerController::BroadCastJump(const FInputActionInstance& Instance)
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

void AMyPlayerController::BroadCastAttack_U(const FInputActionInstance& Instance)
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

void AMyPlayerController::BroadCastAttack_J(const struct FInputActionInstance& Instance)
{
	AMyGameMode* GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		if (GameMode->Attack_J.IsBound())
		{
			GameMode->Attack_J.Broadcast();
		}
	}
}

void AMyPlayerController::BroadCastAttack_I(const struct FInputActionInstance& Instance)
{
	AMyGameMode* GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		if (GameMode->Attack_I.IsBound())
		{
			GameMode->Attack_I.Broadcast();
		}
	}
}




void AMyPlayerController::BroadCastOpenBackpack(const FInputActionInstance& Instance)
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

void AMyPlayerController::OpenSettingUI(const FInputActionInstance& Instance)
{
	if (!SettingWidgetInstance && SettingWidgetClass)
	{
		SettingWidgetInstance = CreateWidget<USettingWidget>(this,SettingWidgetClass);
		if (SettingWidgetInstance)
		{
			SettingWidgetInstance->AddToViewport();

			bShowMouseCursor = true;

			FInputModeGameAndUI InputMode;
			InputMode.SetWidgetToFocus(SettingWidgetInstance->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			SetInputMode(InputMode);

			SetPause(true);
			
		}
	}else
	{
		if (SettingWidgetInstance->IsInViewport())
		{
			SettingWidgetInstance->RemoveFromViewport();
			SettingWidgetInstance = nullptr;

			bShowMouseCursor = false;

			FInputModeGameOnly InputMode;
			SetInputMode(InputMode);

			SetPause(false);
		}
	}
}

void AMyPlayerController::SaveGame(const struct FInputActionInstance& Instance)
{
	AMyPaperZDCharacter* MyCharacter = Cast<AMyPaperZDCharacter>(GetCharacter());
	if (MyCharacter && MyCharacter->bIsOverlapping == true)
	{
		SavePlayerData(MyCharacter);

		UKismetSystemLibrary::PrintString(this,"Yes Cundang");
	}
}

void AMyPlayerController::LoadGame(const struct FInputActionInstance& Instance)
{
	AMyPaperZDCharacter* MyCharacter = Cast<AMyPaperZDCharacter>(GetCharacter());
	if (MyCharacter)
	{
		LoadPlayerData(MyCharacter);
	}
}






