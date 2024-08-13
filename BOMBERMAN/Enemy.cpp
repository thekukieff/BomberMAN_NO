#include "Enemy.hpp"

void Enemy::DrawEnemyLeft()
{
    static int j = 1;//������� ����
    Enemy_image.loadFromFile("C:/Users/k.kukiev/source/repos/BOMBERMAN/sprites/Enemy_left.png");
    Enemy_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Enemy_texture.loadFromImage(Enemy_image);

    Enemy_sprite.setTexture(Enemy_texture);

    x = rand() % 1500 + 50;

    
    while (true)
    {
        y = rand()%550 + 50;
        if (y%100==0)
        {
            break;
        }
    }
    up_down = rand() % 2;//����� ��� ����
    left_right = rand() % 2;//����� ��� ������

    y += j*100;
    j++;
}

void Enemy::DrawWindowEnemy(RenderWindow& window, Pole&Stone, Hero &hero)
{
    int true_y;
    int true_x;
    coords_x++;
    
   // std::cout << move << std::endl;

    if (coords_x == 10) {
        x += move;
        y += move_y;
        //std::cout << "x " << x << std::endl;
        //std::cout << "y " << y << std::endl;
            if (Stone.Destroy_stone_coords[(x + 50)/ 50][y / 50]||x>=1550)//���� �� ��������� � �����
            {
                if (move_x)
                {
                    move = -1;
                }
            }
        
        
        
            else if (Stone.Destroy_stone_coords[(x - move) / 50][y / 50] == 1||x<=0)//���� �� ��������� � �����
            {
                if (move_x)
                {

                    move = 1;
                }
            }

            if ((x-25==hero.coords_x&&y==hero.coords_y)|| (x + 25 == hero.coords_x && y == hero.coords_y))//�������� � �������
            {
                //�������� ��������
                //sleep(seconds(3));
                //window.close();
            }

        coords_x = 0;
    }

    if (x%100==0)//�������� �����/����
    {
        true_y = rand() % 200;
        if (!true_y)
        {
            if (up_down&&!first_y)
            {
                move_y = 1;
                first_y = true;

            }
            else {
                if (!first_y)
                {
                     move_y = -1;
                     first_y = true;

                }
            }
            if (y-move_y <= 70)//���� �� ��������� � ��� � �������
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
            first_x = false;
        }
            if (Stone.Destroy_stone_coords[x / 50][(y+50) / 50]&&move_y == 1)//���� �� ��������� � �����
            {
                move_y = -1;
            }
            else if (Stone.Destroy_stone_coords[x / 50][y  / 50] && move_y == -1)//���� �� ��������� � �����
            {
                move_y = 1;
            }

    }
    if (y%100 == 0&&move==0)
    {
        true_x = rand() % 200;
        if (!true_x)
        {
            if (left_right && !first_x)
            {
                move = 1;
                first_x = true;
            }
            else {
                if (!first_x)
                {
                    move = -1;
                    first_x = true;

                }
            }
            if (x - move <= 70)//���� �� ��������� � ��� � �������
            {
                move = 1;
                //true_y = 0;
            }
            else if (x + move >= 1000)
            {
                // true_y = 0;
                move = -1;
            }
            move_y = 0;
            move_x = true;
            first_y = false;//���� �������� �������
        }
        if (Stone.Destroy_stone_coords[(x+50) / 50][y  / 50] && move == 1)//���� �� ��������� � �����
        {
            move = -1;
        }
        else if (Stone.Destroy_stone_coords[x / 50][y / 50] && move_y == 1)//���� �� ��������� � �����
        {
            move = 1;
        }
        


    }
        Enemy_sprite.setPosition(x, y);
        window.draw(Enemy_sprite);
        //std::cout <<"x: "<< x << '\n';
        //��������� ������ � ������ ����������� ������ ���� � ��� �� x
        
        
}

