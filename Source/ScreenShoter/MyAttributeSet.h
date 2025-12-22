// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"
#include "MyAttributeSet.generated.h"
// Macro útil para o GAS (cole isso antes da declaração da classe)
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class SCREENSHOTER_API UMyAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UMyAttributeSet();

    UPROPERTY(BlueprintReadOnly, Category = "Attributes")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, Health);

    UPROPERTY(BlueprintReadOnly, Category = "Attributes")
    FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, Stamina);

    UPROPERTY(BlueprintReadOnly, Category = "Attributes")
    FGameplayAttributeData MaxStamina;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, MaxStamina);

    UPROPERTY(BlueprintReadOnly, Category = "Attributes")
    FGameplayAttributeData MoveSpeed;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, MoveSpeed);

    // Corrigido: Removido o 'struct' e garantido o posicionamento correto
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};