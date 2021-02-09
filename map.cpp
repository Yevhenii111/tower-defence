#include "BG.hpp"

String Map::TileMap[];

Map::Map(int Level)
{
    HEIGHT_MAP = 20;
    WIDTH_MAP = 20;
    num = Level;
    wall_select = false;
    switch (num)
    {
    case 1:
        TileMap[0] = {"000000000t t00000000"}; //0
        TileMap[1] = {"000000000t tttttttt0"}; //1
        TileMap[2] = {"000000000t        t0"}; //2
        TileMap[3] = {"000000000tttttttt t0"}; //3
        TileMap[4] = {"000000000*0*0*0*t t0"};
        TileMap[5] = {"0tttttttttttttttt t0"};
        TileMap[6] = {"0t                t0"};
        TileMap[7] = {"0t tttttttttttttttt0"};
        TileMap[8] = {"0t t*0000000000000000"};
        TileMap[9] = {"0t t00000000000000000"}; //9
        TileMap[10] = {"0t tttttttttttttttt0"}; //10
        TileMap[11] = {"0t                t0"}; //11
        TileMap[12] = {"0tttttttttttttttt t0"}; //12
        TileMap[13] = {"000000000000000*t t0"}; //13
        TileMap[14] = {"0000000000000000t t0"}; //14
        TileMap[15] = {"000000000000000*t t0"}; //15
        TileMap[16] = {"000000000tttttttt t0"}; //16
        TileMap[17] = {"000000000t        t0"}; //17
        TileMap[18] = {"000000000t tttttttt0"}; //18
        TileMap[19] = {"000000000t t00000000"}; //19
        break;
    case 2:
        TileMap[0] = {"0tttttttttttttttt t0"};  //0
        TileMap[1] = {"0t          -     t0"};  //1
        TileMap[2] = {"0t ttttt ttttttt tt0"};  //2
        TileMap[3] = {"0t   t*t t*000*t  t0"};  //3
        TileMap[4] = {"00tt t0t tt0000tt t0"};  //4
        TileMap[5] = {"00t  t*t  t00000t t0"};  //5
        TileMap[6] = {"00t tt0tt t*000*t t0"};  //6
        TileMap[7] = {"00t t*00t ttttttt t0"};  //7
        TileMap[8] = {"00t t00*t         t0"};  //8
        TileMap[9] = {"00t t*00t ttttttt t0"};  //9
        TileMap[10] = {"00t t00*t t*0000t t0"}; //10
        TileMap[11] = {"00t t*00t t0000*t t0"}; //11
        TileMap[12] = {"00t t00*t t*0000t t0"}; //12
        TileMap[13] = {"0tt ttttt t0000*t t0"}; //13
        TileMap[14] = {"0t   -    t*0000t t0"}; //14
        TileMap[15] = {"0t ttttt tt0000*t t0"}; //15
        TileMap[16] = {"0t t*0*t-t*00000t t0"}; //16
        TileMap[17] = {"0t ttttt tttttttt t0"}; //17
        TileMap[18] = {"0t        -       t0"}; //18
        TileMap[19] = {"0tt ttttttttttttttt0"}; //19
        break;
    case 3:
        TileMap[0] = {"0tt ttttttttttttttt0"};  //0
        TileMap[1] = {"0tw               t0"};  //1
        TileMap[2] = {"0twttttt tttttttt t0"};  //2
        TileMap[3] = {"0twt00*t t*000*0t t0"};  //3
        TileMap[4] = {"0twt*00t t00*000t t0"};  //4
        TileMap[5] = {"0twt00*t tttt00*t t0"};  //5
        TileMap[6] = {"0twt*00t    t*00t t0"};  //6
        TileMap[7] = {"0twt00*tttt-ttttt t0"};  //7
        TileMap[8] = {"0twt*0000*t       t0"};  //8
        TileMap[9] = {"0twtttttttt ttttt t0"};  //9
        TileMap[10] = {"0twt        t*00t t0"}; //10
        TileMap[11] = {"0twt ttttt tt00*t t0"}; //11
        TileMap[12] = {"0twt t*0*t t*000t t0"}; //12
        TileMap[13] = {"0twt ttttt-t000*t t0"}; //13
        TileMap[14] = {"0twt       t*000t t0"}; //14
        TileMap[15] = {"0twttttttt t000*t t0"}; //15
        TileMap[16] = {"0twt*0*0*t t*000t t0"}; //16
        TileMap[17] = {"0twttttttt tttttt-t0"}; //17
        TileMap[18] = {"0twwwwwwww        t0"}; //18
        TileMap[19] = {"0ttttttttt tttttttt0"}; //19
        break;
    case 4:
        TileMap[0] = {"000ttttttt tttttttt0"};
        TileMap[1] = {"000t              t0"};
        TileMap[2] = {"0ttt tttttwtttttt t0"};
        TileMap[3] = {"0t*t t*0*twt*00*t t0"};
        TileMap[4] = {"0ttt-tttttwtttttt t0"};
        TileMap[5] = {"0t                t0"};
        TileMap[6] = {"0t tttttttwtttttt t0"};
        TileMap[7] = {"0t t*000*twt*000t t0"};
        TileMap[8] = {"0t t00*00twt000*t t0"};
        TileMap[9] = {"0t tttttttwtttttt-t0"};
        TileMap[10] = {"0t                t0"};
        TileMap[11] = {"0ttttt tttwtttttt t0"};
        TileMap[12] = {"0t*0*t t*twt*000t t0"};
        TileMap[13] = {"0ttttt t0twt000*t t0"};
        TileMap[14] = {"0t     t*twt*000t t0"};
        TileMap[15] = {"0t ttttt0twtttttt t0"};
        TileMap[16] = {"0t t*0*0*t-       t0"};
        TileMap[17] = {"0t ttttttt tttttttt0"};
        TileMap[18] = {"0t         t*t000000"};
        TileMap[19] = {"0ttttttttt ttt000000"};
        break;
    case 5:
         TileMap[0] = {"t tttttttttttttttttt"};
         TileMap[1] = {"t                  t"};
         TileMap[2] = {"tttttttttttttttttt t"};
         TileMap[3] = {"t*t    t*t     t*t t"};
         TileMap[4] = {"ttt tt ttt ttt ttt t"};
         TileMap[5] = {"t   -      -       t"};
         TileMap[6] = {"t tttttttttttttttttt"};
         TileMap[7] = {"t t*t     t*t    t*t"};
         TileMap[8] = {"t ttt ttt ttt tt ttt"};
         TileMap[9] = {"t       -      -   t"};
        TileMap[10] = {"tttttttttttttttttt t"};
        TileMap[11] = {"t*t    t*t     t*t t"};
        TileMap[12] = {"ttt tt ttt ttt ttt t"};
        TileMap[13] = {"t    -     -       t"};
        TileMap[14] = {"t tttttttttttttttttt"};
        TileMap[15] = {"t t*tt    t*ttt    t"};
        TileMap[16] = {"t tt*t tt ttt*t tt t"};
        TileMap[17] = {"t tttt tt ttttt tt t"};
        TileMap[18] = {"t       -        - t"};
        TileMap[19] = {"tttttttttttttttttt t"};
        break;
    }
}

