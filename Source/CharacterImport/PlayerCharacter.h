// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryItem.h"
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

	FVector	mMoveVector;
	FRotator mRotate;
    
    int32   JumpCounter=0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
	void	EndJump();
    
    UFUNCTION()
    bool    IsCharacterOnGround();

    
    UFUNCTION(BlueprintImplementableEvent, Category = "Debug")
    void    OnCPPJump(int32 Count);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Debug")
    void    OnCPPMove(const FString& DebugText);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Debug")
    float   XController;
    
    //Use Instanced to see the dereferenced pointer in Editor
    UPROPERTY(VisibleAnywhere,Instanced, BlueprintReadOnly, Category="Inventory")
    TArray<class UInventoryItem*>    Inventory;
    
    UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
    int     Score;
    
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
};
