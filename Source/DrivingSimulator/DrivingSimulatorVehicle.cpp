#include "DrivingSimulatorVehicle.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

ADrivingSimulatorVehicle::ADrivingSimulatorVehicle()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 600.0f;
	SpringArm->bUsePawnControlRotation = true;

	// Create Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

void ADrivingSimulatorVehicle::BeginPlay()
{
	Super::BeginPlay();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}

void ADrivingSimulatorVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADrivingSimulatorVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ThrottleAction)
		{
			EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Triggered, this, &ADrivingSimulatorVehicle::ApplyThrottle);
			EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Completed, this, &ADrivingSimulatorVehicle::ApplyThrottle);
		}

		if (BrakeReverseAction)
		{
			EnhancedInputComponent->BindAction(BrakeReverseAction, ETriggerEvent::Triggered, this, &ADrivingSimulatorVehicle::ApplyBrakeReverse);
			EnhancedInputComponent->BindAction(BrakeReverseAction, ETriggerEvent::Completed, this, &ADrivingSimulatorVehicle::ApplyBrakeReverse);
		}

		if (SteerAction)
		{
			EnhancedInputComponent->BindAction(SteerAction, ETriggerEvent::Triggered, this, &ADrivingSimulatorVehicle::ApplySteering);
			EnhancedInputComponent->BindAction(SteerAction, ETriggerEvent::Completed, this, &ADrivingSimulatorVehicle::ApplySteering);
		}

		if (HandbrakeAction)
		{
			EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Started, this, &ADrivingSimulatorVehicle::ApplyHandbrake);
			EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Completed, this, &ADrivingSimulatorVehicle::ReleaseHandbrake);
		}

		if (ResetAction)
		{
			EnhancedInputComponent->BindAction(ResetAction, ETriggerEvent::Started, this, &ADrivingSimulatorVehicle::ResetVehicle);
		}
	}
}

void ADrivingSimulatorVehicle::ApplyThrottle(const FInputActionValue& Value)
{
	if (UChaosWheeledVehicleMovementComponent* MovementComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent()))
	{
		MovementComponent->SetThrottleInput(Value.Get<float>());
	}
}

void ADrivingSimulatorVehicle::ApplyBrakeReverse(const FInputActionValue& Value)
{
	if (UChaosWheeledVehicleMovementComponent* MovementComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent()))
	{
		MovementComponent->SetBrakeInput(Value.Get<float>());
	}
}

void ADrivingSimulatorVehicle::ApplySteering(const FInputActionValue& Value)
{
	if (UChaosWheeledVehicleMovementComponent* MovementComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent()))
	{
		MovementComponent->SetSteeringInput(Value.Get<float>());
	}
}

void ADrivingSimulatorVehicle::ApplyHandbrake(const FInputActionValue& Value)
{
	if (UChaosWheeledVehicleMovementComponent* MovementComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent()))
	{
		MovementComponent->SetHandbrakeInput(true);
	}
}

void ADrivingSimulatorVehicle::ReleaseHandbrake(const FInputActionValue& Value)
{
	if (UChaosWheeledVehicleMovementComponent* MovementComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent()))
	{
		MovementComponent->SetHandbrakeInput(false);
	}
}

void ADrivingSimulatorVehicle::ResetVehicle()
{
	// Simple reset: flip upright and raise slightly
	FTransform Transform = GetActorTransform();
	FRotator CurrentRotation = Transform.GetRotation().Rotator();
	Transform.SetRotation(FQuat(FRotator(0.f, CurrentRotation.Yaw, 0.f)));
	Transform.SetLocation(Transform.GetLocation() + FVector(0.f, 0.f, 200.f));
	
	SetActorTransform(Transform, false, nullptr, ETeleportType::TeleportPhysics);
	
	if (UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetRootComponent()))
	{
		PrimitiveComponent->SetPhysicsLinearVelocity(FVector::ZeroVector);
		PrimitiveComponent->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
	}
}
