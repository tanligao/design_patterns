#include <iostream>
#include "Singleton.h"
#include "Singleton1.h"
#include "Singleton2.h"

using namespace std;

int main()
{
    Singleton* instance = Singleton::getInstance();
    instance->print();
    Singleton::destoryInstance();

    Singleton1 *singletonObj = Singleton1 ::GetInstance();

    singletonObj->print();

    test* t = Singleton2<test>::getInstance();
    t->print();
    
    return 0;
}
