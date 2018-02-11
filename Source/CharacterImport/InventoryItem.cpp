// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"



UInventoryItem::UInventoryItem()
{
    ONSCREEN_DEBUG("Default Constructor")
}

UInventoryItem::UInventoryItem(EInventoryItemType vType, const FString& vName) {
    ONSCREEN_DEBUG("Constructor")
    Name=vName;
    ItemType=vType;
}
