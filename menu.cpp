#include "menu.hpp"

int menu_func(RenderWindow &window)
{
    Image lvlImage1, lvlImage2, lvlImage3, lvlImage4, lvlImage5, exitImage;
    Texture lvlTexture1, lvlTexture2, lvlTexture3, lvlTexture4, lvlTexture5, ExitTexture, backgroundTexture;
    lvlImage1.loadFromFile("images/lvl1.png");
    lvlImage2.loadFromFile("images/lvl2.png");
    lvlImage3.loadFromFile("images/lvl3.png");
    lvlImage4.loadFromFile("images/lvl4.png");
    lvlImage5.loadFromFile("images/lvl5.png");
    exitImage.loadFromFile("images/Exit.png");
    lvlImage1.createMaskFromColor(Color(255, 255, 255));
    lvlImage2.createMaskFromColor(Color(255, 255, 255));
    lvlImage3.createMaskFromColor(Color(255, 255, 255));
    lvlImage4.createMaskFromColor(Color(255, 255, 255));
    lvlImage5.createMaskFromColor(Color(255, 255, 255));
    exitImage.createMaskFromColor(Color(255, 255, 255));
    lvlTexture1.loadFromImage(lvlImage1);
    lvlTexture2.loadFromImage(lvlImage2);
    lvlTexture3.loadFromImage(lvlImage3);
    lvlTexture4.loadFromImage(lvlImage4);
    lvlTexture5.loadFromImage(lvlImage5);
    ExitTexture.loadFromImage(exitImage);
    backgroundTexture.loadFromFile("images/MenuBG.jpg");
    Sprite menu1(lvlTexture1), menu2(lvlTexture2), menu3(lvlTexture3), menu4(lvlTexture4), menu5(lvlTexture5), menuExit(ExitTexture), menuBg(backgroundTexture);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(0, 30);
    menu2.setPosition(0, 110);
    menu3.setPosition(0, 190);
    menu4.setPosition(0, 270);
    menu5.setPosition(0, 350);
    menuExit.setPosition(0, 525);
    menuBg.setPosition(0, 0);

    while (isMenu)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        menu1.setColor(Color::Black);
        menu2.setColor(Color::Black);
        menu3.setColor(Color::Black);
        menu4.setColor(Color::Black);
        menu5.setColor(Color::Black);
        menuExit.setColor(Color::Black);
        menuNum = 0;
        window.clear();

        if (IntRect(0, 30, 200, 60).contains(Mouse::getPosition(window)))
        {
            menu1.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(0, 110, 200, 60).contains(Mouse::getPosition(window)))
        {
            menu2.setColor(Color::Red);
            menuNum = 2;
        }
        if (IntRect(0, 190, 200, 60).contains(Mouse::getPosition(window)))
        {
            menu3.setColor(Color::Red);
            menuNum = 3;
        }
        if (IntRect(0, 270, 200, 60).contains(Mouse::getPosition(window)))
        {
            menu4.setColor(Color::Red);
            menuNum = 4;
        }
        if (IntRect(0, 350, 200, 60).contains(Mouse::getPosition(window)))
        {
            menu5.setColor(Color::Red);
            menuNum = 5;
        }
        if (IntRect(0, 525, 120, 60).contains(Mouse::getPosition(window)))
        {
            menuExit.setColor(Color::Red);
            menuNum = 6;
        }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1)
            {
                isMenu = false;
                return 1;
            }
            if (menuNum == 2)
            {
                isMenu = false;
                return 2;
            }
            if (menuNum == 3)
            {
                isMenu = false;
                return 3;
            }
            if (menuNum == 4)
            {
                isMenu = false;
                return 4;
            }
            if (menuNum == 5)
            {
                isMenu = false;
                return 5;
            }
            if (menuNum == 6)
            {
                window.close();
                isMenu = false;
                return 6;
            }
        }

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        window.draw(menu5);
        window.draw(menuExit);

        window.display();
    }
}