#ifndef SINGLETON1_H
#define SINGLETON1_H


#include <iostream>

class Singleton1
{
public:
    static Singleton1 *GetInstance()
    {
        return m_Instance;
    }
private:
    static Singleton1 *m_Instance;
    // This is important
    class GC
    {
    public :
        ~GC()
        {
            // We can destory all the resouce here, eg:db connector, file handle and so on
            if (m_Instance != NULL )
            {
                std::cout<< "Here is the test" <<std::endl;
                delete m_Instance;
                m_Instance = NULL ;
            }
        }
    };
    static GC gc;
};

#endif // SINGLETON1_H
