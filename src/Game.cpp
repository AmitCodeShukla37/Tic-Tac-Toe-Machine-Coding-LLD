#include "Game.h"
#include <bits/stdc++.h>

using namespace std;

void Game::InitializeGame(){
    cout << "Enter name of player 1 : ";
    cin >> Game::p1.name;
    cout << "Enter the choice of player 1 : (X/O)  ";
    while(cin >> Game::p1.move){
        if(Game::p1.move != 'X' &&  Game::p1.move != 'O'){
            cout << "Invalid Choice ! Try again\n ";
        }
        else{
            break;
        }
    }

    cout << "Enter name of player 2 : ";
    cin >> Game::p2.name;
    Game::p2.move = (Game::p1.move == 'X' ? 'O' : 'X');
    cout << "Enter size of Tic-Toe-Grid : ";
    cin >> Game::board.N;
    cout << "\n";
    Game::turn = 0;
    Game::board.CreateGrid();
    Game::board.DisplayGrid();
}


bool Game::ValidMove(int r, int c){
    r--,c--;
    if(r >= Game::board.N || r < 0 || c >= Game::board.N || c < 0 || Game::board.board[r][c] != '-'){
        return false;
    }
    return true;
}


void Game::TakeTurn(Player &p){
    while(true){
        cout << p.name << " , Your Turn ! Enter Row from (1-" << Game::board.N << ") and Column from (1-" << Game::board.N << ")\n";
        int r, c;
        cin >> r >> c;
        if(Game::ValidMove(r,c)){
            Game::board.board[r-1][c-1] = p.move;
            break;
        }
        else{
            cout << "Incorrect Move ! Try Again\n";
        }
    }
    cout << "\n";
    Game::board.DisplayGrid();
}


bool Game::CheckGameWin(char move){
    bool win = false;
    for(int i = 0; i < Game::board.N; i++){
        bool check = true;
        for(int j = 0; j < Game::board.N; j++){
            if(Game::board.board[i][j] != move){
                check = false;
                break;
            }
        }
        if(check){
            win = true;
            break;
        }
    }

    for(int i = 0; i < Game::board.N && !win; i++){
        bool check = true;
        for(int j = 0; j < Game::board.N; j++){
            if(Game::board.board[j][i] != move){
                check = false;
                break;
            }
        }
        if(check){
            win = true;
            break;
        }
    }

    bool check = true;
    for(int i = 0; i < Game::board.N; i++){
        if(Game::board.board[i][i] != move){
            check = false;
            break;
        }
    }
    if(check) win = check;

    check = true;
    for(int i = 0; i < Game::board.N; i++){
       if(Game::board.board[i][Game::board.N-i-1] != move){
            check = false;
            break;
        }
    }
    if(check) win = check;

    return win;
}

void Game::Play(){
    cout << "Starting Game ! \n\n";
    
    while(!Game::CheckGameWin('X') && !Game::CheckGameWin('O') &&  Game::turn < Game::board.N * Game::board.N){
        if(Game::turn % 2){
            Game::TakeTurn(Game::p2);
        }
        else{
            Game::TakeTurn(Game::p1);
        }
        Game::turn++;
    }

    if(Game::CheckGameWin('X')){
        if(Game::p1.move == 'X'){
            cout << p1.name << " Wins !\n";
        }
        else{
            cout << p2.name << " Wins !\n";
        }
    }
    else if(Game::CheckGameWin('O')){
        if(Game::p1.move == 'O'){
            cout << p1.name << " Wins !\n";
        }
        else{
            cout << p2.name << " Wins !\n";
        }
    }
    else{
        cout << "Its a Draw ! Game Over\n";
    }
}