#ifndef CHESS_TYPEDEFS_H
#define CHESS_TYPEDEFS_H

#include <memory>
#include "wx/wx.h"

using namespace std;

enum Color {
    WHITE,
    BLACK
};

enum Type {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};
class Game;
class Player;
class Board;
class Field;
class Unit;
class MainFrame;
class UI;
class GameFrame;

typedef shared_ptr<Game> GamePtr;
typedef shared_ptr<Player> PlayerPtr;
typedef shared_ptr<Board> BoardPtr;
typedef shared_ptr<Field> FieldPtr;
typedef shared_ptr<Unit> UnitPtr;
typedef shared_ptr<MainFrame> MainFramePtr;
typedef shared_ptr<UI> UIPtr;
typedef shared_ptr<GameFrame> GameFramePtr;
//
//wxColour white_tile = wxColour(196, 196, 196);
//wxColour black_tile = wxColour(59, 59, 59);


#endif //CHESS_TYPEDEFS_H
