
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h" // Importante!
#include "AbilitySystemComponent.h"
#include "GASCharacterBase.generated.h"

UCLASS()
class SCREENSHOTER_API AGASCharacterBase : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
	AGASCharacterBase();

	// VOCÊ PRECISA DESSAS TRÊS LINHAS ABAIXO PARA O .CPP FUNCIONAR:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
    class UAbilitySystemComponent* AbilitySystemComponent;

    UPROPERTY()
    class UMyAttributeSet* AttributeSet;
};
