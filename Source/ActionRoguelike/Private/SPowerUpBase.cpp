// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUpBase.h"
#include "Components/SphereComponent.h"
#include <Net/UnrealNetwork.h>

// Sets default values
ASPowerUpBase::ASPowerUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionProfileName("Powerup");
	RootComponent = SphereComp;

	RespawnTime = 10.0f;
	bIsActive = true;

	SetReplicates(true);
}

void ASPowerUpBase::Interact_Implementation(APawn* InstigatorPawn)
{

}

void ASPowerUpBase::ShowPowerup()
{
	SetPowerupState(true);
}

void ASPowerUpBase::HideAndCooldownPowerup()
{
	SetPowerupState(false);

	FTimerHandle TimerHandle_RespawnTimer;
	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ASPowerUpBase::ShowPowerup, RespawnTime);
}

void ASPowerUpBase::SetPowerupState(bool bNewIsActive)
{
	bIsActive = bNewIsActive;
	OnRep_IsActive();
}

void ASPowerUpBase::OnRep_IsActive()
{
	SetActorEnableCollision(bIsActive);

	RootComponent->SetVisibility(bIsActive, true);
}

void ASPowerUpBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASPowerUpBase, bIsActive);
}

