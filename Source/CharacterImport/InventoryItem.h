// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Debug.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"

/**
 * 
 */


UENUM()
enum class EInventoryItemType : uint8
{
    None
    ,Gem
    ,JumpBuff
};



UCLASS()
class CHARACTERIMPORT_API UInventoryItem : public UObject
{
	GENERATED_BODY()

public:
    UInventoryItem();
    UInventoryItem(EInventoryItemType, const FString&);       //Default Constructor
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory")
    FString   Name;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory")
    EInventoryItemType   ItemType=EInventoryItemType::None;
};
