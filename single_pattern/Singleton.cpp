#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

Singleton::Singleton()
{
    //ctor
}

Singleton::~Singleton()
{
    //dtor
}
