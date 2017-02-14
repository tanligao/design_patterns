#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include <memory>
#include <iostream>

// 简单工厂模式，类似于策略模式，但是
// 违反面向对象的原则：开放关闭原则，因为
// 如果需要增加Product，则需要更改原来的代码
// 例如工厂生产函数中需要增加case
// 所以实际运用较少，易造成代码混乱
enum ProductType
{
  PRODUCTA,
  PRODUCTB,
  PRODUCTC
};

class Product
{
public:
  virtual void show() = 0;
  virtual ~Product();
};

class ProductA : public Product
{
public:
  void show()
  {
    std::cout << "I'm ProductA" << std::endl;
  }
};

class ProductB : public Product
{
public:
  void show()
  {
    std::cout << "I'm ProductB" << std::endl;
  }
};

class ProductC : public Product
{
public:
  void show()
  {
    std::cout << "I'm ProductC" << std::endl;
  }
};

// 一般实际运用中会把工厂类设计成单例模式或者直接
// 把工厂生产函数设计为静态函数，为该类所有，而不
// 需要类的实例对象调用，因为也仅仅是作为工厂运用
class Factory
{
public:
  static Product* createProduct(ProductType type)
  {
    switch(type)
    {
    case PRODUCTA:
      return new ProductA();
      break;
    case PRODUCTB:
      return new ProductB();
      break;
    case PRODUCTC:
      return new ProductC();
      break;
    default:
      return NULL;
    }
  }
};

class Factory1
{
public:
  static Factory1& getInstance()
  {
    return instance;
  }

  static Product* CreateSingle1(ProductType type)
  {
    switch(type)
    {
    case PRODUCTA:
      return new ProductA();
      break;
    case PRODUCTB:
      return new ProductB();
      break;
    case PRODUCTC:
      return new ProductC();
      break;
    default:
      return NULL;
    }
  }

private:
  static Factory1 instance;
  Factory1();
  Factory1& operator=(const Factory1 &right);
};

// 工厂方法模式实现：针对每一个产品都会有一个工厂类
class Factory2
{
public:
  virtual Product* create() = 0;
};

class Factory2A : public Factory2
{
public:
  Product* create()
  {
    return new ProductA();
  }
};

class Factory2B : public Factory2
{
public:
  Product* create()
  {
    return new ProductB();
  }
};

class Factory2C : public Factory2
{
public:
  Product* create()
  {
    return new ProductC();
  }
};


// 抽象工厂模式实现（使用智能指针）
class Single
{
public:
    Single(){}
    virtual ~Single(){}
    virtual void print() = 0;
};

// single A
class SingleA : public Single
{
public:
    SingleA(){}
    ~SingleA(){}
    void print()
    {
        std::cout << "SingleA" << std::endl;
    }
};

// single B
class SingleB : public Single
{
public:
    SingleB(){}
    ~SingleB(){}
    void print()
    {
        std::cout << "SingleB" << std::endl;
    }
};

class Multi
{
public:
    Multi(){}
    virtual ~Multi(){}
    virtual void print() = 0;
};

// multi A
class MultiA : public Multi
{
public:
    MultiA(){}
    ~MultiA(){}
    void print()
    {
        std::cout << "MultiA" << std::endl;
    }
};

// multi B
class MultiB : public Multi
{
public:
    MultiB(){}
    ~MultiB(){}
    void print()
    {
        std::cout << "MultiB" << std::endl;
    }
};

class ProductFactory
{
public:
    ProductFactory(){}
    virtual ~ProductFactory(){}
    virtual std::shared_ptr<Single> CreateSingle() = 0;
    virtual std::shared_ptr<Multi> CreateMulti() = 0;
};

// factory A
class ProductFactoryA : public ProductFactory
{
public:
    ProductFactoryA(){}
    ~ProductFactoryA(){}
    std::shared_ptr<Single> CreateSingle()
    {
        return std::make_shared<SingleA>();
    }
    std::shared_ptr<Multi> CreateMulti()
    {
        return std::make_shared<MultiA>();
    }
};

// factory B
class ProductFactoryB : public ProductFactory
{
public:
    ProductFactoryB(){}
    ~ProductFactoryB(){}
    std::shared_ptr<Single> CreateSingle()
    {
        return std::make_shared<SingleB>();
    }
    std::shared_ptr<Multi> CreateMulti()
    {
        return std::make_shared<MultiB>();
    }
};

#endif // FACTORY_H_INCLUDED
