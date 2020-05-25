#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;

TEST_CASE("Foot soldiers") {
    Board board (8,1);

    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7,0}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Foot Commander") {
    Board board (8,1);

    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7,0}] = new FootCommander(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Sniper") {
    Board board (8,1);

    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new Sniper(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7,0}] = new Sniper(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Sniper Commander") {
    Board board (8,1);

    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new SniperCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7,0}] = new SniperCommander(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Paramedic") {
    Board board (8,1);

    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new Paramedic(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7,0}] = new Paramedic(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Paramedic Commander") {
    Board board (8,1);

    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new ParamedicCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7,0}] = new ParamedicCommander(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(!board.has_soldiers(2));
}



