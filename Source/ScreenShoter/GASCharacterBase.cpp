#include "GASCharacterBase.h"
#include "MyAttributeSet.h"

AGASCharacterBase::AGASCharacterBase()
{
    PrimaryActorTick.bCanEverTick = true;

    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    // Agora o compilador saberá o que é AttributeSet
    AttributeSet = CreateDefaultSubobject<UMyAttributeSet>(TEXT("AttributeSet"));
}
// Called when the game starts or when spawned
void AGASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGASCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGASCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
UAbilitySystemComponent* AGASCharacterBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

