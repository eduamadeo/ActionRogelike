// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SPowerUpBase.generated.h"

class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ASPowerUpBase : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPowerUpBase();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, Category = "Powerup")
	float RespawnTime;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = "OnRep_IsActive")
	bool bIsActive;

	UFUNCTION()
	void ShowPowerup();

	void HideAndCooldownPowerup();

	void SetPowerupState(bool bNewIsActive);

	UFUNCTION()
	void OnRep_IsActive();

public:	

	void Interact_Implementation(APawn* InstigatorPawn) override;

	FText GetInteractText_Implementation(APawn* InstigatorPawn);

};
