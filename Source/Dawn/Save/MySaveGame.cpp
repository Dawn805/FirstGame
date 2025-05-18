// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"

#include "Dawn/MyPaperZDCharacter.h"
#include "Kismet/GameplayStatics.h"

void SavePlayerData(AMyPaperZDCharacter* Player)
{
	if (!Player) return;

	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	if (!SaveGameInstance) return;

	SaveGameInstance->PlayerLocation = Player->GetActorLocation();
	SaveGameInstance->PlayerRotation = Player->GetActorRotation();
	
	FName name = FName(Player->GetWorld()->GetMapName());
	SaveGameInstance->LevelName = name;


	UBackpackComponent* Backpack = Player->Backpack;
	if (Backpack)
	{
		for (auto& item : Backpack->Item)
		{
			FBackpackItems SaveItem;
			SaveItem.ItemName = item.ItemName;
			SaveItem.ItemQuantity = item.ItemQuantity;
			SaveItem.ItemIcon = item.ItemIcon;

			SaveGameInstance->BackpackItems.Add(SaveItem);
		}
	}
	UGameplayStatics::SaveGameToSlot(SaveGameInstance,TEXT("PlayerSave"),0);
}

void LoadPlayerData(AMyPaperZDCharacter* Player)
{
	if (!Player) return;

	if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerSave"),0))
	{
		UMySaveGame* LoadedGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSave"), 0));
		if (!LoadedGame) return;

		FName name = FName(Player->GetWorld()->GetMapName());

		if (name != LoadedGame->LevelName)
		{
			UGameplayStatics::OpenLevel(Player, LoadedGame->LevelName);
			return;
		}

		Player->SetActorLocation(LoadedGame->PlayerLocation);
		Player->SetActorRotation(LoadedGame->PlayerRotation);

		UBackpackComponent* Backpack = Player->Backpack;
		if (Backpack)
		{
			Backpack->Item.Empty();
			for (auto& item : LoadedGame->BackpackItems)
			{
				FBackpackItems NewItem;
				NewItem.ItemName = item.ItemName;
				NewItem.ItemQuantity = item.ItemQuantity;
				NewItem.ItemIcon = item.ItemIcon;

				Backpack->Item.Add(NewItem);
			}
		}

		Player->MP = Player->MaxMP;
		Player->HP = Player->MaxHP;
	}
}
