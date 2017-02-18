#ifndef __FACADE__
#define __FACADE__

#include <iostream>

using namespace std;

// 门面模式（外观模式）的实现：
// 将子系统中的一组接口提供一个一致的界面，
// 外观模式定义了一个高层接口，这个接口使得
// 这一子系统更加容易使用

// 例子：模拟VS编译按钮：语法分析，生成中间代码，
// 生成汇编代码，链接成可执行文件

class CSyntaxParser
{
public:
  void SyntaxParser()
  {
    cout << "Syntax Parser" << endl;
  }
};

class CGenMidCode
{
public:
  void GenMidCode()
  {
    cout << "Generate middle code" << endl;
  }
};

class CGenAssemblyCode
{
public:
  void GenAssemblyCode()
  {
    cout << "Generate assembly code" << endl;
  }
};

class CLinkSystem
{
public:
  void LinkSystem()
  {
    cout << "Link System" << endl;
  }
};

class Facade
{
public:
  void Compile()
  {
    CSyntaxParser syntaxParser;
    CGenMidCode genMidCode;
    CGenAssemblyCode genAssemblyCode;
    CLinkSystem linkSystem;

    syntaxParser.SyntaxParser();
    genMidCode.GenMidCode();
    genAssemblyCode.GenAssemblyCode();
    linkSystem.LinkSystem();
  }
};

#endif // __FACADE__
