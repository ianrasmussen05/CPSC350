// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// TreeNode.h

#ifndef _TREENODE_H
#define _TREENODE_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class TreeNode
{
  private:
    // No private variables

  public:
    TreeNode(); // Construcor
    TreeNode(T k); // Overloaded constructor
    // TreeNode(int k, <type> value);
    ~TreeNode();
    // virtual ~TreeNode(); // Research virtual

    T key;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

#endif

// Default constructor
template <typename T>
TreeNode<T>::TreeNode()
{
  key = 0;
  left = NULL;
  right = NULL;
}

// Overloaded Construcor
template <typename T>
TreeNode<T>::TreeNode(T k)
{
  key = k;
  left = NULL;
  right = NULL;
}

// Destructor
template <typename T>
TreeNode<T>::~TreeNode()
{
  delete right;
  delete left;
}
