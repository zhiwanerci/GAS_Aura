// copyright qileisong


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Actor/AuraProjectile.h"
#include <Interaction/CombatInterface.h>

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	// UKismetSystemLibrary::PrintString(this, FString("ActivateAbility (C++)"), true, true, FLinearColor::Yellow, 3.f);


}

void UAuraProjectileSpell::SpawnProjectile(const FVector ProjectileTargetLocation)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();

	if (!bIsServer) return;

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());

	if (CombatInterface)
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		FRotator Rotator = (ProjectileTargetLocation - SocketLocation).Rotation();
		Rotator.Pitch = 0.f;

		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		SpawnTransform.SetRotation(Rotator.Quaternion());

		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
			ProjectileClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn
		);

		//TODO: Give the projectile a gameplay effect spec for causing damage.

		Projectile->FinishSpawning(SpawnTransform);
	}
}