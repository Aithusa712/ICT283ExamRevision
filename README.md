# Additional links 
## Algorithm Repo by [TheAlgorithm](https://github.com/TheAlgorithms)

### [Data Structure Algorithms](https://github.com/TheAlgorithms/C-Plus-Plus/tree/master/data_structures)

### [Sort Algorithms](https://github.com/TheAlgorithms/C-Plus-Plus/tree/master/sorting)

### [Search Algorithms](https://github.com/TheAlgorithms/C-Plus-Plus/tree/master/search)



# Programming Concepts Revision (2025)

## UML Diagram Relationships

### Inheritance / Specialization
```
Inherited Class ----|>  Base Class
```

### Composition
```
Base Class -----<//> Composited Class
```

### Aggregation
```
Base Class ------< > Aggregated Class
```

### Additional UML Notes
- For template classes, add a dotted [T] in the upper right corner
- Attributes are almost always private
- Methods can be public or private

## Object-Oriented Design Principles

### Encapsulation
- Don't expose internal structures for modification
- Example: Nodes in a BST should not be returned directly
- When passing elements by reference, mark them as `const`

#### Protecting Class Members
```cpp
// Protecting Retrievals 
const Type& getAttribute();

// Protecting Mutations
void setAttribute(const Type& obj);
```

### Avoiding Friend Functions
Any code written using friends can be written without them by using public methods:

```cpp
// Using friend function
void friendFunction(Test& obj)
{
    obj.a = 1;
    obj.b = 2;
}

// Better approach with public methods
void unfriendFunction(Test& obj)
{
    obj.setA(1);
    obj.setB(2);
}
```

### Single Responsibility / Low Coupling
- Functions should not be aware of any more than they need to
  - E.g., Vector should not be aware of File I/O
  - E.g., Calculations should not be "locked" to a problem's data type

### No Inlining
- Avoid inline functions for better code organization

### Minimal and Complete Class Design

#### Completeness
- A class should have everything it needs to function in the general case
- Use the acronym CRUD - Create, Read, Update, Delete
- If random index access is possible, ensure operations work on any index
- Class must manage its own memory:
  * Constructor
  * Destructor
  * Copy Constructor
- The class must support all reasonable operators:
  * Comparison and Equality (makes insertion into other data structures possible)
  * Assignment (usually equivalent to copy constructor)
  * Subscript `[]` access operators (for data structures with random access)

#### Minimality
- Goes back to single responsibility - is your class doing more than it needs to?
- Maximize reusability by keeping classes focused

### When Not to Use Classes
- Utility functions can be standalone in .h/.cpp files
- Data-only structures can be simple structs:

```cpp
// Don't use a class like this:
class Point
{
private:
    int x;
    int y;

public:
    int getX();
    // etc.
};

// Instead, use a struct:
struct Point
{
    int x;
    int y;
};
```

### Class Encapsulation
Reuse existing classes by "hiding" their interface and providing your own:
- Useful to change function names, hide methods, implement custom error handling

## C++ Conventions

- Braces on the next line after the declaration, vertically aligned
- Classes and function names have first letter capitalized
- Attributes start with "m_" for member

```cpp
class Track
{
public:
    void GetName();
    void SetName(string name);
private:
    string m_title;
};
```

## Data Structures Performance and Implementation

### Array-Based Structures
- **Time Complexities**:
  - Random access: O(1)
  - Search: O(n)
  - Shifting elements after insertion/deletion: O(n)
- **Memory Operations**:
  - Allocation: Entire array at once
  - Deallocation: Entire array at once

### Linked List-Based Structures
- **Time Complexities**:
  - Traverse to index: O(n)
  - Search: O(n)
  - No shifting needed
- **Memory Operations**:
  - Allocation: Iteratively create nodes O(n)
  - Deallocation: Recursively delete nodes O(n)

### Tree-Based Structures
- **Time Complexities**:
  - No direct indexing
  - BST search: O(log n) average case
  - Finding predecessor/successor: O(log n) average case
