#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void MazeGeneration(int width, int height);
void PrintMaze(int width, int height);
void WallDivision(int x, int y, int width, int height);
void loadingBar();

const int WALL = 1;
const int SPACE = 0;
int Maze[30][30] = {};



int main()
{
	srand(time(NULL));

	int width = 0;
	int height = 0;
	int Selection = 0;
	loadingBar();

	std::cout << "\n\n\t *** Maze Generation *** \n";

	std::cout << "Please Select What size Maze you wish to generate...\n\n";
	std::cout << "1. 25 x 25 \n";
	std::cout << "2. 30 x 30 \n";
	std::cin >> Selection;

	switch (Selection)
	{
	case 1:
		width = 25;
		height = 25;
		MazeGeneration(width, height);
	case 2:
		width = 30;
		height = 30;
		MazeGeneration(width, height);
	}
	WallDivision(0, 0, width, height);
	PrintMaze(width, height);

	return 0;
}

void MazeGeneration(int width, int height)
{

	for (int i=0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			Maze[i][j] = SPACE;
		}
	}

}


void PrintMaze(int width, int height)
{
	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "?";
	}
	std::cout << "\n";
	
	for (int i = 0; i < height; i++)
	{
		std::cout << "?";
		for (int j = 0; j < width; j++)
		{
			std::cout << Maze[j][i];
		}
		std::cout << "?\n";
	}
	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "?";
	}
	std::cout << "\n";
}

void WallDivision(int x, int y, int width, int height)
{

		loadingBar();
		bool HOR = true;
		if (width < 2 || height < 2)
		{
			return;
		}
		if (width > height)
		{
			HOR = false;
		}
		if (HOR)
		{
			int Startx = x;
			int Starty = y + height / 2;

			int NewW = width;
			int NewH = height / 2;

			for (int i = 0; i < NewW; i++)
			{
				Maze[Startx + i][Starty] = WALL;
			}

			int Holex = Startx + rand() % width;
			int Holey = Starty;

			Maze[Holex][Holey] = SPACE;

		}
		else
		{
			int Startx = x + width / 2;
			int Starty = y;

			int NewW = width / 2;
			int NewH = height;

			for (int i = 0; i < NewH; i++)
			{
				Maze[Startx][Starty + i] = WALL;
			}

			int Holex = Startx;
			int Holey = Starty + rand() % height;

			Maze[Holex][Holey] = SPACE;

		}
	

}

void loadingBar()
{
	// 0 - black background,
	// A - Green Foreground
	system("color 0A");

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t\t" "Loading...\n\n");
	printf("\t\t\t\t\t");

	// Print initial loading bar
	for (int i = 0; i < 26; i++)
		printf("%c", a);

	// Set the cursor again starting
	// point of loading bar
	printf("\r");
	printf("\t\t\t\t\t");

	// Print loading bar progress
	for (int i = 0; i < 26; i++) {
		printf("%c", b);

		// Sleep 
		Sleep(10);
	}
	printf("\n\n\n");
}