#include "GameContainer.h"

#include <SFML/Graphics.h>
#include "WindowConstants.h"
#include "ParticleConstants.h"
#include "ParticleSystems.h"
#include "UserInteractionSystems.h"

static void init(sfRenderWindow **window, char *particles, int *placeValue, 
		sfFont **font, sfText **text);
static void destroy(sfRenderWindow *window, sfFont *font, sfText *text);

static void handleEvents(sfRenderWindow *window, sfEvent *event, 
		float *mouseWheelDelta);

static void update(sfRenderWindow *window, char *particles, int *placeValue, 
		float mouseWheelDelta, sfText *text);
static void updateText(sfText *text, int placeValue);
static void render(sfRenderWindow *window, char *particles, sfText *text);

void startGame() {
	// Declaring important structures and variables we will use in our game.
	sfRenderWindow *window;
	char particles[COUNT_PARTICLES];
	int placeValue;
	float mouseWheelDelta;
	sfFont *font;
	sfText *text;

	// Initialize the above structures and variables.
	init(&window, particles, &placeValue, &font, &text);

	// Do the game loop.
	sfEvent event;
	while (sfRenderWindow_isOpen(window)) {
		handleEvents(window, &event, &mouseWheelDelta);
		update(window, particles, &placeValue, mouseWheelDelta, text);
		render(window, particles, text);
	}

	// Return allocated memory.
	destroy(window, font, text);
}

static void init(sfRenderWindow **window, char *particles, int *placeValue, 
		sfFont **font, sfText **text) {
	// Set some properties of the window.
	sfVideoMode videoMode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
	*window = sfRenderWindow_create(videoMode, WINDOW_TITLE, 
			sfTitlebar | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(*window, FRAMERATE);

	// Set the particles to air.
	setParticles(particles, PARTICLE_AIR);

	// Set the initial place value to sand.
	*placeValue = PARTICLE_SAND;

	// Create the font and text.
	*font = sfFont_createFromFile("Resources/8bitOperatorPlus8-Regular.ttf");
	*text = sfText_create();
	sfText_setFont(*text, *font);
	sfText_setCharacterSize(*text, 24);
	sfText_setFillColor(*text, sfWhite);
}

static void handleEvents(sfRenderWindow *window, sfEvent *event, 
		float *mouseWheelDelta) {
	*mouseWheelDelta = 0;
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtMouseWheelScrolled)
			*mouseWheelDelta = event->mouseWheelScroll.delta;
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window);
	}
}

static void update(sfRenderWindow *window, char *particles, int *placeValue, 
		float mouseWheelDelta, sfText *text) {
	updateUserInteraction(window, particles, placeValue, mouseWheelDelta);
	updateText(text, *placeValue);
	updateParticles(particles);
}

static void updateText(sfText *text, int placeValue) {
	switch (placeValue) {
		case PARTICLE_DIRT:
			sfText_setString(text, "Place: DIRT");
			break;
		case PARTICLE_SAND:
			sfText_setString(text, "Place: SAND");
			break;
		case PARTICLE_WATER:
			sfText_setString(text, "Place: WATER");
			break;
	}
}

static void render(sfRenderWindow *window, char *particles, sfText *text) {
	sfRenderWindow_clear(window, sfTransparent);
	drawParticles(window, particles);
	sfRenderWindow_drawText(window, text, NULL);
	sfRenderWindow_display(window);
}

static void destroy(sfRenderWindow *window, sfFont *font, sfText *text) {
	sfRenderWindow_destroy(window);
	sfFont_destroy(font);
	sfText_destroy(text);
}