- **Memory Operations**:
  - Allocation: Insert each node O(n log n) average case
  - Deallocation: Post-order traversal and delete O(n)

### Hash-Based Structures
- **Time Complexities**:
  - Compute hash: O(1)
  - Resolving collision: O(n) worst case
  - No shifting needed
- **Memory Operations**:
  - Allocation: Hash and probe O(n²) worst case
  - Deallocation: Free the underlying array

## Common Data Structures

### Vectors
- Flexible array that automatically grows when required
- Operations: Create, Read, Update, Delete

### Sets
- Follows the mathematical definition of a set
- Operations: Union, Intersection, Difference, Subset, Find

### Maps
- Associates a key to a value: `Map<KeyType, ValueType>`
- Typically implemented with HashTable or BST
- Operations: Create (Add), Read (Retrieve), Update, Delete

### Stacks
- Last in, First out (LIFO) structure
- Property: Reverses the input
- Operations: Push (Create), Pop (Read/Delete)
- Error conditions: Overflow (push when full), Underflow (pop when empty)

### Queues
- First in, First out (FIFO) structure
- Operations: Enqueue (Create), Dequeue (Read/Delete)
- Error conditions: Overflow (enqueue when full), Underflow (dequeue when empty)

## Recursion
- Functions that call themselves
- Must have:
  - Base case (termination condition)
  - Recursive case

## Trees

- Hierarchical series of nodes
- Each node has a parent and children
- Topmost node with no parent is the root

### Binary Search Tree (BST)
- Binary: Each node can have up to 2 children
- Search: Follows BST property (smaller elements left, larger elements right)
- Operations:
  - Create: Insert node
  - Read: Find specific value or traverse
  - Delete: Replace with predecessor/successor

### BST Traversal Orders
- **Preorder**: Good for allocating memory
- **Inorder**: Generates sorted list
- **Postorder**: Good for destructors

Note: If trees are not balanced, operations may degrade to O(n)
- AVL Trees are one way to maintain balance

## Algorithms

### Searching
- **Linear Search**
  - Visit every element in the list
  - Worst case: O(n) when target not found or at the end
- **Binary Search**
  - Precondition: Sorted list
  - Start in the middle and divide search space in half each time
  - Time complexity: O(log n)

### Merge Algorithm
- Combine two sorted lists into one sorted output in O(n) time
- Traverse each list from left to right

### Sorting

#### O(n²) Algorithms
- **Selection Sort**: Extract minimum item and move to front
- **Insertion Sort**: Create sorted sublist on left, insert each new item
- **Bubble Sort**: Swap adjacent items pairwise from left to right

#### O(n log n) Algorithms
- **Quicksort**: Recursively partition a list
- **Mergesort**: Recursively break down list, then merge using merge algorithm

### Hashing
- Used for mappings (key → value)
- Key is processed by hash function to produce an index
- Collision handling:
  - Probing
  - Separate chaining

## Graphs
- Consist of vertices connected by edges
- Edges can be directed or undirected
- Representations:
  - Adjacency Matrices
  - Adjacency Lists

### Graph Algorithms
- **Traversal**:
  - Breadth First Search (BFS)
  - Depth First Search (DFS)
- **Applications**:
  - Minimum Spanning Tree
  - Shortest Paths
  - Topological Sort

&nbsp;&nbsp;&nbsp;

# Programming Concepts Revision (FROM PREVIOUS BATCH 2024)


## 1. UML Relationships

### UML Diagram Types
- **High-Level Model**: Only shows names of classes and their relationships
- **Low-Level Model**: Shows all details including attributes and methods of classes

### Relationship Types
- **Dependency** (`---->`)
  - A class requires another class but doesn't own or contain it
  - Example: A method using another class as a parameter

- **Composition** (`------<▪>` solid diamond)
  - "Has-a" relationship where component cannot exist without parent
  - When parent is destroyed, component is also destroyed
  - Example: A House has Rooms; if House is destroyed, Rooms cease to exist

