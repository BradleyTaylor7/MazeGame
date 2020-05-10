#pragma once

#include <vector>

using namespace std;

class Maze {
public:
	Maze();
	Maze(vector<vector<char>> maze_contents);
	void UpdateMaze(vector<vector<char>> maze_contents);
	void DrawMaze();
	char GetTile(int x, int y);
	// Getters
	bool IsExit(int x, int y);
	bool IsWall(int x, int y);

private:
	vector<vector<char>> maze_contents;
	char
		path = ' ',
		wall = 'x',
		exit = 'O';
};
