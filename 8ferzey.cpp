#include <iostream>
using namespace std;
int board[8][8];
int check(int a, int b)
{
  for(int i = 0; i < 8; ++i)
  {
    if (board[i][b])
      return 0;
    if (b-a+i>=0)
      if(board[i][b-a+i])
        return 0;
    if (b+a-i<8)
      if (board[i][b+a-i])
        return 0;
  }
  return 1;
}
 
int vert(int i)
{
  if (i == 8)
    return 1;
  for(int j = 0; j < 8; ++j)
  {
    if (check(i,j))
    {
      board[i][j] = 1;
      if (vert(i+1))
        return 1;
      board[i][j] = 0;
    }
  }
  return 0;
}
 
int main()
{
  vert(0);
  for(int i = 0; i< 8; ++i)
  {
    for(int j = 0; j< 8; ++j)
    {
      if (board[i][j] == 0)
        cout << "- ";
      else if (board[i][j] == 1)
        cout << "w ";
    }
  cout << endl;
  }
}
