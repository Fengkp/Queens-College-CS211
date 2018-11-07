#include <iostream>
using namespace std;

int main() {
	int perfectSq;

	for (int i = 1; i > 0; i++) {
		perfectSq = i * i;
		int firstDigit = perfectSq % 10;
		int secondDigit = (perfectSq % 100) / 10;

		if (firstDigit % 2 != 0 && secondDigit % 2 != 0) {
			cout << perfectSq;
			break;
		}
	}
	return 0;
}
