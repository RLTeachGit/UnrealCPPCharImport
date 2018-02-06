// Fill out your copyright notice in the Description page of Project Settings.

#include	"PlayerCharacter.h"
#include	"Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include	"Debug.h"


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
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::EndJump);
}

void APlayerCharacter::MoveForward(float vValue) 
{
	if (Controller != NULL)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, vValue);
		
	}
}

void APlayerCharacter::MoveRight(float vValue) 
{
	if (Controller != NULL) 
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, vValue);
	}
}

void APlayerCharacter::StartJump()
{
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		Jump();
	}
	else
	{
		ONSCREEN_DEBUG("Not on ground")
	}
}

void APlayerCharacter::EndJump()
{
	StopJumping();
}
