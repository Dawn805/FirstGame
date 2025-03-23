// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "PaperFlipbookComponent.h"
#include "PaperZDAnimInstance.h"
#include "Dawn/MyPaperZDCharacter.h"
#include "Dawn/MyPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health_sub = Health;

	GetSprite()->SetFlipbook(nullptr);

	UPaperZDAnimInstance* FAnimInstance = GetAnimInstance();
	if (FAnimInstance)
	{
		FAnimInstance->JumpToNode("Hurt", "Orc_Locomotion");
	}


	// GetWorldTimerManager().SetTimer(
	// 	Time_UpdateFacing,               
	// 	FTimerDelegate::CreateUObject(this, &AEnemyCharacter::UpdateFacing), 
	// 	0.2f,                                  
	// 	true                                    
	// );
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health != Health_sub && !bIsInHurtState)
	{
		HealthChange();
	}
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyCharacter::MoveJump()
{
	Super::Jump();
}

void AEnemyCharacter::UpdateWalkSpeed(float NewWalkSpeed)
{
	UCharacterMovementComponent* CharMovement = GetCharacterMovement();
	if (CharMovement)
	{
		CharMovement->MaxWalkSpeed = NewWalkSpeed;
	}
}

void AEnemyCharacter::HealthChange()
{
	UPaperZDAnimInstance* FAnimInstance = GetAnimInstance();
	if (FAnimInstance)
	{
		HealthChange_PlayAnimation();
		bIsInHurtState = true;
	}
	Health_sub = Health;
}




// void AEnemyCharacter::UpdateFacing()
// {
// 	UPaperZDAnimInstance* FAnimInstance = GetAnimInstance();
//
// 	APlayerController* FPlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
// 	AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(FPlayerController);
// 	ACharacter* FCharacter = MyPlayerController->GetCharacter();
// 	AMyPaperZDCharacter* MyPaperZdCharacter = Cast<AMyPaperZDCharacter>(FCharacter);
// 	
// 	if (FAnimInstance && MyPaperZdCharacter)
// 	{
// 		float Direction = this->GetActorLocation().X - MyPaperZdCharacter->GetActorLocation().X;
//
// 		if (Direction < 0)
// 		{
// 			this->SetActorRotation(FRotator(0, 0, 0));
// 		}else if (Direction > 0)
// 		{
// 			this->SetActorRotation(FRotator(0, 180, 0));
// 		}
// 	}
// }


