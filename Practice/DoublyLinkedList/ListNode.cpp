#include "ListNode.h"

ListNode::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

ListNode::ListNode(int d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

ListNode::~ListNode()
{
  // Build some character
  delete next;
  delete prev;
}
