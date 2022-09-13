// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosive.h"

// Sets default values
ASExplosive::ASExplosive()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComp=CreateDefaultSubobject<USceneComponent>("SceneComp");//创建场景组件
	SceneComp=RootComponent;//将场景组件设置为根组件
	
	StaticMeshComp=CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");//创建静态网格体组件
	StaticMeshComp->SetupAttachment(RootComponent);//将静态网格体组件附加到根组件上

	
	RadialForceComp=CreateDefaultSubobject<URadialForceComponent>("RadialForceComp");//创建径向力组件
	RadialForceComp->SetupAttachment(StaticMeshComp);//径向力附加到静态网格体组件上
}

// Called when the game starts or when spawned
void ASExplosive::BeginPlay()
{
	Super::BeginPlay();
	StaticMeshComp->OnComponentHit.AddDynamic(this,&ASExplosive::ActorOnHit);
}

// Called every frame
void ASExplosive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASExplosive::ActorOnHit(UPrimitiveComponent* HitComponent,AActor* OtherActor, UPrimitiveComponent *OtherComp,FVector NormalImpuse,const FHitResult& Hit )
{
	RadialForceComp->FireImpulse();
}
