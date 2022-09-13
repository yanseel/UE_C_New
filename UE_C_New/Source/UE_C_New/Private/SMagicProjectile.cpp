// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
	SphereComp=CreateDefaultSubobject<USphereComponent>("SphereComp");//初始化碰撞组件
	RootComponent=SphereComp;//让碰撞组件成为根组件
	SphereComp->SetCollisionProfileName("Projectile");//设置碰撞简介名字
	// SphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	// SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	// SphereComp->SetCollisionResponseToChannel(ECC_Pawn,ECR_Ignore);
	
	EffectMovement=CreateDefaultSubobject<UParticleSystemComponent>("EffectMovement");//初始化粒子系统
	EffectMovement->SetupAttachment(SphereComp);//粒子系统附加在球形碰撞组件上
	
	MovementComp=CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");//初始化抛射体
	MovementComp->InitialSpeed=1000.0f;//初始速度
	MovementComp->bRotationFollowsVelocity=true;//旋转跟随速度
	MovementComp->bInitialVelocityInLocalSpace=true;//原地初始速度？
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

