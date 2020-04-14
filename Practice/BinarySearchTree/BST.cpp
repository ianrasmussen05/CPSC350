#include <iostream>
#include <string>

using namespace std;

#include "TreeNode.h"
#include "BST.h"

BST::BST()
{
  root = NULL;
}

BST::~BST()
{

}

/*
virtual BST::~BST()
{

}
*/

void BST::printTree(TreeNode *node)
{
  // in-order
  if (node == NULL)
  {
    return;
  }

  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);
}

TreeNode* BST::getMin()
{
  TreeNode *curr = root;

  if (root == NULL)
  {
    return NULL;
  }

  while (curr->left != NULL)
  {
    curr = curr->left;
  }

  return curr;
  // return curr->key;
}

TreeNode* BST::getMax()
{
  TreeNode *curr = root; // start at root

  if (root == NULL)
  {
    return NULL; // Tree is empty
  }

  while (curr->right != NULL)
  {
    curr = curr->right;
  }

  return curr;
  // return curr->key;
}

bool BST::isEmpty()
{
  return (root == NULL);
}

void BST::insert(int value)
{
  TreeNode *node = new TreeNode(value);

  if (isEmpty())
  {
    // We have an empty tree
    root = node;
  }
  else
  {
    // Tree is not empty, we need to find location
    TreeNode *curr = root;
    TreeNode *parent = NULL; // empty node

    while (true)
    {
      // Let's find the isertion point
      parent = curr;

      if (value < curr->key) // Go left
      {
        curr = curr->left;

        if (curr == NULL)
        {
          parent->left = node;
          break;
        }
      }
      else // go right
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

bool BST::search(int value)
{
  if (isEmpty())
  {
    return false;
  }
  else // Tree is not empty
  {
    TreeNode *curr = root;

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

bool BST::deleteNode(int k)
{
  if (isEmpty())
  {
    return false;
  }
  else if (!search(k))
  {
    return false;
  }
  else // Tree is not empty and value exists
  {
    TreeNode *curr = root;
    TreeNode *parent = root;
    bool isLeft = true;

    // Usual code to find tree node
    // Also update pointers
    while (curr->key != k)
    {
      parent = curr;

      if (k < curr->key)
      {
        isLeft = true;
        curr = curr->left;
      }
      else
      {
        isLeft = false;
        curr = curr->right;
      }

      if (curr == NULL)
      {
        return false;
      }
    }

    // If we made it here, then we have found the node
    // Now let's proceed to deleteNode

    // No children, leaf TreeNode
    if (curr->left == NULL && curr->right == NULL)
    {
      if (curr == root)
      {
        root = NULL;
      }
      else if (isLeft)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
    }
    // One child and the child is left
    else if (curr->right == NULL) // No right child
    {
      if (curr == root)
      {
        root = curr->left;
      }
      else if (isLeft)
      {
        parent->left = curr->left;
      }
      else
      {
        parent->right = curr->left;
      }
    }
    // One child and the child is right
    else if (curr->left == NULL) // No left child
    {
      if (curr == root)
      {
        root = curr->right;
      }
      else if (isLeft)
      {
        parent->left = curr->right;
      }
      else
      {
        parent->right = curr->right;
      }
    }
    // The node has two children
    else
    {
      TreeNode *successor = getSuccessor(curr);

      if (curr == root)
      {
        root = successor;
      }
      else if (isLeft)
      {
        parent->left = successor;
      }
      else
      {
        parent->right = successor;
      }

      successor->left = curr->left;

      return true;
    }
  }
}

TreeNode* BST::getSuccessor(TreeNode *d)
{
  // d is the node to be deleted

  TreeNode *sp = d;
  TreeNode *successor = d;
  TreeNode *curr = d->right;

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
  }

  return successor;
}
