#include <iostream>
#include "Bridge.h"

using namespace std;

int main(int argc,char **argv)
{
  Implementor *imple = new ConcreteImplement();
  Abstract *conabstrack = new ConcreteAbstract(imple);

  conabstrack->Operation();

  delete conabstrack;
  conabstrack = NULL;
  delete imple;
  imple = NULL;
  return 0;
}