Cell::Cell(int type)
{
    type_Cell = type;

    switch (type_Cell)
    {
    case 0: //клетка
        image_Cell.loadFromFile("images/ground1.png");
        break;
    case 1: //клетка где можно построить башню
        image_Cell.loadFromFile("images/ground_tow.png");
        break;
    case 2: //дорожка
        image_Cell.loadFromFile("images/ground_stone.jpg");
        break;
    case 3: // fakel
        image_Cell.loadFromFile("images/torch1.png");
        break;
    case 4: //wall
        image_Cell.loadFromFile("images/wall1.jpg");
        break;
    }
    texture_Cell.loadFromImage(image_Cell);
    sprite_Cell.setTexture(texture_Cell);
    if (type_Cell == 0)
        sprite_Cell.setColor(Color(150, 150, 150));
}

void map_draw(RenderWindow &window, bool &pause_bool, int &level_life, Data &data, int &level)
{
    Sprite sprite;
    static Cell c(0);
    static Cell c_tow(1);
    static Cell c_trp(2);
    static Cell torch(3);
    static Cell wall(4);
    static Map map(level);
    for (int i = 0; i < map.HEIGHT_MAP; i++) //y
    {
        for (int j = 0; j < map.WIDTH_MAP; j++) //x
        {
            if (map.TileMap[i][j] == '0')
                sprite = c.sprite_Cell;
            if (map.TileMap[i][j] == '*' || map.TileMap[i][j] == '1')
                sprite = c_tow.sprite_Cell;
            if (map.TileMap[i][j] == ' ' || map.TileMap[i][j] == '-')
            {
                sprite = c_trp.sprite_Cell;
                if (map.wall_select && map.TileMap[i][j] == '-')
                {
                    sprite.setColor(Color(0, 255, 0, 150));
                }
            }
            if (map.TileMap[i][j] == 't')
                sprite = torch.sprite_Cell;
            if (map.TileMap[i][j] == 'w')
                sprite = wall.sprite_Cell;
            sprite.setPosition(j * 32, i * 32);
            window.draw(sprite);
        }
    }
    bg_draw(window, pause_bool, level_life, map, data, level);
}

String Map::getTileCode(int i, int j)
{
    if ((i > -1) && (i < HEIGHT_MAP) && (j > -1) && (j < WIDTH_MAP))
    {
        return TileMap[i][j];
    }

    return "-5";
}

void Map::setTileCode(int i, int j, char code)
{
    if ((i > -1) && (i < HEIGHT_MAP) && (j > -1) && (j < WIDTH_MAP))
    {
        TileMap[i][j] = code;
    }
}