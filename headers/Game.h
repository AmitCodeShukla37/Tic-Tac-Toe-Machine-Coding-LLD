#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Player.h"

class Game{

    private:
            Grid board;
            Player p1, p2;
            int turn;

    public:
            void Play();
            void InitializeGame();

    private:
            void TakeTurn(Player &p);
            bool ValidMove(int r, int c);
            bool CheckGameWin(char move);
};

#endif