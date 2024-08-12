#ifndef BOMB_HPP
#define BOMB_HPP
#include "Hero_sprite.hpp"
#include "Pole.hpp"
#include "Enemy.hpp"

class Bomb {
public:

	void DrawBomb(Hero& hero);
	void DrawWindowBomb(RenderWindow& window);
	void DestroyBomb(int x, int y, int Destroy_stone_coords[32][21], Enemy &enemy);

private:
	Texture Bomb_big_texture;
	Sprite  Bomb_big_sprite;
	Image  Bomb_big_image;
	int Power = 1;




};






#endif BOMB_HPP