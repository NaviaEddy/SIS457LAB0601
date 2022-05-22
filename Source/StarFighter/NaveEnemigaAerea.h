// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaAerea.generated.h"

UCLASS()
class STARFIGHTER_API ANaveEnemigaAerea : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANaveEnemigaAerea();

	//Creacion del projectil
	void ProjectileNaveEnemiga();

	//Creacion del contador del projectil
	void ContadorProjectiles();


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ShipMeshComponent;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float FireRate;

	// Ayuda de contador de disparos
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool Disparo;

	// Velocidad de la nave enemiga
	/*UPROPERTY(Category = "MoveActor", EditAnywhere)
		float Speed = 5;*/

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }
	FORCEINLINE void SetShipMeshComponent(class UStaticMeshComponent* _ShipMeshComponent) { ShipMeshComponent = _ShipMeshComponent; }

	// Mango para una gestión eficiente del temporizador ShotTimerExpired
	FTimerHandle TimerHandle_ShotTimerExpired;

	//Inicializacion de los projectiles
	int DisparoProjectil;
	int NumProjectil;
};
