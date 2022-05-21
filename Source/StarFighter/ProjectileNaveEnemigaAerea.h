// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileNaveEnemigaAerea.generated.h"

UCLASS()
class STARFIGHTER_API AProjectileNaveEnemigaAerea : public AActor
{
	GENERATED_BODY()
	
		/** Sphere collision component */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileMesh;


public:	
	// Sets default values for this actor's properties
	AProjectileNaveEnemigaAerea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
