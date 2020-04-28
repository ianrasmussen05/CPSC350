// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// BinarySearchTree.h

#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include "TreeNode.h"

template <typename T>
class BinarySearchTree
{
  private:
    TreeNode<T> *root;

  public:
    BinarySearchTree();
    ~BinarySearchTree();
    // virtual ~BST(); - when working with template class

    void insert(T value); // Insert a node
    bool search(T value); // Searched for a node
    bool deleteNode(T k); // Deletes a node

    bool isEmpty(); // Returns true or false if the tree is empty
    TreeNode<T> *getMin(); // Gets the minimum value
    TreeNode<T> *getMax(); // Gets the maximum value

    TreeNode<T> *getSuccessor(TreeNode<T> *d);
    void inOrder(); // This prints the tree in ascending order
};

#endif

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
  root = NULL;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
  delete root;
}

template <typename T>
void BinarySearchTree<T>::insert(T value)
{
  TreeNode<T> *node = new TreeNode<T>(value);

  if (isEmpty()) // The tree is empty
  {
    root = node;
  }
  else // Tree is not empty, must find location
  {
    TreeNode<T> *curr = root;
    TreeNode<T> *parent = NULL;

    while (true)
    {
      // Finding insertion point
      parent = curr;

      if (value < curr->key) // This goes to the left value
      {
        curr = curr->left;

        if (curr == NULL)
        {
          parent->left = node;
          break;
        }
      }
      else // This goes to the right value
      {
        curr = curr->right;

        if (curr == NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <typename T>
bool BinarySearchTree<T>::search(T value)
{
  if (isEmpty()) // If the tree is empty
  {
    return false;
  }
  else // The tree is not empty
  {
    TreeNode<T> *curr = root;

    while (curr->key != value)
    {
      if (value < curr->key)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }

      if (curr == NULL)
      {
        return false;
      }
    }

    return true;
  }
}

template <typename T>
bool BinarySearchTree<T>::deleteNode(T k)
{
  if (isEmpty()) // If the tree is empty
  {
    return false;
  }
  else if (!search(k)) // Checks to see if the value is in the tree
  {
    return false;
  }
  else // The value is in the tree and the tree isn't empty
  {
    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    // Must search to find the tree node first
    while (curr->key != k)
    {
      parent = curr;

      if (k < curr->key) // Goes to the left child
      {
        isLeft = true;
        curr = curr->left;
      }
      else // Goes to the right child
      {
        isLeft = false;
        curr = curr->right;
      }

      if (curr == NULL) // THe node doesn't exist
      {
        return false;
      }
    }

    // We have found the node, now lets delete the node

    // No children, leaf TreeNode
    if (curr->left == NULL && curr->right == NULL)
    {
      if (curr == root) // Nulls the root value and tree is empty
      {
        root = NULL;
      }
      else if (isLeft) // Checks if the current node is the left value
      {
        parent->left = NULL; // The left child of the parent is nulled out
      }
      else // Checks if current node is the right value
      {
        parent->right = NULL; // The right child of the parent is nulled out
      }
    }
    else if (curr->right == NULL) // There is one child, and the child is left
    {
      if (curr == root) // Checks if the searched value is the root
      {
        root = curr->left; // Changes the root to the left child
      }
      else if (isLeft) // If the searched value is left
      {
        parent->left = curr->left;
      }
      else // If the searched value is right
      {
        parent->right = curr->right;
      }
    }
    else if (curr->left == NULL) // There is one child, and the child is right
    {
      if (curr == root) // If the current value is the root
      {
        root = curr->right; // Replace root as right child
      }
      else if (isLeft) // If the current value is the left child
      {
        parent->left = curr->right;
      }
      else // If the current value is the right child
      {
        parent->right = curr->right;
      }
    }
    else // The searched value has both children
    {
      // Must find the successor
      TreeNode<T> *successor = getSuccessor(curr);

      if (curr == root) // If the searched value is the root
      {
        root = successor; // Make root the successor
      }
      else if (isLeft) // If the value searched is left
      {
        parent->left = successor; // Make the left child of parent the successor
      }
      else // If the value searched is right
      {
        parent->right = successor; // Make the right child of parent the successor
      }

      successor->left = curr->left; // The left child of the successor is the
                                    // left child of the searched value

      return true; // The operation is successful
    }
  }
}

// The successor is finding the minimum value on the right side of the
// node inputed to replace
template <typename T>
TreeNode<T>* BinarySearchTree<T>::getSuccessor(TreeNode<T> *d)
{
  // d is the node to be deleted

  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *curr = d->right;

  while (curr != NULL)
  {
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if (successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;

    return successor; // Return the minimum value from right of curr
  }
}

// Returns true or false if the tree is empty
template <typename T>
bool BinarySearchTree<T>::isEmpty()
{
  return (root == NULL);
}

// Returns the node that is the minimum value of the tree
template <typename T>
TreeNode<T> *BinarySearchTree<T>::getMin()
{
  TreeNode<T> *curr = root;

  if (root == NULL) // Checks if the root is Null and returns it
  {
    return NULL;
  }

  while (curr->left != NULL) // Keeps iterating to the left value
  {
    curr = curr->left;
  }

  return curr;
}

// Returns the node that is the maximum value of the tree
template <typename T>
TreeNode<T> *BinarySearchTree<T>::getMax()
{
  TreeNode<T> *curr = root;

  if (root == NULL) // Checks if the root is Null and returns it
  {
    return NULL;
  }

  while (curr->right != NULL) // Keeps iterating to the right value of tree
  {
    curr = curr->right;
  }

  return curr;
}

// In this case, I will be printing in the inorder transversal format because
// it prints the nodes from ascending order (min to max)
template <typename T>
void BinarySearchTree<T>::inOrder()
{
  TreeNode<T> *curr = root;

  if (curr != NULL)
  {
    inOrder(curr->left);
    cout << curr->key << endl;
    inOrder(curr->right);
  }
}
