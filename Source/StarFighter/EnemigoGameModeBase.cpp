// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoGameModeBase.h"
#include "NaveEnemigaAerea.h"

void AEnemigoGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawn NaveEnemigaAerea"));

	FTransform SpawnLocation;
	GetWorld()->SpawnActor<ANaveEnemigaAerea>(ANaveEnemigaAerea::StaticClass(), SpawnLocation);
}
