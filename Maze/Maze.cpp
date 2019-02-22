#include "Maze.h"
#include "Keyboard.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

//1st constructor
Maze::Maze(int newDim,
           char _avatarToken,
           char _emptyToken,
           char _wallToken,
           char _exitToken,
           char _stairsUpToken,
           char _stairsDownToken,
           char _bossToken) : dim(newDim),
                              avatarToken(_avatarToken),
                              emptyToken(_emptyToken),
                              wallToken(_wallToken),
                              exitToken(_exitToken),
                              stairsUpToken(_stairsUpToken),
                              stairsDownToken(_stairsDownToken),
                              bossToken(_bossToken),
                              grid(dim, std::vector<char>(dim))
{
    //place avatar location in center of maze
    this->avatarRow = (newDim - 1) / 2;
    this->avatarCol = (newDim - 1) / 2;
    
    //initialize top wall of grid
    for(int i = 0; i < this->dim; i++)
        this->grid[0][i] = this->wallToken;
    
    //initialize middle of grid
    for(int j = 1; j < this->dim - 1; j++)
        for(int k = 0; k < this->dim; k++)
        {
            if(k == 0 || k == this->dim - 1)
                this->grid[j][k] = this->wallToken;
            else
                this->grid[j][k] = this->emptyToken;
        }
    
    //initialize bottom wall of grid
    for(int l = 0; l < this->dim; l++)
        this->grid[this->dim - 1][l] = this->wallToken;
    
    //place exit token in the maze
    this->grid[this->dim / 3][0] = this->exitToken;
    
    //place stairs up token in random spot in the maze
    this->grid[0][this->dim / 2] = this->stairsUpToken;
    
    //place stairs down token in the maze
    this->grid[this->dim - 1][2] = this->stairsDownToken;
    
    //place boss token in maze
    if(this->dim + 1 != this->avatarRow && this->dim - 1 != this->avatarCol)
        this->grid[this->avatarRow - 1][this->avatarCol + 1] = this->bossToken;
    
}

//print maze row by row
void Maze::printMe()
{
    //rows
    for(int m = 0; m < this->dim; m++)
    {
        //columns
        for(int n = 0; n < this->dim; n++)
        {
            //print avatar token
            if(m == this->avatarRow && n == this->avatarCol)
                std::cout << this->avatarToken;
            else
                std::cout << this->grid[m][n];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//update location of the avatar
bool Maze::takeTurn(std::string _direction)
{
    if(_direction == Up)
    {
        if(this->grid[this->avatarRow - 1][this->avatarCol] != this->wallToken)
        {
            if(this->grid[this->avatarRow - 1][this->avatarCol] == this->exitToken ||
               this->grid[this->avatarRow - 1][this->avatarCol] == this->bossToken ||
               this->grid[this->avatarRow - 1][this->avatarCol] == this->stairsUpToken ||
               this->grid[this->avatarRow - 1][this->avatarCol] == this->stairsDownToken)
            {
                --this->avatarRow;
                return true;
            }
            else
            {
                --this->avatarRow;
                return false;
            }
        }
    }
    else if(_direction == Down)
    {
        if(this->grid[this->avatarRow + 1][this->avatarCol] != this->wallToken)
        {
            if(this->grid[this->avatarRow + 1][this->avatarCol] == this->exitToken ||
               this->grid[this->avatarRow + 1][this->avatarCol] == this->bossToken ||
               this->grid[this->avatarRow + 1][this->avatarCol] == this->stairsUpToken ||
               this->grid[this->avatarRow + 1][this->avatarCol] == this->stairsDownToken)
            {
                ++this->avatarRow;
                return true;
            }
            else
            {
                ++this->avatarRow;
                return false;
            }
        }
    }
    else if(_direction == Left)
    {
        if(this->grid[this->avatarRow][this->avatarCol - 1] != this->wallToken)
        {
            if(this->grid[this->avatarRow][this->avatarCol - 1] == this->exitToken ||
               this->grid[this->avatarRow][this->avatarCol - 1] == this->bossToken ||
               this->grid[this->avatarRow][this->avatarCol - 1] == this->stairsUpToken ||
               this->grid[this->avatarRow][this->avatarCol - 1] == this->stairsDownToken)
            {
                --this->avatarCol;
                return true;
            }
            else
            {
                --this->avatarCol;
                return false;
            }
        }
    }
    else if(_direction == Right)
    {
        if(this->grid[this->avatarRow][this->avatarCol + 1] != this->wallToken)
        {
            if(this->grid[this->avatarRow][this->avatarCol + 1] == this->exitToken ||
               this->grid[this->avatarRow][this->avatarCol + 1] == this->bossToken ||
               this->grid[this->avatarRow][this->avatarCol + 1] == this->stairsUpToken ||
               this->grid[this->avatarRow][this->avatarCol + 1] == this->stairsDownToken)
            {
                ++this->avatarCol;
                return true;
            }
            else
            {
                ++this->avatarCol;
                return false;
            }
        }
    }
    return false;
}
