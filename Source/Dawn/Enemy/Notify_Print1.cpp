// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_Print1.h"

#include "Kismet/KismetSystemLibrary.h"

void UNotify_Print1::OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	UKismetSystemLibrary::PrintString(this,"It's OK");
}

