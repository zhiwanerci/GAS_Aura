// copyright qileisong

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemy();

	// Í¨¹ý IEnemyInterface ¼Ì³Ð
	void HighlightActor() override;
	void UnHighlightActor() override;

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
};
