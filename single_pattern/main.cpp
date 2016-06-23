#include <iostream>
#include "Singleton.h"
#include "Singleton1.h"

using namespace std;

int main()
{
    Singleton* instance = Singleton::getInstance();
    instance->print();
    Singleton::destoryInstance();

    Singleton1 *singletonObj = Singleton1 ::GetInstance();

    return 0;
}
