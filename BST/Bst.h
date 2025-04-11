#ifndef BST_H
#define BST_H
#include <iostream>
template <typename T> struct Node {
  T info;
  Node *left;
  Node *right;

  Node(const T &newInfo) {
    info = newInfo;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T> class Bst {
  typedef void (*ProcessNode)(T &); // Function Pointer
public:
  // Minimal but complete section
  Bst();                                  // Constructor
  Bst(const Bst<T> &otherBst);            // Copy Constructor
  Bst &operator=(const Bst<T> &otherBst); // Copy Assignment Operator
  ~Bst();                                 // Destructor
  void Delete();                          // Delete Tree
  void Insert(const T &newData);          // Insert data into tree
  T &Get(const T &target) const;          // Retrieve/Read data from tree
  // Traversal Orders
  void inOrder(ProcessNode processNode)
      const; // process a void function node in inOrder traversal
  void preOrder(ProcessNode processNode)
      const; // process a void function node in preOrder traversal
  void postOrder(ProcessNode processNode)
      const; // process a void function node in postOrder traversal

protected:
  // Recursive Functions
  Node<T> *copyTree(const Node<T> *other);
  void Insert(Node<T> *newNode, Node<T> *root);
  void Delete(Node<T> *&root);
  Node<T> *Get(Node<T> *node, const T &target) const;
  void inOrder(Node<T> *root, ProcessNode processNode) const;
  void preOrder(Node<T> *root, ProcessNode processNode) const;
  void postOrder(Node<T> *root, ProcessNode processNode) const;
  // holds the root node of the tree
  Node<T> *root;
};

// Constructor

template <typename T> Bst<T>::Bst() { root = nullptr; }

// Copy Constructor

template <typename T> Bst<T>::Bst(const Bst<T> &otherBst) {
  root = copyTree(otherBst.root);
}

// Copy Assignment Operator

template <typename T> Bst<T> &Bst<T>::operator=(const Bst<T> &otherBst) {
  root = copyTree(otherBst.root);
}

// Copy Tree Recursive Function

template <typename T> Node<T> *Bst<T>::copyTree(const Node<T> *other) {
  if (other == nullptr) {
    return nullptr;
  }
  Node<T> *newNode = new Node(other->info);
  newNode->left = copyTree(other->left);
  newNode->right = copyTree(other->right);
  return newNode;
}

// Destructor

template <typename T> Bst<T>::~Bst() { Delete(root); }

// Delete Tree

template <typename T> void Bst<T>::Delete() { Delete(root); }

// Delete Recursive Function

template <typename T> void Bst<T>::Delete(Node<T> *&root) {
  if (root == nullptr) {
    return;
  }

  Delete(root->left);
  Delete(root->right);

  delete root;
  root = nullptr;
};

// Insert

template <typename T> void Bst<T>::Insert(const T &newData) {
  Node<T> *newNode = new Node<T>(newData);
  if (root == nullptr) {
    root = newNode;
  } else {
    Insert(newNode, root);
  }
}

// Insert Recursive Function

template <typename T> void Bst<T>::Insert(Node<T> *newNode, Node<T> *root) {
  if (newNode->info < root->info) {
    if (root->left == nullptr) {
      root->left = newNode;
    } else {
      Insert(newNode, root->left);
    }
  } else {
    if (root->right == nullptr) {
      root->right = newNode;
    } else {
      Insert(newNode, root->right);
    }
  }
}

// Get Function

template <typename T> T &Bst<T>::Get(const T &target) const {
  Node<T> *node = Get(root, target);
  if (node == nullptr) {
    throw node;
  }
  return node->info;
}

// Get Recursive Function

template <typename T>
Node<T> *Bst<T>::Get(Node<T> *node, const T &target) const {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->info == target) {
    return node;
  }
  if (target < node->info) {
    return Get(node->left, target);
  } else {
    return Get(node->right, target);
  }
}

// InOrder Traversal Function

template <typename T> void Bst<T>::inOrder(ProcessNode processNode) const {
  if (root == nullptr) {
    return;
  } else {
    inOrder(root, processNode);
  }
}

// InOrder Traversal Recursive Function

template <typename T>
void Bst<T>::inOrder(Node<T> *root, ProcessNode processNode) const {
  if (root == nullptr) {
    return;
  }
  inOrder(root->left, processNode);
  processNode(root->info);
  inOrder(root->right, processNode);
}

// preOrder Traversal Function

template <typename T> void Bst<T>::preOrder(ProcessNode processNode) const {
  if (root == nullptr) {
    return;
  } else {
    preOrder(root, processNode);
  }
}

// preOrder Traversal Recursive Function

template <typename T>
void Bst<T>::preOrder(Node<T> *root, ProcessNode processNode) const {
  if (root == nullptr) {
    return;
  }
  processNode(root->info);
  preOrder(root->left, processNode);
  preOrder(root->right, processNode);
}

// postOrder Traversal Function

template <typename T> void Bst<T>::postOrder(ProcessNode processNode) const {
  if (root == nullptr) {
    return;
  } else {
    postOrder(root, processNode);
  }
}

// postOrder Traversal Recursive Function

template <typename T>
void Bst<T>::postOrder(Node<T> *root, ProcessNode processNode) const {
  if (root == nullptr) {
    return;
  }
  postOrder(root->left, processNode);
  postOrder(root->right, processNode);
  processNode(root->info);
}
#endif // BST_H
