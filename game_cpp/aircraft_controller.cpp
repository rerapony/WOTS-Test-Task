#include "aircraft_controller.hpp"

AircraftController::AircraftController()
{
}

void AircraftController::init()
{
    aircraftNum = 0;
}

void AircraftController::deinit()
{
    for (auto& aircraft : aircrafts) {
        aircraft.deinit();
    }
}

void AircraftController::update(float dt)
{
    for (auto& aircraft : aircrafts) {
        if (aircraft.getIsFlying()) {
            aircraft.update(dt);

            if (aircraft.getIsReturning()) {
                if (distance(aircraft.getPosition(), ship->getPosition()) <= 0.01f) {
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
    }
}

void AircraftController::placeAircraft()
{
    if (aircraftNum < params::aircraft::AIRCRAFT_NUM) {
        for (auto& aircraft : aircrafts) {
            if (!aircraft.getIsFlying()) {
                aircraft.init();
                aircraft.setTarget(target);
                aircraftNum++;
            }
        }
    }
}

void AircraftController::setShip(Ship * s)
{
    ship = s;
}

void AircraftController::setTarget(Target * e)
{
    target = e;
}
