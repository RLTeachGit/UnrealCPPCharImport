#pragma once
#include "Engine/Engine.h"
#include "Runtime/Engine/Public/EngineGlobals.h"

#ifdef UE_BUILD_DEBUG

#define	ONSCREEN_DEBUG(vMessage) 	if (GEngine) {GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT(vMessage));}
#else
#define    ONSCREEN_DEBUG(vMessage) //Do nothing
#endif

