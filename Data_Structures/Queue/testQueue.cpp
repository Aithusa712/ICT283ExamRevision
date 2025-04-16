#include "Queue.h"

using namespace std;

int main() {
  Queue<int> myQueue;
  myQueue.Enqueue(10);
  myQueue.Enqueue(6);
  myQueue.Enqueue(16);

  for (int i = 0; i < 3; i++) {
    cout << "number: " << myQueue.Dequeue() << endl;
  }

  myQueue.Enqueue(634);
  myQueue.Enqueue(24);
  myQueue.Enqueue(75);

  for (int i = 0; i < 3; i++) {
    cout << "number: " << myQueue.Dequeue() << endl;
  }

  return 0;
}
