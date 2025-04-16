#ifndef SETS_H
#define SETS_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T> class Sets {
public:
  Sets();
  ~Sets();
  void insert(const T &value);
  const T &get(const int &idx);
  int size();
  Sets<T> union_set(const Sets<T> &set_a, const Sets<T> &set_b);
  Sets<T> difference_set(const Sets<T> &set_a, const Sets<T> &set_b);
  bool is_subset(const Sets<T> &other_set);

private:
  void Resize();
  int capacity;
  int current_size;
  T *Array;
};

#endif // SETS_H

template <typename T> Sets<T>::Sets() {
  capacity = 10;
  current_size = 0;
  Array = new T[capacity];
}

template <typename T> Sets<T>::~Sets() { delete[] Array; }

template <typename T> void Sets<T>::insert(const T &value) {
  bool exist = false;
  for (int i = 0; i < current_size; i++) {
    if (value == Array[i]) {
      exist = true;
      break;
    }
  }
  if (!exist) {
    Array[current_size];
    current_size++;
  }
}

template <typename T> const T &Sets<T>::get(const int &idx) {
  return Array[idx];
}

template <typename T> int Sets<T>::size() { return current_size; }

template <typename T>
Sets<T> Sets<T>::union_set(const Sets<T> &set_a, const Sets<T> &set_b) {
  Sets<T> set_c;
  for (int i = 0; i < set_a.size(); i++) {
    set_c.insert(set_a.get(i));
  }

  for (int i = 0; i < set_b.size(); i++) {

    set_c.insert(set_b.get(i));
  }
  return set_c;
}

template <typename T>
Sets<T> Sets<T>::difference_set(const Sets<T> &set_a, const Sets<T> &set_b) {
  Sets<T> set_c; // set_a - set_b
  for (int i = 0; i < set_a.size(); i++) {
    bool exist_inB = false;
    for (int j = 0; j < set_b.size(); j++) {
      if (set_a.get(i) == set_b.get(j))
        exist_inB = true;
    }
    if (!exist_inB)
      set_c.insert(set_a.get(i));
  }
  return set_c;
}

template <typename T> bool Sets<T>::is_subset(const Sets<T> &other_set) {
  for (int i = 0; i < other_set.size(); i++) {
    bool is_inB = false;
    for (int j = 0; j < this.size(); j++) {
      if (this.get(i) == other_set.get(i))
        is_inB = true;
    }
    if (!is_inB)
      return false;
  }
  return true;
}

template <typename T> void Sets<T>::Resize() {
  T *tempArray = new T[capacity * 2];
  for (int i = 0; i < current_size; i++) {
    tempArray[i] = Array[i];
  }

  delete[] Array;
  capacity *= 2;
  Array = tempArray;
}
