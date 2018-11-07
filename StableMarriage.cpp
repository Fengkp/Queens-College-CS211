#include <iostream>
using namespace std;

bool ok(int q[], int col) {
	int mp[3][3] = {
		{ 0, 2, 1 },
	{ 0, 2, 1 },
	{ 1, 2, 0 } };
	int wp[3][3] = {
		{ 2, 1, 0 },
	{ 0, 1, 2 },
	{ 2, 0, 1 } };

	for (int man = 0; man < col; man++) {   // q[col] = new W, q[i] = current W, col = new Man
		if (q[man] == q[col])
			return false;
		if ((mp[man][q[col]] < mp[man][q[man]]) && (wp[q[col]][man] < wp[q[col]][col]))
			return false;
		if ((mp[col][q[man]] < mp[col][q[col]]) && (wp[q[man]][col] < wp[q[man]][man]))
			return false;
	}
	return true;
}

void backtrack(int &col) {
	col--;
	if (col == -1)
		exit(1);
}

void print(int q[]) {
	for (int i = 0; i < 3; i++) {
		cout << q[i];
	}
	cout << "\n";
}

int main() {
	int q[] = { -1, -1, -1 };	// Marriage configurations; For each index = man, there is a value = woman
	int col = 0;

	while (col < 3) {
		q[col]++;
		if (q[col] > 2) {
			q[col] = -1;
			backtrack(col);
		}
		else if (ok(q, col))
			col++;
		if (col == 3) {
			print(q);
			backtrack(col);
		}
	}
	return 0;
}
