// @ajinkyax


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& Tag) const
{
	for (const auto& [InputTag, InputAction] : NativeInputActions)
	{
		if (InputTag.MatchesTag(Tag) && InputAction)
		{
			return InputAction;
		}
	}

	return nullptr;
}
