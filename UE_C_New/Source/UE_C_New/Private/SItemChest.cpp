// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemChest.h"

// Sets default values
ASItemChest::ASItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseComp=CreateDefaultSubobject<UStaticMeshComponent>("BaseComp");
	RootComponent=BaseComp;
	LidComp=CreateDefaultSubobject<UStaticMeshComponent>("LidComp");
	LidComp->SetupAttachment(BaseComp);
}

// Called when the game starts or when spawned
void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASItemChest::interact_Implementation(APawn* Instigatorpawn)
{
	LidComp->SetRelativeRotation(FRotator(110,0,0));
}

