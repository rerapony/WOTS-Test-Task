
#include <cassert>
#include <cmath>

#include "../framework/game.hpp"
#include "../framework/math/vector.hpp"
#include "object/ship.hpp"
#include "aircraft_controller.hpp"

namespace game
{
	Ship ship;
    AircraftController aircraftController;
    Target target;

	void init()
	{
		ship.init();
        aircraftController.init();
        target.init();

        if (!aircraftController.getIsInitialized()) {
            aircraftController.Initialize(&target, &ship);
        }
	}


	void deinit()
	{
		ship.deinit();
        aircraftController.deinit();
        target.deinit();
	}


	void update( float dt )
	{
		ship.update( dt );
        aircraftController.update(dt);
        target.update(dt);
	}


	void keyPressed( int key )
	{
		ship.keyPressed( key );
	}


	void keyReleased( int key )
	{
		ship.keyReleased( key );
	}


	void mouseClicked( float x, float y, bool isLeftButton )
	{

		Vector2 worldPosition( x, y );
		scene::screenToWorld( &worldPosition.x, &worldPosition.y );
		
        if (isLeftButton) {
            target.setPosition(worldPosition);
        }
        else {
            if (aircraftController.getIsInitialized()) {
                aircraftController.placeAircraft();
            }
        }
	}
}

