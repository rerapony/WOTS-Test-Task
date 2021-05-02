#pragma once

#include "object/ship.hpp"
#include "object/aircraft.hpp"
#include "object/target.hpp"
#include "common.hpp"

class AircraftController: Entity
{
public:
    AircraftController();
    virtual void init() override;
    virtual void deinit() override;
    virtual void update(float dt) override;

    void placeAircraft();
    void Initialize(Target* target, Ship* ship);
    bool getIsInitialized();

private:
    Aircraft aircrafts[params::aircraft::AIRCRAFT_NUM];
    float time_delays[params::aircraft::AIRCRAFT_NUM];
    Ship* ship;
    Target* target;
    size_t aircraftNum;
    bool isInitialized;
};

