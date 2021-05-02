#include "aircraft_controller.hpp"

AircraftController::AircraftController() : 
    ship(nullptr), 
    target(nullptr), 
    isInitialized(false)
{
} 

void AircraftController::init()
{
    aircraftNum = 0;

    for (auto& time : time_delays) {
        time = params::aircraft::DELAY_TIME;
    }
}

void AircraftController::deinit()
{
    for (auto& aircraft : aircrafts) {
        if (aircraft.getIsFlying()) {
            aircraft.deinit();
        }
    }
}

void AircraftController::update(float dt)
{
    for (int i = 0; i < params::aircraft::AIRCRAFT_NUM; ++i) {
        Aircraft& aircraft = aircrafts[i];
        float& time_delay = time_delays[i];

        if (aircraft.getIsFlying()) {
            aircraft.update(dt);

            if (aircraft.getIsReturning()) {
                if (distance(aircraft.getPosition(), ship->getPosition()) <= 0.05f) {
                    aircraft.deinit();
                    aircraftNum--;
                }
            }
            else {
                if (aircraft.getTime() >= params::aircraft::FLIGHT_TIME) {
                    aircraft.setIsReturning(true);
                    aircraft.setTarget(ship);
                }
            }
        }
        else {
            time_delay += dt;
        }
    }
}

void AircraftController::placeAircraft()
{
    if (aircraftNum < params::aircraft::AIRCRAFT_NUM) {
        for (int i = 0; i < params::aircraft::AIRCRAFT_NUM; ++i) {
            Aircraft& aircraft = aircrafts[i];
            float& time_delay = time_delays[i];

            if (!aircraft.getIsFlying() && time_delay >= params::aircraft::DELAY_TIME) {
                time_delay = 0;
                aircraft.setPosition(ship->getPosition());
                aircraft.setAngle(ship->getAngle());
                aircraft.init();
                aircraft.setTarget(target);
                aircraftNum++;
                break;
            }
        }
    }
}

void AircraftController::Initialize(Target * t, Ship * s)
{
    if (!isInitialized) {
        target = t;
        ship = s;
        isInitialized = true;
    }
}

bool AircraftController::getIsInitialized()
{
    return isInitialized;
}
