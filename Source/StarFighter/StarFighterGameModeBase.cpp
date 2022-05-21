// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveEnemigaAerea.h"

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//auto ne = SpawnNave<ANaveTerrestreEnemiga01>();
	//UE_LOG(LogTemp, Warning, TEXT("Dentro de BeginPlay en GameModeBase"));
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawn NaveEnemigaAerea"));

	MovementY = 10.0f;

	FVector Location(355.1f, MovementY, 75.0f);
	FRotator Rotation(0.0f, 180.0f, 0.0f);

	GetWorld()->SpawnActor<ANaveEnemigaAerea>(ANaveEnemigaAerea::StaticClass(), Location, Rotation);
	
	do {
		ValueY = MovementY + 50.0f;

		FVector FLocation(355.1f, ValueY, 75.0f);

		GetWorld()->SpawnActor<ANaveEnemigaAerea>(ANaveEnemigaAerea::StaticClass(), FLocation, Rotation);

		ValueY = MovementY + 50.0f;
	} while (ValueY == 400.0f);


	do {
		MovementY = MovementY - 1;
	} while (MovementY == -400.0f);

}

AStarFighterGameModeBase::AStarFighterGameModeBase()
{
	/*UE_LOG(LogTemp, Warning, TEXT("Dentro de constructor en GameModeBase"));
	GetWorld()->SpawnActor<ANaveTerrestreEnemiga01>(FVector::ZeroVector, FRotator::ZeroRotator);*/

	//SpawnNave<ANaveTerrestreEnemiga01>();

}
