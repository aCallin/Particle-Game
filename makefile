ParticleGame: Source\Main.c
	gcc -o"Particle Game" \
	-I"Source" Source\Main.c Source\WindowConstants.h Source\GameContainer.h Source\GameContainer.c Source\ParticleConstants.h Source\ParticleSystems.h Source\ParticleSystems.c Source\UserInteractionSystems.h Source\UserInteractionSystems.c Source\Sand.h Source\Sand.c Source\Water.h Source\Water.c \
	-L"CSFML-2.5.1-windows-64-bit\lib\gcc" -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-network \
	-I"CSFML-2.5.1-windows-64-bit\include"