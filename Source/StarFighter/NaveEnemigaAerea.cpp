// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaAerea.h"
#include "time.h"

// Sets default values
ANaveEnemigaAerea::ANaveEnemigaAerea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	//Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

}

// Called when the game starts or when spawned
void ANaveEnemigaAerea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemigaAerea::Tick(float DeltaSeconds)
{

	/*srand(time(NULL));

	MovementX = rand() % 5 - 1;
	MovementY = rand() % 5 - 1;

	MoveSpeed = 20;


	const FVector MoveDirection = FVector(MovementX, MovementY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}*/
}

