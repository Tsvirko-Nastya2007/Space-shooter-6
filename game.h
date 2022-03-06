#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"
#include "meteor.h"
#include "laser.h"
#include "text.h"
#include "splash.h"
#include "bonus.h"
#include "explosion.h"
#include <vector>
#include <list>

class Game {
public:
	enum GameState { INTRO, PLAY, GAME_OVER };
	Game();
	void play();
private:
	sf::RenderWindow window;
	GameState game_state=PLAY;
	Player player;
	std::vector<Meteor*> meteors;
	std::list<Laser*> lasers;
	TextObject player_hp;
	TextObject score_text;
	SplashScreen game_over_screen;
	std::list<Bonus*> bonuses;
	std::list<Explosion*> explosions;
	size_t score = 0;
	sf::Clock clock;
	size_t fire_delay=200;
	void check_events();
	void update();
	void draw();
	void check_colisions();
};