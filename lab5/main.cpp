#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "../core/Game.h"

void adaptiveLoop(Game& game, float& lastTime, float updateTarget = 0)
{
    float current = game.getElapsed().asSeconds();
    
    game.handleInput();
    game.update(updateTarget);
    game.render(updateTarget);
    float endtime = game.getElapsed().asSeconds();

    float t = endtime - current;
    
    if (t < updateTarget)
    {
        sf::sleep(sf::Time(sf::seconds(updateTarget - t)));
        endtime = game.getElapsed().asSeconds();
        t = endtime - current;
    }

    float elapsedSeconds = endtime - current;
    int FPS = int(1 / elapsedSeconds);
    game.setFPS(FPS);

    lastTime = current;
}

int main(int argc, char** argv[])
{
    // Try to load the level:
    std::ifstream levelRead{ "levels/lvl0.txt" };
    if (!levelRead)
    {
        throw std::exception("File not found\n");
    }

    // Convert the read file into a vector of strings, one per line:
    std::vector<std::string> lines;
    while (levelRead)
    {
        std::string strInput;
        std::getline(levelRead, strInput);
        lines.emplace_back(strInput);
    }


    // Create and initalize the game.
    Game game;
    game.init(lines);

    // GAME LOOP (with an update target time at 60FPS)
    float updateTarget = 0.016f; //FPS: 60
    float lastTime = game.getElapsed().asSeconds();

    while (!game.getWindow()->isWindowDone())
    {
        //Adaptive loop to elapsed time, with a target update.
        adaptiveLoop(game, lastTime, updateTarget);
    }

    
    return 0;
}