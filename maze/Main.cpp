#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void MazeGeneration();
void PrintMaze(int width, int height);
void WallDivision(int x, int y, int width, int height);
void loadingBar();

const int HWALL = 2;
const int VWALL = 1;
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
		MazeGeneration();
		break;
	case 2:
		width = 30;
		height = 30;
		MazeGeneration();
		break;
	}

	loadingBar();
	WallDivision(0, 0, width, height);
	PrintMaze(width, height);

	return 0;
}

void MazeGeneration()
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
	for (int i = 0; i < width*2 + 2; i++)
	{
		std::cout << "?";
	}
	std::cout << "\n";
	
	for (int i = 0; i < height; i++)
	{
		std::cout << "?";
		for (int j = 0; j < width; j++)
		{
			if (Maze[j][i] == SPACE)
			{
				std::cout << " ";

			}
			else if (Maze[j][i] == HWALL)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << "|";
			}
		}
		std::cout << "?\n";
	}
	for (int i = 0; i < width*2 + 2; i++)
	{
		std::cout << "?";
	}
	std::cout << "\n";
	system("pause");
}

void WallDivision(int x, int y, int width, int height)
{



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

			for (int i = 0; i < width; i++)
			{
				Maze[Startx + i][Starty] = HWALL;
			}

			int Holex = Startx + rand() % width;
			int Holey = Starty;

			Maze[Holex][Holey] = SPACE;

			WallDivision(x, y, width, height/2);
			WallDivision(x, Starty+1, width, (height/2)-1);
		}
		else
		{
			int Startx = x + width / 2;
			int Starty = y;

			for (int i = 0; i < height; i++)
			{
				Maze[Startx][Starty + i] = VWALL;
			}

			int Holex = Startx;
			int Holey = Starty + rand() % height;

			Maze[Holex][Holey] = SPACE;

			WallDivision(x, y, width /2, height);
			WallDivision(Startx +1, y, (width / 2) - 1, height);

		}

	

}

void loadingBar()
{
	// 0 - black background,
	// 9 - Light Blue Foreground
	system("color 09");

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