

#include <iostream>
using namespace std;

bool isEquivalent(int a[], int b[], int n) {		// Iterates through arrays to check for equivalence. Duplicate code otherwise.
  for (int index = 0; index < n; index++)
    if (a[index] != b[index])
      return false;
  return true;
}

bool equivalent(int a[], int b[], int n) {
  for (int shiftCount = 1; shiftCount <= n; shiftCount++) {
    int lastN = a[n - 1];

    for (int index = n - 1; index >= 0; index--)
      a[index + 1] = a[index];
    a[0] = lastN;

    if (isEquivalent(a, b, n)) {
      cout << "Array matched in " << shiftCount + 1 << " shifts to the right.";			// shiftCount doesn't count for current shift, so we have to add it on.
      return true;
    }
  }
  return false;
}

int main() {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {3, 4, 5, 1, 2};
  int size = sizeof(a) / 4;

  if (isEquivalent(b, a, size)) {
    cout << "Arrays already match.";
    return 0;
  }

  if (equivalent(b, a, size))
    return 0;

  cout << "Arrays are incompatible.";
  return 0;
}
