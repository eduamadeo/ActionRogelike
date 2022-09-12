// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "SDashProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASDashProjectile : public ASProjectileBase
{
	GENERATED_BODY()
	
protected:

	FTimerHandle TimerHandle_PreDash;

public:

	ASDashProjectile();

protected:

	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	void PreDash_TimeElapsed();

	void Explode();

	void Explosion_TimeElapsed();

public:

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
