#include "GenQueue.h"

using namespace std;

int main(int argc, char** argv)
{
  GenQueue *myQueue = new GenQueue(10);

  myQueue->insert('I');
  myQueue->insert('a');
  myQueue->insert('n');

  cout << "Peek: " << myQueue->peek() << endl;
  cout << "Remove: " << myQueue->remove() << endl;
  cout << "Inserting b, d, p into the queue" << endl;

  myQueue->insert('b');
  myQueue->insert('d');
  myQueue->insert('p');

  cout << "Purging the queue" << endl;
  while (!myQueue->isEmpty())
  {
    cout << "Remove: " << myQueue->remove() << endl;
  }

  delete myQueue;

  return 0;
}
