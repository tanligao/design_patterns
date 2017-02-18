#ifndef __DECORATOR__
#define __DECORATOR__

#include <iostream>

using namespace std;

// 装饰模式的实现：
// 动态地给一个对象添加一些额外的职责。就增加功能
// 来说，Decorator模式相比生成子类更为灵活，基于对
// 象组合的方式，可以很灵活的给对象添加所需要的功能

class Component
{
public:
  virtual void Operation() = 0;
  virtual ~Component() {}
};

class ConcreteComponent : public Component
{
public:
  void Operation()
  {
    cout << "ConcreteComponent" << endl;
  }
};

class Decorator : public Component
{
public:
  Decorator(Component *imple) : _imple(imple) {}
  virtual void Operation()
  {
    if( _imple )
      _imple->Operation();
  }
protected:
  Component *_imple;
};

class ConcreteDecorator1 : public Decorator
{
public:
  ConcreteDecorator1(Component *imple) : Decorator(imple) {}

  void Operation()
  {
    AddOperation();
    Decorator::Operation();
  }

  void AddOperation()
  {
    cout << "add Operation1" << endl;
  }
};

class ConcreteComponent2 : public Decorator
{
public:
  ConcreteComponent2(Component *imple) : Decorator(imple) {}
  void Operation()
  {
    AddOperation();
    Decorator::Operation();
  }
  void AddOperation()
  {
    cout << "add Operation2" << endl;
  }
};

#endif // __DECORATOR__

