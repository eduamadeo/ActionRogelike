// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerState.h"

ASPlayerState::ASPlayerState()
{
	Credits = 0;
}

void ASPlayerState::AddCredits(int32 Delta)
{
	Credits += Delta;
	OnCreditsChanged.Broadcast(this, Credits, Delta);
}

bool ASPlayerState::RemoveCredits(int32 Delta)
{
	if (Delta <= Credits)
	{
		Credits -= Delta;
		OnCreditsChanged.Broadcast(this, Credits, Delta);
		return true;
	}
	return false;
}
