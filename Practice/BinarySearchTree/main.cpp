#include "TreeNode.h"
#include "BST.h"

int main (int argc, char **argv)
{
  BST *tree = new BST();
  TreeNode *node = new TreeNode();

  tree->insert(5);
  tree->insert(6);
  tree->insert(3);

  tree->printTree();

  delete tree;
  delete node;

  return 0;
}
