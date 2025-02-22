// copyright qileisong


#include "Test/MyTestCharacter.h"
#include "AbilitySystemComponent.h"


AMyTestCharacter::AMyTestCharacter()
{
	MyTestAbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	MyTestAbilitySystemComponent->SetIsReplicated(true);
}

UAbilitySystemComponent* AMyTestCharacter::GetAbilitySystemComponent() const
{
	return MyTestAbilitySystemComponent;
}

