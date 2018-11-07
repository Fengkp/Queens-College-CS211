#include <iostream>
using namespace std;

bool ok(int q[], int column) {
  for (int i = 0; i < column; ++i) {
    if (q[i] == q[column] || (column - i) == abs(q[column] - q[i]))
      return false;
  }
	return true;
}

void backtrack(int &column, int &solutionCount) {
	column--;
	if (column == -1) {
    cout << "\n" << solutionCount;
  	exit(1);
  }
}

void print(int q[], int &solutionCount) {
	for (int i = 0; i < 8; i++) {
		cout << q[i];
	}
	cout << "\n";
  solutionCount++;
}

int main() {
  int solutionCount = 0;
	int q[8] = {0};
	int column = 1;

	while (column < 8) {
		q[column]++;
		if (q[column] == 8) {
			q[column] = -1;
			backtrack(column, solutionCount);
		}
		else if (ok(q, column))
			column++;
		if (column == 8) {
			print(q, solutionCount);
			backtrack(column, solutionCount);
		}
	}
}
