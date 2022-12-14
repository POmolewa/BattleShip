#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tial.h"
#include "BattleField.h"
#include "Text.h"
#include <vector>
#include "Battleship.h"
#include "CreateShip.h"
#include "Count.h"

using namespace std;
using namespace sf;

//Planning on making this the main game loop
int main()
{
    srand(time(0));
    Field* Player1tials = NULL;
    Field* Player2tials = NULL;

    Field* Player1tialsWater = NULL;
    Field* Player2tialsWater = NULL;

    vehicle* ship = NULL;
    BigShip* ship2 = NULL;
    Small* ship3 = NULL;

    vehicle* Pship = NULL;
    BigShip* Pship2 = NULL;
    Small* Pship3 = NULL;

    bool again = true;

    Count Total;
    Count Total2;

    Vector2f gone;

    vector <Vector2f> coords;

    gone.x = -100.0;
    gone.y = -100.0;

    int num = 64;

    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "BattleField Game", Style::Fullscreen);

    enum class State { Player1Screen, Player2Screen, Title, Player1ScreenWater, Player2ScreenWater};

    State state = State::Title;

    delete[] Player1tials;
    Player1tials = CreateTials(num);
    delete[] Player2tials;
    Player2tials = CreateTials(num);

    delete[] Player1tialsWater;
    Player1tialsWater = CreateTialsWater(num);
    delete[] Player2tialsWater;
    Player2tialsWater = CreateTialsWater(num);

    for (int i = 0; i < num; i++)
    {
        coords.push_back(Player1tials[i].GetLocation());
    }

    delete[] ship;
    ship = CreateShip(coords);

    delete[] ship2;
    ship2 = CreateShip2(coords);

    delete[] ship3;
    ship3 = CreateShip3(coords);

    delete[] Pship;
    Pship = CreateShip(coords);

    delete[] Pship2;
    Pship2 = CreateShip2(coords);

    delete[] Pship3;
    Pship3 = CreateShip3(coords);

    //load Fonts
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    Text Choices;
    Choices.setFont(font);
    Choices.setFillColor(Color::Black);
    Choices.setCharacterSize(40);
    Choices.setPosition(440, 580);

    Text player1;
    player1.setFont(font);
    player1.setFillColor(Color::Magenta);
    player1.setCharacterSize(40);
    player1.setPosition(640, 0);

    Text player2;
    player2.setFont(font);
    player2.setFillColor(Color::Black);
    player2.setCharacterSize(40);
    player2.setPosition(640, 0);

    //load a texture for background
    Texture LandMap;
    LandMap.loadFromFile("Textures/TankMapBackroundTexture.png");
    Sprite GroundForcesMap;
    GroundForcesMap.setTexture(LandMap);
    GroundForcesMap.setPosition(320, 0);

    Texture WaterMap;
    WaterMap.loadFromFile("Textures/OceanMapBackround2.png");
    Sprite BattleShipMap;
    BattleShipMap.setTexture(WaterMap);
    BattleShipMap.setPosition(320, 0);

    Texture Title;
    Title.loadFromFile("Textures/GameIntroScreen (1).png");
    Sprite TitleScreen;
    TitleScreen.setTexture(Title);
    TitleScreen.setPosition(320, 0);


    while (window.isOpen())
    {
     

        // Create event object
        Event event;
        //Handle player input 
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num1) && state == State::Title)
            {
                if (event.key.code == Keyboard::Num1)
                {
                    state = State::Player1Screen;
                }

            }
            else if (Keyboard::isKeyPressed(Keyboard::Num2) && state == State::Title)
            {
                if (event.key.code == Keyboard::Num2)
                {
                    state = State::Player1ScreenWater;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player2Screen)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player1Screen;
                }
                
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player1Screen)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player2Screen;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player2ScreenWater)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player1ScreenWater;
                }

            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player1ScreenWater)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player2ScreenWater;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::B) || state == State::Player1ScreenWater || state == State::Player2ScreenWater || state == State::Player1Screen || state == State::Player2Screen)
            {
                if (event.key.code == Keyboard::B)
                {
                    state = State::Title;
                }
            }
        }
        
        int count = 0;
        if (state == State::Player1Screen)
        {
           
            //Check if one of the grids were selected
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i Select;
                Vector2f Check;
                Select = Mouse::getPosition(window);
                Check.x = Select.x;
                Check.y = Select.y;
                //Moves the clicked tial out of the way
                for (int i = 0; i < num; i++)
                {
                    if (Player1tials[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Vector2f poss = Player1tials[i].GetLocation();                    
                        Player1tials[i].update(gone);  
                        count++;
                    }
                  
                }
                if (event.key.code == Mouse::Left)
                {
                    for (int i = 0; i < 3; i++)
                    {

                        if (ship[i].GetVehicle().getGlobalBounds().contains(Check))
                        {
                            Total.add3();
                        }
                    }
                    for (int i = 0; i < 2; i++)
                    {

                        if (ship2[i].GetVehicle1().getGlobalBounds().contains(Check))
                        {
                            Total.add2();
                        }
                    }
                    for (int i = 0; i < 1; i++)
                    {

                        if (ship3[i].GetVehicle2().getGlobalBounds().contains(Check))
                        {
                            Total.add();
                        }
                    }
                }

            }
            
        }

        if (state == State::Player1ScreenWater)
        {

            //Check if one of the grids were selected
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i Select;
                Vector2f Check;
                Select = Mouse::getPosition(window);
                Check.x = Select.x;
                Check.y = Select.y;
                //Moves the clicked tial out of the way
                for (int i = 0; i < num; i++)
                {
                    if (Player1tialsWater[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Player1tialsWater[i].Hit();
                        Player1tialsWater[i].update(gone);
                    }

                }
                if (event.key.code == Mouse::Left)
                {
                    for (int i = 0; i < 3; i++)
                    {

                        if (ship[i].GetVehicle().getGlobalBounds().contains(Check))
                        {
                            Total.add3();
                        }
                    }
                    for (int i = 0; i < 2; i++)
                    {

                        if (ship2[i].GetVehicle1().getGlobalBounds().contains(Check))
                        {
                            Total.add2();
                        }
                    }
                    for (int i = 0; i < 1; i++)
                    {

                        if (ship3[i].GetVehicle2().getGlobalBounds().contains(Check))
                        {
                            Total.add();
                        }
                    }
                }

            }
                
                

            
        }
        
        if (state == State::Player1Screen)
        {
            window.clear();
            window.draw(GroundForcesMap);
            
            
            for (int i = 0; i < 3; i++)
            {
                window.draw(ship[i].GetVehicle());
            }
            for (int i = 0; i < 2; i++)
            {
                window.draw(ship2[i].GetVehicle1());
            }
            for (int i = 0; i < 1; i++)
            {
                window.draw(ship3[i].GetVehicle2());
            }
            for (int i = 0; i < num; i++)
            {
                window.draw(Player1tials[i].GetTialS());
            }

            player1.setString(Player1Text(Total));
            window.draw(player1);
            window.display();
            cout << Total.Get() << endl;

        }

        if (state == State::Player1ScreenWater)
        {
            window.clear();
            window.draw(BattleShipMap);

            
            for (int i = 0; i < 3; i++)
            {
                window.draw(ship[i].GetVehicle());
            }
            for (int i = 0; i < 2; i++)
            {
                window.draw(ship2[i].GetVehicle1());
            }
            for (int i = 0; i < 1; i++)
            {
                window.draw(ship3[i].GetVehicle2());
            }
            for (int i = 0; i < num; i++)
            {
                window.draw(Player1tialsWater[i].GetTialS());
            }

            player1.setString(Player1Text(Total));
            window.draw(player1);
            window.display();

        }

        if (state == State::Player2Screen)
        {

            //Check if one of the grids were selected
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i Select;
                Vector2f Check;
                Select = Mouse::getPosition(window);
                Check.x = Select.x;
                Check.y = Select.y;
                //Moves the clicked tial out of the way
                for (int i = 0; i < num; i++)
                {
                    if (Player2tials[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Player2tials[i].Hit();
                        Player2tials[i].update(gone);
                    }

                }
                if (event.key.code == Mouse::Left)
                {
                    for (int i = 0; i < 3; i++)
                    {

                        if (Pship[i].GetVehicle().getGlobalBounds().contains(Check))
                        {
                            Total2.add3();
                        }
                    }
                    for (int i = 0; i < 2; i++)
                    {

                        if (Pship2[i].GetVehicle1().getGlobalBounds().contains(Check))
                        {
                            Total2.add2();
                        }
                    }
                    for (int i = 0; i < 1; i++)
                    {

                        if (Pship3[i].GetVehicle2().getGlobalBounds().contains(Check))
                        {
                            Total2.add();
                        }
                    }
                }

            }

          
        }

        if (state == State::Player2ScreenWater)
        {

            //Check if one of the grids were selected
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i Select;
                Vector2f Check;
                Select = Mouse::getPosition(window);
                Check.x = Select.x;
                Check.y = Select.y;
                //Moves the clicked tial out of the way
                for (int i = 0; i < num; i++)
                {
                    if (Player2tialsWater[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Player2tialsWater[i].Hit();
                        Player2tialsWater[i].update(gone);
                    }

                }
                if (event.key.code == Mouse::Left)
                {
                    for (int i = 0; i < 3; i++)
                    {

                        if (Pship[i].GetVehicle().getGlobalBounds().contains(Check))
                        {
                            Total2.add3();
                        }
                    }
                    for (int i = 0; i < 2; i++)
                    {

                        if (Pship2[i].GetVehicle1().getGlobalBounds().contains(Check))
                        {
                            Total2.add2();
                        }
                    }
                    for (int i = 0; i < 1; i++)
                    {

                        if (Pship3[i].GetVehicle2().getGlobalBounds().contains(Check))
                        {
                            Total2.add();
                        }
                    }
                }

            }
        }

        if (state == State::Player2Screen)
        {
            window.clear();
            window.draw(GroundForcesMap);

            
            for (int i = 0; i < 3; i++)
            {
                window.draw(Pship[i].GetVehicle());
            }
            for (int i = 0; i < 2; i++)
            {
                window.draw(Pship2[i].GetVehicle1());
            }
            for (int i = 0; i < 1; i++)
            {
                window.draw(Pship3[i].GetVehicle2());
            }
            for (int i = 0; i < num; i++)
            {
                window.draw(Player2tials[i].GetTialS());
            }

            player2.setString(Player2Text(Total2));
            window.draw(player2);
            window.display();

        }

        if (state == State::Player2ScreenWater)
        {
            window.clear();
            window.draw(BattleShipMap);

            
            for (int i = 0; i < 3; i++)
            {
                window.draw(Pship[i].GetVehicle());
            }
            for (int i = 0; i < 2; i++)
            {
                window.draw(Pship2[i].GetVehicle1());
            }
            for (int i = 0; i < 1; i++)
            {
                window.draw(Pship3[i].GetVehicle2());
            }
            for (int i = 0; i < num; i++)
            {
                window.draw(Player2tialsWater[i].GetTialS());
            }

            player2.setString(Player2Text(Total2));
            window.draw(player2);
            window.display();

        }

        if (state == State::Title)
        {
            window.clear();
            window.draw(TitleScreen);
            
            Choices.setString(ChoicesText());

            window.draw(Choices);
            window.display();

           

        }
        
    }

    return 0;
}