- **Aggregation** (`------<◇>` hollow diamond)
  - "Has-a" relationship where component can exist independently
  - Example: A University has Students; if University closes, Students still exist

- **Specialization/Inheritance** (`------|>` straight line, hollow triangle)
  - "Is-a" relationship where child inherits characteristics of parent
  - Example: A Dog is an Animal

- **Realization** (`- - - -|>` dotted line, hollow triangle)
  - Implementation of an interface or abstract class
  - Example: A class implementing an interface like `Comparable`

## 2. Model-View-Controller (MVC) Pattern

- **Model**
  - Represents the data structure and business logic
  - Responsible for data storage, retrieval, and state changes
  - Independent of the user interface

- **View**
  - Presents information to users
  - Responsible for UI elements and visualization
  - Renders data from the Model to the user

- **Controller**
  - Mediates between Model and View
  - Processes user input and updates Model/View accordingly
  - Contains application logic and workflow

### Relationships
```
View <--> Controller <--> Model
```

## 3. Vector Implementation and Big O Analysis

### Vector Operations
- `insert()`: O(n) - May require shifting elements or resizing
- `search()`: O(n) - Worst case requires checking all elements
- `delete()`: O(n) - May require shifting elements after deletion
- `access()`: O(1) - Direct index-based access

### Vector Resize Implementation
```cpp
template <typename T>
void Vector<T>::resize() {
    // Create new array with double capacity
    T* newElements = new T[m_capacity * 2];
    
    // Copy existing elements
    for (int i = 0; i < m_size; i++) {
        newElements[i] = m_elements[i];
    }
    
    // Delete old array and update pointer
    delete[] m_elements;
    m_elements = newElements;
    
    // Update capacity
    m_capacity *= 2;
}
```

## 4. Binary Search Tree (BST) and Big O

### BST Properties
- Each node has at most two children
- Left subtree contains values less than the node
- Right subtree contains values greater than or equal to the node

### BST Search Operation
```cpp
template <typename T>
Node<T>* BST<T>::search(Node<T>* root, const T& value) {
    // Base case: root is null or value found
    if (root == nullptr || root->data == value) {
        return root;
    }
    
    // Recursive case: search in appropriate subtree
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}
```

### BST Big O Analysis
- `search()`: O(log n) average case (balanced tree), O(n) worst case (unbalanced tree)
- `insert()`: O(log n) average case, O(n) worst case
- `delete()`: O(log n) average case, O(n) worst case

## 5. Queue and Stack Implementations

### Queue (FIFO - First In, First Out)

#### Using Array Implementation
```cpp
class Queue {
private:
    int m_front;
    int m_rear;
    int m_capacity;
    int* m_elements;
    
public:
    Queue(int capacity) {
        m_capacity = capacity;
        m_elements = new int[capacity];
        m_front = m_rear = -1;
    }
    
    void enqueue(int value) {
        if ((m_rear + 1) % m_capacity == m_front) {
            // Queue is full
            return;
        }
        
        if (m_front == -1) {
            m_front = m_rear = 0;
        } else {
            m_rear = (m_rear + 1) % m_capacity;
        }
        
        m_elements[m_rear] = value;
    }
    
    int dequeue() {
        if (m_front == -1) {
            // Queue is empty
            return -1;
        }
        
        int value = m_elements[m_front];
        
        if (m_front == m_rear) {
            m_front = m_rear = -1;
        } else {
            m_front = (m_front + 1) % m_capacity;
        }
        
        return value;
    }
};
```

#### Using STL
```cpp
#include <queue>

std::queue<int> q;
q.push(10);  // Enqueue
int value = q.front();  // Peek
q.pop();  // Dequeue
```

### Stack (LIFO - Last In, First Out)

