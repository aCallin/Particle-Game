#include "Water.h"

void updateWaterParticle(char *particles, int *particleIndex, int x, int y) {
	// Try move down.
	int downParticle = particleAtPosition(particles, x, y + PARTICLE_SIZE);
	if (downParticle == PARTICLE_AIR) {
		particles[*particleIndex + WINDOW_WIDTH] = PARTICLE_WATER;
		particles[*particleIndex] = PARTICLE_AIR;	
		return;
	}

	// Try move down-right.
	int downRightParticle = particleAtPosition(particles, x + PARTICLE_SIZE, 
			y + PARTICLE_SIZE);
	if (downRightParticle == PARTICLE_AIR) {
		particles[*particleIndex + 1 + WINDOW_WIDTH] = PARTICLE_WATER;
		particles[*particleIndex] = PARTICLE_AIR;	
		return;
	}

	// Try move down-left.
	int downLeftParticle = particleAtPosition(particles, x - PARTICLE_SIZE, 
			y + PARTICLE_SIZE);
	if (downLeftParticle == PARTICLE_AIR) {
		particles[*particleIndex - 1 + WINDOW_WIDTH] = PARTICLE_WATER;
		particles[*particleIndex] = PARTICLE_AIR;
		return;
	}

	// Try move right.
	int rightParticle = particleAtPosition(particles, x + PARTICLE_SIZE, y);
	if (rightParticle == PARTICLE_AIR) {
		particles[*particleIndex + 1] = PARTICLE_WATER;
		particles[*particleIndex] = PARTICLE_AIR;
		return;
	}

	// Try move left.
	int leftParticle = particleAtPosition(particles, x - PARTICLE_SIZE, y);
	if (leftParticle == PARTICLE_AIR) {
		particles[*particleIndex - 1] = PARTICLE_WATER;
		particles[*particleIndex] = PARTICLE_AIR;
		*particleIndex = *particleIndex - 2; // Don't update the same particle. 
		return;
	}
}
