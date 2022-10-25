// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCreditsChanged, ASPlayerState*, PlayerState, int32, NewCredits, float, Delta);

UCLASS()
class ACTIONROGUELIKE_API ASPlayerState : public APlayerState
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, ReplicatedUsing = "OnRep_Credits", Category = "PlayerState|Credits")
	int32 Credits;

	UFUNCTION()
	void OnRep_Credits(int32 OldCredits);

public:

	ASPlayerState();

	UFUNCTION(BlueprintCallable, Category = "PlayerState|Credits")
	void AddCredits(int32 Delta);

	UFUNCTION(BlueprintCallable, Category = "PlayerState|Credits")
	bool RemoveCredits(int32 Delta);

	UPROPERTY(BlueprintAssignable)
	FOnCreditsChanged OnCreditsChanged;
	
};
