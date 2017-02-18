#ifndef __PROTOTYPE__
#define __PROTOTYPE__

// 原型模式的实现：用原型实例指定创建对象的种类，
// 并且通过拷贝这些原型创建新的对象
// 简单来说，就是为了复制对象

class Prototype
{
public:
  virtual ~Prototype() {}
  virtual Prototype* Clone() = 0;
};

class ConcreteType : public Prototype
{
public:
  ConcreteType():_count(0){}

  inline int count() { return _count; }
  inline void count(int c) { _count = c; }
  ~ConcreteType() {}

  ConcreteType(const ConcreteType &right)
  {
    _count = right._count;
  }

  ConcreteType* Clone()
  {
    // 调用拷贝构造函数
    return new ConcreteType(*this);
  }

private:
  int _count;
};


#endif // __PROTOTYPE__
