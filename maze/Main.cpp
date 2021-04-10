#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

// These are Prototypes
void MazeGeneration();
void PrintMaze(int width, int height);
void WallDivision(int x, int y, int width, int height, int Mwidth, int Mheight);
void loadingBar();
// These are Prototypes

const int HWALL = 2; // Setting the HWALL as 2
const int VWALL = 1; // Setting the VWALL as 1
const int SPACE = 0; // Setting Spaces as 0
int Maze[30][30] = {}; // Inits a 30 X 30 grid for all mazes



int main()
{
	srand(time(NULL)); // seeding random number generator

	int width = 0; // Inting the Width
	int height = 0;// Inting the Height
	int Mwidth = 0; // Inting the Max Width
	int Mheight = 0;// Inting the Max Height
	int Selection = 0; // Inting the selection Input

	loadingBar(); // The first call of our Loading bar

	std::cout << "\n\n\t *** Maze Generation *** \n"; // Title of the program

	std::cout << "Please Select What size Maze you wish to generate...\n\n"; // Gets the user input from Cin
	std::cout << "1. 25 x 25 \n";
	std::cout << "2. 30 x 30 \n";
	std::cin >> Selection;

	switch (Selection) // Switch statement, Changing what maze the Player gets
	{
	case 1:
		width = 25; // Setters for botht the Width and Height
		height = 25;
		Mwidth = 25; // Setters for botht the Width and Height
		Mheight = 25;

		MazeGeneration(); // Goes to Maze Generation, setting up the maze
		break;
	case 2:
		width = 30;// Setters for both the Width and Height
		height = 30;
		Mwidth = 30;// Setters for both the Width and Height
		Mheight = 30;
		MazeGeneration(); // Goes to Maze Generation, setting up the maze
		break;
	}

	loadingBar(); // Second call of Loading bar

	WallDivision(0, 0, width, height, Mwidth, Mheight); // Begins the RECURSIVE division of the walls
	PrintMaze(width, height); // Prints out the Maze

	return 0;
}

void MazeGeneration()
{

	for (int i=0; i < 30; i++) 
	{
		for (int j = 0; j < 30; j++)
		{
			Maze[i][j] = SPACE; // Both for loops set all 30 x 30 Squares to Blank spaces
		}
	}

}


void PrintMaze(int width, int height)
{
	for (int i = 0; i < width*2 + 2; i++)
	{
		std::cout << "?"; // Sets the Top bar as all ??
	}
	std::cout << "\n";// new line after the line of ?
	
	for (int i = 0; i < height; i++)
	{
		std::cout << "?"; //Sets a question mark at the start of each line 
		for (int j = 0; j < width; j++)
		{
			if (Maze[j][i] == SPACE) // If its a blank space, It turns blank
			{
				std::cout << "  ";// changed

			}
			else if (Maze[j][i] == HWALL)// If its not a space, and its called HWALL ( Horizontal Wall ) Than it gets placed like this
			{
				std::cout << "##"; 
			}
			else
			{
				std::cout << "##"; // Vertical Walls are the Else
			}
		}
		std::cout << "?\n";//Sets a question mark at the end of each line, and starts the next
	}
	for (int i = 0; i < width*2 + 2; i++) // sets the entire bottom line as ?
	{
		std::cout << "?";
	}
	std::cout << "\n"; // New line after printing.
	system("pause"); // Pauses the Program after the Entirety is printed.
}

void WallDivision(int x, int y, int width, int height, int Mwidth, int Mheight)
{
		bool HOR = true; // Bool Statement, Checking if Horizantal is true.
		if (width < 2 || height < 2) // If too small, Breaks the loop
		{
			return;
		}
		if (width > height)
		{
			HOR = false;// checks if width is greather than height, Thus seeing which cut needs to be made 
		}
		if (HOR) // IF it is Horizantal
		{
			int Startx = x;
			int Starty = y + height / 2; // Selection is being made for where the slice goes

			for (int i = 0; i < width; i++) // This is what sets it as a HWALL
			{
				Maze[Startx + i][Starty] = HWALL;
			}

			int HoleCount = 0;
			 if (Startx - 1 > 0 && Maze[Startx - 1][Starty] == SPACE) // <- TODO:: FIX THIS
			{
				HoleCount++;
				Maze[Startx][Starty] = SPACE;
			}
			if (Startx + 1 > 0 && Maze[Startx + 1][Starty] == SPACE) // <- TODO:: FIX THIS
			{
				HoleCount++;
				Maze[Startx][Starty] = SPACE;
			}
			if (Startx + width < Mwidth && Maze[Startx+width][Starty] == SPACE)// <- TODO:: FIX THIS
			{
				HoleCount++;
				Maze[Startx + (width - 1)][Starty] = SPACE;
			}
			if (HoleCount == 0)
			{
				int Holex = Startx + rand() % width; // Hole is Randomly selected
				int Holey = Starty;

				Maze[Holex][Holey] = SPACE; // Sets the Space 
			}
			WallDivision(x, y, width, height/2, Mwidth, Mheight); // Calls to slice again, but only above the height it did last time
			
			if (height % 2 == 0)
			{
				WallDivision(x, Starty +1, width, (height / 2)-1, Mwidth, Mheight);// calls to slice again, but under the OG height
			}	
			else
			{
				WallDivision(x, Starty + 1, width, (height / 2), Mwidth, Mheight);
			}
		}
		else // IF not HORIZANTAL, its Verticle!
			// This works Just like the Above statement
		{
			int Startx = x + width / 2;
			int Starty = y;

			for (int i = 0; i < height; i++)
			{
				Maze[Startx][Starty + i] = VWALL;
			}

			int VHoleCount = 0;
			if (Starty - 1 > 0 && Maze[Startx][Starty - 1] == SPACE)// <- TODO:: FIX THIS
			{
				VHoleCount++;
				Maze[Startx][Starty] = SPACE;

				
			}
			if (Starty + height < Mheight && Maze[Startx][Starty + height] == SPACE)// <- TODO:: FIX THIS
			{
				VHoleCount++;
				Maze[Startx][Starty+(height-1)] = SPACE;
			}
			if (VHoleCount == 0)
			{
			int Holex = Startx;
			int Holey = Starty + rand() % height;
			Maze[Holex][Holey] = SPACE;
			}
			

			WallDivision(x, y, width /2, height, Mwidth, Mheight); // calls to slice to the left
			if(width % 2 == 0)
			{
				WallDivision(Startx +1, y, (width / 2) - 1, height, Mwidth, Mheight);
			}	// calls to slice to the right
			else
			{
				WallDivision(Startx + 1, y, (width / 2), height, Mwidth, Mheight);
			}
		
		}

	// This is all called Over, and Over again until it cant anymore

}

void loadingBar() // This is a loading bar Function using PrintF
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