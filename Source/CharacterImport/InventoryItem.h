// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"

/**
 * This implements the functionality of the Pickup Item
 */


UCLASS()
class CHARACTERIMPORT_API UInventoryItem : public UObject
{
	GENERATED_BODY()

public:
    UInventoryItem();		//This cannot have init variables in Unreal

protected:
	virtual void	Init(const AActor* VActor);		//Default Init routine

	virtual	void	ItemTick(float vTime);

};
