#include <iostream>
#include <string>
#include "Entity.h"
#include "Maze.h"
#include <vector>
#include <conio.h>
#include <ctime>

using namespace std;

int lvl;

const int
GAME_EXIT = 0,
GAME_RUNNING = 1;

const char
UP = 'W',
LEFT = 'A',
DOWN = 'S',
RIGHT = 'D';

const char
PLAYER = '@',
ENEMY = '<';

void Instructions();
void ChooseLevel();

Entity enemy = Entity(9, 6);
Entity player = Entity(1, 1);
Maze maze;
char input;
int game_state = 0;

vector<vector<char>> ReadFile1()
{
	vector<vector<char>> maze_contents; // Store the maze contents
	const int // Maze Dimensions
		width = 25,
		height = 25;
	// Buffer to load data in
	char buffer[(width + 1) * height];
	// Set a pointer to the file
	FILE * file = fopen("Mazes\Level1.txt", "r");
	// Read file from pointer to buffer, with each location of memory being a char big, and loading full buffer.
	fread(buffer, sizeof(char), sizeof(buffer), file);
	for (int row = 0; row < height; row++)
	{
		// Add a vector to store the next line
		maze_contents.push_back(vector<char>());
		for (int column = 0; column < width; column++)
			// Read in the next line
			maze_contents[row].push_back(buffer[(row * (width + 1)) + column]);
	}
	// Return vector of vectors of characters
	return maze_contents;
}

vector<vector<char>> ReadFile2()
{
	vector<vector<char>> maze_contents; // Store the maze contents
	const int // Maze Dimensions
		width = 25,
		height = 25;
	// Buffer to load data in
	char buffer[(width + 1) * height];
	// Set a pointer to the file
	FILE * file = fopen("Mazes/Level2.txt", "r");
	// Read file from pointer to buffer, with each location of memory being a char big, and loading full buffer.
	fread(buffer, sizeof(char), sizeof(buffer), file);
	for (int row = 0; row < height; row++)
	{
		// Add a vector to store the next line
		maze_contents.push_back(vector<char>());
		for (int column = 0; column < width; column++)
			// Read in the next line
			maze_contents[row].push_back(buffer[(row * (width + 1)) + column]);
	}
	// Return vector of vectors of characters
	return maze_contents;
}

vector<vector<char>> ReadFile3()
{
	vector<vector<char>> maze_contents; // Store the maze contents
	const int // Maze Dimensions
		width = 25,
		height = 25;
	// Buffer to load data in
	char buffer[(width + 1) * height];
	// Set a pointer to the file
	FILE * file = fopen("Mazes/Level3.txt", "r");
	// Read file from pointer to buffer, with each location of memory being a char big, and loading full buffer.
	fread(buffer, sizeof(char), sizeof(buffer), file);
	for (int row = 0; row < height; row++)
	{
		// Add a vector to store the next line
		maze_contents.push_back(vector<char>());
		for (int column = 0; column < width; column++)
			// Read in the next line
			maze_contents[row].push_back(buffer[(row * (width + 1)) + column]);
	}
	// Return vector of vectors of characters
	return maze_contents;
}

vector<vector<char>> ReadFile4()
{
	vector<vector<char>> maze_contents; // Store the maze contents
	const int // Maze Dimensions
		width = 25,
		height = 25;
	// Buffer to load data in
	char buffer[(width + 1) * height];
	// Set a pointer to the file
	FILE * file = fopen("Mazes/Level4.txt", "r");
	// Read file from pointer to buffer, with each location of memory being a char big, and loading full buffer.
	fread(buffer, sizeof(char), sizeof(buffer), file);
	for (int row = 0; row < height; row++)
	{
		// Add a vector to store the next line
		maze_contents.push_back(vector<char>());
		for (int column = 0; column < width; column++)
			// Read in the next line
			maze_contents[row].push_back(buffer[(row * (width + 1)) + column]);
	}
	// Return vector of vectors of characters
	return maze_contents;
}

vector<vector<char>> ReadFile5()
{
	vector<vector<char>> maze_contents; // Store the maze contents
	const int // Maze Dimensions
		width = 25,
		height = 25;
	// Buffer to load data in
	char buffer[(width + 1) * height];
	// Set a pointer to the file
	FILE * file = fopen("Mazes/Level5.txt", "r");
	// Read file from pointer to buffer, with each location of memory being a char big, and loading full buffer.
	fread(buffer, sizeof(char), sizeof(buffer), file);
	for (int row = 0; row < height; row++)
	{
		// Add a vector to store the next line
		maze_contents.push_back(vector<char>());
		for (int column = 0; column < width; column++)
			// Read in the next line
			maze_contents[row].push_back(buffer[(row * (width + 1)) + column]);
	}
	// Return vector of vectors of characters
	return maze_contents;
}

