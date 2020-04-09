#ifndef _TREENODE_H
#define _TREENODE_H

class TreeNode
{
  private:
    // No private variables

  public:
    TreeNode();
    TreeNode(int k);
    // TreeNode(int k, <type> value);
    ~TreeNode();
    // virtual ~TreeNode(); // Research virtual

    int key;
    TreeNode *left;
    TreeNode *right;
};

#endif