#### Using Array Implementation
```cpp
class Stack {
private:
    int m_top;
    int m_capacity;
    int* m_elements;
    
public:
    Stack(int capacity) {
        m_capacity = capacity;
        m_elements = new int[capacity];
        m_top = -1;
    }
    
    void push(int value) {
        if (m_top >= m_capacity - 1) {
            // Stack overflow
            return;
        }
        
        m_elements[++m_top] = value;
    }
    
    int pop() {
        if (m_top < 0) {
            // Stack underflow
            return -1;
        }
        
        return m_elements[m_top--];
    }
    
    int peek() {
        if (m_top < 0) {
            // Stack is empty
            return -1;
        }
        
        return m_elements[m_top];
    }
};
```

#### Using STL
```cpp
#include <stack>

std::stack<int> s;
s.push(10);
int value = s.top();  // Peek
s.pop();
```

## 6. Test Plans

Test plans should be organized in a table format:

| Test No. | Test Case Name | Description | Actual Data | Expected Output | Passed/Failed |
|----------|---------------|-------------|-------------|-----------------|---------------|
| 1 | Valid Insert | Test insert with valid data | insert(5) | Element 5 added | Passed |
| 2 | Overflow Test | Test insert on full stack | push() on full stack | Error message | Passed |
| 3 | Empty Check | Test isEmpty on empty queue | isEmpty() | true | Passed |

### Key Components:
- **Test No.**: Unique identifier
- **Test Case Name**: Brief title of the test
- **Description**: What aspect is being tested
- **Actual Data**: Input data/method calls
- **Expected Output**: Expected result
- **Passed/Failed**: Result of test execution

## 7. Unit Tests

Unit tests verify if individual methods or components work as expected.

```cpp
void testVectorInsert() {
    // Setup
    Vector<int> v;
    
    // Test
    v.push_back(5);
    
    // Verify
    if (v.size() == 1 && v[0] == 5) {
        std::cout << "Vector Insert Test: Passed" << std::endl;
    } else {
        std::cout << "Vector Insert Test: Failed" << std::endl;
        std::cout << "Expected size: 1, Actual size: " << v.size() << std::endl;
        std::cout << "Expected element: 5, Actual element: " << v[0] << std::endl;
    }
}

void testBSTSearch() {
    // Setup
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    // Test & Verify
    if (tree.search(10) && tree.search(5) && tree.search(15) && !tree.search(20)) {
        std::cout << "BST Search Test: Passed" << std::endl;
    } else {
        std::cout << "BST Search Test: Failed" << std::endl;
    }
}
```

### Modern Unit Testing Frameworks
Many C++ projects use frameworks like Google Test, Catch2, or Boost.Test:

```cpp
// Using Google Test
TEST(VectorTest, InsertWorks) {
    Vector<int> v;
    v.push_back(5);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 5);
}
```

## 8. Merge Algorithm

The merge algorithm combines two sorted arrays into one sorted array.

```cpp
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];
    
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    // Merge temp arrays back into arr
    int i = 0;    // Initial index of left subarray
    int j = 0;    // Initial index of right subarray
    int k = left; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    // Free memory
    delete[] leftArr;
    delete[] rightArr;
}
```

### Time and Space Complexity
- **Time Complexity**: O(n) where n is the total number of elements
- **Space Complexity**: O(n) for the temporary arrays

## 9. Set Operations

### Custom Implementation

```cpp
template <typename T>
class Set {
private:
    std::vector<T> elements;
    
    bool contains(const T& value) const {
        for (const T& elem : elements) {
            if (elem == value) {
                return true;
            }
        }
        return false;
    }

public:
    // Add element
    void insert(const T& value) {
        if (!contains(value)) {
            elements.push_back(value);
        }
    }
    
    // Check if this set is subset of other
    bool isSubset(const Set<T>& other) const {
        for (const T& elem : elements) {
            if (!other.contains(elem)) {
                return false;
            }
        }
        return true;
    }
    
    // Union operation
    Set<T> setUnion(const Set<T>& other) const {
        Set<T> result = *this;
        
        for (const T& elem : other.elements) {
            result.insert(elem);
        }
        
        return result;
    }
    
    // Intersection operation
    Set<T> intersection(const Set<T>& other) const {
        Set<T> result;
        
        for (const T& elem : elements) {
            if (other.contains(elem)) {
                result.insert(elem);
            }
        }
        
        return result;
    }
    
    // Difference operation (this - other)
    Set<T> difference(const Set<T>& other) const {
        Set<T> result;
        
        for (const T& elem : elements) {
            if (!other.contains(elem)) {
                result.insert(elem);
            }
        }
        
        return result;
    }
};
```

