//
// Created by Hubert Klonowski on 18/06/2023.
//

#include "SaveManager.h"
#include <iostream>
#include <fstream>
#include <vector>

#include "Unit.h"

using namespace std;

SaveManager::SaveManager(GamePtr game, BoardPtr board): game(game), board(board) {}

SaveManager::~SaveManager() {}

string boolToString(bool b){
    return b ? "true":"false";
}

//save
std::ostream &operator<<(ostream &out,  Game &obj) {
    out << obj.isWhiteTurn() << "\n" << obj.isCheckWhite() << "\n" << obj.isCheckBlack() << "\n" << obj.getTotalTurns() << "\n";
    return out;
}

std::ostream &operator<<(ostream &out,  Board &obj) {
    out << obj.getXDimension() << "\n" << obj.getYDimension() << "\n";
    return out;
}

std::ostream &operator<<(ostream &out,  Field &obj) {
    out << obj.getXCoord() << "\n" << obj.getYCoord() << "\n" <<obj.isOccupied() << "\n" <<obj.getColor() << "\n";
    return out;
}

std::ostream &operator<<(ostream &out,  Unit &obj) {
    string col;
    if(obj.getColor() == BLACK)
        col = "BLACK";
    else col = "WHITE";
    int x = 0;
    int y = 0;
    if(obj.getField() != nullptr)
    {
        x = obj.getField()->getXCoord();
        y = obj.getField()->getYCoord();
    }
    out << x << "|" <<y << ":" <<obj.getUuid() << "[" <<obj.isAlive() << "]" <<obj.isEnpassantable() << "/" << obj.getColor() << "\n";

    return out;
}

vector<int> splitStringToCoords(string str)
{
    vector<int> coords;
    coords.push_back(str[0]);
    coords.push_back(str[2]);
    return coords;
}

Color getColor(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '/')
        {
            if(str[i+1] == '0')
                return WHITE;
            else
                return BLACK;
        }
    }
}

string getName(string str)
{
    string name = "";
    bool readName = false;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ':')
        {
            readName = true;
            continue;
        }

        if(str[i] == '[')
        {
            break;
        }

        if(readName)
        {
            name = name + str[i];
        }
    }
    return name;
}

bool getAlive(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '[')
        {
            if(str[i+1] == '1')
            {
                return true;
            } else
                return false;
        }
    }
    return false;
}

bool getEnpassantable(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ']')
        {
            if(str[i+1] == '1')
            {
                return true;
            } else
                return false;
        }
    }
    return false;
}
void addUnitToTaken(Color color, UnitPtr unit, GamePtr game)
{
    game->add_unit_to_taken(unit, color);
}

bool SaveManager::LoadGame(GamePtr game) {

    std::ifstream in("SaveData.txt");

    string str;
    int model = 0;
    int i = 0;
    while(getline(in, str))
    {
        if(str == "GAME")
        {
            model = 1;
            i = 0;
            continue;
        }

        if(str == "BOARD"){
            model = 2;
            i = 0;
            continue;
        }

        if(str == "FIELD"){
            model = 3;
            i = 0;
            continue;
        }

        if(str == "UNIT"){
            model = 4;
            i = 0;
            continue;
        }

        if(str == "TAKEN UNITS BLACK")
        {
            model = 5;
            i = 0;
            continue;
        }

        if(str == "TAKEN UNITS WHITE")
        {
            model = 6;
            i = 0;
            continue;
        }

        switch(model){
            case 1:
                if(i == 0)
                    game->setWhiteTurn(stoi(str));
                if(i == 1)
                    game->setIsCheckWhite(stoi(str));
                if(i == 2)
                    game->setIsCheckBlack(stoi(str));
                if(i == 3)
                    game->setTotalTurns(stoi(str));
                i++;
                break;
            case 2:
                if(i == 0)
                    game->getBoard()->setXDimension(stoi(str));
                if(i == 1)
                    game->getBoard()->setYDimension(stoi(str));
                i++;
                break;
            case 4:
                if(i == 0)
                {
                    int x = str[0] - '0';
                    int y = str[2] - '0';
                    int uuid = stoi(getName(str));
                    bool isAlive = getAlive(str);
                    bool isEnpassantable = getEnpassantable(str);
                    vector<UnitPtr> units;
                    for(int o = 0; o < game->getBoard()->getXDimension(); o++)
                    {
                        for(int p = 0; p < game->getBoard()->getYDimension(); p++)
                        {
                            if(game->getBoard()->get_field(o, p)->isOccupied())
                                units.push_back(game->getBoard()->get_field(o,p)->getOccupiedByUnit());
                        }
                    }

                    for(int i = 0; i < units.size(); i++)
                    {
                        if(units[i]->getUuid() == uuid)
                        {
                            units[i]->getField()->deoccupy();
                            units[i]->setField(nullptr);
                            if(!isAlive)
                            {
                                addUnitToTaken(getColor(str), units[i], game);
                                break;
                            }
                            units[i]->setField(game->getBoard()->get_field(x, y));
                            game->getBoard()->get_field(x,y)->occupy(units[i]);
                            units[i]->setAlive(isAlive);
                            units[i]->setEnpassantable(isEnpassantable);
                            units[i]->setColor(getColor(str));
                            break;
                        }
                    }
                }
                i++;
                break;
            case 5:
                if(i == 0)
                {
//                    addUnitToTaken(BLACK, str, game);
                }
                i++;
                break;
            case 6:
                if(i == 0)
                {
//                    addUnitToTaken(WHITE, str, game);
                }
                i++;
                break;

        }

    }

    return true;
}



bool SaveManager::SaveGame() {

    ofstream file1;
    std::ofstream out("SaveData.txt");
    out << "GAME" << endl;
    out << *game;
    out << "BOARD" << endl;
    out << *board;
//    for(int i = 0; i < board->getFields().size(); i++)
//    {
//        out << "FIELD" << endl;
//        out << *board->getFields()[i];
//    }

//    for(int x = 0; x < board->getXDimension(); x++)
//    {
//        for(int y = 0; y < board->getYDimension(); y++)
//        {
//            out << "FIELD" << endl;
//            out << *board->get_field(x, y);
//        }
//    }

//    out << "TAKEN UNITS BLACK" << endl;

    for(int i = 0; i < game->getTakenUnitsByColor(BLACK).size(); i++)
    {
        out << "UNIT" << endl;
        out << *game->getTakenUnitsByColor(BLACK)[i];
    }

//    out << "TAKEN UNITS WHITE" << endl;

    for(int i = 0; i < game->getTakenUnitsByColor(WHITE).size(); i++)
    {
        out << "UNIT" << endl;
        out << *game->getTakenUnitsByColor(WHITE)[i];
    }

    for(int x = 0; x < board->getXDimension(); x++)
    {
        for(int y = 0; y < board->getYDimension(); y++)
        {
            if(board->get_field(x, y)->isOccupied())
            {
                out << "UNIT" << endl;
                out << *board->get_field(x, y)->getOccupiedByUnit();
            }
        }
    }



    out.close();

    return true;
}

