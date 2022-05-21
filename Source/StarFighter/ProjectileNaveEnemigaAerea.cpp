// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileNaveEnemigaAerea.h"
#include "NaveEnemigaAerea.h"

// Sets default values
AProjectileNaveEnemigaAerea::AProjectileNaveEnemigaAerea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	//ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	//ProjectileMesh->OnComponentHit.AddDynamic(this, &AProyectil::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;


}

// Called when the game starts or when spawned
void AProjectileNaveEnemigaAerea::BeginPlay()
{

}

// Called every frame
void AProjectileNaveEnemigaAerea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

