#include "enemy.hpp"

int Enemy::num_i = 1;
int Enemy::wave = 0;
int Enemy::spawn_type = 1;
float Enemy::x_beg = 0;
float Enemy::y_beg = 0;
std::list<Enemy *> Enemy::enemyes;
std::list<Enemy *>::iterator Enemy::it;
float Enemy::enemy_timer = 0;
float Enemy::time = 6000;
float Enemy::spawn_kof = 1;
bool Enemy::end_enemyes = false;
Vector2i Enemy::start(0, 0);
Vector2i Enemy::finish(0, 0);

Enemy::Enemy(float X, float Y, float W, float H, int Number, int Type)
{
    life = true;
    trace_life = true;
    new_wall = false;
    dir = 0;
    dx = 0;
    dy = 0;
    speed = 0;
    i = 0;
    i_trace = 0;
    i_trace_beg = 10;
    ii = 0;
    CurrentFrame = 0;
    timer_trace = 1;
    type = Type;
    health = 10;
    w = W;
    h = H;
    number = Number;
    if (type == 1)
    {
        image.loadFromFile("images/hero.png");
        image.createMaskFromColor(Color(41, 33, 59));
    }
    else
    {
        if (type == 2)
        {
            image.loadFromFile("images/dragon.png");
            image.createMaskFromColor(Color(255, 255, 255));
        }
    }
    image_trace.loadFromFile("images/trace.png");
    image_trace.createMaskFromColor(Color(255, 255, 255));
    texture_trace.loadFromImage(image_trace);
    sprite_trace.setTexture(texture_trace);
    sprite_trace.setColor(Color::Black);
    for (int i = 0; i < 3; i++)
    {
        SpriteTrace.push_back(sprite_trace);
        SpriteTrace[i].setPosition(0, -32);
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X;
    y = Y;
    sprite.setTextureRect(IntRect(0, 0, w, h));
    if (type == 1)
    {
        sprite.setScale(0.625, 0.625);
    }
    else
    {
        if (type == 2)
        sprite.setScale(0.75, 0.75);
    }
    SearchWay(start.y, start.x, finish.y, finish.x, way, type);
}

void Enemy::update(float time)
{
    switch (dir)
    {
    case 0:
        dx = speed;
        dy = 0;
        break; //вправо
    case 1:
        dx = -speed;
        dy = 0;
        break; //влево
    case 2:
        dx = 0;
        dy = speed;
        break; //вниз
    case 3:
        dx = 0;
        dy = -speed;
        break; //вверх
    }

    x += dx * time;
    y += dy * time;
    speed = 0;
    sprite.setPosition(x, y);
    hb_update(health, x, y);
}

void Enemy::begin_values(float Time, int Wave, float X_beg, float Y_beg, Vector2i Start, Vector2i Finish, int &level)
{
    num_i = 1;
    enemy_timer = 0;
    time = Time;
    spawn_kof = 1;
    end_enemyes = false;
    wave = Wave;
    x_beg = X_beg;
    y_beg = Y_beg;
    start = Start;
    finish = Finish;
    spawn_type = 1;
    Map map(level);
}

void Enemy::spawn()
{
    if (enemy_timer * spawn_kof > 1500 && !end_enemyes)
    {
        if (spawn_type == 1)
        {
            enemyes.push_back(new Enemy(x_beg, y_beg, 96.0, 96.0, num_i, spawn_type));
        }
        else
        {
            if (spawn_type == 2)
                enemyes.push_back(new Enemy(x_beg - 6, y_beg, 96.0, 96.0, num_i, spawn_type));
        }
        enemy_timer = 0;
        if (num_i == 5)
        {
            enemy_timer -= time;
            spawn_kof = 2;
            wave--;
        }
        if (num_i == 15)
        {
            enemy_timer -= time;
            spawn_kof = 1.5;
            wave--;
        }
        if (num_i == 30)
        {
            enemy_timer -= time;
            spawn_kof = 2.5;
            wave--;
            spawn_type = 2;
        }
        if (num_i == 40)
        {
            enemy_timer -= time;
            spawn_kof = 2;
            wave--;
        }
        if (num_i == 60)
        {
            enemy_timer -= time;
            spawn_kof = 2.5;
            wave--;
        }
        if (num_i == 70)
        {
            enemy_timer -= time;
            spawn_kof = 1.5;
            wave--;
        }
        if (!wave)
            end_enemyes = true;
        num_i++;
    }
}

void Enemy::draw(RenderWindow &window, float &time, Data &data)
{
    for (it = enemyes.begin(); it != enemyes.end(); it++)
        for (auto itt = (*it)->SpriteTrace.begin(); itt != (*it)->SpriteTrace.end(); itt++)
            window.draw(*itt);

    for (it = enemyes.begin(); it != enemyes.end();)
    {
        Enemy *p = *it;
        p->lion_and_trace(window, time, data);
        if (p->trace_life == false)
        {
            it = enemyes.erase(it);
            delete p;
        }
        else
            it++;
    }
}

void Enemy::trip(float &time, Data &data)
{
    if (new_wall)
        if (type == 1)
        {
            int x = way[i + 1];
            int y = way[i];
            way.clear();
            SearchWay(y, x, finish.y, finish.x, way, type);
            new_wall = false;
            i = 0;
        }

    static int x_d = 14;
    static int y_d = 28;
    if (type == 1)
    {
        x_d = 14;
        y_d = 28;
        speed = 0.1;
    }
    else
    {
        if (type == 2)
        {
            x_d = 20;
            y_d = 40;
            speed = 0.13;
        }
    }
    
    if (way[i] * 32 - y_d > (y + 1)) //вниз
    {
        dir = 2;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 3)
            CurrentFrame -= 3;
        sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
        if ((way[i] * 32 - y_d - y) < 3)
        {
            y = way[i] * 32 - y_d;
            x = way[i + 1] * 32 - x_d;
            SpriteTrace[i_trace].setRotation(-90);
            SpriteTrace[i_trace].setPosition(x + 20, y + 58);
            i_trace++;
            if (i_trace == 3)
            {
                i_trace = 0;
            }
            i += 2;
        }
    }
    else
    {
        if (way[i + 1] * 32 - x_d < (x - 1)) //лево
        {
            dir = 1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
            if ((x - (way[i + 1] * 32 - x_d)) < 3)
            {
                x = way[i + 1] * 32 - x_d;
                y = way[i] * 32 - y_d;
                SpriteTrace[i_trace].setRotation(0);
                SpriteTrace[i_trace].setPosition(x + 20, y + 40);
                i_trace++;
                if (i_trace == 3)
                {
                    i_trace = 0;
                }
                i += 2;
            }
        }
        else
        {
            if (way[i + 1] * 32 - x_d > (x + 1)) //право
            {
                dir = 0;
                CurrentFrame += 0.005 * time;
                if (CurrentFrame > 3)
                    CurrentFrame -= 3;
                sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));
                if ((way[i + 1] * 32 - x_d - x) < 3)
                {
                    x = way[i + 1] * 32 - x_d;
                    y = way[i] * 32 - y_d;
                    SpriteTrace[i_trace].setRotation(180);
                    SpriteTrace[i_trace].setPosition(x + 38, y + 60);
                    i_trace++;
                    if (i_trace == 3)
                    {
                        i_trace = 0;
                    }
                    i += 2;
                }
            }
            else
            {
                if (way[i] * 32 - y_d < (y - 1)) //вверх
                {
                    dir = 3;
                    CurrentFrame += 0.005 * time;
                    if (CurrentFrame > 3)
                        CurrentFrame -= 3;
                    sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96));
                    if ((y - (way[i] * 32 - y_d)) < 3)
                    {
                        y = way[i] * 32 - y_d;
                        x = way[i + 1] * 32 - x_d;
                        SpriteTrace[i_trace].setRotation(90);
                        SpriteTrace[i_trace].setPosition(x + 40, y + 42);
                        i_trace++;
                        if (i_trace == 3)
                        {
                            i_trace = 0;
                        }
                        i += 2;
                    }
                }
            }
        }
    }
    update(time);
    if (i >= way.size())
    {
        data.health -= 1;
        life = false;
    }
    if (health <= 0)
    {
        data.score += 1;
        data.coins += 1;
        life = false;
    }
}

void Enemy::lion_and_trace(RenderWindow &window, float &time, Data &data)
{
    timer_trace += time;
    if (!life && trace_life && (timer_trace > 300))
    {
        timer_trace = 0;
        auto it_tr = SpriteTrace.begin();
        std::advance(it_tr, i_trace - ii);
        SpriteTrace.erase(it_tr);
        i_trace++;
        ii++;
        if (i_trace == 3)
        {
            i_trace_beg = i_trace - ii;
            i_trace = 0;
            ii = 0;
        }
        if (i_trace == i_trace_beg)
        {
            trace_life = false;
        }
    }
    if (life == true)
    {
        trip(time, data);
        window.draw(sprite);
        window.draw(hb_sprite);
        window.draw(bar);
        timer_trace = 0;
    }
}

FloatRect Enemy::getRect()
{
    return FloatRect(x, y, w, h);
}