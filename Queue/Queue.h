// First in, First out. Queue structure
// To visualize, pretend you're working in starbucks, handling customer orders.
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class T> class Queue {
public:
  Queue();                      // Start your shift
  ~Queue();                     // Ran out of coffee/Closing Shop
  void Enqueue(const T &value); // Take a customer's order.
  T &Dequeue();                 // Hello, here's your latte. bye bye.

private:
  bool IsEmpty() const; // Check for any customers
  bool IsFull() const;  // Check if you get paid enough to deal with this shit.
  int Capacity;         // The capacity of how much shit you can deal with.
  int front;            // Index of the person at the front of the queue
  int rear;             // Index of the person at the rear of the queue
  T *Arr;               // People who are queueing
};

template <typename T> Queue<T>::Queue() {
  T *Arr = new T[1];
  front = -1;
  rear = -1;
  Capacity = 10; // Set anything you want here.
}

template <typename T> Queue<T>::~Queue() {
  delete[] Arr;
  front = -1;
  rear = -1;
}

template <typename T> void Queue<T>::Enqueue(const T &value) {
  if (IsFull()) {
    cout << "I'm not getting paid enough for this";

  } else {
    if (front ==
        -1) { // if front == -1 true, it means it's the start of the queue so we
              // remove the sentinal value and assign the front as index 0
      front = 0;
    }
    Arr[++rear] = value;
  }
}

template <typename T> T &Queue<T>::Dequeue() {
  T temp = Arr[front];
  if (IsEmpty()) {
    cout << "No more customers, hooray!";
    return;
  } else {
    if (front >= rear) { // if front >= rear is true, itmeans there is only one
                         // guy left in the queue, so we reset the queue by
                         // reassigning the front and rear its sentinal case,
                         // which is (-1).
      front = -1;
      rear = -1;
    } else {
      front++;
    }
    return temp;
  }
}

template <typename T> bool Queue<T>::IsFull() const {
  return rear == Capacity - 1;
}

template <typename T> bool Queue<T>::IsEmpty() const {
  return front == Capacity - 1;
}
#endif
