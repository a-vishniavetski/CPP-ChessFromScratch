#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <vector>
#include <typedefs.h>
#include "Board.h"

using namespace std;


class Player;
class Board;


class Game {
public:
    // --------------- Konstruktor ---------------
    Game();
    Game(const vector<PlayerPtr> &_players, BoardPtr const _board, int _totalTurns);
    // --------------- gettery a settery ---------------
    bool isCheckWhite() const;
    void setIsCheckWhite(bool isCheckWhite);
    bool isCheckBlack() const;
    void setIsCheckBlack(bool isCheckBlack);
    void setCheckFor(Color color, bool is_check);
    bool isMate() const;
    void setIsMate(bool isMate);
    void setPlayers(const vector<PlayerPtr> &players);
    BoardPtr getBoard() ;
    void setBoard(const BoardPtr &board);
    int getTotalTurns() const;
    void setTotalTurns(int totalTurns);
    bool isWhiteTurn() const;
    void setWhiteTurn(bool whiteTurn);
    Color getVictoryColor() const;
    void setVictoryColor(Color victoryColor);
    bool isTie() const;
    void setIsTie(bool isTie);
    bool isStalemate() const;
    void setIsStalemate(bool isStalemate);
    // --------------- logika gry, deska i ruchi ---------------
    void newGame(bool is_against_ai, Color ai_color);
    void placeUnitAt(int x_coord, int y_coord, UnitPtr unit, BoardPtr board);
    BoardPtr createEmptyBoard() const;
    virtual ~Game();
    const vector<PlayerPtr> &getPlayers() const;
    void makeMove(UnitPtr unit, FieldPtr destination_field, BoardPtr board, GamePtr game);
    vector<FieldPtr> getLegalMoves(UnitPtr unit);
    void addUnitToTaken(UnitPtr unit, Color color);
    BoardPtr copyBoard(BoardPtr board);
    // --------------- logika gry, check, checkmate, update ---------------
    bool isCheckState(GamePtr game, BoardPtr board, Color color);
    bool isCheckmateState(GamePtr game, BoardPtr board, Color color);
    int allLegalMoveCount(GamePtr game, BoardPtr board, Color color);
    void updateGameStatus(GamePtr game, BoardPtr board);

    FieldPtr findKingByColor(Color color);
    vector<UnitPtr> getTakenUnitsByColor(Color color);

private:
    vector<PlayerPtr> players;
    BoardPtr board;
    int total_turns;
    bool white_turn = true;
    bool is_check_white = false;
    bool is_check_black = false;
    bool is_mate = false;
    bool is_stalemate = false;
    bool is_tie = false;
    Color victory_color;
    //PlayerPtr victory_player = nullptr;
    vector<UnitPtr> taken_white_units;
    vector<UnitPtr> taken_black_units;

    int givePlayerInitialUnits(PlayerPtr player, int initial_uuid);
    void createAndPlaceUnit(int x_coord, int y_coord, UnitPtr unit, PlayerPtr player, int *uuid_count);
};


#endif //CHESS_GAME_H
