// Minimal But complete Vector implementation

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <class T> class Vector {
public:
  Vector();                             // Default Constructor (Capacity = 1)
  Vector(const Vector<T> &otherVector); // Copy Constructor
  ~Vector();                            // Destructor
  void push_back(const T &value);       // Insert value into Vector
  T &operator[](const int index); // Subscript operator to read/retrieve value
                                  // from the Vector
  Vector &operator=(const Vector<T> &otherVector); // Copy Assignment Operator
  void remove(const int index);                    // Delete value from Vector

private:
  void Resize();    // Double the Capacity of the Vector
  int Capacity;     // Capacity of the Vector
  int Current_Size; // Current Size of the Vector
  T *Arr;           // Pointer
};

template <typename T> Vector<T>::Vector() {
  Arr = new T[1];
  Capacity = 1;
  Current_Size = 0;
}

template <typename T> Vector<T>::Vector(const Vector<T> &otherVector) {
  Capacity = otherVector.Capacity;
  Current_Size = otherVector.Current_Size;
  for (int i = 0; i < Current_Size; i++) {
    Arr[i] = otherVector.Arr[i];
  }
}

template <typename T> Vector<T>::~Vector() { delete[] Arr; }

template <typename T> void Vector<T>::push_back(const T &value) {
  if (Current_Size == Capacity) {
    Resize();
  }
  Arr[Current_Size] = value;
  Current_Size++;
}

template <typename T> T &Vector<T>::operator[](const int index) {
  return Arr[index];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &otherVector) {
  Capacity = otherVector.Capacity;
  Current_Size = otherVector.Current_Size;
  for (int i = 0; i < Current_Size; i++) {
    Arr[i] = otherVector.Arr[i];
  }
}

template <typename T> void Vector<T>::Resize() {
  T *temp = new T[Capacity * 2];
  for (int i = 0; i < Capacity; i++) {
    temp[i] = Arr[i];
  }
  delete[] Arr;
  Capacity *= 2;
  Arr = temp;
}

template <typename T> void Vector<T>::remove(const int index) {
  if (index < 0 || index >= Current_Size) {
    cout << "Out of bounds";
    return;
  }
  for (int i = index; i < Current_Size - 1; ++i) {
    Arr[i] = Arr[i + 1];
  }
  --Current_Size;
}
#endif
