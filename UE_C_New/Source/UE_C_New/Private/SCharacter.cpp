// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "UE_C_New/Public/SCharacter.h"

#include "SMagicProjectile.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASCharacter::ASCharacter()

{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp=CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation=true;//使用pawn控制旋转
	CameraComp=CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
	GetCharacterMovement()->bOrientRotationToMovement=true;//将旋转朝向运动
	bUseControllerRotationYaw=false;//使用控制器旋转yaw

}
// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,&ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ASCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",this,&APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("PrimaryAttack",IE_Pressed,this,&ASCharacter::PrimaryAttack);
	 PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ASCharacter::Jump);
}


void ASCharacter::MoveForward(float value)
{
	FRotator controlrot =GetControlRotation();//获得摄像机的旋转视角
	controlrot.Pitch=0.0f;
	controlrot.Roll=0.0f;
	AddMovementInput(controlrot.Vector(),value);//将摄像机的方向作为角色移动的方向
}
//X   forword red 
//Y   right  green 
//Z   up  blue 
void ASCharacter::MoveRight(float value)
{
	FRotator controlrot =GetControlRotation();//获得摄像机的旋转视角
	controlrot.Pitch=0.0f;
	controlrot.Roll=0.0f;
	FVector rightvector= FRotationMatrix(controlrot).GetScaledAxis(EAxis::Y);//获得向右向量
	AddMovementInput(rightvector,value);
}

void ASCharacter::PrimaryAttack()
{
	FVector HandsLocation=GetMesh()->GetSocketLocation("Muzzle_01");
	FTransform SpawnTM=FTransform(GetActorRotation(),HandsLocation);//通过一个旋转矩阵收集旋转和位置信息
	FActorSpawnParameters SpawnParameters;//定义Spawn参数变量
	SpawnParameters.SpawnCollisionHandlingOverride=ESpawnActorCollisionHandlingMethod::AlwaysSpawn;//定义处理碰撞方式
	GetWorld()->SpawnActor<AActor>(ProjectileClass,SpawnTM,SpawnParameters);/*通过GetWorld()的SpawnActor方法，进行抛射体的卵生。
	其中三个参数分别是要产生的类名，一个旋转体（包括位置和旋转），以及Spawn的相关参数，参数中最重要的就是卵生类的碰撞处理*/
}



















