// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"
#include "Debug.h"


UInventoryItem::UInventoryItem() {}	//Does nothing for now

void UInventoryItem::Init(const AActor* vActor)
{
	FString	tText = FString::Printf(TEXT("Item Picked up by %s"), vActor->GetDebugName);
	ONSCREEN_DEBUG(tText);
}


void UInventoryItem::ItemTick(float vTime)
{
}
