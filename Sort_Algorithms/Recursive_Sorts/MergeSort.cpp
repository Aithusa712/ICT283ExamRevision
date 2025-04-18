#include <iostream>
using namespace std;

void Merge(int *array, int *leftArray, int leftSize, int *rightArray,
           int rightSize) {
  int leftIndex = 0;
  int rightIndex = 0;
  int currentIndex = 0;

  // Merge elements from both arrays into the array passed
  while (leftIndex < leftSize && rightIndex < rightSize) {
    if (leftArray[leftIndex] <= rightArray[rightIndex]) {
      array[currentIndex] = leftArray[leftIndex];
      leftIndex++;

    } else {
      array[currentIndex] = rightArray[rightIndex];
      rightIndex++;
    }
    currentIndex++;
  }

  // Copy any remaining elements from the leftArray to the main array
  while (leftIndex < leftSize) {
    array[currentIndex] = leftArray[leftIndex];
    currentIndex++;
    leftIndex++;
  }

  // Copy any remaining elements from the rightArray to the main array
  while (rightIndex < rightSize) {
    array[currentIndex] = rightArray[rightIndex];
    currentIndex++;
    rightIndex++;
  }
}

void MergeSort(int *array, int size) {
  if (size <= 1)
    return; // Base case: array of length 1 or 0 is already sorted

  int mid = size / 2;

  // Create temporary arrays to hold left and right parts
  int *leftArray = new int[mid];
  int *rightArray = new int[size - mid];

  // Copy data to temporary arrays
  for (int i = 0; i < mid; i++) {
    leftArray[i] = array[i];
  }
  for (int i = mid; i < size; i++) {
    rightArray[i - mid] = array[i];
  }

  // Recursively split and sort the two halves
  MergeSort(leftArray, mid);
  MergeSort(rightArray, size - mid);

  // Merge the sorted halves back into the original array
  Merge(array, leftArray, mid, rightArray, size - mid);

  delete[] leftArray;
  delete[] rightArray;
}
int main() {

  int array[6] = {7, 4, 8, 1, 6, 3};
  cout << "Unsorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }

  MergeSort(array, 6);

  cout << "Sorted" << endl;

  for (int i = 0; i < 6; i++) {
    cout << array[i] << endl;
  }
}
