#include <iostream>
#include "Adapter.h"

using namespace std;

int main()
{
    MySequence *stack1 = new MyStack();
    stack1->push(1);
    stack1->push(2);
    stack1->pop();
    stack1->pop();
    MySequence *queue1 = new MyQueue();
    queue1->push(1);
    queue1->push(2);
    queue1->pop();
    queue1->pop();

    delete stack1;
    delete queue1;
    return 0;
}
