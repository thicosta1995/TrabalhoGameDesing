#include "MyAttributeSet.h"
#include "GameplayEffectExtension.h" // Essencial para o PostGameplayEffectExecute
#include "GameplayEffectTypes.h"

UMyAttributeSet::UMyAttributeSet()
{
    MoveSpeed = 600.0f;
    InitHealth(100.0f);
    InitStamina(100.0f);
    InitMaxStamina(100.0f);
}

void UMyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    // Se o atributo que mudou for a Vida, vamos garantir que não passe dos limites
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        SetHealth(FMath::Clamp(GetHealth(), 0.0f, 100.0f));
    }
}