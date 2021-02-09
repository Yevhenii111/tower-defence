#include "levels.hpp"

void gameRunning(RenderWindow &window, int &level)
{
    if (level == 6)
        return;

    if (level == 1)
    {
        if (!levels(window, level, 6000, 2, 306, -60, Vector2i(10, 0), Vector2i(10, 19), 1, 3))
        {
            gameRunning(window, level);
        }
        else
        {
            level = 2;
        }
    }

    if (level == 2)
    {
        if (!levels(window, level, 6000, 3, 530, -72, Vector2i(17, 0), Vector2i(3, 19), 2, 5))
        {
            gameRunning(window, level);
        }
        else
        {
            level = 3;
        }
    }
    if (level == 3)
    {
        if (!levels(window, level, 6000, 4, 82, -72, Vector2i(3, 0), Vector2i(10, 19), 5, 8))
        {
            gameRunning(window, level);
        }
        else
        {
            level = 4;
        }
    }
    if (level == 4)
    {
        if (!levels(window, level, 7000, 5, 306, -72, Vector2i(10, 0), Vector2i(10, 19), 6, 10))
        {
            gameRunning(window, level);
        }
        else
        {
            level = 5;
        }
    }
    if (level == 5)
    {
        if (!levels(window, level, 7000, 6, 18, -72, Vector2i(1, 0), Vector2i(18, 19), 5, 10))
        {
            gameRunning(window, level);
        }
        else
        {
            level = 1;
        }
    }
}

bool levels(RenderWindow &window, int &level, int spawn_tiwer, int wave, float beg_x, float beg_y, Vector2i begin, Vector2i end, int health, int coins)
{
    const int level_id = level;
    Enemy::begin_values(spawn_tiwer, wave, beg_x, beg_y, begin, end, level);
    Data data(health, coins);
    MyText mytext;
    BG gameover(9);
    BG gameoverBG(10);
    int level_life = 10, i = 0;
    bool pause_bool = false, after_over = false;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1300;
        if (pause_bool)
            time = 0;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                level = 6;
                return 0;
            }
        }

        Enemy::enemy_timer += time;
        Enemy::spawn();
        Tower::full_create(i);

        window.clear();

        map_draw(window, pause_bool, level_life, data, level);
        Enemy::draw(window, time, data);
        Tower::tower_game(window, time, i, data);

        mytext.text_display(window, data);
        if (level_life == 0 || level_id != level)
        {
            if (after_over)
            {
                Data::full_score -= data.score;
                after_over = false;
            }
            Tower::towers.clear();
            Enemy::enemyes.clear();
            return 0;
        }
        if (Enemy::end_enemyes && !Enemy::enemyes.size())
        {
            if (!pause_bool)
                Data::full_score += data.score;

            pause_bool = true;
            Tower::towers.clear();
            Enemy::enemyes.clear();
            if (level == 5)
            {
                BG gameoverBG(10);
                BG win(12);
                window.draw(gameoverBG.sprite_BG);
                window.draw(win.sprite_BG);
                MyText full_score(window);
            }
            else
            {
                return 1;
            }
        }
        if (data.health <= 0)
        {
            if (!pause_bool)
                Data::full_score += data.score;

            pause_bool = true;
            after_over = true;
            window.draw(gameoverBG.sprite_BG);
            window.draw(gameover.sprite_BG);
            MyText full_score(window);
            level_life = 1;
        }
        window.display();
    }
    return 0;
}