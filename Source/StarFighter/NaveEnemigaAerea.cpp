// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaAerea.h"
#include "ProjectileNaveEnemigaAerea.h"
//#include "time.h"


// Sets default values
ANaveEnemigaAerea::ANaveEnemigaAerea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	SetActorEnableCollision(true);

	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	Disparo = true;
	DisparoProjectil = 0;
}

// Called when the game starts or when spawned
void ANaveEnemigaAerea::BeginPlay()
{
	Super::BeginPlay();

	// Cantidad de projectiles generados

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ANaveEnemigaAerea::ContadorProjectiles, 60);
	
}

// Called every frame
void ANaveEnemigaAerea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (DisparoProjectil % 30 == 0)
		ProjectileNaveEnemiga();
	DisparoProjectil++;

	//FVector Location = GetActorLocation();
	//FVector FLocation(0.0f, 30.0f, 0.0f);

	//Location += FLocation * Speed * DeltaTime;
		//SetActorLocation(Location);

}

void ANaveEnemigaAerea::ProjectileNaveEnemiga()
{
	if (Disparo)
	{
		// Spawn de projectiles
		const FRotator FRotation(0.0f, 180.0f, 0.0f);
		const FVector SpawnLocation = GetActorLocation() + FRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			World->SpawnActor<AProjectileNaveEnemigaAerea>(SpawnLocation, FRotation);
			NumProjectil++;
		}

		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, FireRate, true);
	}
}

void ANaveEnemigaAerea::ContadorProjectiles()
{
	// Mensaje de cantidad de projectiles generados

	GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Green, FString::Printf(TEXT("Numero proyectiles generados en 1 min: %d"), NumProjectil));
}
