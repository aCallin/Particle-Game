#ifndef USER_INTERACTION_SYSTEMS_H
#define USER_INTERACTION_SYSTEMS_H

#include <SFML/Graphics.h>
#include "ParticleConstants.h"
#include "ParticleSystems.h"

void updateUserInteraction(sfRenderWindow *window, char *particles, 
		int *placeValue, float mouseWheelDelta);

#endif
