// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NaveEnemigaAerea.h"
#include "StarFighterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AStarFighterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStarFighterGameModeBase();

	float MovementY;

	//template<typename T>
	//T SpawnNave();

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Creacion de un puntero a la variable SpawnEnemigo
	UPROPERTY()
		ANaveEnemigaAerea* SpawnEnemigo;

	//Creacion de la destruccion del enemigo
	UFUNCTION()
		void DestroyActorFunction();

};

//template<typename T>
//T AStarFighterGameModeBase::SpawnNave() {
	
	//return GetWorld()->SpawnActor<T>(FVector::ZeroVector, FRotator::ZeroRotator);
//}
