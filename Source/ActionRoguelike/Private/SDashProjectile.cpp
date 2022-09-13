// Fill out your copyright notice in the Description page of Project Settings.


#include "SDashProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

ASDashProjectile::ASDashProjectile()
{
	MovementComp->InitialSpeed = 6000.0f;
}

void ASDashProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_PreDash, this, &ASDashProjectile::PreDash_TimeElapsed, 0.2f);
}

void ASDashProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SphereComp->OnComponentHit.AddDynamic(this, &ASDashProjectile::OnCompHit);
}

void ASDashProjectile::PreDash_TimeElapsed()
{
	Explode();
}

void ASDashProjectile::Explode()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_PreDash);

	EffectComp->DeactivateSystem();

	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());

	MovementComp->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_Explosion;
	GetWorldTimerManager().SetTimer(TimerHandle_Explosion, this, &ASDashProjectile::Explosion_TimeElapsed, 0.2f);
}

void ASDashProjectile::Explosion_TimeElapsed()
{
	AActor* ExplosionInstigator = GetInstigator();

	if (ExplosionInstigator)
	{
		ExplosionInstigator->TeleportTo(GetActorLocation(), ExplosionInstigator->GetActorRotation(), false, false);
		Destroy();
	}
}

void ASDashProjectile::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Explode();
}
