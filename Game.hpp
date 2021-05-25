// T04_G02

#ifndef GAME_H
#define GAME_H  // avoid compiling errors related to redefinition

#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Maze.hpp"
#include "Player.hpp"
#include "Robot.hpp"
#include "gamestructs.hpp"
#include <map>

using namespace std;

class Game{
    public:
        Game(const string &mapName);  // build game from the map file name
        bool play();  // play the game
        void updateLeaderboards(string mazeLeaderboardFile, bool mazeLeaderboard, bool winnersLeaderboard);  /* update (possibly create too) all leaderboards
                                                                                                                second argument signals existance of a leaderboard file (for the map played)
                                                                                                                third argument signals existance of the overall winners file  */
    private:
        // leaderboard
        void organizeLeaderboard(string lbPath) const;
        void readEntries(string lbPath, vector <LbEntry> &entries) const;
        // play
        void setObjectsFromMap(ifstream &map);  // to be used once, at the start of each game
        void showDisplay();  // no need to update display (is always up to date)
        Movement moveInput();  // gets the Movement from a valid player movement input (loops until input is accepted)
        void movePlayer();  // everything related to player movement
        void moveRobots();  // everything related to robots movement
        bool valid_move(Robot& robot, int postIndex, Movement mov); // check if robot collided with post 
        bool valid_move(Player& player, Robot& robot, Movement mov); // check if human and robot collided 
        bool valid_move(Robot& robot0, Robot& robot1, Movement mov); // check if two robots collided 
        bool valid_move(Player& player, Post& post, Movement mov); // check if human collided with post (any type)
        void playerExits();  // signals that the player has found an exit
    private:
        Maze maze;  // the maze corresponding to the game
        Player player;
		map<Position, Robot> robots;
        int timePlayed;  // time score to use on leaderboards
        bool playerExited;

};

#endif