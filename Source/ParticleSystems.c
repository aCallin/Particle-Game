#include "ParticleSystems.h"

static sfColor particleColor(char particleValue);

void setParticles(char *particles, int value) {
	for (int i = 0; i < COUNT_PARTICLES; i++) {
		particles[i] = value;
	}
}

void requestSetParticle(char *particles, sfVector2i position, int value) {
	// Deny requests outside of the bounds of the window.
	if (position.x < 0 || position.x >= WINDOW_WIDTH || position.y < 0 || 
			position.y >= WINDOW_HEIGHT)
		return;

	// Place the particle if it is air (this is used to remove other 
	// particles) or if the particle at the position is currently air.
	int particleIndex = (position.x / PARTICLE_SIZE) + (position.y / 
			PARTICLE_SIZE) * WINDOW_WIDTH;
	if (value == PARTICLE_AIR || particles[particleIndex] == PARTICLE_AIR)
		particles[particleIndex] = value;
}

void updateParticles(char *particles) {
	for (int i = (COUNT_PARTICLES - 1); i >= 0; i--) {
		int particleX = (i * PARTICLE_SIZE) % WINDOW_WIDTH;
		int particleY = (i * PARTICLE_SIZE) / WINDOW_WIDTH;
		switch (particles[i]) {
			case PARTICLE_AIR:
				break;
			case PARTICLE_DIRT:
				break;
			case PARTICLE_SAND:
				updateSandParticle(particles, i, particleX, particleY);
				break;
			case PARTICLE_WATER:
				updateWaterParticle(particles, &i, particleX, particleY);
				break;
		}
	}
}

void drawParticles(sfRenderWindow *window, char *particles) {
	sfVector2f particleSize = {PARTICLE_SIZE, PARTICLE_SIZE};
	sfRectangleShape *particle = sfRectangleShape_create();
	sfRectangleShape_setSize(particle, particleSize);

	for (int i = 0; i < COUNT_PARTICLES; i++) {
		int positionX = (i * PARTICLE_SIZE) % WINDOW_WIDTH;
		int positionY = (i * PARTICLE_SIZE) / WINDOW_HEIGHT;
		sfVector2f pixelPosition = {positionX, positionY};
		sfRectangleShape_setPosition(particle, pixelPosition);
		sfRectangleShape_setFillColor(particle, particleColor(particles[i]));
		sfRenderWindow_drawRectangleShape(window, particle, NULL);
	}

	sfRectangleShape_destroy(particle);
}

int particleAtPosition(char *particles, int x, int y) {
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return OUT_OF_BOUNDS;
	int index = (x / PARTICLE_SIZE) + (y / PARTICLE_SIZE) * WINDOW_WIDTH;	
	return particles[index];
}

static sfColor particleColor(char particleValue) {
	switch (particleValue) {
		case PARTICLE_AIR:
			return COLOR_AIR;
		case PARTICLE_DIRT:
			sfColor sandColor = COLOR_DIRT;
			return sandColor;
		case PARTICLE_SAND:
			sfColor dirtColor = COLOR_SAND;
			return dirtColor;
		case PARTICLE_WATER:
			return COLOR_WATER;
	}
}
