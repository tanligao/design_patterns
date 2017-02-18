#ifndef __COMPOSITE__
#define __COMPOSITE__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 组合模式的实现：
// 将对象组合成树形结构以表示“部分-整体”的
// 层次结构。组合（Composite）模式使得用户
// 对单个对象和组合对象的使用具有一致性

// 组合模式就是把一些现有的对象或者元素，经
// 过组合后组成新的对象，新的对象提供内部方法，
// 可以让我们很方便的完成这些元素或者内部对象的访问和操作

class Component
{
public:
  Component(std::string name):_name(name) {}

  virtual void Operation() = 0;
  virtual void Add(Component *) = 0;
  virtual void Remove(Component *) = 0;
  virtual void Print() = 0;
  virtual Component* GetChild(unsigned int index) = 0;
  virtual ~Component() {}
  virtual std::string GetName() { return _name; }
protected:
  std::string _name;
};

class Leaf : public Component
{
public:
  Leaf(std::string name) : Component(name) {}

  void Operation()
  {
    std::cout << "I'm " << _name << std::endl;
  }
  void Add(Component*) {}
  void Remove(Component*) {}
  Component* GetChild(unsigned int index) { return NULL; }
  void Print()
  {
    std::cout << _name << std::endl;
  }

  ~Leaf() {}
};

class Composite : public Component
{
public:
  Composite(std::string name):Component(name) {}

  void Operation()
  {
    std::cout << "I'm " << _name << std::endl;
  }
  void Add(Component *com)
  {
    _leaf_array.push_back(com);
  }
  void Remove(Component *com)
  {
    vector<Component*>::iterator it_find = find(_leaf_array.begin(),_leaf_array.end(),com);
    if( it_find != _leaf_array.end() )
    {
      if( *it_find != NULL )
      {
        delete *it_find;
        *it_find = NULL;
      }
      _leaf_array.erase(it_find);
    }
  }
  Component* GetChild(unsigned int index)
  {
    if( index < 0 || index >= _leaf_array.size() )
      return NULL;
    return _leaf_array[index];
  }
  void Print()
  {
    cout << "size: " << _leaf_array.size() << std::endl;
    for(vector<Component*>::iterator it = _leaf_array.begin(); it != _leaf_array.end(); ++it)
    {
      (*it)->Print();
    }
  }
  ~Composite()
  {
    vector<Component*>::iterator it = _leaf_array.begin();
    while( it != _leaf_array.end() )
    {
      if( *it )
      {
        cout << "delete " << (*it)->GetName() << endl;
        delete *it;
        *it = NULL;
      }
      _leaf_array.erase(it);

      it = _leaf_array.begin();
    }
  }
private:
  vector<Component*> _leaf_array;
};

#endif // __COMPOSITE__

