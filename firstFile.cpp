#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class player
{
public:
    std::string name;
    int sLevel;
    char element;

    void playerCons()
    {
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << std::endl;
        sLevel = 1;
        std::cout << "Pick Your Element: ";
        std::cin >> element;
    }
};

void gameRules();
int gameMenu();
void playGame();

class enemy
{
    std::string type;
    int sLevel;
    char element;
};

int main()
{
    bool gameOn;
    int pick = 0;
    do
    {
        pick = gameMenu();
        switch (pick)
        {
        case 1:
            gameOn = true;
            break;
        case 2:
            gameRules();
            break;
        default:
            gameOn = false;
            return 0;
        }
    } while (pick != 1);

    if (gameOn)
    {
        playGame();
    }
    else
    {
        std::cout << "Goodbye!" << std::endl;
        return 0;
    }
}

void playGame()
{
}

int gameMenu()
{
    int pick = 0;
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1) Start Games" << std::endl;
    std::cout << "2) Rules" << std::endl;
    std::cout << "3) Exit" << std::endl;
    std::cin >> pick;
    return pick;
}

void gameRules()
{
    std::string line;
    std::ifstream myGameRules("C:/Users/jenna/hello-world/rules.txt");
    // C:\Users\jenna\hello-world\rules.txt
    if (myGameRules.is_open())
    {
        while (std::getline(myGameRules, line))
        {
            std::cout << line << '\n';
        }
        myGameRules.close();
    }
    else
    {
        std::cout << "unable to open rules";
    }
};