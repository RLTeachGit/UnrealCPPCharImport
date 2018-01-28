#pragma once
#include "Engine/Engine.h"
#include "Runtime/Engine/Public/EngineGlobals.h"


#define	ONSCREEN_DEBUG(vMessage) 	if (GEngine) {GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT(vMessage));}


