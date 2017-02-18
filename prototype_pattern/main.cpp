#include <iostream>
#include "Prototype.h"

using namespace std;

int main(int argc,char *argv[])
{
  ConcreteType *prototype = new ConcreteType();
  prototype->count(1024);

  ConcreteType *clonetype = prototype->Clone();

  cout << prototype->count() << endl;
  cout << clonetype->count() << endl;

  delete prototype;
  prototype = NULL;
  delete clonetype;
  prototype = NULL;
  return 0;
}
