#include <iostream>
using namespace std;

int main() {
	int count = 0;
	int board[8][8] = { 0 };
	int row = 0;
	int column = 0;

	// Initiate first Queen in top left corner
	board[row][column] = 1;
nextColumn:
	column++;
	if (column == 8)
		goto finish;
	row = -1;   // Reset row for each column
nextRow:
	row++;
	if (row == 8)
		goto backtrack;

	// Check horizontal
	for (int i = 0; (i < column) && (row < 8); i++) {
		if (board[row][i] == 1)
			goto nextRow;
	}

	// Check up diagnol
	for (int i = 1; (row >= i) && (column >= i); i++) {
		if (board[row - i][column - i] == 1)
			goto nextRow;
	}

	// Check down diagnol
	for (int i = 1; ((row + i) < 8) && (row < 8); i++) {
		if (board[row + i][column - i] == 1)
			goto nextRow;
	}

	board[row][column] = 1;
	if (column < 8)
		goto nextColumn;

backtrack:
	column--;
	if (column == -1)
		return 0;
	else {
		for (int i = 7; i >= 0; i--) {
			if (board[i][column] == 1) {
				board[i][column] = 0;
				row = i;
				goto nextRow;
			}
		}
}

finish:
	for (int r = 0; r < 8; r++) {
		cout << endl;
		for (int c = 0; c < 8; c++)
			if (board[r][c] == 1)
				cout << "1 ";
			else
				cout << "0 ";
	}
	cout << "Solution Count: " << ++count << endl;
	goto backtrack;
}
