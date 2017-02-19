#ifndef __CHAIN_RES__
#define __CHAIN_RES__

#include <iostream>

using namespace std;

// 职责链模式的实现
// 使多个对象都有机会处理请求，从而避免请求
// 的发送者和接收者之间的耦合关系。将这些对
// 象连成一条链，直到有一个对象处理它为止

// 例子：员工向公司提交休假申请，需要依次经过项目经理、项目
// 主管和部门主管中，直到某一个同意处理为止

class HolidayRequest
{
public:
  HolidayRequest(int hour) : _hour(hour) {}

  int GetHour() { return _hour; }
private:
  int _hour;
};

class Manager
{
public:
  virtual ~Manager() {}
  virtual bool HandleRequest(HolidayRequest *request) = 0;
};

class PM : public Manager
{
public:
  PM(Manager *manager) : _manager(manager) {}
  bool HandleRequest(HolidayRequest *request)
  {
    if( request->GetHour() <= 2 || _manager == NULL )
    {
      cout << "Request hour : " << request->GetHour() << " PM agree" << endl;
      return true;
    }
    return _manager->HandleRequest(request);
  }
private:
  Manager *_manager;
};

class PS : public Manager
{
public:
  PS(Manager *manager) : _manager(manager) {}
  bool HandleRequest(HolidayRequest *request)
  {
    if( request->GetHour() <= 5 || _manager == NULL )
    {
      cout << "Request hour : " << request->GetHour() << " PS agree" << endl;
      return true;
    }
    return _manager->HandleRequest(request);
  }
private:
  Manager *_manager;
};

class DM : public Manager
{
public:
  DM(Manager *manager) : _manager(manager) {}
  bool HandleRequest(HolidayRequest *request)
  {
    cout << "Request hour : " << request->GetHour() << " DM agree" << endl;
    return true;
  }
private:
  Manager *_manager;
};

#endif // __CHAIN_RES__
