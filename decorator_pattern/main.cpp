#include <iostream>
#include "Decorator.h"

using namespace std;

int main(int argc,char **argv)
{
  Component *pCom1 = new ConcreteComponent();
  Decorator *pDec1 = new ConcreteDecorator1(pCom1);

  pDec1->Operation();
  cout << "dec1 end" << endl;

  Decorator *pDec2 = new ConcreteComponent2(pCom1);
  pDec2->Operation();
  cout << "dec2 end" << endl;

  Decorator *pDec3 = new ConcreteDecorator1(pDec1);
  pDec3->Operation();
  cout << "dec3 end" << endl;

  delete pCom1;
  delete pDec1;
  delete pDec2;
  delete pDec3;

  return 0;
}
