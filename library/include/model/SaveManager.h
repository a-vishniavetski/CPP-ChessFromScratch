//
// Created by Hubert Klonowski on 18/06/2023.
//

#ifndef CHESS_SAVEMANAGER_H
#define CHESS_SAVEMANAGER_H

#include "Game.h"
#include "Board.h"
#include "Unit.h"
#include "Field.h"
#include "Unit.h"

class SaveManager{
public:
    SaveManager(GamePtr game, BoardPtr board);
    ~SaveManager();

    bool SaveGame();
    bool LoadGame(GamePtr game);

    //save
    friend std::ostream & operator << (std::ostream &out,  Game & obj);
    friend std::ostream & operator << (std::ostream &out,  Board & obj);
    friend std::ostream & operator << (std::ostream &out,  Field & obj);
    friend std::ostream & operator << (std::ostream &out,  Unit & obj);

    //read
    friend std::istream & operator >> (std::istream &in,  Game &obj);
    friend std::istream & operator >> (std::istream &in,  Board &obj);
    friend std::istream & operator >> (std::istream &in,  Field &obj);
    friend std::istream & operator >> (std::istream &in,  Unit &obj);

private:
    GamePtr game;
    BoardPtr board;

};

#endif //CHESS_SAVEMANAGER_H
