// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"




UInventoryItem::UInventoryItem() {
    ONSCREEN_DEBUG("Constructor")
    Name=FString(TEXT("Gem"));
    ItemType=EInventoryItemType::Gem;
}
