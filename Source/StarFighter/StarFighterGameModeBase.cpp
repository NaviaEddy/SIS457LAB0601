// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "ProjectileNaveEnemigaAerea.h"

AStarFighterGameModeBase::AStarFighterGameModeBase()
{
	/*UE_LOG(LogTemp, Warning, TEXT("Dentro de constructor en GameModeBase"));
	GetWorld()->SpawnActor<ANaveTerrestreEnemiga01>(FVector::ZeroVector, FRotator::ZeroRotator);*/

	//SpawnNave<ANaveTerrestreEnemiga01>();

}



void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//auto ne = SpawnNave<ANaveTerrestreEnemiga01>();
	//UE_LOG(LogTemp, Warning, TEXT("Dentro de BeginPlay en GameModeBase"));
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawn NaveEnemigaAerea"));

	//Declaracion del temporizador
	FTimerHandle Timer;

	//Spawn de la nave enemiga en las coordenadas indicadas
	FVector Location(370.0f, 10.0f, 100.0f);
	FRotator Rotation(0.0f, 180.0f, 0.0f);
	SpawnEnemigo = GetWorld()->SpawnActor<ANaveEnemigaAerea>(ANaveEnemigaAerea::StaticClass(), Location, Rotation);

	//Tiempo en que la nave enemiga sera destruida
	GetWorldTimerManager().SetTimer(Timer, this, &AStarFighterGameModeBase::DestroyActorFunction, 60);
			
}


void AStarFighterGameModeBase::DestroyActorFunction()
{
	if (SpawnEnemigo != nullptr) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("NaveEnemigaAereaDestruida"));
		SpawnEnemigo->Destroy();
	}
}

