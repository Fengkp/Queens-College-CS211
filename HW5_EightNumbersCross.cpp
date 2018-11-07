#include <iostream>
using namespace std;

bool ok(int cross[], int helper[], int box) {
	// Check if a number was previously used
	for (int i = 0; i < box; i++) {
		if (cross[box] == cross[i])
			return false;
	}

	// Check if current box and adj. boxes have a difference greater than 1
	for (int i = 0; helper[i] != -1; i++) {        // Will only check if there are adjacent boxes
		if (abs(cross[box] - cross[helper[i]]) == 1)
			return false;
	}
	return true;
}

void backtrack(int &box) {
	box--;
  if (box == -1)
    exit(1);
}

void print(int cross[]) {
  for (int i = 0; i < 8; i++) {
		cout << cross[i];
	}
  cout << "\n";
}

int main() {
	int cross[8] = { 0 };
	int helper[8][5] = {
	  { -1, -1, -1, -1, -1 },
	  { 0, -1, -1, -1, -1 },
	  { 0, -1, -1, -1, -1 },
	  { 0, 1, 2, -1, -1 },
	  { 0, 1, 3, -1, -1 },
	  { 1, 4, -1, -1, -1 },
	  { 2, 3, 4, -1, -1 },
	  { 3, 4, 5, 6, -1 } };
	int box = 0;

	while (box < 8) {   // Keep going until boxes are filled
		cross[box]++;
		if (cross[box] > 8) {
			cross[box] = 0;
			backtrack(box);
		}
		else if (ok(cross, helper[box], box))
			box++;
    if (box == 8) {
      print(cross);
      backtrack(box);
    }
	}
}