### Using STL Set

```cpp
#include <set>
#include <algorithm>
#include <iterator>

// Union
std::set<int> setUnion(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> result;
    std::set_union(
        set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::inserter(result, result.begin())
    );
    return result;
}

// Intersection
std::set<int> intersection(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> result;
    std::set_intersection(
        set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::inserter(result, result.begin())
    );
    return result;
}

// Difference (set1 - set2)
std::set<int> difference(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> result;
    std::set_difference(
        set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::inserter(result, result.begin())
    );
    return result;
}

// Is subset
bool isSubset(const std::set<int>& set1, const std::set<int>& set2) {
    return std::includes(set2.begin(), set2.end(), set1.begin(), set1.end());
}
```

### Common STL Set Methods
- `clear()`: Removes all elements
- `empty()`: Checks if set is empty
- `begin()`: Returns iterator to first element
- `end()`: Returns iterator to position after last element
- `erase()`: Removes specified element
- `find()`: Finds element with specific value
- `insert()`: Inserts element
- `size()`: Returns number of elements
- `swap()`: Swaps contents with another set

## 10. SOLID Principles

### S - Single Responsibility Principle (SRP)
- A class should have only one reason to change
- Each class should focus on doing one thing well
- High cohesion: related functionality grouped together

```cpp
// Bad: Class doing too much
class Employee {
public:
    void calculatePay() { /* ... */ }
    void saveToDatabase() { /* ... */ }
    void generateReport() { /* ... */ }
};

// Good: Separated responsibilities
class Employee {
public:
    void calculatePay() { /* ... */ }
};

class EmployeeRepository {
public:
    void save(const Employee& employee) { /* ... */ }
};

class EmployeeReporter {
public:
    void generateReport(const Employee& employee) { /* ... */ }
};
```

### O - Open/Closed Principle (OCP)
- Software entities should be open for extension but closed for modification
- Add new functionality by extending, not changing existing code

```cpp
// Bad: Need to modify Shape class for each new shape
class Shape {
public:
    enum Type { CIRCLE, SQUARE };
    Type type;
    
    double area() {
        if (type == CIRCLE) { /* Circle area calculation */ }
        else if (type == SQUARE) { /* Square area calculation */ }
        // Need to modify this method for each new shape
    }
};

// Good: Open for extension
class Shape {
public:
    virtual double area() = 0;
};

class Circle : public Shape {
public:
    double radius;
    double area() override { return 3.14159 * radius * radius; }
};

class Square : public Shape {
public:
    double side;
    double area() override { return side * side; }
};
```

### L - Liskov Substitution Principle (LSP)
- Subtypes must be substitutable for their base types without altering program correctness
- Child classes should extend, not restrict, behavior of parent class

```cpp
// Bad: Rectangle can't be substituted for Square
class Rectangle {
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int getArea() { return width * height; }
protected:
    int width;
    int height;
};

class Square : public Rectangle {
public:
    void setWidth(int w) override {
        width = w;
        height = w;  // Violates LSP - changes behavior unexpectedly
    }
    
    void setHeight(int h) override {
        width = h;   // Violates LSP - changes behavior unexpectedly
        height = h;
    }
};

// Good: Shape hierarchy maintains substitutability
class Shape {
public:
    virtual double area() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    double area() override { return width * height; }
protected:
    int width;
    int height;
};

class Square : public Shape {
public:
    Square(int side) : side(side) {}
    double area() override { return side * side; }
protected:
    int side;
};
```

### I - Interface Segregation Principle (ISP)
- No client should be forced to depend on methods it does not use
- Many client-specific interfaces are better than one general-purpose interface

