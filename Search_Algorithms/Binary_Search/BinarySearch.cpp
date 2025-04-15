#include <iostream>

using namespace std;

bool BinarySearch(int *array, int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = (right + left) / 2;

    if (array[mid] == target) {
      return true;
    } else if (array[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

int main() {
  int array[6] = {5, 10, 31, 4, 7, 8};
  if (BinarySearch(array, 6, 31))
    cout << "31 in Array: True" << endl;
  else
    cout << "31 in Array: False" << endl;

  if (BinarySearch(array, 6, 32))
    cout << "32 in Array: True" << endl;
  else
    cout << "32 in Array: False" << endl;
}
