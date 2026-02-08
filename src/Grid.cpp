#include "Grid.h"
#include <bits/stdc++.h>

void Grid::CreateGrid(){
    std::cout << "Creating Arena ! \n\n";
    Grid::board.resize(Grid::N, std::vector<char>(Grid::N, '-'));
}

void Grid::DisplayGrid(){
    for(int i = 0; i < Grid::N; i++){
        for(int j = 0; j < Grid::N; j++){
            std::cout << " " << Grid::board[i][j] << " ";
            if(j < Grid::N-1){
                std::cout << "|";
            }
        }
        std::cout << "\n";
        if(i < Grid::N-1){
            for(int j = 0; j < Grid::N; j++){
                std::cout << "---";
                if(j < Grid::N-1){
                    std::cout << "+";
                }
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}