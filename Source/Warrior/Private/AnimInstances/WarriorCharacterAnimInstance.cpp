// @ajinkyax


#include "AnimInstances/WarriorCharacterAnimInstance.h"

#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwnerCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	if (IsValid(OwnerCharacter))
	{
		OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (!OwnerCharacter || !OwnerMovementComponent)
	{
		return;
	}

	GroundSpeed = OwnerCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwnerMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
