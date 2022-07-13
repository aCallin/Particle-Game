#include "UserInteractionSystems.h"

static void requestPlace(char *particles, sfVector2i mousePosition, int 
		placeValue);

void updateUserInteraction(sfRenderWindow *window, char *particles, 
		int *placeValue, float mouseWheelDelta) {
	// Place particles.
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		sfVector2i mousePosition = sfMouse_getPosition((sfWindow *)window);
		requestPlace(particles, mousePosition, *placeValue);
	} else if (sfMouse_isButtonPressed(sfMouseRight)) {
		// Remove particles (i.e., place air).
		sfVector2i mousePosition = sfMouse_getPosition((sfWindow *)window);
		requestPlace(particles, mousePosition, PARTICLE_AIR);
	}

	// Change place value.
	if (mouseWheelDelta != 0) {
		*placeValue = (*placeValue - (int)mouseWheelDelta) % 
			(COUNT_PARTICLE_TYPES - 1);
		*placeValue = (*placeValue < 1 ? (COUNT_PARTICLE_TYPES - 1) + 
				*placeValue : *placeValue);
	}
}

static void requestPlace(char *particles, sfVector2i mousePosition, int 
		placeValue) {
	int placeSize = 3;

	int offset = -(placeSize / 2);
	for (int x = offset; x < placeSize + offset; x++) {
		for (int y = offset; y < placeSize + offset; y++) {
			sfVector2i requestPosition = {mousePosition.x + x * 
				PARTICLE_SIZE, mousePosition.y + y * PARTICLE_SIZE};
			requestSetParticle(particles, requestPosition, placeValue); 
		}
	}
}
