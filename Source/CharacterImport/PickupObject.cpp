// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupObject.h"
#include "Debug.h"       //Macro defintion for debug


// Sets default values
APickupObject::APickupObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void    APickupObject::PickedUpBy(APlayerCharacter* vPlayer)
{
    FString    tDebugText=FString::Printf(TEXT("%s Picked up by %s"),*this->GetName(),*vPlayer->GetName());
    ONSCREEN_DEBUG(*tDebugText)
    vPlayer->Score+=100;
    this->Destroy();
}

