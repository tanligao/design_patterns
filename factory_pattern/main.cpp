#include <iostream>
#include "Factory.h"
#include <memory>

using namespace std;

int main()
{
    ProductFactoryA *factoryA = new ProductFactoryA();
    ProductFactoryB *factoryB = new ProductFactoryB();
    std::shared_ptr<Single> singleA = factoryA->CreateSingle();
    singleA->print();
    std::shared_ptr<Single> singleB = factoryB->CreateSingle();
    singleB->print();

    std::shared_ptr<Multi> multiA = factoryA->CreateMulti();
    multiA->print();
    std::shared_ptr<Multi> multiB = factoryB->CreateMulti();
    multiB->print();

    delete factoryA;
    delete factoryB;
    return 0;
}
