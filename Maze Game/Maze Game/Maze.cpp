#pragma once
#include "Maze.h"

Maze::Maze() {
	UpdateMaze({ {} });
}
Maze::Maze(vector<vector<char>> maze_contents) {
	UpdateMaze(maze_contents);
}

void Maze::UpdateMaze(vector<vector<char>> maze_contents) {
	this->maze_contents.clear();
	this->maze_contents = maze_contents;
}

char Maze::GetTile(int x, int y) {
	char tile = maze_contents[y][x];
	return
		tile == 'W' ? wall :
		tile == 'P' ? path :
		tile == 'E' ? exit :
		'_';
}

bool Maze::IsExit(int x, int y) {
	return GetTile(x, y) == this->exit;
}

bool Maze::IsWall(int x, int y) {
	return GetTile(x, y) == this->wall;
}

void Maze::DrawMaze() {
	for (vector<char> row : this->maze_contents) {
		for (char column : row)
			printf("%c", column);
		printf("\n");
	}
}
