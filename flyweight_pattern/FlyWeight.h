#ifndef __FLYWEIGHT__
#define __FLYWEIGHT__

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 亨元模式的实现：
// 运用共享技术有效地支持大量细粒度的对象
// 使用享元模式可以避免大量相似对象的开销，减小了空间消耗

// 例子：五子棋的黑白棋和棋盘，共享棋子的内部状态颜色，
// 而外部状态位置则不同

struct Point
{
  int x;
  int y;

  Point() {}
  Point(int a,int b):x(a),y(b) {}

  // 为支持map中的默认的less仿函数
  bool operator<(const Point &right) const
  {
    if( x < right.x )
      return true;
    else if( x == right.x )
    {
      return y < right.y;
    }
    return false;
  }
};

enum PieceColorTag
{
  BLACK,
  WHITE
};

class CPiece
{
public:
  CPiece(PieceColorTag color) : _color(color) {}

  PieceColorTag GetColor() { return _color; }
  void SetPoint(Point point) { _point = point; }

  Point GetPoint() { return _point; }

protected:
  PieceColorTag _color;
  Point _point;
};

class CGomoku : public CPiece
{
public:
  CGomoku(PieceColorTag color) : CPiece(color) {}
};

class CPieceFactory
{
public:
  CPiece *GetPiece(PieceColorTag color)
  {
    CPiece *pPiece = NULL;
    if( _vecPiece.empty() )
    {
      pPiece = new CGomoku(color);
      _vecPiece.push_back(pPiece);
    }
    else
    {
      for(vector<CPiece*>::iterator it = _vecPiece.begin(); it != _vecPiece.end(); ++it)
      {
        if( (*it)->GetColor() == color )
        {
          pPiece = *it;
        }
      }
      if( pPiece == NULL )
      {
        pPiece = new CGomoku(color);
        _vecPiece.push_back(pPiece);
      }
    }
    return pPiece;
  }
  ~CPieceFactory()
  {
    for(vector<CPiece*>::iterator it = _vecPiece.begin(); it != _vecPiece.end(); ++it)
    {
      if( *it != NULL )
      {
        delete *it;
        *it = NULL;
      }
    }
    // 释放vector对象内存
    vector<CPiece*>().swap(_vecPiece);
  }
private:
  vector<CPiece*> _vecPiece;
};

class CChessboard
{
public:
  void Draw(CPiece *piece)
  {
    if( piece->GetColor() == WHITE )
    {
      cout << "Draw a white at(" << piece->GetPoint().x << "," << piece->GetPoint().y << ")" << endl;
    }
    else
    {
      cout << "Draw a black at(" << piece->GetPoint().x << "," << piece->GetPoint().y << ")" << endl;
    }
    _mapPieces.insert(make_pair(piece->GetPoint(),piece));
  }

  void ShowAllPieces()
  {
    for(map<Point,CPiece*>::iterator it = _mapPieces.begin(); it != _mapPieces.end(); ++it)
    {
      if( it->second->GetColor() == WHITE )
      {
        cout << "(" << it->first.x << "," << it->first.y << ") has a white chese." << endl;
      }
      else
      {
        cout << "(" << it->first.x << "," << it->first.y << ") has a black chese." << endl;
      }
    }
  }
private:
  map<Point,CPiece*> _mapPieces;
};

#endif // __FLYWEIGHT__
