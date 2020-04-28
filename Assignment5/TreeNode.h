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
    TreeNode();
    TreeNode(T k);
    // TreeNode(int k, <type> value);
    ~TreeNode();
    // virtual ~TreeNode(); // Research virtual

    T key;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

#endif


template <typename T>
TreeNode<T>::TreeNode()
{
  key = 0;
  left = NULL;
  right = NULL;
}

template <typename T>
TreeNode<T>::TreeNode(T k)
{
  key = k;
  left = NULL;
  right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
  delete right;
  delete left;
}
