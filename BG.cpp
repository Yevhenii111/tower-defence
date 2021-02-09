#include "BG.hpp"

BG::BG(int type)
{
    type_BG = type;
    select_tower_BG = false;
    tower_type_BG = 0;
    switch (type_BG)
    {
    case 0: // свиток
        image_BG.loadFromFile("images/BG.jpg");
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(640, 0);
        break;
    case 1: //exit
        image_BG.loadFromFile("images/Exit.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setScale(0.75, 0.75); //90, 45
        sprite_BG.setPosition(750, 590);
        break;
    case 2: // menu
        image_BG.loadFromFile("images/Menu.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(640, 590);
        break;
    case 3: // pause
        image_BG.loadFromFile("images/Pause.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(650, 470);
        break;
    case 4: // restart
        image_BG.loadFromFile("images/Restart.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(650, 530);
        break;
    case 5: // tower
        image_BG.loadFromFile("images/tower_menu.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(650, 200);
        tower_type_BG = 1;
        break;
    case 6: //health
        image_BG.loadFromFile("images/health.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(640, 17);
        sprite_BG.setColor(Color::Black);
        break;
    case 7: //score
        image_BG.loadFromFile("images/score.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(635, 80);
        sprite_BG.setColor(Color::Black);
        break;
    case 8: //coins
        image_BG.loadFromFile("images/coins.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(635, 130);
        sprite_BG.setColor(Color::Black);
        break;
    case 9: //gameover
        image_BG.loadFromFile("images/GameOver.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(0, 128);
        sprite_BG.setColor(Color::Red);
        break;
    case 10: //gameoverBG
        image_BG.create(640, 640, Color(128, 128, 128, 200));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(0, 0);
        break;
    case 11: // wall
        image_BG.loadFromFile("images/wall_menu.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(750, 200);
        tower_type_BG = 2;
        break;
    case 12: //gameover
        image_BG.loadFromFile("images/win.png");
        image_BG.createMaskFromColor(Color(255, 255, 255));
        texture_BG.loadFromImage(image_BG);
        sprite_BG.setTexture(texture_BG);
        sprite_BG.setPosition(0, 128);
        sprite_BG.setColor(Color::Red);
        break;
    }
}

void bg_draw(RenderWindow &window, bool &pause_bool, int &level_life, Map &map, Data &data, int &level)
{
    static int i = 0;
    int num = 0;
    static BG bg(0);
    static BG exit(1);
    static BG menu(2);
    static BG pause(3);
    static BG restart(4);
    static BG tower(5);
    static BG health(6);
    static BG score(7);
    static BG coins(8);
    static BG wall(11);

    exit.sprite_BG.setColor(Color::Black);
    menu.sprite_BG.setColor(Color::Black);
    pause.sprite_BG.setColor(Color::Black);
    restart.sprite_BG.setColor(Color::Black);

    if (IntRect(750, 590, 90, 45).contains(Mouse::getPosition(window))) //exit
    {
        exit.sprite_BG.setColor(Color::Red);
        num = 1;
    }
    if (IntRect(640, 590, 105, 45).contains(Mouse::getPosition(window))) //menu
    {
        menu.sprite_BG.setColor(Color::Red);
        num = 2;
    }
    if (IntRect(660, 470, 160, 60).contains(Mouse::getPosition(window))) //pause
    {
        pause.sprite_BG.setColor(Color::Red);
        num = 3;
    }
    if (IntRect(650, 530, 180, 54).contains(Mouse::getPosition(window))) //restart
    {
        restart.sprite_BG.setColor(Color::Red);
        num = 4;
    }
    if (IntRect(650, 200, 80, 120).contains(Mouse::getPosition(window)))
    {
        num = 5;
    }
    if (IntRect(750, 200, 80, 120).contains(Mouse::getPosition(window)))
    {
        num = 6;
    }
    if (Mouse::isButtonPressed(Mouse::Left) && i > 50)
    {
        if (num == 1)
        {
            level = 6;
            window.close();
        }
        if (num == 2)
        {
            pause_bool = true;
            i = 0;
            wall.select_tower_BG = false;
            wall.sprite_BG.setColor(Color::White);
            tower.select_tower_BG = false;
            tower.sprite_BG.setColor(Color::White);
            level = menu_func(window);
        }
        if (num == 3)
        {
            if (!pause_bool)
            {
                pause_bool = true;
                i = 0;
            }
            else
            {
                pause_bool = false;
                i = 0;
            }
        }
        if (num == 4)
        {
            wall.select_tower_BG = false;
            tower.select_tower_BG = false;
            wall.sprite_BG.setColor(Color::White);
            tower.sprite_BG.setColor(Color::White);
            Tower::towers.clear();
            Enemy::enemyes.clear();
            level_life = 0;
            i = 0;
        }
        if (num == 5)
        {
            tower.select_tower_BG = true;
            tower.sprite_BG.setColor(Color::Green);
            i = 0;
        }
        if (num == 6)
        {
            wall.select_tower_BG = true;
            wall.sprite_BG.setColor(Color::Green);
            map.wall_select = true;
            i = 0;
        }
    }
    if (tower.select_tower_BG && Mouse::isButtonPressed(Mouse::Left))
    {
        int towerType = tower.tower_type_BG;
        int price = 0;

        if (towerType == 1)
            price = 2;
        if (price > data.coins)
        {
            tower.select_tower_BG = false;
            tower.sprite_BG.setColor(Color::White);
        }
        else
        {
            Vector2i clickPosition = Mouse::getPosition(window);

            int x = clickPosition.y / 32;
            int y = clickPosition.x / 32;

            if (map.getTileCode(x, y) == '*' && i > 50)
            {
                map.setTileCode(x, y, '1');
                Tower::tower_type = tower.tower_type_BG;
                Tower::i_tow = x;
                Tower::j_tow = y;
                data.coins -= price;
            }
            if (Mouse::isButtonPressed(Mouse::Left) && i > 50)
            {
                tower.select_tower_BG = false;
                tower.sprite_BG.setColor(Color::White);
            }
        }
    }
    if (wall.select_tower_BG && Mouse::isButtonPressed(Mouse::Left))
    {
        int towerType = wall.tower_type_BG;
        int price = 0;

        if (towerType == 2)
            price = 1;
        if (price > data.coins)
        {
            wall.select_tower_BG = false;
            wall.sprite_BG.setColor(Color::White);
            map.wall_select = false;
        }
        else
        {
            Vector2i clickPosition = Mouse::getPosition(window);

            int x = clickPosition.y / 32;
            int y = clickPosition.x / 32;
            bool enemy_here = false;

            for (Enemy::it = Enemy::enemyes.begin(); Enemy::it != Enemy::enemyes.end(); Enemy::it++)
                if ((*Enemy::it)->getRect().intersects(FloatRect(y * 32 + 30, x * 32 + 30, 2, 2)))
                    enemy_here = true;
                    
            if (map.getTileCode(x, y) == '-' && !enemy_here)
            {
                map.setTileCode(x, y, 'w');
                for (Enemy::it = Enemy::enemyes.begin(); Enemy::it != Enemy::enemyes.end(); Enemy::it++)
                {
                    (*Enemy::it)->new_wall = true;
                }
                data.coins -= price;
            }
            if (Mouse::isButtonPressed(Mouse::Left) && i > 50)
            {
                wall.select_tower_BG = false;
                wall.sprite_BG.setColor(Color::White);
                map.wall_select = false;
            }
        }
    }
    i++;
    window.draw(bg.sprite_BG);
    window.draw(exit.sprite_BG);
    window.draw(menu.sprite_BG);
    window.draw(pause.sprite_BG);
    window.draw(restart.sprite_BG);
    window.draw(tower.sprite_BG);
    window.draw(health.sprite_BG);
    window.draw(score.sprite_BG);
    window.draw(coins.sprite_BG);
    window.draw(wall.sprite_BG);
}