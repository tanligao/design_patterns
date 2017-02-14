#ifndef __BUILDER__
#define __BUILDER__

#include <iostream>

/* 建造者模式：将一个复杂对象的构建与它的表示分离，
 * 使得同样的构建过程可以创建不同的表示，把复杂对
 * 象的创建和部件的创建分别开来，分别用Builder类
 * 和Director类来表示Director负责最后构建复杂对象，
 * 而Builder则负责复杂对象构建的过程，以人的部件构造
 * 为例子，构造分为头部、身体、双手和双脚
 */
enum ManTypeTag
{
  kFatMan,
  kThinMan,
  kNormal
};

class Man
{
public:
  void setHead(ManTypeTag type) { _type = type; }
  void setBody(ManTypeTag type) { _type = type; }
  void setLeftHand(ManTypeTag type) { _type = type; }
  void setRightHand(ManTypeTag type) { _type = type; }
  void setLeftFoot(ManTypeTag type) { _type = type; }
  void setRightFoot(ManTypeTag type) { _type = type; }

  void showMan()
  {
    switch(_type)
    {
    case kFatMan:
      std::cout << "this is a fat man" << std::endl;
      break;
    case kThinMan:
      std::cout << "this is a thin man" << std::endl;
      break;
    default:
      std::cout << "this is a normal man" << std::endl;
    }
  }
private:
  ManTypeTag _type;
};

class Builder
{
public:
  Builder(){}
  virtual ~Builder(){}
  virtual void buildHead(){}
  virtual void buildBody(){}
  virtual void buildLeftHand(){}
  virtual void buildRightHand(){}
  virtual void buildLeftFoot(){}
  virtual void buildRightFoot(){}

  virtual Man* getMan(){ return NULL; }
};

class FatBuilder : public Builder
{
public:
  FatBuilder() { _fatman = new Man(); }
  ~FatBuilder() { if( _fatman ) delete _fatman; }

  void buildHead() { _fatman->setHead(kFatMan); }
  void buildBody() { _fatman->setBody(kFatMan); }
  void buildLeftHand() { _fatman->setLeftHand(kFatMan); }
  void buildRightHand() { _fatman->setRightHand(kFatMan); }
  void buildLeftFoot() { _fatman->setLeftFoot(kFatMan); }
  void buildRightFoot() { _fatman->setRightFoot(kFatMan); }

  Man* getMan() { return _fatman; }
private:
  Man *_fatman;
};

class ThinBuilder : public Builder
{
public:
  ThinBuilder() { _thinman = new Man(); }
  ~ThinBuilder() { delete _thinman; _thinman = NULL; }

  void buildHead() { _thinman->setHead(kThinMan); }
  void buildBody() { _thinman->setBody(kThinMan); }
  void buildLeftHand() { _thinman->setLeftHand(kThinMan); }
  void buildRightHand() { _thinman->setRightHand(kThinMan); }
  void buildLeftFoot() { _thinman->setLeftFoot(kThinMan); }
  void buildRightFoot() { _thinman->setRightFoot(kThinMan); }

  Man* getMan() { return _thinman; }
private:
  Man *_thinman;
};

class Director
{
public:
  Director(Builder *builder):_builder(builder) {}
  void createMan()
  {
    _builder->buildHead();
    _builder->buildBody();
    _builder->buildLeftHand();
    _builder->buildRightHand();
    _builder->buildLeftFoot();
    _builder->buildRightFoot();
  }
private:
  Builder *_builder;
};

#endif // __BUILDER__
