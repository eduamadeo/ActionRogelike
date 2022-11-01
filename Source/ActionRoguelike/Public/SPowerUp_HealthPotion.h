// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerUpBase.h"
#include "SPowerUp_HealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPowerUp_HealthPotion : public ASPowerUpBase
{
	GENERATED_BODY()

public:

	ASPowerUp_HealthPotion();
	
protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "PlayerState|Credits")
	int32 CreditsCost;

	void Interact_Implementation(APawn* InstigatorPawn) override;

	FText GetInteractText_Implementation(APawn* InstigatorPawn) override;
};
