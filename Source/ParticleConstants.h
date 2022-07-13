#ifndef PARTICLE_CONSTANTS_H
#define PARTICLE_CONSTANTS_H

#include <SFML/Graphics.h>

// Make sure that the particle size fits the window width and height.
#define PARTICLE_SIZE 6

#define PARTICLE_AIR 0
#define PARTICLE_DIRT 1
#define PARTICLE_SAND 2
#define PARTICLE_WATER 3

// Keep this up to date with the number of types of particles there are.
#define COUNT_PARTICLE_TYPES 4

#define COLOR_AIR sfTransparent
#define COLOR_DIRT {155, 118, 83, 255}
#define COLOR_SAND {242, 209, 107, 255}
#define COLOR_WATER sfBlue

#endif