vector<vector<char>> ReadFile6()
{
	vector<vector<char>> maze_contents; // Store the maze contents
	const int // Maze Dimensions
		width = 25,
		height = 25;
	// Buffer to load data in
	char buffer[(width + 1) * height];
	// Set a pointer to the file
	FILE * file = fopen("Mazes/Level6.txt", "r");
	// Read file from pointer to buffer, with each location of memory being a char big, and loading full buffer.
	fread(buffer, sizeof(char), sizeof(buffer), file);
	for (int row = 0; row < height; row++)
	{
		// Add a vector to store the next line
		maze_contents.push_back(vector<char>());
		for (int column = 0; column < width; column++)
			// Read in the next line
			maze_contents[row].push_back(buffer[(row * (width + 1)) + column]);
	}
	// Return vector of vectors of characters
	return maze_contents;
}

int main(void)
{
	Instructions();
	ChooseLevel();
	switch (lvl)
	{
	case 1: maze = Maze(ReadFile1());
		break;
	case 2: maze = Maze(ReadFile2());
		break;
	case 3: maze = Maze(ReadFile3());
		break;
	case 4: maze = Maze(ReadFile4());
		break;
	case 5: maze = Maze(ReadFile5());
		break;
	case 6: maze = Maze(ReadFile6());
		break;
	}

	clock_t StartTime = clock();

	game_state = true;
	while (game_state == GAME_RUNNING)
	{

		// Clear the console
		system("cls");
		printf("\n-- %s --\n\nGame by [%s]\n",
			"Escape Characters!",
			"Bradley Taylor, First Year CS, University of Reading"
		);
		// Display all tiles of Maze
		for (int y = 0; y < 25; y++)
		{
			printf("\n\t");
			for (int x = 0; x < 25; x++)
				// Print each tile
				printf(
					// Character
					"%c ",
					// If it's an enemy, print the enemy
					x == enemy.x && y == enemy.y ? ENEMY :
					// If it's a player, print the player
					x == player.x && y == player.y ? PLAYER :
					// Else print a wall
					maze.GetTile(x, y)
				);
			// New row
		}
		// Get Input
		printf("");
		input = (char)getche();

		// Exception Handing
		input = input > 'Z' ? input - ' ' : input; // Uppercase

		// Input Handler
		int old_x = player.x,
			old_y = player.y;

		if (input == UP) player.y--;
		if (input == LEFT) player.x--;
		if (input == DOWN) player.y++;
		if (input == RIGHT) player.x++;

		// Update Handler
		if (maze.IsWall(player.x, player.y))player.setXY(old_x, old_y); // if player hits wall, go back
		if (player.colliding(enemy)) player.setXY(1, 1); // if player hits enemy, reset
		if (maze.IsExit(player.x, player.y)) game_state = GAME_EXIT; // if player hits exit, exit maze
	}
	clock_t EndTime = clock();
	clock_t ClockTicksTaken = EndTime - StartTime;
	double TimeInSeconds = ClockTicksTaken / (double)CLOCKS_PER_SEC;
	double TimeInMinutes = floor(TimeInSeconds / 60);
	while (TimeInSeconds > 60) 
	{
		TimeInSeconds -= 60;
	}
	system("cls");
	cout << "\n\t - You completed the Maze, gg - " << endl;
	if (TimeInMinutes > 0) 
	{
		cout << "\n\t - You completed the maze in " << TimeInMinutes << " minute(s) " << TimeInSeconds << " seconds" << endl;
	}
	else 
	{
		cout << "\n\t - You completed the maze in " << TimeInSeconds << " seconds" << endl;
	}
	cout << "\n\t - Press enter to quit... - " << endl;
	getchar();
	exit(0);
}

void Instructions()
{
	// Maze Instructions
	cout << "\n\t - Welcome to Escape Characters - \n\n - You are @\n - Your objective is to reach O\n - Navigate through the maze and reach O in order to complete the maze" << endl;
	printf("\n - - - - - - - - - - -"
		"\n -              W    -"
		"\n - Controls   A S D  -"
		"\n - - - - - - - - - - - \n"
	);
	cout << "\n - Press enter to continue..." << endl;
	getchar();
	system("cls");
}

void ChooseLevel()
{
	cout << "\n\t - Choose a level - \n\n - You have 6 levels to choose from\n - Enter the number of the level you would like to play and press enter" << endl;
	cin >> lvl;
}