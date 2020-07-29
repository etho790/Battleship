#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void clearBoard(char clearArray[10][10]); // Clears the board																												
void drawBoard(char acWhichBoard[10][10]); // Draws a board and places a given array inside of it.																		
int Menu(string & firstplayername); // Draws the main menu	
void player1placingships(int &player,string &firstplayername, string &secondplayername, char PGrid[10][10], char PshootGrid[10][10], char EshootGrid[10][10], char EcantseeGrid[10][10]);
void ships(int &player, int &currentpick, char &symbol, int &size, string &boatname);
void player2placingships(int &player, string &firstplayername, string &secondplayername, char PGrid[10][10], char PshootGrid[10][10], char EshootGrid[10][10], char EcantseeGrid[10][10]);
void shootingships(int &player, string &firstplayername, string &secondplayername, char PGrid[10][10], char PshootGrid[10][10], char EshootGrid[10][10], char EcantseeGrid[10][10]);



void clearBoard(char clearArray[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			clearArray[i][j] = ' ';
		}
	}

	
}

int Menu(string & firstplayername)
{
	// Draws a main menu user interface
	int MenuChoice;

	cout << R"(BATTLESHIPS GAME )" << endl;

	cout << "Select from the options below!" << endl << endl;
	cout << "1.) Single Player" << endl;

	cout << "2.) Exit Game" << endl;
	cin >> MenuChoice; // Asks for user's choice
	if (MenuChoice == 1) // If single player is selected then ask for player's name
	{
		cout << "Enter Player Name: ";
		cin >> firstplayername;
	}
	if (MenuChoice == 2) // If exit selected send message
	{
		cout << "Thanks for playing" << endl;
		system("PAUSE");
	}

	system("CLS");
	return MenuChoice;

}

void drawBoard(char anyarray[10][10])  //takes in an array which is the value to be placed in the board
{
	cout << "  "; // Inital spacing
	for (int Xvalue = 0; Xvalue < 10; Xvalue++)
	{
		cout << " " << Xvalue + 1 << "  "; // Top Numbers
	}
	cout << endl << " "; // new line and initial spacing 

	for (int Xvalue = 0; Xvalue < 10; Xvalue++)
	{
		cout << "----"; // Top line
	}
	cout << " " << endl;
	for (int Yvalue = 0; Yvalue < 10; Yvalue++)
	{
		cout << char(Yvalue + 'A'); // Displays side alphabets converting the number +A into alphabets 
		for (int Xvalue = 0; Xvalue < 10; Xvalue++)
		{
			cout << "| " << anyarray[Yvalue][Xvalue] << " "; // the acWhichBoard[row][coloumn] is the array or the value thats going to be placed in grid
		}
		cout << "|" << endl;
		cout << " ";
		for (int Xvalue = 0; Xvalue < 10; Xvalue++)
		{
			cout << "----"; // Draws last lines
		}
		cout << " " << endl;
	}
	cout << endl;
}

