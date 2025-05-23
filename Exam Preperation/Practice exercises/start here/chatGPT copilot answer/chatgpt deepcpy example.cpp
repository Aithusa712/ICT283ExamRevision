/* Code answer generated by copilot when asked:

"Using C++ examples, explain the concepts of deep and shallow copy.
Your explanation would need to highlight situations when these concepts
become relevant and what methods should class designers provide to handle
these situations."

*/

//Copilot: 
// "Certainly! Let�s dive into the concepts of deep copy and shallow copy in C++, along with relevant examples and guidance for class designers."

// UC note (smr):
// This type of answer will (and has) result(ed) in a mark of 0 if assessed for lab/assignment/exam because the class code does not separate interface/specification from implementation.

// But ignoring the above, or assuming the separation occurred, what do you think of the answer? What is given below is the exact output given by copilot, including comments. Hint: You need to know the concepts covered in this unit before you can evaluate where "AI" got it wrong in more ways than one. That must not stop you from using AI as a personal tutor, but **you need to check the answer yourself**.

#include <iostream>
using namespace std;

class Box {
private:
    int length;
    int* breadth; // Dynamically allocated memory

public:
    Box() {
        breadth = new int; // Allocate memory for breadth
    }

    void set_dimensions(int len, int brea) {
        length = len;
        *breadth = brea;
    }

    void show_data() {
        cout << "Length = " << length << "\nBreadth = " << *breadth << endl;
    }

    // Copy constructor for deep copy
    Box(const Box& other) {
        length = other.length;
        breadth = new int; // Allocate new memory
        *breadth = *(other.breadth); // Copy value
    }

    // Destructor to release dynamically allocated memory
    ~Box() {
        delete breadth;
    }
};

int main() {
    Box original;
    original.set_dimensions(14, 12);
    original.show_data();

    // Shallow copy (compiler-generated)
    Box shallow_copy = original;
    shallow_copy.show_data();

    // Deep copy (using custom copy constructor)
    Box deep_copy(original);
    deep_copy.set_dimensions(20, 18); // Modify deep_copy
    original.show_data(); // Original remains unchanged
    deep_copy.show_data();

    return 0;
}
