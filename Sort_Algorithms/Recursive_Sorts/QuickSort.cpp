#include <iostream>
using namespace std;

int Partition(int *array, int low, int high) {
  int pivot = array[high]; // Take last element of the array as pivot
  int leftwall = low;      // Index of smaller element

  for (int i = low; i < high; i++) {
    // If current element is smaller or equal to pivot
    if (array[i] <= pivot) {
      // SWAP
      int temp = array[i];
      array[i] = array[leftwall];
      array[leftwall] = temp;

      leftwall++; // Increment index of smaller element
    }
  }
  // SWAP
  int temp = array[leftwall];
  array[leftwall] = array[high];
  array[high] = temp;

  return (leftwall);
}

void QuickSort(int *array, int low, int high) {
  if (low < high) {

    int pivot_location = Partition(array, low, high);

    QuickSort(array, low, pivot_location - 1);
    QuickSort(array, pivot_location + 1, high);
  }
}

int main() {

  int array[6] = {7, 4, 8, 1, 6, 3};
  cout << "Unsorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }

  QuickSort(array, 0, 6);

  cout << "Sorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }
}
