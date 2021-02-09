#include "levels.hpp"
#include "menu.hpp"

int main()
{
    int level = 0;
    RenderWindow window(VideoMode(840, 640), "Tower defence!");
    level = menu_func(window);
    gameRunning(window, level);
    return 0;
}