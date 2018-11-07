#include <iostream>
using namespace std;

bool ok(int q[], int column) {
	for (int i = 0; i < column; ++i) {
		if (q[i] == q[column] || (column - i) == abs(q[column] - q[i]))
			return false;
	}
	return true;
}

void initBoard(int q[], int n) {
	for (int i = 0; i < n; i++) {
		q[i] = 0;
	}
}

int nQueens(int n) {
	if (n == 1)
		return 1;           // There is only one possible solution for a 1x1 board; return 1 and don't execute.

	int *q = new int[n];
	int column = 1;
	int solutionCount = 0;
	initBoard(q, n);

	while (column < n) {
		q[column]++;
		if (q[column] == n) {
			q[column] = -1;
			column--;                  // Backtrack
		}
		else if (ok(q, column))
			column++;
		if (column == n) {
			solutionCount++;
			column--;                // Backtrack
		}
		if (column == -1) {
			delete []q;
			return solutionCount;
		}
	}
	return solutionCount;
}

int main() {
	int n;
	cout << "How many boards?" << endl;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << "There are " << nQueens(i) << " solutions to the "
			<< i << " queens problem." << endl;
	}
	return 0;
}
