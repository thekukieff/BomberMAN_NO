#include "Start.hpp"
#include "Hero_sprite.hpp"
#include "Pole.hpp"
#include "Bomb.hpp"
#include "Enemy.hpp"


void Start()
{
    srand(time(NULL));
    bool boom = false;

    RenderWindow window(VideoMode(1680,1050), "Bomberman!");//запуск окна

    Pole DestroyStone, IndestructibleStone, BG, Door;
    Hero hero;
    Bomb bomb;
    Enemy enemy1,enemy2,enemy3,enemy4, enemy5;
    Clock clock_bomb, clock_game;

    const int MAX_TIME = 300;
    int timer_bomb = 0;
    int timer_game = 0;

    IndestructibleStone.DrawIndestructibleStone();//вся отрисовка неломающегося камня
    DestroyStone.DrawDestroyStone();//вся отрисовка ломающегося камня
    BG.Background();
    Door.Door(DestroyStone);
    enemy1.DrawEnemyLeft();
    enemy2.DrawEnemyLeft();
    enemy3.DrawEnemyLeft();
    enemy4.DrawEnemyLeft();
    enemy5.DrawEnemyLeft();
    //вынести в отдельную функцию
    //разобраться с рандомом



    hero.Face_Hero_stay();

    while (window.isOpen())//главный цикл программы
    
    {
        timer_game = clock_game.getElapsedTime().asSeconds();
        std::cout << timer_game << std::endl;
        //std::cout << timer_bomb<<std::endl;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();//повтор
        if (!boom)
        {
            clock_bomb.restart();
            timer_bomb -= timer_bomb;
        }


        BG.DrawBackground(window);
        Door.DrawDoor(window);
        IndestructibleStone.DrawPole(window);
        DestroyStone.WindowDrawDestroy(window);
        hero.Draw_Hero_Stay(window);
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Left))//нажатие клавиши 
        {
            hero.Left_Hero_stay();//Анимация разворота

            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x - hero.move) / 50][hero.coords_y / 50])//чтоб не врезаться в стену
            {
                if (!(hero.coords_x == bomb.x+50 && hero.coords_y == bomb.y))
                {

                    hero.Draw_Left_Hero_Stay(window);//отрисовка 
                    event.type = Event::KeyReleased;//отпускание клавиши
                }
            }

        }

        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Right))
        {
            hero.Right_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x + 50) / 50][hero.coords_y / 50])
            {
                if (!(hero.coords_x == bomb.x-50 && hero.coords_y == bomb.y ))
                {
                    hero.Draw_Right_Hero_Stay(window);
                    event.type = Event::KeyReleased;
                   
                }
            }
        }
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Up))
        {
            hero.Up_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y - hero.move) / 50])
            {
                if (!(hero.coords_x == bomb.x && hero.coords_y == bomb.y + 50))
                {

                hero.Draw_Up_Hero_Stay(window);
                event.type = Event::KeyReleased;
                }
            }
        }
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Down))
        {
            hero.Face_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y + 50) / 50])
            {
                if (!(hero.coords_x == bomb.x&&hero.coords_y==bomb.y-50))
                {

                hero.Draw_Down_Hero_Stay(window);
                event.type = Event::KeyReleased;
                }
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Escape)||timer_game == MAX_TIME)
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            system("cls");
            std::cout << "\nenemyx " << " " << enemy1.x << " " << enemy2.x << " " << enemy3.x << " " << enemy4.x << " " << enemy5.x;

        }//временно
        
        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::W)&&!bomb.bomb_count)
        {

            if ((hero.coords_x % 100 == 0 && hero.coords_y % 100 == 0)|| (hero.coords_x % 100 == 50 && hero.coords_y % 100 == 0)||
                (hero.coords_x % 100 == 0 && hero.coords_y % 100 == 50)||
                (hero.coords_x % 100 == 50 && hero.coords_y % 100 == 50))//можно ли поставить бомбу
            {//поставить звук типо нельзя ставить  мину;
                boom = true;
                bomb.bomb_count = 1;


            bomb.DrawBomb(hero);
            }
            
            event.type = Event::KeyPressed;


        }
        enemy1.DrawWindowEnemy(window, DestroyStone, hero);
        enemy2.DrawWindowEnemy(window, DestroyStone, hero);
        enemy3.DrawWindowEnemy(window, DestroyStone, hero);
        enemy4.DrawWindowEnemy(window, DestroyStone, hero);
        enemy5.DrawWindowEnemy(window, DestroyStone, hero);
        
        bomb.DrawWindowBomb(window);
        //sleep(seconds(10));
        if (hero.coords_x==Door.door_x*50&&hero.coords_y==Door.door_y*50)
        {
            std::cout << "зашел\n";
            if (!enemy1.life&&!enemy2.life&&!enemy3.life&&!enemy4.life&&!enemy5.life)
            {
                std::cout << "\nWIN";
                window.close();
            }
        }

        if(boom)
        {

            timer_bomb = clock_bomb.getElapsedTime().asSeconds();
            if (timer_bomb == 3)//таймер бомбы
            {

                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy1, hero);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy2, hero);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy3, hero);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy4, hero);
                bomb.DestroyBomb(DestroyStone.Destroy_stone_coords, enemy5, hero);
                bomb.BOOM(timer_bomb, boom,clock_bomb);

                clock_bomb.restart();
                timer_bomb -= timer_bomb;
                boom = false;
                bomb.bomb_count = 0;
            }

        }
        window.display();//повтор
    }


}


