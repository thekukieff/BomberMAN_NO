#ifndef BOMB_HPP
#define BOMB_HPP
#include "Hero_sprite.hpp"
#include "Pole.hpp"
#include "Enemy.hpp"

class Bomb {
public:
	void BOOM(int& timer, bool &boom, Clock& clock);
	void DrawBomb(Hero& hero);
	void DrawWindowBomb(RenderWindow& window);
	void DestroyBomb(int Destroy_stone_coords[32][21], Enemy &enemy, Hero& hero);
	int x=-100;
	int y=-100;
	int bomb_count = 0;
private:
	Texture Bomb_big_texture;
	Sprite  Bomb_big_sprite;
	Image  Bomb_big_image;
	int Power = 1;




};






#endif BOMB_HPP