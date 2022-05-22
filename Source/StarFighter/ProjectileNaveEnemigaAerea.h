// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileNaveEnemigaAerea.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS()
class STARFIGHTER_API AProjectileNaveEnemigaAerea : public AActor
{
	GENERATED_BODY()
	
		/** Sphere collision component */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileMesh;

		/** Projectile movement component */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;


public:	
	// Sets default values for this actor's properties
	AProjectileNaveEnemigaAerea();

	/** Function to handle the projectile hitting something */
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns ProjectileMesh subobject **/
	FORCEINLINE UStaticMeshComponent* GetProjectileMesh() const { return ProjectileMesh; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = "MoveActor", EditAnywhere)
		float Speed = 5;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
