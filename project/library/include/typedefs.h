#ifndef CHESS_TYPEDEFS_H
#define CHESS_TYPEDEFS_H

#include <memory>

using namespace std;


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


#endif //CHESS_TYPEDEFS_H
