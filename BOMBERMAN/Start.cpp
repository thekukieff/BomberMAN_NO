#include "Start.hpp"
#include "Hero_sprite.hpp"
#include "Pole.hpp"
#include "Bomb.hpp"
#include "Enemy.hpp"


void Start()
{
    srand(time(NULL));


    RenderWindow window(VideoMode(1680,1050), "Bomberman!");//запуск окна

    Pole DestroyStone, IndestructibleStone, BG, Door;
    Hero hero;
    Bomb bomb;
    Enemy enemy1,enemy2,enemy3,enemy4, enemy5;

    IndestructibleStone.DrawIndestructibleStone();//вс€ отрисовка неломающегос€ камн€
    DestroyStone.DrawDestroyStone();//вс€ отрисовка ломающегос€ камн€
    BG.Background();
    Door.Door(DestroyStone);
    enemy1.DrawEnemyLeft();
    enemy1.x = rand() % 1500 + 50;
    enemy2.DrawEnemyLeft();
    enemy2.x = rand() % 1500 + 50;
    enemy3.DrawEnemyLeft();
    enemy3.x = rand() % 1500 + 50;
    enemy4.DrawEnemyLeft();
    enemy4.x = rand() % 1500 + 50;
    enemy5.DrawEnemyLeft();
    enemy5.x = rand() % 1500 + 50;
    //вынести в отдельную функцию
    //разобратьс€ с рандомом
    std::cout<<std::endl << enemy1.x << " " << enemy2.x << " " << enemy3.x;



    hero.Face_Hero_stay();

    while (window.isOpen())//главный цикл программы
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();//повтор



        BG.DrawBackground(window);
        Door.DrawDoor(window);
        IndestructibleStone.DrawPole(window);
        DestroyStone.WindowDrawDestroy(window);
        hero.Draw_Hero_Stay(window);
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Left))//нажатие клавиши 
        {
            hero.Left_Hero_stay();//јнимаци€ разворота

            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x - hero.move) / 50][hero.coords_y / 50])//чтоб не врезатьс€ в стену
            {
                hero.Draw_Left_Hero_Stay(window);//отрисовка 
                event.type = Event::KeyReleased;//отпускание клавиши
            }




        }

        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Right))
        {
            hero.Right_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[(hero.coords_x + 50) / 50][hero.coords_y / 50])
            {
                hero.Draw_Right_Hero_Stay(window);
                event.type = Event::KeyReleased;
            }
        }
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Up))
        {
            hero.Up_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y - hero.move) / 50])
            {
                hero.Draw_Up_Hero_Stay(window);
                event.type = Event::KeyReleased;
            }
        }
        
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Down))
        {
            hero.Face_Hero_stay();
            if (!DestroyStone.Destroy_stone_coords[hero.coords_x / 50][(hero.coords_y + 50) / 50])
            {
                hero.Draw_Down_Hero_Stay(window);
                event.type = Event::KeyReleased;
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            system("cls");
            std::cout << "\nenemyx " << " " << enemy1.x << " " << enemy2.x << " " << enemy3.x << " " << enemy4.x << " " << enemy5.x;

        }//временно
        
        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::W))
        {

            bomb.DrawBomb(hero);
            bomb.DestroyBomb(hero.coords_x, hero.coords_y, DestroyStone.Destroy_stone_coords,enemy1);
            bomb.DestroyBomb(hero.coords_x, hero.coords_y, DestroyStone.Destroy_stone_coords, enemy2);
            bomb.DestroyBomb(hero.coords_x, hero.coords_y, DestroyStone.Destroy_stone_coords, enemy3);
            bomb.DestroyBomb(hero.coords_x, hero.coords_y, DestroyStone.Destroy_stone_coords, enemy4);
            bomb.DestroyBomb(hero.coords_x, hero.coords_y, DestroyStone.Destroy_stone_coords, enemy5);

            
            
            
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
            if (enemy1.x==-100&&enemy2.x==-100&&enemy3.x==-100&&enemy4.x==-100&&enemy5.x==-100)
            {
                std::cout << "\nWIN";
                window.close();
            }
        }





        window.display();//повтор
    }


}


