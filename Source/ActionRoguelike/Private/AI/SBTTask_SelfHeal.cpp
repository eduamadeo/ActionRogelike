// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTTask_SelfHeal.h"
#include "SAttributeComponent.h"
#include "AIController.h"

EBTNodeResult::Type USBTTask_SelfHeal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ensure(AIPawn))
	{
		USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(AIPawn);
		if (AttributeComp)
		{
			if (AttributeComp->ApplyHealthChange(nullptr, AttributeComp->GetHealthMax()))
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
