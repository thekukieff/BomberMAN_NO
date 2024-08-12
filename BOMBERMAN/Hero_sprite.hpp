#ifndef HERO_SPRITE
#define HERO_SPRITE
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <cmath>

#include <ctime>
using namespace sf;


class Hero {

public:
	void Face_Hero_stay();
	void Left_Hero_stay();
	void Right_Hero_stay();
	void Up_Hero_stay();
	void Draw_Down_Hero_Stay(RenderWindow& window);
	void Draw_Left_Hero_Stay(RenderWindow &window);
	void Draw_Up_Hero_Stay(RenderWindow& window);
	void Draw_Right_Hero_Stay(RenderWindow& window);
	void Draw_Hero_Stay(RenderWindow &window);

	int coords_x = 0;
	int coords_y = 50;//стартовые координаты
	int move = 5;

private:
	Image Hero_image;
	Texture Hero_texture;
	Sprite Hero_sprite;


};





#endif HERO_SPRITE