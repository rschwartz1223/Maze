#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>

extern const std::string Up;
extern const std::string Down;
extern const std::string Left;
extern const std::string Right;

class Maze
{
private:
    char avatarToken; //character that represents the avatar
    char emptyToken; //character that represents empty space in the maze
    char wallToken; //character that represents a wall
    char exitToken; //character that represents an exit - where you quit the game
    char stairsUpToken; //character that represents stairs that take you to an UPPER level
    char stairsDownToken; //character that represents a Hole that takes you a LOWER level
    char bossToken; //character that repreents a boss that kills you (you lose/exit the game)
    
    int dim; //width of this square maze
    std::vector< std::vector<char> > grid; //a vector of vectors of characters
    //consider each successive member of the top level container to be a row of the matrix
    
    int avatarRow; //row position of our avatar from zero to dim-1 (NOT from 1 to dim)
    int avatarCol; //column position of our avatar from zero to dim-1 (NOT from 1 to dim)
    
    int currentLevel; //BONUS: current level number we are on
    
    std::vector< std::string > levels; //BONUS: our N-strings that each represent a level except for level[ 0 ]
    //see MazeData.h
    
    
public:
    //this is our 1st  constructor. declaration only (you must implement the definition in Maze.cpp)
    Maze(int newDim = 4,
         char _avatarToken = 'A',
         char _emptyToken = ' ',
         char _wallToken = '*',
         char _exitToken = 'E',
         char _stairsUpToken = '^',
         char _stairsDownToken = 'V',
         char _bossToken = 'B');
    
    // BONUS: this is our 2st constructor.  declaration only (you must implement the definition in Maze.cpp)
    Maze(std::vector<std::string> levels,
         int levelStart = 1,
         int avatarRowStart = 1 ,
         int avatarColStart = 1);
    
    void printMe();
    bool takeTurn(std::string direction); //move the avatar in the requested direction if possible
};

#endif
