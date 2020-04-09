// Ian Rasmussen 
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// ListNode.h

#ifndef _LISTNODE_H
#define _LISTNODE_H

class ListNode
{
  private:
    // No private variables

  public:
    ListNode();
    ListNode(int d);
    ~ListNode();

    int data;
    ListNode *next;
    ListNode *prev;
}

#endif
