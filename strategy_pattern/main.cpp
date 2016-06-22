#include <iostream>
#include "Strategy.h"

using namespace std;

int main()
{
    Context *con1 = new Context(SA);
    con1->doPrint();

    Context *con2 = new Context(SB);
    con2->doPrint();

    Context *con3 = new Context(SC);
    con3->doPrint();

    delete con1;
    delete con2;
    delete con3;
    return 0;
}
