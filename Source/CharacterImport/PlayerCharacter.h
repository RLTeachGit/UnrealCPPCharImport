// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include	"GreenGem.h"
#include    "PickupObject.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class CHARACTERIMPORT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Movement section
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
	UFUNCTION()     //Allows this function to be called from Blueprint
	void	MoveForward(float vValue);
    
	UFUNCTION()
	void	MoveRight(float vValue);
    
    UFUNCTION()
    void    TurnRight(float vValue);

	UFUNCTION()
	void	StartJump();

    
    UFUNCTION()
    bool    IsCharacterOnGround();
    
	//Player Inventory section
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
    void    OnNewItem(const UInventoryItem* Item);
    
    //Use Instanced to see the dereferenced pointer in Editor
    UPROPERTY(VisibleAnywhere,Instanced, BlueprintReadOnly, Category="Inventory")
    TArray<class UInventoryItem*>    Inventory;
	

	//Collision section
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
	//UI section
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")	//Allows us to link widget from Level BP, whcih creates the UI
		TSubclassOf<class UUserWidget> UUIWidget;		//UI Widget, this will contain Inventory

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	int     Score;

};
