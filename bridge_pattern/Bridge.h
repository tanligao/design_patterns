#ifndef __BRIDGE__
#define __BRIDGE__

#include <iostream>

// 桥接模式的实现：
// 将抽象部分和它的实现部分分离，使它们都可以
// 独立的变化。简单来说，就是抽象对外提供
// 调用的接口；对外隐瞒实现部分，在抽象中引用
// 实现部分，从而实现抽象对实现部分的调用，而
// 抽象中引用的实现部分可以在今后的开发过程中，
// 切换成别的实现部分。

class Implementor
{
public:
  virtual void OperatorImpl() = 0;
  virtual ~Implementor() {}
};

class ConcreteImplement : public Implementor
{
public:
  void OperatorImpl()
  {
    std::cout << "ConcreteImplement" << std::endl;
  }
  ~ConcreteImplement() {}
};

class Abstract
{
public:
  Abstract(Implementor *imple) : _imple(imple) {}
  virtual ~Abstract() {}
  virtual void Operation() = 0;
protected:
  Implementor *_imple;
};

class ConcreteAbstract : public Abstract
{
public:
  ConcreteAbstract(Implementor *imple) : Abstract(imple) {}
  ~ConcreteAbstract() {}
  void Operation()
  {
    _imple->OperatorImpl();
  }
};

#endif // __BRIDGE__
