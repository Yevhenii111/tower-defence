#include "towers.hpp"

int Tower::tower_type = 0;
int Tower::i_tow = -1;
int Tower::j_tow = -1;
std::list<Tower *> Tower::towers;
std::list<Tower *>::iterator Tower::towers_it;

Tower::Tower()
{
    attackZone.setSize(Vector2f(96, 96));
    attackZone.setOrigin(48, 48);

    power = 0;
    distance_b = 0;
    is_attack = 0;
    ii = 1;
    bullet_life = false;
}

void Tower::full_create(int &i)
{
    if (tower_type == 1)
    {
        towers.push_front(new Tower());
        towers_it = towers.begin();
        (*towers_it)->create(tower_type);
        (*towers_it)->setPosition(Vector2f(j_tow * 32, (i_tow + 1) * 32));
        j_tow = -1;
        i_tow = -1;
        tower_type = 0;
        i = 0;
    }
}

void Tower::tower_game(RenderWindow &window, float &time, int &i, Data &data)
{
    int price = 0;
    
    for (towers_it = towers.begin(); towers_it != towers.end(); towers_it++)
    {
        (*towers_it)->draw(window);
        if (IntRect((*towers_it)->getPosition().x, (*towers_it)->getPosition().y, 32, -45).contains(Mouse::getPosition(window)) && Mouse::isButtonPressed(Mouse::Left) && i > 100 && (*towers_it)->power < 3)
        {
            if ((*towers_it)->power == 1)
            {
                price = 4;
            }
            else
            {
                price = 8;
            }
            if (price <= data.coins)
            {
                (*towers_it)->upgrade();
                data.coins -= price;
            }
            i = 0;
        }

        for (Enemy::it = Enemy::enemyes.begin(); Enemy::it != Enemy::enemyes.end(); Enemy::it++)
        {
            if (!(*towers_it)->is_attack || (*towers_it)->is_attack == (*Enemy::it)->number)
            {
                if ((*Enemy::it)->getRect().intersects((*towers_it)->attackZone.getGlobalBounds()) && (*Enemy::it)->life && !(*towers_it)->bullet_life)
                {
                    (*towers_it)->sprite_b.setPosition(Vector2f((*towers_it)->getPosition().x + 16, (*towers_it)->getPosition().y - 32));
                    (*towers_it)->pos_b = (*towers_it)->sprite_b.getPosition();
                    (*towers_it)->bullet_life = true;
                    (*towers_it)->is_attack = (*Enemy::it)->number;
                }
                else
                {
                    (*towers_it)->is_attack = false;
                }
                if ((*towers_it)->bullet_life)
                {
                    (*towers_it)->is_attack = (*Enemy::it)->number;
                    (*towers_it)->distance_b = sqrt(((*Enemy::it)->sprite.getPosition().x + 36 - (*towers_it)->pos_b.x) * ((*Enemy::it)->sprite.getPosition().x + 36 - (*towers_it)->pos_b.x) + ((*Enemy::it)->sprite.getPosition().y + 36 - (*towers_it)->pos_b.y) * ((*Enemy::it)->sprite.getPosition().y + 36 - (*towers_it)->pos_b.y));
                    if ((*towers_it)->distance_b > 10)
                    {
                        (*towers_it)->draw_b(window);
                        (*towers_it)->pos_b.x += 0.2 * time * ((*Enemy::it)->sprite.getPosition().x + 36 - (*towers_it)->pos_b.x) / (*towers_it)->distance_b;
                        (*towers_it)->pos_b.y += 0.2 * time * ((*Enemy::it)->sprite.getPosition().y + 36 - (*towers_it)->pos_b.y) / (*towers_it)->distance_b;
                        (*towers_it)->sprite_b.setPosition(Vector2f((*towers_it)->pos_b));
                    }
                    else
                    {
                        (*Enemy::it)->health -= (*towers_it)->power;
                        (*towers_it)->bullet_life = false;
                    }
                }
            }
        }
        i++;
    }
}

void Tower::create(int Type)
{
    int type = Type;
    if (type == 1)
    {
        image.loadFromFile("images/tower1.png");
        image.createMaskFromColor(Color(255, 255, 255));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, 32, 45));
        sprite.setOrigin(0, 45);

        image_b.loadFromFile("images/bullet.png");
        image_b.createMaskFromColor(Color(255, 255, 255));
        texture_b.loadFromImage(image_b);
        sprite_b.setTexture(texture_b);
        sprite_b.setOrigin(5, 5);
        power = 1;
    }
}

void Tower::setPosition(Vector2f position)
{
    sprite.setPosition(position);
    attackZone.setPosition(position.x + 16, position.y - 16);
}

void Tower::setPosition_b(Vector2f position)
{
    sprite_b.setPosition(position.x + 16, position.y - 30);
}

void Tower::draw(RenderWindow &window)
{
    window.draw(sprite);
}

void Tower::draw_b(RenderWindow &window)
{
    window.draw(sprite_b);
}

Vector2f Tower::getPosition()
{
    return sprite.getPosition();
}

Vector2f Tower::getPosition_b()
{
    return sprite_b.getPosition();
}

void Tower::upgrade()
{
    power++;
    sprite.setTextureRect(IntRect(32 + ((power - 1) * 48), 0, -48, 45));
    sprite.setOrigin(10 , 46);
}

Tower::~Tower()
{
}