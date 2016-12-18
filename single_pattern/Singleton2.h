#ifndef __SINGLETON2_H_
#define __SINGLETON2_H_

#include <pthread.h>
#include <iostream>

using namespace std;

class noncopyble
{
private:
	noncopyble(noncopyble &right);
	const noncopyble& operator=(noncopyble &right);
protected:
	noncopyble() {};
	~noncopyble() {};
};

class test
{
public:
	test(){};
	~test(){};
	
	void print()
	{
		cout << "test singleton2" << endl;
	}
};

template<typename T>
class Singleton2 : public noncopyble
{
public:
	static T* getInstance()
	{
		pthread_once(&m_once,&Singleton2::init);
		return m_instance;
	}

private:
	static T *m_instance;
	static pthread_once_t m_once;
	static void init()
	{
		m_instance = new T();
	}
};

template<typename T>
T* Singleton2<T>::m_instance = nullptr;

template<typename T>
pthread_once_t Singleton2<T>::m_once = PTHREAD_ONCE_INIT;

#endif
