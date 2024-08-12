#include "Bomb.hpp"

void Bomb::DrawBomb(Hero& hero)
{
    int x = hero.coords_x;
    int y = hero.coords_y;
    bool bomb = true;

    Bomb_big_image.loadFromFile("C:/Users/k.kukiev/source/repos/BOMBERMAN/sprites/Bomb_big.png");
    Bomb_big_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Bomb_big_texture.loadFromImage(Bomb_big_image);

    Bomb_big_sprite.setTexture(Bomb_big_texture);
    Bomb_big_sprite.setPosition(x, y);
    //sleep(seconds(3));
    
   

    



}

void Bomb::DrawWindowBomb(RenderWindow& window)
{


    window.draw(Bomb_big_sprite);
    

}

void Bomb::DestroyBomb(int x, int y, int Destroy_stone_coords[32][21], Enemy &enemy)
{
    if (x % 100 == 0||x%100==50) {

        Destroy_stone_coords[x / 50 + Power][y / 50] = 0;
        Destroy_stone_coords[x / 50 - Power][y / 50] = 0;

    }
    if (y % 100 == 0||y%100==50) {
        Destroy_stone_coords[x / 50 ][y / 50+Power] = 0;
        Destroy_stone_coords[x / 50][y / 50 - Power] = 0;

    }
    for (int i = 0; i < 51; i++)
    {

        if ((x + i == enemy.x && y == enemy.y) ||(x-i==enemy.x && y==enemy.y))
        {
            enemy.move = 0;
            enemy.x = -100;
            enemy.y = -100;
        }
        else 
        {//коллизия
            if (y - i == enemy.y ) {
                for (int j = 0; j < 25; j++)
                {

                if (enemy.x == x - j|| enemy.x == x + j)
                    {
                    enemy.move = 0;

                    enemy.x = -100;
                    enemy.y = -100;
                    break;
                    }
                }
            }
            else if (y + i == enemy.y)
                {
                for (int j = 0; j < 51; j++)
                {

                if (enemy.x == x - j || enemy.x == x + j)
                {
                    enemy.move = 0;

                    enemy.x = -100;
                    enemy.y = -100;
                    break;
                }
            }
            
            }
                
                
        }
    }

}
