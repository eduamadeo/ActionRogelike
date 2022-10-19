// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUp_GrantAction.h"
#include "SActionComponent.h"
#include "SAction.h"

ASPowerUp_GrantAction::ASPowerUp_GrantAction()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);
}

void ASPowerUp_GrantAction::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	USActionComponent* ActionComp = USActionComponent::GetActions(InstigatorPawn);
	if (ActionComp)
	{
		if (ActionComp->GetAction(ActionClass))
		{
			//UE_LOG(LogTemp, Log, TEXT("Instigator already has action of class: %s"), *GetNameSafe(ActionToGrant));
			FString DebugMsg = FString::Printf(TEXT("Action '%s' already known."), *GetNameSafe(ActionClass));
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, DebugMsg);
			return;
		}

		// Give new Ability
		ActionComp->AddAction(InstigatorPawn, ActionClass);
		HideAndCooldownPowerup();
	}
}
