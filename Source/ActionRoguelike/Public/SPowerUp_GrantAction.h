// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerUpBase.h"
#include "SPowerUp_GrantAction.generated.h"

class USAction;

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPowerUp_GrantAction : public ASPowerUpBase
{
	GENERATED_BODY()
	
public:

	ASPowerUp_GrantAction();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "Action")
	TSubclassOf<USAction> ActionClass;

	void Interact_Implementation(APawn* InstigatorPawn) override;
};
