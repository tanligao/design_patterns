#ifndef __PROXY__
#define __PROXY__

#include <iostream>

using namespace std;

// 代理模式的实现
// 为其他对象提供一种代理以控制对这个对象的访问

class Subject
{
public:
  Subject() {}
  virtual ~Subject() {}

  virtual void Request() = 0;
};

class RealSubject
{
public:
  RealSubject() {}

  void Request()
  {
    cout << "Real Request" << endl;
  }
};

class ProxySubject
{
public:
  ProxySubject() : _subject(NULL){}
  ProxySubject(RealSubject *subject) : _subject(subject) {}
  ~ProxySubject()
  {
    if( _subject )
    {
      delete _subject;
      _subject = NULL;
    }
  }

  void Request()
  {
    if( !_subject )
    {
      _subject = new RealSubject();
    }
    cout << "Proxy Request" << endl;
    _subject->Request();
  }
private:
  RealSubject *_subject;
};

#endif // __PROXY__

