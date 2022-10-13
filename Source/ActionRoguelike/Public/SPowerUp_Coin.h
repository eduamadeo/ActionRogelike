// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerUpBase.h"
#include "SPowerUp_Coin.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPowerUp_Coin : public ASPowerUpBase
{
	GENERATED_BODY()
	
public:

	ASPowerUp_Coin();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "PlayerState|Credits")
	int32 CreditsAmount;

	void Interact_Implementation(APawn* InstigatorPawn) override;
};
