// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EnemigoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	
};
