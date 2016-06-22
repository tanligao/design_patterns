#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include <memory>

//test the abstract factory pattern
//there are two core product with multi number core
//use the smart pointer

class Single
{
public:
    Single(){}
    virtual ~Single(){}
    virtual void print() = 0;
};

//single A
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

//single B
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

//multi A
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

//multi B
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

//factory A
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

//factory B
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
