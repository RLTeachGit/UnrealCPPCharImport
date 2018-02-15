// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "GreenGem.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERIMPORT_API UGreenGem : public UInventoryItem
{
	GENERATED_BODY()

		virtual void	Init(const AActor* VActor)	 override;		//Override default Init

};
