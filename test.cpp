#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
  StackT myStack;
  myStack.Push(1);
  myStack.Push(2);
  myStack.Push(3);

  cout << "Pushed 1, 2, 3" << endl;
  cout << "Top is " << myStack.Top() << endl;
  cout << "Pop" << endl;
  myStack.Pop();
  cout << "Top is " << myStack.Top() << endl;
  /*
  cout << "Pop 3 more times" << endl;
  myQueue.Pop();
  myQueue.Pop();
  myQueue.Pop();
  cout << "Top returns " << myQueue.Top() << endl;
  */

  // Test an empty queue:
  StackT emptyQ;

  StackT copiedQ(myStack);
  cout << "Copied Stack top: " << copiedQ.Top();
  cout << "\tSize: " << copiedQ.Size() << endl;

  cout << "Push 4, 5:" << endl;
  copiedQ.Push(4);
  copiedQ.Push(5);
  cout << "Copied Q contents:" << endl;
  for(size_t i = 0; i < 4; ++i) {
    cout << copiedQ.Top() << endl;
    copiedQ.Pop();
  }

  cout << endl << endl << "Test assignment;" << endl;

  StackT evens;
  StackT odds;

  for (int i = 0; i < 10; ++i) {
    evens.Push(2 * i);
    odds.Push(2 * i + 1);
  }
  cout << "Even top: " << evens.Top() << endl;
  cout << "Odd top: " << odds.Top() << endl;

  cout << "Evens reassigned to odds: " << endl;
  evens = odds;
  cout << "Now 'evens':" << endl;
  for (int i = 0; i < 10; ++i) {
    cout << evens.Top() << endl;
    evens.Pop();
  }
  cout << "Testing empty Stack" << endl;
  emptyQ.Pop();
  emptyQ.Top();
  return 0;
}
