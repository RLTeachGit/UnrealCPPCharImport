// Fill out your copyright notice in the Description page of Project Settings.

#include "DebugLib.h"

#include "Engine/Engine.h"
#include "Runtime/Engine/Public/EngineGlobals.h"



void	UDebugLib::DebugPrintOnScreen(const FString& vText, const ErrorTextColour Colour)
{
	if (GEngine)
	{
		FColor	tColour = FColor::White;
		switch (Colour)
		{	
			case	ErrorTextColour::Error_Red:
				tColour = FColor::Red;
			break;

			case	ErrorTextColour::Error_Amber:
				tColour = FColor::Orange;
				break;

			case	ErrorTextColour::Error_Yellow:
				tColour = FColor::Yellow;
				break;

			default:
				break;
		}
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, tColour, vText);
	}
}