```cpp
// Bad: Monolithic interface
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

class Robot : public Worker {
public:
    void work() override { /* ... */ }
    void eat() override { /* Not applicable */ }  // Forced to implement
    void sleep() override { /* Not applicable */ }  // Forced to implement
};

// Good: Segregated interfaces
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Sleepable {
public:
    virtual void sleep() = 0;
};

class Human : public Workable, public Eatable, public Sleepable {
    void work() override { /* ... */ }
    void eat() override { /* ... */ }
    void sleep() override { /* ... */ }
};

class Robot : public Workable {
    void work() override { /* ... */ }
};
```

### D - Dependency Inversion Principle (DIP)
- High-level modules should not depend on low-level modules
- Both should depend on abstractions
- Abstractions should not depend on details; details should depend on abstractions

```cpp
// Bad: High-level module depends on low-level module
class MySQLDatabase {
public:
    void insert(const std::string& data) { /* ... */ }
};

class UserRepository {
private:
    MySQLDatabase database;  // Direct dependency on concrete class
public:
    void saveUser(const std::string& userData) {
        database.insert(userData);
    }
};

// Good: Dependency on abstraction
class Database {
public:
    virtual void insert(const std::string& data) = 0;
};

class MySQLDatabase : public Database {
public:
    void insert(const std::string& data) override { /* ... */ }
};

class PostgreSQLDatabase : public Database {
public:
    void insert(const std::string& data) override { /* ... */ }
};

class UserRepository {
private:
    Database& database;  // Dependency on abstraction
public:
    UserRepository(Database& db) : database(db) {}
    
    void saveUser(const std::string& userData) {
        database.insert(userData);
    }
};
```

## 11. Recursion vs Iteration

### Recursion
- A function calls itself to solve a problem
- Components:
  - Base case: Termination condition to stop recursion
  - Recursive case: Calls itself with modified parameters

```cpp
// Factorial using recursion
int factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}
```

### Iteration
- Uses loops (for, while, do-while) to repeat operations
- State maintained through variables

```cpp
// Factorial using iteration
int factorial(int n) {
    int result = 1;
    
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;
}
```

### Comparison

| Aspect | Recursion | Iteration |
|--------|-----------|-----------|
| Memory | More (call stack) | Less |
| Speed | Generally slower | Generally faster |
| Code | Often cleaner for complex problems | Can be more verbose |
| Termination | Base case | Loop condition |
| Stack Overflow | Risk with deep recursion | No risk |
| Use Cases | Tree/graph traversals, divide & conquer | Simple repetitive tasks |

## 12. Pointers

### Basic Concepts
- Pointers store memory addresses of other variables
- Declaration: `Type* pointerName;`
- Address-of operator: `&`
- Dereference operator: `*`

```cpp
int value = 10;
int* ptr = &value;  // ptr holds address of value
*ptr = 20;          // Changes value to 20
```

### Dynamic Memory Allocation
```cpp
// Single element
int* ptr = new int;
*ptr = 10;
delete ptr;  // Release memory

// Array
int* arr = new int[5];
arr[0] = 1;
delete[] arr;  // Release array memory
```

### Pointer Arithmetic
```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* ptr = arr;

// Move to next element
ptr++;  // Points to arr[1]

// Access element
int value = *(ptr + 2);  // Gets arr[3] (40)
```

### Common Issues
- **Null Pointers**: `int* ptr = nullptr;`
- **Dangling Pointers**: Pointing to deleted memory
- **Memory Leaks**: Forgetting to `delete` allocated memory
- **Double Free**: Calling `delete` twice on same pointer

### Smart Pointers (Modern C++)
```cpp
#include <memory>

// Unique pointer (exclusive ownership)
std::unique_ptr<int> uptr = std::make_unique<int>(10);

// Shared pointer (shared ownership)
std::shared_ptr<int> sptr1 = std::make_shared<int>(20);
std::shared_ptr<int> sptr2 = sptr1;  // Reference count = 2

// Weak pointer (non-owning reference)
std::weak_ptr<int> wptr = sptr1;
```

