#include <iostream>
#include "ChainRes.h"

using namespace std;

int main(int argc,char **argv)
{
  HolidayRequest *request1 = new HolidayRequest(3);

  DM *pDm = new DM(NULL);
  PS *pPs = new PS(pDm);
  PM *pPm = new PM(pPs);

  pPm->HandleRequest(request1);

  delete request1;

  request1 = new HolidayRequest(25);
  pPm->HandleRequest(request1);

  delete request1;
  delete pDm;
  delete pPs;
  delete pPm;

  return 0;
}

