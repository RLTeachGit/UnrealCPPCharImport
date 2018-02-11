// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter.h"
#include "InventoryItem.h"
#include "PickupObject.generated.h"


UCLASS()
class CHARACTERIMPORT_API APickupObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    UInventoryItem* InventoryItem;

public:	
	// Called every frame
	virtual void    Tick(float DeltaTime) override;
    virtual void    PickedUpBy(APlayerCharacter* vPlayer);
};