## 13. Inheritance

### Basic Inheritance
```cpp
class Animal {
protected:
    std::string name;
    
public:
    Animal(const std::string& n) : name(n) {}
    virtual void makeSound() { std::cout << "Some sound" << std::endl; }
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    void makeSound() override { std::cout << "Woof!" << std::endl; }
};
```

### Access Modifiers in Inheritance

| Access in Base | public inheritance | protected inheritance | private inheritance |
|----------------|--------------------|-----------------------|---------------------|
| public         | public             | protected             | private             |
| protected      | protected          | protected             | private             |
| private        | Not accessible     | Not accessible        | Not accessible      |

### Types of Inheritance
- **Single**: One base class, one derived class
- **Multiple**: One derived class with multiple base classes
- **Multilevel**: Chain of inheritance (A → B → C)
- **Hierarchical**: One base class, multiple derived classes
- **Hybrid**: Combination of multiple inheritance types

### Virtual Functions and Polymorphism
```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function
    virtual ~Shape() {}  // Virtual destructor
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
};

// Polymorphism
void printArea(Shape* shape) {
    std::cout << "Area: " << shape->area() << std::endl;
}

int main() {
    Shape* circle = new Circle(5);
    printArea(circle);  // Calls Circle::area()
    delete circle;
}
```

## 14. Abstract Classes and Interfaces

### Abstract Class
- Contains at least one pure virtual function
- Cannot be instantiated directly
- Derived classes must implement all pure virtual functions

```cpp
class AbstractShape {
public:
    // Pure virtual function
    virtual double area() = 0;
    
    // Regular method
    void printInfo() {
        std::cout << "This is a shape with area " << area() << std::endl;
    }
    
    // Virtual destructor
    virtual ~AbstractShape() {}
};

class Circle : public AbstractShape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
};
```

### Interface (Pure Abstract Class)
- All methods are pure virtual
- No data members (except static constants)
- No constructor implementation

```cpp
class Drawable {
public:
    virtual void draw() = 0;
    virtual void resize(int width, int height) = 0;
    virtual ~Drawable() {}
};

class Rectangle : public Drawable {
private:
    int m_width, m_height;
    
public:
    Rectangle(int w, int h) : m_width(w), m_height(h) {}
    
    void draw() override {
        std::cout << "Drawing rectangle" << std::endl;
    }
    
    void resize(int width, int height) override {
        m_width = width;
        m_height = height;
    }
};
```

## 15. Deep and Shallow Copy

### Shallow Copy
- Copies pointers/references rather than data
- Both objects point to same memory location
- Default copy constructor and assignment operator perform shallow copy
- Can lead to double-deletion problems

```cpp
class ShallowCopy {
private:
    int* data;
    
public:
    ShallowCopy(int value) {
        data = new int(value);
    }
    
    // Default copy constructor does shallow copy
    // ShallowCopy(const ShallowCopy& other) = default;
    
    ~ShallowCopy() {
        delete data;  // Problem: both objects try to delete same memory
    }
};
```

### Deep Copy
- Creates new copies of dynamically allocated data
- Each object has its own independent copy of data
- Must be implemented manually for classes with dynamic memory

```cpp
class DeepCopy {
private:
    int* data;
    
public:
    DeepCopy(int value) {
        data = new int(value);
    }
    
    // Deep copy constructor
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data);  // Create new memory and copy value
    }
    
    // Deep copy assignment operator
    DeepCopy& operator=(const DeepCopy& other) {
        if (this != &other) {  // Check for self-assignment
            delete data;  // Free existing resource
            data = new int(*other.data);  // Create new memory and copy value
        }
        return *this;
    }
    
    ~DeepCopy() {
        delete data;
    }
};
```

### When to Use Each
- **Shallow Copy**: When objects share data intentionally (reference semantics)
- **Deep Copy**: When objects need completely independent data (value semantics)
- Rule of thumb: If your class manages resources (dynamic memory, file handles, etc.), implement deep copy
