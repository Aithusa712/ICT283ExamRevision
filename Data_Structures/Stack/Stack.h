// Last in, First out. Stack Aka the pringles data structure
// To visualize, just think of eating from a Pringle can.
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T> class Stack {
public:
  Stack();  // You found an empty pringle can from the dumpster and claim it as
            // your own.
  ~Stack(); // Throw away the pringle can.
  void push(const T &value); // Insert a pringle into your can
  T &pop();                  // Grab a pringle from the can and eat it. (Can no
                             // longer be retrieved from your stomach)

private:
  void Resize();        // Using tape and scissors, create a longer pringle can.
                        // (Required for a Dynamic Pringle can)
  bool IsFull() const;  // Look into the can to see if one more pringle can fit,
                        // if it can't, you cry.
  bool IsEmpty() const; // You look into the can, if you dont see anymore
                        // pringles, you cry.
  T *Arr;               // The pringle can itself.
  int Capacity;         // How many pringles can fit in your can.
  int Top;              // The index of the top most pringle.
};

template <typename T> Stack<T>::Stack() {
  Top = -1;
  Capacity = 10; // Set how many pringles you want to store here.
  Arr = new T[Capacity];
}

template <typename T> Stack<T>::~Stack() { delete[] Arr; }

template <typename T> void Stack<T>::push(const T &value) {
  if (IsFull()) {
    cout << "Stack Overflow" << endl;
    throw -1;
    // For a dynamic stack implementation, uncomment below.
    // Resize();
    // Arr[++Top] = value;
  } else {
    Arr[++Top] = value;
  }
}

template <typename T> T &Stack<T>::pop() {
  if (IsEmpty()) {
    cout << "No more pringles, big sad.";
    throw -1;
  } else {
    return Arr[Top--];
  }
}

template <typename T> bool Stack<T>::IsEmpty() const { return Top < 0; }

template <typename T> bool Stack<T>::IsFull() const {
  return Top >= Capacity - 1;
}

// For a dynamic stack implementation, uncomment below.

// template <typename T> void Stack<T>::Resize() {
//   T *temp = new T[Capacity * 2];
//   for (int i = 0; i < Capacity; i++) {
//     temp[i] = Arr[i];
//   }
//   delete[] Arr;
//   Capacity *= 2;
//   Arr = temp;
// }

#endif
