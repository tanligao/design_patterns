#ifndef ADAPTER_H_INCLUDED
#define ADAPTER_H_INCLUDED

#include <iostream>

// 适配器模式的实现：将一个类的接口转换成客户希望的
// 另外一个接口。适配器模式使得原本由于接口不兼容而
// 不能一起工作的那些类可以一起工作

// 例子：STL中的stack和queue适配器就是对deque序列容器
// 的适配，使deque的使用符合stack和queue的特点，stack特
// 点是：后进先出，queue特点是：先进先出

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
