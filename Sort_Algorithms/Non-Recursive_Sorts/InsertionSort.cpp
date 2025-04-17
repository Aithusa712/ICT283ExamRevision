#include <iostream>
using namespace std;

void InsertionSort(int *array, int size) {
  for (int i = 0; i < size; i++) {
    int j = i;
    while (j > 0 && array[j-1] > array[j]) {
      // Swap
      int temp = array[j];
      array[j] = array[j - 1];
      array[j - 1] = temp;
      j--;
    }
  }
}

int main() {

  int array[6] = {7, 4, 8, 1, 6, 3};
  cout << "Unsorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }

  InsertionSort(array, 6);

  cout << "Sorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }
}
