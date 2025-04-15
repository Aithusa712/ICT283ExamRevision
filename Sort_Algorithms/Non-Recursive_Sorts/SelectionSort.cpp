#include <iostream>

using namespace std;

void SelectionSort(int *array, int size) {

  for (int j = 0; j < size; j++) {
    int iMin = j;
    for (int i = j + 1; i < size; i++) {
      if (array[i] < array[iMin])
        iMin = i;
    }
    if (iMin != j) {
      int temp = array[iMin];
      array[iMin] = array[j];
      array[j] = temp;
    }
  }
}

int main() {

  int array[6] = {7, 4, 1, 2, 5, 8};

  cout << "unsorted:" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }
  SelectionSort(array, 6);

  cout << "\nsorted:" << endl;
  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }
}
