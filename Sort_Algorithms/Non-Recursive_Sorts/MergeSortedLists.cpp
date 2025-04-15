#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int> &leftArray,
                       const std::vector<int> &rightArray) {
  int leftIndex = 0;
  int rightIndex = 0;
  std::vector<int> array;
  // Merge elements from both arrays into the array passed
  while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
    if (leftArray[leftIndex] <= rightArray[rightIndex]) {
      array.push_back(leftArray[leftIndex]);
      leftIndex++;
    } else {
      array.push_back(rightArray[rightIndex]);
      rightIndex++;
    }
  }

  // Copy any remaining elements from the leftArray to the main array
  while (leftIndex < leftArray.size()) {
    array.push_back(leftArray[leftIndex]);
    leftIndex++;
  }

  // Copy any remaining elements from the rightArray to the main array
  while (rightIndex < rightArray.size()) {
    array.push_back(rightArray[rightIndex]);
    rightIndex++;
  }

  return array;
}

int main() {
  std::vector<int> list1;
  std::vector<int> list2;
  std::vector<int> mergelist;
  list1.push_back(1);
  list1.push_back(3);
  list1.push_back(5);
  list1.push_back(7);

  list2.push_back(2);
  list2.push_back(4);
  list2.push_back(6);
  list2.push_back(8);

  mergelist = Merge(list1, list2);

  for (int i = 0; i < mergelist.size(); i++) {
    std::cout << mergelist[i] << std::endl;
  }
}
