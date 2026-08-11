#include "DrivingSimulatorGameMode.h"
#include "DrivingSimulatorVehicle.h"

ADrivingSimulatorGameMode::ADrivingSimulatorGameMode()
{
	// Set default pawn class to our vehicle class, this can be overridden in Blueprints later
	DefaultPawnClass = ADrivingSimulatorVehicle::StaticClass();
}
