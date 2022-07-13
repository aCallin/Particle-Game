#include "Sand.h"

void updateSandParticle(char *particles, int particleIndex, int x, int y) {
	// Try move down.
	int downParticle = particleAtPosition(particles, x, y + PARTICLE_SIZE);
	if (downParticle != OUT_OF_BOUNDS) {
		if (downParticle == PARTICLE_AIR) {
			particles[particleIndex + WINDOW_WIDTH] = PARTICLE_SAND;
			particles[particleIndex] = PARTICLE_AIR;	
			return;
		} else if (downParticle == PARTICLE_WATER) {
			particles[particleIndex + WINDOW_WIDTH] = PARTICLE_SAND;
			particles[particleIndex] = PARTICLE_WATER;	
			return;
		}
	}

	// Try move down-right.
	int downRightParticle = particleAtPosition(particles, x + PARTICLE_SIZE, 
			y + PARTICLE_SIZE);
	if (downRightParticle != OUT_OF_BOUNDS) {
		if (downRightParticle == PARTICLE_AIR) {
			particles[particleIndex + 1 + WINDOW_WIDTH] = PARTICLE_SAND;
			particles[particleIndex] = PARTICLE_AIR;	
			return;
		} else if (downRightParticle == PARTICLE_WATER) {
			particles[particleIndex + 1 + WINDOW_WIDTH] = PARTICLE_SAND;
			particles[particleIndex] = PARTICLE_WATER;	
			return;
		}
	}

	// Try move down-left.
	int downLeftParticle = particleAtPosition(particles, x - PARTICLE_SIZE, 
			y + PARTICLE_SIZE);
	if (downLeftParticle != OUT_OF_BOUNDS) {
		if (downLeftParticle == PARTICLE_AIR) {
			particles[particleIndex - 1 + WINDOW_WIDTH] = PARTICLE_SAND;
			particles[particleIndex] = PARTICLE_AIR;
			return;
		} else if (downLeftParticle == PARTICLE_WATER) {
			particles[particleIndex - 1 + WINDOW_WIDTH] = PARTICLE_SAND;
			particles[particleIndex] = PARTICLE_WATER;
			return;
		}
	}
}
