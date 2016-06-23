#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <mutex>

//test the singleton pattern

class Singleton
{
    public:
        //use the c++11 mutex(lock() and unlock() to
        //protect the thread safe
        static Singleton* getInstance()
        {
            if(!instance)
            {
                std::mutex mtx;
                mtx.lock();
                if(!instance)
                {
                    instance = new Singleton();
                }
                mtx.unlock();
            }
            return instance;
        }

        static void destoryInstance()
        {
            if(instance)
            {
                delete instance;
                instance = nullptr;
            }
        }

        void print()
        {
            std::cout << "print the single" << std::endl;
        }

        virtual ~Singleton();
    private:
        Singleton();
        static Singleton *instance;
};

#endif // SINGLETON_H
