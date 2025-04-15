#include <iostream>
using namespace std;

void BubbleSort(int *array, int size) {
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {

  int array[6] = {7, 4, 8, 1, 6, 3};
  cout << "Unsorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }

  BubbleSort(array, 6);

  cout << "Sorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }
}
