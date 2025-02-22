// copyright qileisong

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "MyTestCharacter.generated.h"

class UAbilitySystemComponent;

UCLASS()
class AURA_API AMyTestCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AMyTestCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:

	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> MyTestAbilitySystemComponent;
};
