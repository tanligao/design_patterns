#include <iostream>
#include "FlyWeight.h"

using namespace std;

int main(int argc,char **argv)
{
  CPieceFactory *pPieceFactory = new CPieceFactory();
  CChessboard *pChessboard = new CChessboard();

  CPiece *pPiece = pPieceFactory->GetPiece(WHITE);
  pPiece->SetPoint(Point(2,3));
  pChessboard->Draw(pPiece);

  pPiece = pPieceFactory->GetPiece(BLACK);
  pPiece->SetPoint(Point(4,5));
  pChessboard->Draw(pPiece);

  pPiece = pPieceFactory->GetPiece(WHITE);
  pPiece->SetPoint(Point(6,7));
  pChessboard->Draw(pPiece);

  cout << "Show all cheses" << endl;
  pChessboard->ShowAllPieces();

  if( pChessboard )
    delete pChessboard;

  if( pPieceFactory )
    delete pPieceFactory;

  return 0;
}

