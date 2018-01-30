// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DebugLib.generated.h"

/**
 * 
 */

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ErrorTextColour : uint8
{
	Error_Red 		UMETA(DisplayName = "Red"),
	Error_Amber 	UMETA(DisplayName = "Amber"),
	Error_Yellow	UMETA(DisplayName = "Yellow")
};

UCLASS()
class CHARACTERIMPORT_API UDebugLib : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static	void	DebugPrintOnScreen(const FString& vText, const ErrorTextColour Colour);
};
