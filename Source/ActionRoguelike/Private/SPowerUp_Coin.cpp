// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUp_Coin.h"
#include "SPlayerState.h"

ASPowerUp_Coin::ASPowerUp_Coin()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);

	CreditsAmount = 10;
}

void ASPowerUp_Coin::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	if (ASPlayerState* PS = InstigatorPawn->GetPlayerState<ASPlayerState>())
	{
		PS->AddCredits(CreditsAmount);
		HideAndCooldownPowerup();
	}
}
