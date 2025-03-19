// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//添加背包组件
#include "Component/BackpackComponent.h"

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "UI/BackpackWidget.h"
#include "MyPaperZDCharacter.generated.h"


UCLASS()
class DAWN_API AMyPaperZDCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPaperZDCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// //创建胶囊体组件
	// UPROPERTY(EditAnywhere,BlueprintReadwrite)
	// UCapsuleComponent* CapsuleCollision;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;
	
	UFUNCTION()
	void MoveRight(float value);
	UFUNCTION()
	void MoveJump();


	//攻击_U
	UFUNCTION(BlueprintImplementableEvent)
	void Attack_U();

	UPROPERTY(EditAnywhere)
	bool AnimRight = true;

public:
	//背包组件
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBackpackComponent* Backpack;

	//订阅虚幻官方的当物体重叠时
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,
		UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool FromSweep,const FHitResult& SweepResult);

	//背包UI
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<UBackpackWidget> BackpackWidgetClass;

	//UI实例
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBackpackWidget* BackpackWidgetInstance;

	//打开背包
	UFUNCTION()
	void OpenBackpack();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxHP = 100;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float HP = 100;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxMP = 100;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MP = 100;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Attack = 10;
};