int main()
{
	string firstplayername;
	string secondplayername;
	int player=1;

	char PGrid[10][10];
	char PshootGrid[10][10];
	char EshootGrid[10][10];
	char EcantseeGrid[10][10];

	clearBoard(PGrid);
	clearBoard(PshootGrid);
	clearBoard(EshootGrid);
	clearBoard(EcantseeGrid);

	int iChoice = 0; // clears iChoice
	iChoice = Menu(firstplayername); //Recives the INT MENUCHOICE result from MainMenu function
	if (iChoice == 2) // If player selected exit...
	{
		return 0; // End program
	}
	
	if (iChoice == 1) 
	{
		secondplayername = "AI";
		
		drawBoard(PGrid);
		player1placingships(player, firstplayername, secondplayername, PGrid, PshootGrid,EshootGrid,EcantseeGrid );

		player2placingships(player, firstplayername, secondplayername, PGrid, PshootGrid, EshootGrid, EcantseeGrid);
		shootingships(player,firstplayername,secondplayername, PGrid, PshootGrid, EshootGrid, EcantseeGrid);
		return 0; // Game has finished end the game.
	}
	system("PAUSE");

}
void player1placingships(int &player, string &firstplayername, string &secondplayername, char PGrid[10][10], char PshootGrid[10][10], char EshootGrid[10][10], char EcantseeGrid[10][10])
{
	int currentpick=1;
	char symbol;
	int size;
	string boatname;
	
	char Ylocation;
	int Ycoordinate;
	int Xcoordinate;
	int direction;
	
	

	while (player==1)
	{
			
		ships(player,currentpick, symbol, size, boatname);
		cout << "where would you place your " << boatname << endl;	//typing x coordinate
		cout << "X: ";
		cin >> Xcoordinate;
	while (Xcoordinate<1|| Xcoordinate>10)
		{
			cout << "must be in 1-10 range sorry" << endl;
			cout << "Try again" << endl;
			cout << "X: ";
			cin >> Xcoordinate;
			if (Xcoordinate >= 1 && Xcoordinate <=10)
			{
				break;
			}
		}

		cout << "Y: ";													//typing y coordinate
		cin >> Ylocation;
		(int)Ylocation - 96;
		while (Ylocation<97 || Ylocation>106)
		{
			cout << "must be lower case letter from a-j" << endl;
			cout << "Try again" << endl;
			cout << "Y: ";
			cin >> Ylocation;
			if (Ylocation >= 97 && Ylocation <= 106)
			{
				break;
			}
		}
		Ycoordinate = Ylocation - 96;
		system("CLS");

		while (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') 
		{
			cout << "you cant place it there, enter your X and Y co-ordinates again" << endl;
			cout << "X: ";
			cin >> Xcoordinate;
			while (Xcoordinate<1 || Xcoordinate>10)
			{
				cout << "must be in 1-10 range sorry" << endl;
				cout << "Try again" << endl;
				cout << "X: ";
				cin >> Xcoordinate;
				if (Xcoordinate >= 1 && Xcoordinate <= 10)
				{
					break;
				}
			}
			cout << "Y: ";													//typing y coordinate
			cin >> Ylocation;
			(int)Ylocation - 96;
			while (Ylocation<97 || Ylocation>106)
			{
				cout << "must be lower case letter from a-j" << endl;
				cout << "Try again" << endl;
				cout << "Y: ";
				cin >> Ylocation;
				if (Ylocation >= 97 && Ylocation <= 106)
				{
					break;
				}
			}
			Ycoordinate = Ylocation - 96;
			
		}
		if (PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ')		//if co-ordinate is not on any ship
		{
			PGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;	//places the respective symbol of ship on array
			drawBoard(PGrid);									//passes the array on the board to be shown
		}
		
		cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
		cin >> direction;


		while (direction < 1 ||direction >4)
		{
			cout << "must be one of the four options" << endl;
			cin >> direction;
			if (direction >= 1 && direction <= 4) 
			{
				
				break;
			}
		}
		switch (direction)
		{
		case (1):
		ONE:	
			while (PGrid[0][Xcoordinate - 1]==PGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				cout << "cant go up, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
					if (direction ==2)
					{
						goto TWO;
					}
					if (direction == 3)
					{
						goto THREE;
					}
					if (direction == 4)
					{
						goto FOUR;
					}
			}
			while(PGrid[1][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1]&& size>2)													//FIX THE !XCOORDINATE
			{
				cout << "cant go up, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				
					if (direction == 2)
					{
						goto TWO;
					}
					if (direction == 3)
					{
						goto THREE;
					}
					if (direction == 4)
					{
						goto FOUR;
					}
			}
			while (PGrid[2][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)													//FIX THE !XCOORDINATE
			{
				cout << "cant go up, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				
					if (direction == 2)
					{
						goto TWO;
					}
					if (direction == 3)
					{
						goto THREE;
					}
					if (direction == 4)
					{
						goto FOUR;
					}
				
			}
			while (PGrid[3][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)													//FIX THE !XCOORDINATE
			{
				cout << "cant go up, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				
					if (direction == 2)
					{
						goto TWO;
					}
					if (direction == 3)
					{
						goto THREE;
					}
					if (direction == 4)
					{
						goto FOUR;
					}
				
			}

			while (PGrid[4][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)													//FIX THE !XCOORDINATE
			{
				cout << "cant go up, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				
					if (direction ==2)
					{
						goto TWO;
					}
					if (direction == 3)
					{
						goto THREE;
					}
					if (direction == 4)
					{
						goto FOUR;
					}
				
			}
			while (PGrid[Ycoordinate - 1][Xcoordinate - 1])		
			{
				

				if (size == 0)										
				{
					break;
				}
				size = size - 1;
				Ycoordinate--;												//checking for one above original symbol
				while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')		//if the above coordinate is empty
				{
					PGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(PGrid);
					size = size - 1;
					Ycoordinate--;
					if (size == 0)										
					{
						goto HASH;
					}
					if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the coordinate above is occupied
					{
						currentpick--;
						Ycoordinate++;
						cout << "try a diff direction next time" << endl;
						while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)	
						{
						size = size + 1;
						
						PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(PGrid);
						Ycoordinate++;
						if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}
						} 

					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the second ship is literally below the first
				{
					currentpick--;
					Ycoordinate++;
					cout << "try a diff direction next time" << endl;	//try adding the y co-ordinate
					while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol) 
					{
						size = size + 1;
					

						PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(PGrid);
					if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
						goto HASH;
						}
					} 

				}
				
				
			}
			
			break;


		case (2):
			TWO:
			while (PGrid[9][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				cout << "cant go down, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				
					if (direction == 1)
					{
						goto ONE;
					}
					if (direction == 3)
					{
						goto THREE;
					}
					if (direction == 4)
					{
						goto FOUR;
					}
				
			}
			while (PGrid[8][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>2)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go down, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (PGrid[7][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go down, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction = 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (PGrid[6][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go down, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (PGrid[5][Xcoordinate - 1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go down, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (PGrid[Ycoordinate - 1][Xcoordinate - 1])
			{
				
				
				if (size == 0)										//temp fix. look into this later
				{
					break;
				}
				size = size - 1;
				Ycoordinate++;										//if the below coordinate is empty
				while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')
				{
					PGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(PGrid);
					size = size - 1;
					Ycoordinate++;
					if (size == 0)
					{
						goto HASH;
					}
					if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the coordinate below is occupied
					{
						currentpick--;
						Ycoordinate--;
						cout << "try a diff direction next time" << endl;
						while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
						{
							size = size + 1;
							PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
							system("CLS");
							drawBoard(PGrid);
							Ycoordinate--;

							if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}

						}
												
					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the second ship is literally above the first
				{
					currentpick--;
					Ycoordinate--;
					cout << "try a diff direction next time" << endl;
					while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
					{
						size = size + 1;
						PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(PGrid);
						if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
							goto HASH;
						}
					}
				}
			}
		
			break;




		case (3):
			THREE:
			while (PGrid[Ycoordinate - 1][0] == PGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				cout << "cant go left, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (PGrid[Ycoordinate - 1][1] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>2)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go left, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;


				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (PGrid[Ycoordinate - 1][2] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go left, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (PGrid[Ycoordinate - 1][3] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go left, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (PGrid[Ycoordinate - 1][4] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go left, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (PGrid[Ycoordinate - 1][Xcoordinate - 1])
			{
				

				if (size == 0)										//temp fix. look into this later
				{
					break;
				}
				size = size - 1;
				Xcoordinate--;
				while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')
				{
					PGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(PGrid);
					size = size - 1;
					Xcoordinate--;
					if (size == 0)
					{
						goto HASH;
					}
					if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
					{
						currentpick--;
						Xcoordinate++;
						cout << "try a diff direction next time" << endl;
						while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
						{
							size = size + 1;
							PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
							system("CLS");
							drawBoard(PGrid);
							Xcoordinate++;
							if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}
						}
					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
				{
					currentpick--;
					Xcoordinate++;
					cout << "try a diff direction next time" << endl;
					while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
					{
						size = size + 1;

						PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(PGrid);
						if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
							goto HASH;
						}
					}
				}
			}
			
			
			break;





		case (4):
			FOUR:
			while (PGrid[Ycoordinate - 1][9] == PGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				cout << "cant go right, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (PGrid[Ycoordinate - 1][8] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>2)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go right, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (PGrid[Ycoordinate - 1][7] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go right, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (PGrid[Ycoordinate - 1][6] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go right, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}
			while (PGrid[Ycoordinate - 1][5] == PGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)//wont place cuz subsequent symbols will be out of grid
			{
				cout << "cant go right, try again" << endl;
				cout << "what position, up(1), down(2), left(3) or right(4)?" << endl;
				cin >> direction;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (PGrid[Ycoordinate - 1][Xcoordinate - 1])
			{

				

		
				if (size == 0)										//temp fix. look into this later
				{
					break;
				}
				size = size - 1;
				Xcoordinate++;
				while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')
				{
					PGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(PGrid);
					size = size - 1;
					Xcoordinate++;
					if (size == 0)
					{
						goto HASH;
					}
					if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
					{
						currentpick--;
						Xcoordinate--;
						cout << "try a diff direction next time" << endl;
						while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
						{
							size = size + 1;
							PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
							system("CLS");
							drawBoard(PGrid);
							Xcoordinate--;
							if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}
						}
					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
				{
					currentpick--;
					Xcoordinate--;
					cout << "try a diff direction next time" << endl;
					while (PGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
					{
						size = size + 1;
						PGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(PGrid);
						if (PGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
							goto HASH;
						}
					}
				}


			}

			break;



		}
		
		
		
		HASH:
		currentpick++;
		if (currentpick > 5)
		{
			goto ENDOFFUNTCION;
		}

	}

	ENDOFFUNTCION:
	player = 2;
	currentpick = 1;
	

}




void ships(int& player, int &currentpick, char &symbol, int &size, string &boatname)
{
	switch (currentpick)
	{
	case(1):
		boatname = "patrol boat";
		symbol = 'P';
		size = 2;
		break;
	case(2):
		boatname = "Destroyer";
		symbol = 'D';
		size = 3;
		break;
	case(3):
		boatname = "submarine";
		symbol = 'S';
		size = 3;
		break;
	case(4):
		boatname = "Battleship";
		symbol = 'B';
		size = 4;
		break;
	case(5):
		boatname = "Aircraft carrier";
		symbol = 'A';
		size = 5;
		break;
	default:
		break;
	}
	
}


void player2placingships(int &player, string &firstplayername, string &secondplayername, char PGrid[10][10], char PshootGrid[10][10], char EshootGrid[10][10], char EcantseeGrid[10][10])
{
	int currentpick = 1;
	char symbol;
	int size;
	string boatname;

	char Ylocation;
	int Ycoordinate;
	int Xcoordinate;
	int direction;
	srand(time(0));
	while (player == 2)
	{

		ships(player, currentpick, symbol, size, boatname);
	
		Xcoordinate=1+rand()%10;
		while (Xcoordinate<1 || Xcoordinate>10)
		{
			Xcoordinate = 1 + rand() % 10;
			if (Xcoordinate >= 1 && Xcoordinate <= 10)
			{
				break;
			}
		}

		Ycoordinate = 1 + rand() % 10;
		while (Ycoordinate<1 || Ycoordinate>10)
		{
			Ycoordinate = 1 + rand() % 10;
			if (Ycoordinate >= 1 && Ycoordinate <= 10)
			{
				break;
			}
		}
		
		system("CLS");

		while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
		{
			Xcoordinate = 1 + rand() % 10;
			while (Xcoordinate<1 || Xcoordinate>10)
			{
				Xcoordinate = 1 + rand() % 10;
				if (Xcoordinate >= 1 && Xcoordinate <= 10)
				{
					break;
				}
			}
			Ycoordinate = 1 + rand() % 10;
			while (Ycoordinate<1 || Ycoordinate>10)
			{
				Ycoordinate = 1 + rand() % 10;
				if (Ycoordinate >= 1 && Ycoordinate <= 10)
				{
					break;
				}
			}
			
			system("CLS");
		}
		if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ')		//if co-ordinate is not on any ship
		{
			EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;	
			drawBoard(EcantseeGrid);									//TEST PURPOSES MUST DELETE
		}

		direction = 1 + rand() % 4;


		while (direction < 1 || direction >4)
		{
			direction = 1 + rand() % 4;
			if (direction >= 1 && direction <= 4)
			{

				break;
			}
		}
		switch (direction)
		{
		case (1):
		ONE:
			while (EcantseeGrid[0][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				direction = 1 + rand() % 4;
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (EcantseeGrid[1][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>2)													//FIX THE !XCOORDINATE
			{
				direction = 1 + rand() % 4;

				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (EcantseeGrid[2][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)													//FIX THE !XCOORDINATE
			{
				direction = 1 + rand() % 4;

				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}

			}
			while (EcantseeGrid[3][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)													//FIX THE !XCOORDINATE
			{
				direction = 1 + rand() % 4;

				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}

			}

			while (EcantseeGrid[4][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)													//FIX THE !XCOORDINATE
			{
				direction = 1 + rand() % 4;

				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}

			}
			while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1])
			{


				if (size == 0)
				{
					break;
				}
				size = size - 1;
				Ycoordinate--;												//checking for one above original symbol
				while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')		//if the above coordinate is empty
				{
					EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(EcantseeGrid);  //MUSTDELETE
					size = size - 1;
					Ycoordinate--;
					if (size == 0)
					{
						goto HASH;
					}
					if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the coordinate above is occupied
					{
						currentpick--;
						Ycoordinate++;
						
						while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
						{
							size = size + 1;

							EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
							system("CLS");
							drawBoard(EcantseeGrid); //MUSTDELETE
							Ycoordinate++;
							if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}
						}

					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the second ship is literally below the first
				{
					currentpick--;
					Ycoordinate++;
					
					while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
					{
						size = size + 1;


						EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(EcantseeGrid); //MUSTDELETE
						if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
							goto HASH;
						}
					}

				}


			}

			break;


		case (2):
		TWO:
			while (EcantseeGrid[9][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				direction = 1 + rand() % 4;

				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}

			}
			while (EcantseeGrid[8][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>2)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (EcantseeGrid[7][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction = 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (EcantseeGrid[6][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (EcantseeGrid[5][Xcoordinate - 1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 3)
				{
					goto THREE;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1])
			{


				if (size == 0)										//temp fix. look into this later
				{
					break;
				}
				size = size - 1;
				Ycoordinate++;										//if the below coordinate is empty
				while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')
				{
					EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(PGrid); //MUSTDELETE
					size = size - 1;
					Ycoordinate++;
					if (size == 0)
					{
						goto HASH;
					}
					if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the coordinate below is occupied
					{
						currentpick--;
						Ycoordinate--;
						
						while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
						{
							size = size + 1;
							EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
							system("CLS");
							drawBoard(EcantseeGrid); //MUSTDELETE
							Ycoordinate--;

							if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}

						}

					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ') //if the second ship is literally above the first
				{
					currentpick--;
					Ycoordinate--;
					
					while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
					{
						size = size + 1;
						EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(EcantseeGrid); //MUSTDELETE
						if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
							goto HASH;
						}
					}
				}
			}

			break;




		case (3):
		THREE:
			while (EcantseeGrid[Ycoordinate - 1][0] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (EcantseeGrid[Ycoordinate - 1][1] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>2)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;


				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (EcantseeGrid[Ycoordinate - 1][2] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (EcantseeGrid[Ycoordinate - 1][3] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}

			while (EcantseeGrid[Ycoordinate - 1][4] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 4)
				{
					goto FOUR;
				}
			}
			while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1])
			{


				if (size == 0)										//temp fix. look into this later
				{
					break;
				}
				size = size - 1;
				Xcoordinate--;
				while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')
				{
					EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(EcantseeGrid);//MUSTDELETE
					size = size - 1;
					Xcoordinate--;
					if (size == 0)
					{
						goto HASH;
					}
					if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
					{
						currentpick--;
						Xcoordinate++;
						
						while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
						{
							size = size + 1;
							EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
							system("CLS");
							drawBoard(EcantseeGrid);//MUSTDELETE
							Xcoordinate++;
							if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}
						}
					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
				{
					currentpick--;
					Xcoordinate++;
					
					while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
					{
						size = size + 1;

						EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(EcantseeGrid);//MUSTDELETE
						if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
							goto HASH;
						}
					}
				}
			}


			break;





		case (4):
		FOUR:
			while (EcantseeGrid[Ycoordinate - 1][9] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1]) //wont place cuz out of map
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (EcantseeGrid[Ycoordinate - 1][8] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>2)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (EcantseeGrid[Ycoordinate - 1][7] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>3)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (EcantseeGrid[Ycoordinate - 1][6] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>4)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}
			while (EcantseeGrid[Ycoordinate - 1][5] == EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] && size>5)//wont place cuz subsequent symbols will be out of grid
			{
				direction = 1 + rand() % 4;
				if (direction == 1)
				{
					goto ONE;
				}
				if (direction == 2)
				{
					goto TWO;
				}
				if (direction == 3)
				{
					goto THREE;
				}
			}

			while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1])
			{




				if (size == 0)										//temp fix. look into this later
				{
					break;
				}
				size = size - 1;
				Xcoordinate++;
				while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ')
				{
					EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = symbol;
					system("CLS");
					drawBoard(EcantseeGrid);  //MUSTDELETE
					size = size - 1;
					Xcoordinate++;
					if (size == 0)
					{
						goto HASH;
					}
					if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
					{
						currentpick--;
						Xcoordinate--;
					
						while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
						{
							size = size + 1;
							EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
							system("CLS");
							drawBoard(EcantseeGrid); //MUSTDELETE
							Xcoordinate--;
							if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
							{
								goto HASH;
							}
						}
					}
					if (size == 0)										//temp fix. look into this later
					{
						goto HASH;
					}
				}
				if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != ' ')
				{
					currentpick--;
					Xcoordinate--;
					
					while (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == symbol)
					{
						size = size + 1;
						EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = ' ';
						system("CLS");
						drawBoard(EcantseeGrid); //MUSTDELETE
						if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] != symbol)
						{
							goto HASH;
						}
					}
				}


			}

			break;



		}



	HASH:
		currentpick++;
		if (currentpick > 5)
		{
			player = 1;
			goto ENDOFFUNTCION;
		}

	}

ENDOFFUNTCION:
	cout << "AI has placed all its ships" << endl;
	system("PAUSE");

}

void shootingships(int &player, string &firstplayername, string &secondplayername, char PGrid[10][10], char PshootGrid[10][10], char EshootGrid[10][10], char EcantseeGrid[10][10])
{
	char symbol;
	int sizeS, sizeES;
	int sizeP, sizeEP;
	int sizeA, sizeEA;
	int sizeD, sizeED;
	int sizeB, sizeEB;
	string boatname;

	char Ylocation;
	int Ycoordinate;
	int Xcoordinate;
	int direction;
	srand(time(0));
	
		sizeP = 2;
		sizeD = 3;
		sizeS = 3;
		sizeB = 4;
		sizeA = 5;


		sizeEP = 2;
		sizeED = 3;
		sizeES = 3;
		sizeEB = 4;
		sizeEA = 5;
	
front:
	while (player==1)
	{

		system("CLS");
		cout << "Your turn" << endl;
		cout << "where would you like to shoot" << endl;
		cout << "X: ";
		cin >> Xcoordinate;
		while (Xcoordinate<1 || Xcoordinate>10)
		{
			cout << "must be in 1-10 range sorry" << endl;
			cout << "Try again" << endl;
			cout << "X: ";
			cin >> Xcoordinate;
			if (Xcoordinate >= 1 && Xcoordinate <= 10)
			{
				break;
			}
		}

		cout << "Y: ";													//typing y coordinate
		cin >> Ylocation;
		(int)Ylocation - 96;
		while (Ylocation<97 || Ylocation>106)
		{
			cout << "must be lower case letter from a-j" << endl;
			cout << "Try again" << endl;
			cout << "Y: ";
			cin >> Ylocation;
			if (Ylocation >= 97 && Ylocation <= 106)
			{
				break;
			}
		}
		Ycoordinate = Ylocation - 96;
		
		if(EcantseeGrid[Ycoordinate-1][Xcoordinate-1]==' ')		//IF MISS
		{ 
			cout << "MISS" << endl;
			PshootGrid[Ycoordinate - 1][Xcoordinate - 1] = 'M';
			drawBoard(PshootGrid);
			system("PAUSE");

			player = 2;
		}	
		if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'S' || EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'A'||EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'D' || EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'B'|| EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'P')		//IF HIT
		{
			
			cout << "HIT!!" << endl;
			
			if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'S')
			{
				sizeS--;
				if (sizeS == 0)
				{
					cout << "you have sunk the enemys submarine" << endl;
				}
								
			}
			if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'P')
			{
				sizeP--;
				if (sizeP == 0)
				{
					cout << "you have sunk the enemys patrolboat" << endl;
				}
								
			}
			if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'B')
			{
				sizeB--;
				if (sizeB == 0)
				{
					cout << "you have sunk the enemys Battleship" << endl;
				}
								
			}
			if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'A')
			{
				sizeA--;
				if (sizeA == 0)
				{
					cout << "you have sunk the enemys Aircraft carrier" << endl;
				}
												
			}
			if (EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] == 'D')
			{
				sizeD--;
				if (sizeD == 0)
				{
					cout << "you have sunk the enemys Destroyer" << endl;
				}
					
			}
			PshootGrid[Ycoordinate - 1][Xcoordinate - 1] = 'X';
			EcantseeGrid[Ycoordinate - 1][Xcoordinate - 1] = 'X';
			drawBoard(PshootGrid);
			system("PAUSE");



			player = 2;
		}
		
		if (sizeS == 0 && sizeP == 0 && sizeD == 0 && sizeB == 0 && sizeA == 0)
		{
			cout << "YOU HAVE SUNK ALL SHIPS, YOU WIN" << endl;
			system("PAUSE");
			return;
		}
	}

	while (player==2)
	{
		system("CLS");
		cout << "AI'S turn" << endl;
		
		Xcoordinate = 1 + rand() % 10;
		while (Xcoordinate<1 || Xcoordinate>10)
		{
			Xcoordinate = 1 + rand() % 10;
			if (Xcoordinate >= 1 && Xcoordinate <= 10)
			{
				break;
			}
		}

		Ycoordinate = 1 + rand() % 10;
		while (Ycoordinate<1 || Ycoordinate>10)
		{
			Ycoordinate = 1 + rand() % 10;
			if (Ycoordinate >= 1 && Ycoordinate <= 10)
			{
				break;
			}
		}
		if (PGrid[Ycoordinate - 1][Xcoordinate - 1] == ' ') //IF ITS A MISS
		{
			cout << "MISS" << endl;
			EshootGrid[Ycoordinate - 1][Xcoordinate - 1] = 'M';
			drawBoard(EshootGrid);
			system("PAUSE");

			player = 1;
		}

		if (PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'S'|| PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'A'|| PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'D'|| PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'B'|| PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'P')
		{
			
			cout << "HIT!!" << endl;

			if (PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'S')
			{
				sizeES--;
				if (sizeES == 0)
				{
					cout << "your  submarine has sunk " << endl;
				}

			}
			if (PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'P')
			{
				sizeEP--;
				if (sizeEP == 0)
				{
					cout << "your patrolboat has sunk" << endl;
				}

			}
			if (PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'B')
			{
				sizeEB--;
				if (sizeEB == 0)
				{
					cout << "you  Battleship has sunk" << endl;
				}

			}
			if (PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'A')
			{
				sizeEA--;
				if (sizeEA == 0)
				{
					cout << "you Aircraft carrier's sunk" << endl;
				}

			}
			if (PGrid[Ycoordinate - 1][Xcoordinate - 1] == 'D')
			{
				sizeED--;
				if (sizeED == 0)
				{
					cout << "you Destroyer has been sunk" << endl;
				}

			}
			EshootGrid[Ycoordinate - 1][Xcoordinate - 1] = 'X';
			drawBoard(EshootGrid);
			system("PAUSE");

			player = 1;
		}
		if (sizeES == 0 && sizeEP == 0 && sizeED == 0 && sizeEB == 0 && sizeEA == 0)
		{
			cout << "YOU HAVE ALL SUNKEN SHIPS, YOU LOSE" << endl;
			system("PAUSE");
			return;
		}
		goto front;
	}

	
}

