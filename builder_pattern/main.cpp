#include <iostream>
#include "Builder.h"

using namespace std;

int main(int argc,char **argv)
{
  Builder *fatbuilder = new FatBuilder();
  Director director(fatbuilder);
  director.createMan();

  Man *man = fatbuilder->getMan();
  if( man )
    man->showMan();

  if( fatbuilder )
  {
    delete fatbuilder;
    fatbuilder = NULL;
  }

  return 0;
}

