#ifndef PARTICLE_SYSTEMS_H
#define PARTICLE_SYSTEMS_H

#include <SFML/Graphics.h>
#include "WindowConstants.h"
#include "ParticleConstants.h"
#include "Sand.h"
#include "Water.h"

#define COUNT_PARTICLES WINDOW_WIDTH * WINDOW_HEIGHT / PARTICLE_SIZE

#define OUT_OF_BOUNDS -1

// Sets each element in particles to a specified value. The value should 
// correspond to a valid particle type. Note that this is not a request - each 
// particle will be set.
void setParticles(char *particles, int value);

// Requests to set the particle at a position. This is a request because 
// several factors could prevent a particle from being set.
void requestSetParticle(char *particles, sfVector2i position, int value);

// Returns the particle at a given position, or OUT_OF_BOUNDS if the position 
// is outside of the window's bounds.
int particleAtPosition(char *particles, int x, int y);

// Updates each particle according to their behaviour.
void updateParticles(char *particles);

// Draws each particle onto the window.
void drawParticles(sfRenderWindow *window, char *particles);

#endif
