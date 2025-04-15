#include <iostream>
using namespace std;
bool LinearSearch(int *array, int size, int target) {

  for (int i = 0; i < size; i++) {
    if (target == array[i]) {
      return true;
    }
  }
  return false;
}

int main() {
  int array[6] = {5, 10, 31, 4, 7, 8};
  if (LinearSearch(array, 6, 31))
    cout << "31 in Array: True" << endl;
  else
    cout << "31 in Array: False" << endl;

  if (LinearSearch(array, 6, 32))
    cout << "32 in Array: True" << endl;
  else
    cout << "32 in Array: False" << endl;
}
