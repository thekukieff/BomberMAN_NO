#include "Enemy.hpp"

void Enemy::DrawEnemyLeft()
{
    static int j = 1;//переход вниз
    Enemy_image.loadFromFile("C:/Users/k.kukiev/source/repos/BOMBERMAN/sprites/Enemy_left.png");
    Enemy_image.createMaskFromColor(Color::White);//убирает белый (задний фон)
    Enemy_texture.loadFromImage(Enemy_image);

    Enemy_sprite.setTexture(Enemy_texture);

    
    
    while (true)
    {
        y = rand()%550 + 50;
        if (y%100==0)
        {
            break;
        }
    }
    up_down = rand() % 2;//вверх или вниз

    y += j*100;
    j++;
}

void Enemy::DrawWindowEnemy(RenderWindow& window, Pole&Stone, Hero &hero)
{
    int true_y;
    coords_x++;
    
    if (coords_x == 10) {
        x += move;
        y += move_y;
        //std::cout << "x " << x << std::endl;
        //std::cout << "y " << y << std::endl;
            if (Stone.Destroy_stone_coords[(x + 50)/ 50][y / 50]||x>=1550)//чтоб не врезатьс€ в стену
            {
                if (move_x)
                {
                    move = -1;
                }
            }
        
        
        
            else if (Stone.Destroy_stone_coords[(x - move) / 50][y / 50] == 1||x<=0)//чтоб не врезатьс€ в стену
            {
                if (move_x)
                {

                    move = 1;
                }
            }
            if ((x-25==hero.coords_x&&y==hero.coords_y)|| (x + 25 == hero.coords_x && y == hero.coords_y))//коллизи€ с игроком
            {
                //добавить анимацию
                //sleep(seconds(3));
                //window.close();
            }

        coords_x = 0;
    }

    if (x%100==0)//движение вверх/вниз
    {
        true_y = rand() % 200;
        if (!true_y)
        {
            if (up_down&&!first)
            {
                move_y = 1;
                first = true;
            }
            else {
                if (!first)
                {
                     move_y = -1;
                     first = true;

                }
            }
            if (y-move_y <= 70)//чтоб не врезатьс€ в пол и потолок
            {
                move_y = 1;
                //true_y = 0;
            }
            else if (y+move_y>=1000)
            {
               // true_y = 0;
                move_y = -1;
            }
            move = 0;
            move_x = false;
        }
            if (Stone.Destroy_stone_coords[x / 50][(y+50) / 50]&&move_y == 1)//чтоб не врезатьс€ в стену
            {
                move_y = -1;
            }
            else if (Stone.Destroy_stone_coords[x / 50][y  / 50] && move_y == -1)//чтоб не врезатьс€ в стену
            {
                move_y = 1;
            }

    }
        Enemy_sprite.setPosition(x, y);
        window.draw(Enemy_sprite);
        //std::cout <<"x: "<< x << '\n';
        //загуглить почему у разных экзэмпл€ров класса один и тот же x
        
        
}

