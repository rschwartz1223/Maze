#include "Maze.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::cout << "-------------\tMaze\t-------------\n\n";
    
    Maze maze(10);
    maze.printMe();
    std::string direction;
    
    bool play_game = true;
    
    while(play_game)
    {
        std::cout << "Input a character to move your avatar in the maze \nand press RETURN ";
        std::cout << "(w = UP, s = DOWN, a = LEFT, d = RIGHT):\n";
        std::cin >> direction;
        if(maze.takeTurn(direction))
        {
            std::cout << "\nYou exited the maze.\n";
            play_game = false;
        }
        maze.printMe();
    }
    
    return 0;
}
