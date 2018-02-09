// Fill out your copyright notice in the Description page of Project Settings.

#include	"PlayerCharacter.h"
#include	"Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"

#include	"Debug.h"       //Macro defintion for debug


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->SetWalkableFloorAngle(90.0f);	//Allow for steeper slopes
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent); //Call base class setup
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward); //Link Input to c++ Function, so it gets called when input happens
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight", this, &APlayerCharacter::TurnRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::EndJump);
}

void APlayerCharacter::TurnRight(float vValue)
{
    if (Controller != NULL)
    {
        // find out which way is right
        AddControllerYawInput(vValue);
        if(fabs(vValue)>0.1f) {
            FString    tDebugText=FString::Printf(TEXT("Rotation %.2f"),vValue);
            OnCPPMove(tDebugText);
        }
    }
}
//Function to tell us if Character is grounded
bool    APlayerCharacter::IsCharacterOnGround() {
    return  GetCharacterMovement()->IsMovingOnGround();
}

void APlayerCharacter::MoveForward(float vValue) 
{
	if (Controller != NULL)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation(); //Get characters current rotation
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X); //Generate vector in forward direction
		AddMovementInput(Direction, vValue); //Tell Character to move
        if(fabs(vValue)>0.1f) {
            FString    tDebugText=FString::Printf(TEXT("Speed %.2f"),vValue);
            OnCPPMove(tDebugText); //Call Event in BP
        }
	}
}

void APlayerCharacter::MoveRight(float vValue) 
{
	if (Controller != NULL) 
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();     //Get current rotation
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y); //Create a vector pointing in direction character of Characters Right vector
        XController=vValue;
		AddMovementInput(Direction, vValue);        //Tell Character to move
        
	}
}
//Function to start character jumping
void APlayerCharacter::StartJump()
{
	if (IsCharacterOnGround())
	{
		Jump();
        OnCPPJump(++JumpCounter);
        Inventory.Add(NewObject<UInventoryItem>());

	}
	else
	{
		ONSCREEN_DEBUG("Not on ground")
	}
}

//Abort Jump
void APlayerCharacter::EndJump()
{
	StopJumping();
}
