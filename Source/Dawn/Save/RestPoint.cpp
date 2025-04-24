// Fill out your copyright notice in the Description page of Project Settings.


#include "RestPoint.h"

#include "Dawn/MyPaperZDCharacter.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
ARestPoint::ARestPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
	RootComponent = SpriteComp;
	BoxComp = CreateDefaultSubobject<UBoxComponent>("Box");

	if (BoxComp)
	{
		BoxComp->OnComponentBeginOverlap.AddDynamic(this,&ARestPoint::OnBoxBeginOverlap);
	}
}

// Called when the game starts or when spawned
void ARestPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARestPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARestPoint::OnBoxBeginOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult)
{
	if (Cast<AMyPaperZDCharacter>(Actor))
	{
		AMyPaperZDCharacter* MyCharacter = Cast<AMyPaperZDCharacter>(Actor);
		MyCharacter->bIsOverlapping = true;
		UKismetSystemLibrary::PrintString(this,"Yes Cundangpoint");
	}
}

void ARestPoint::OnBoxEndOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I)
{
	if (Cast<AMyPaperZDCharacter>(Actor))
	{
		AMyPaperZDCharacter* MyCharacter = Cast<AMyPaperZDCharacter>(Actor);
		MyCharacter->bIsOverlapping = false;
	}
}




