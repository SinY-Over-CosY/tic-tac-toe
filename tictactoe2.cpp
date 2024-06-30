#include <iostream>
#include <conio.h>

char places[3][3] = {		// grid for all markers
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

char selects[3][3] = {		// grid for selection pointer
	{' ', ' ', ' '},
	{' ', '^', ' '},
	{' ', ' ', ' '}
};

int selectCol{ -1 };	// column of selection pointer
int selectRow{ -1 };	// row of selection pointer
char marker{ 'x' };		// marker: naught or cross
int turns{ 0 };

void switchMarker() {	// changes which player's turn it is
	if (marker == 'x') {
		marker = 'o';
	}
	else {
		marker = 'x';
	}
}

void printGrid() {	// simple print grid function that displays the placements of naughts and crosses on a 3x3 grid
	for (int i{ 0 }; i < 3; i++) {	// display grids as well as x and o
		for (int j{ 0 }; j < 3; j++) {
			if (places[i][j] == ' ') {
				std::cout << "/ ";
			}
			else {
				std::cout << places[i][j] << " ";
			}

		}
		std::cout << std::endl;
		for (int k{ 0 }; k < 3; k++) {	// selection pointer beneath grids
			std::cout << selects[i][k] << " ";
		}
		std::cout << std::endl;
	}
}

void placeMarker() {	// move selection pointer across grid to place next move
	// find marker and store its position in row and column vars
	for (int i{ 0 }; i < 3; i++) {
		for (int j{ 0 }; j < 3; j++) {
			if (selects[i][j] == '^') {
				selectRow = i;
				selectCol = j;
			}
		}
	}

	selects[selectRow][selectCol] = ' ';	// remove selector from initial position to move to another position

	switch (_getch()) {		// get user input
	case 'x':	// place marker at selector position
		if (places[selectRow][selectCol] == ' ') {
			places[selectRow][selectCol] = marker;

			switchMarker();		// next player's turn
			turns++;
		}
		break;
	case 'w':
		if (selectRow > 0) {
			selectRow--;
		}
		break;
	case 's':
		if (selectRow < 2) {
			selectRow++;
		}
		break;
	case 'a':
		if (selectCol > 0) {
			selectCol--;
		}
		break;
	case 'd':
		if (selectCol < 2) {
			selectCol++;
		}
		break;
	}
	selects[selectRow][selectCol] = '^';
}



bool checkWin(char checkMark) {
	int i{ 0 };

	char winPos[8][3][3] = {	// all possible winning combinations
	{
		{checkMark, checkMark, checkMark},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	},
	{
		{' ', ' ', ' '},
		{checkMark, checkMark, checkMark},
		{' ', ' ', ' '}
	},
	{
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{checkMark, checkMark, checkMark}
	},
	{
		{checkMark, ' ', ' '},
		{checkMark, ' ', ' '},
		{checkMark, ' ', ' '}
	},
	{
		{' ', checkMark, ' '},
		{' ', checkMark, ' '},
		{' ', checkMark, ' '}
	},
	{
		{' ', ' ', checkMark},
		{' ', ' ', checkMark},
		{' ', ' ', checkMark}
	},
	{
		{checkMark, ' ', ' '},
		{' ', checkMark, ' '},
		{' ', ' ', checkMark}
	},
	{
		{' ', ' ', checkMark},
		{' ', checkMark, ' '},
		{checkMark, ' ', ' '}
	},
	};

	int matchMarks{ 0 };	// number of marks that match the compared winning combination

	while (i < 7 && matchMarks < 3) {
		for (i = 0; i < 8; i++) {
			for (int x{ 0 }; x < 3; x++) {
				for (int y{ 0 }; y < 3; y++) {
					if (winPos[i][x][y] == places[x][y] && places[x][y] != ' ') {	// if current position matches marker at current combination in winPos and is not empty
						matchMarks++;
					}
				}
			}
			if (matchMarks == 3) {	// if there are 3 marker matches in any of the compared winning combinations, then 3 are in a row and the game is over
				return true;
				break;
			}
			else {
				matchMarks = 0;
			}
		}
	}

	checkMark = 'o';	// repeats entire process for o lmao

	while (i < 7 && matchMarks < 3) {
		for (i = 0; i < 8; i++) {
			for (int x{ 0 }; x < 3; x++) {
				for (int y{ 0 }; y < 3; y++) {
					if (winPos[i][x][y] == places[x][y] && places[x][y] != ' ') {
						matchMarks++;
					}
				}
			}
			if (matchMarks == 3) {
				return true;
				break;
			}
			else {
				matchMarks = 0;
			}
		}
	}


	return false;
}

int main()
{
	bool gameWon{ false };
	char winner{ ' ' };

	while (turns < 9){
		system("cls");	// clears console to print updated one
		printGrid();	// prints updated grid

		placeMarker();

		gameWon = checkWin('x');
		if (gameWon == true) {
			winner = 'x';
			system("cls");	// clears console to print updated one
			printGrid();	// prints updated grid
			break;
		}
		gameWon = checkWin('o');
		if (gameWon == true) {
			winner = 'o';
			system("cls");	// clears console to print updated one
			printGrid();	// prints updated grid
			break;
		}
	}

	if (winner != ' ') {
		std::cout << "winner is " << winner;
	}
	else {
		system("cls");
		printGrid();
		std::cout << "draw";
	}
}

// TODO
// - good enough, push to main