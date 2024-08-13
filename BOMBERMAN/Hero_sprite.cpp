#include "Hero_sprite.hpp"


//RenderWindow window(sf::VideoMode(800, 800), "SFML works!");//������ ����
//CircleShape shape(100.f);//�������� �����
//
//Image Hero_image;
//
//
//Texture Hero_texture;
//
//
//Sprite Hero_sprite;



//Hero_texture.loadFromImage(Hero_image);
//Hero_image.loadFromFile("F:/�����/C++/07.06.24/sprites/norm_sprite.png");
//shape.setFillColor(sf::Color::Green);//��������� ���� �������
//Hero_sprite.setTexture(Hero_texture);
//Hero_sprite.setPosition(25, 25);

void Hero::Face_Hero_stay()//������, ����� �����
{


    Hero_image.loadFromFile("C:/Users/k.kukiev/source/repos/BOMBERMAN/sprites/stay_face.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x,coords_y);





}


void Hero::Left_Hero_stay()//������, ����� �����
{


    Hero_image.loadFromFile("C:/Users/k.kukiev/source/repos/BOMBERMAN/sprites/stay_left.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x,coords_y);
    



}

void Hero::Right_Hero_stay()//������, ����� ������
{
    Hero_image.loadFromFile("C:/Users/k.kukiev/source/repos/BOMBERMAN/sprites/stay_right.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);



}

void Hero::Up_Hero_stay()//������, ����� ������
{
    Hero_image.loadFromFile("C:/Users/k.kukiev/source/repos/BOMBERMAN/sprites/stay_up.png");
    Hero_image.createMaskFromColor(Color::White);//������� ����� (������ ���)
    Hero_texture.loadFromImage(Hero_image);

    Hero_sprite.setTexture(Hero_texture);
    Hero_sprite.setPosition(coords_x, coords_y);


}

void Hero::Draw_Down_Hero_Stay(RenderWindow& window)//���������, ����� �����
{



        if ( coords_x % 100 == 0) {//���� �� ��������� � �����
            if (coords_y+move<=1000)//max-50(=)
            {

                Hero_sprite.setPosition(coords_x, coords_y += move);
            }
        }
    

    window.draw(Hero_sprite);
}

void Hero::Draw_Left_Hero_Stay(RenderWindow& window)//���������, ����� �����
{


        if ( coords_y % 100 == 0) {//���� �� ��������� � �����
            if (coords_x - move >= 0) {
                Hero_sprite.setPosition(coords_x -= move, coords_y);
            }

        }


    window.draw(Hero_sprite);




}

void Hero::Draw_Up_Hero_Stay(RenderWindow& window)//���������, ����� ������
{


            if ( coords_x % 100 == 0) {//���� �� ��������� � �����
            
                if (coords_y-move>=50)
                {

                Hero_sprite.setPosition(coords_x, coords_y -= move);
                }
            
            }




        window.draw(Hero_sprite);


}

void Hero::Draw_Right_Hero_Stay(RenderWindow& window)//���������, ����� ������
{




            if (coords_y % 100 == 0) {//���� �� ��������� � �����
                
                if (coords_x + move <= 1550) {
                    Hero_sprite.setPosition(coords_x += move, coords_y);
                }
            }
        

        window.draw(Hero_sprite);


}


void Hero::Draw_Hero_Stay(RenderWindow& window)//���������, �����
{
    Hero_sprite.setPosition(coords_x, coords_y);
    window.draw(Hero_sprite);
}


