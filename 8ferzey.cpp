#include <iostream>
using namespace std;
int board[8][8];
void set(int i, int j)
{
  for (int x = 0; x < 8; ++x)
  {
    ++board[x][j];
    ++board[i][x];
    int diag;
    diag = j - i + x;
    if (diag >= 0 && diag < 8)
      ++board[x][diag];
    diag = j + i - x;
    if (diag >= 0 && diag < 8)
      ++board[x][diag];
  }
  board[i][j] = -1;
}

void reset(int i, int j)
{
  for (int x = 0; x < 8; ++x)
  {
    --board[x][j];
    --board[i][x];
    int diag;
    diag = j - i + x;
    if (diag >= 0 && diag < 8)
      --board[x][diag];
    diag = j + i - x;
    if (diag >= 0 && diag < 8)
      --board[x][diag];
  }
  board[i][j] = 0;
}

bool tryq(int i)
{
  bool result = false;
  for (int j = 0; j < 8; ++j)
  {
    if (board[i][j] == 0)
    {
      set(i,j);
      if (i == 7)
	      result = true;
      else
      {
      	if (!(result = tryq(i + 1)))
      	  reset(i, j);
      }
    }
    if (result)
      break;
  }
  return result;
}

int main()
{
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      board[i][j] = 0;
  tryq(0);
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      if (board[i][j] == -1)
      	cout << " w ";
      else
      	cout << " - ";
    }
    cout << endl;
  }
  return 0;
}
