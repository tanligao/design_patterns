#ifndef ADAPTER_H_INCLUDED
#define ADAPTER_H_INCLUDED

#include <iostream>

//test the adapter pattern

//like the STL stack and queue
//use a deque to control

class MyDeque
{
public:
    void push_back(){ std::cout << "deque : push_back" << std::endl;}
    void push_front(){ std::cout << "deque : push_front" << std::endl;}
    void pop_back() { std::cout << "deque : pop_back" << std::endl;}
    void pop_front() { std::cout << "deque : pop_front" << std::endl;}
};

class MySequence
{
public:
    virtual void push(int x) = 0;
    virtual void pop() = 0;
    virtual ~MySequence(){}
};

class MyStack : public MySequence
{
public:
    void push(int x) { _deque.push_back();}
    void pop() { _deque.pop_back();}
private:
    MyDeque _deque;
};

class MyQueue : public MySequence
{
public:
    void push(int x) { _deque.push_front();}
    void pop() { _deque.pop_front();}
private:
    MyDeque _deque;
};


#endif // ADAPTER_H_INCLUDED
