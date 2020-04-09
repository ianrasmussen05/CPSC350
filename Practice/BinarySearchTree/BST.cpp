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
  return true;
}

bool BST::deleteNode(int k)
{
  return true;
}

TreeNode* BST::getSuccessor(TreeNode *d)
{
  return d;
}
