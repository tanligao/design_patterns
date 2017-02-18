#include <iostream>
#include "Composite.h"

using namespace std;

int main(int argc,char **argv)
{
  Component *pHeadNode = new Composite("Head Node");
  Component *pSubNode1 = new Leaf("Sub Node1");
  Component *pSubNode2 = new Composite("Sub Node2");
  Component *pSubNode3 = new Composite("Sub Node3");

  pHeadNode->Add(pSubNode1);
  pHeadNode->Add(pSubNode2);
  pHeadNode->Add(pSubNode3);

  Component *pSubNode21 = new Leaf("Sub Node2 1");
  Component *pSubNode22 = new Leaf("Sub Node2 2");
  pSubNode2->Add(pSubNode21);
  pSubNode2->Add(pSubNode22);

  Component *pSubNode31 = new Leaf("Sub Node3 1");
  Component *pSubNode32 = new Leaf("Sub Node3 2");
  Component *pSubNode33 = new Leaf("Sub Node3 3");

  pSubNode3->Add(pSubNode31);
  pSubNode3->Add(pSubNode32);
  pSubNode3->Add(pSubNode33);

  pHeadNode->Print();

  if( pHeadNode )
    delete pHeadNode;

  return 0;
}


