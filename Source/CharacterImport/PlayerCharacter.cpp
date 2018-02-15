// Fill out your copyright notice in the Description page of Project Settings.


#include	"PlayerCharacter.h"
#include	"Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include    "Components/CapsuleComponent.h"
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
    UCapsuleComponent *tCapsule =GetCapsuleComponent();
    tCapsule->OnComponentBeginOverlap.AddDynamic(this,&APlayerCharacter::OnBeginOverlap);
}

void APlayerCharacter::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Other Actor is the actor that triggered the event. Check that is not ourself.
    if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr ) )
    {
        APickupObject* tPickup=Cast<APickupObject>(OtherActor);		//Did we hit a pickup Object?
        if(tPickup != nullptr)
        {
            tPickup->PickedUpBy(this);  //Get Pickup to handle itself
            UInventoryItem* tItem=NewObject<UGreenGem>();
            Inventory.Add(NewObject<UInventoryItem>(tItem));
            OnNewItem(tItem);
        }
    }
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
}

void APlayerCharacter::TurnRight(float vValue)
{
    if (Controller != NULL)
    {
        // find out which way is right
        AddControllerYawInput(vValue);
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
	}
}

void APlayerCharacter::MoveRight(float vValue) 
{
	if (Controller != NULL) 
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();     //Get current rotation
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y); //Create a vector pointing in direction character of Characters Right vector
		AddMovementInput(Direction, vValue);        //Tell Character to move
	}
}
//Function to start character jumping
void APlayerCharacter::StartJump()
{
	if (IsCharacterOnGround())	//Only jump if charcatre grounded
	{
		Jump();
	}
}
