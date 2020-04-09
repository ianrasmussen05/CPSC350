#ifndef _BST_H
#define _BST_H

class BST
{
  private:
    TreeNode *root;

  public:
    BST();
    ~BST();
    // virtual ~BST(); - when working with template class

    void insert(int value);
    bool search(int value);
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode *getMin();
    TreeNode *getMax();

    TreeNode *getSuccessor(TreeNode *d);
    void printTree(TreeNode *node);
};

#endif
