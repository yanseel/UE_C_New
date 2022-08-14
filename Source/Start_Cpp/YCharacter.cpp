// Fill out your copyright notice in the Description page of Project Settings.


#include "YCharacter.h"
#include "../../../../Epic_game/UE_4.26/Engine/Source/Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "../../../../Epic_game/UE_4.26/Engine/Source/Runtime/Engine/Classes/Camera/CameraComponent.h"

// Sets default values
AYCharacter::AYCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	springarmcomp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	springarmcomp->SetupAttachment(RootComponent);
	cameracomp = CreateDefaultSubobject<UCameraComponent>("camera");
	cameracomp->SetupAttachment(springarmcomp);
}

// Called when the game starts or when spawned
void AYCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AYCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}

// Called every frame
void AYCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AYCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this,&AYCharacter::MoveForward );
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
}

