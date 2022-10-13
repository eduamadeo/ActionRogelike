// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUp_HealthPotion.h"
#include "SAttributeComponent.h"
#include "SPlayerState.h"


ASPowerUp_HealthPotion::ASPowerUp_HealthPotion()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);

	CreditsCost = 50;
}

void ASPowerUp_HealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	if (ASPlayerState* PS = InstigatorPawn->GetPlayerState<ASPlayerState>())
	{
		if (PS->RemoveCredits(CreditsCost))
		{
			USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(InstigatorPawn);
			if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
			{
				if (AttributeComp->ApplyHealthChange(this, AttributeComp->GetHealthMax()))
				{
					HideAndCooldownPowerup();
				}
			}
		}
	}
}
