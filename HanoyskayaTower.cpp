#include <iostream>
using namespace std;
void move(int st1, int st2)
{
  cout << st1 << " => " << st2 << endl;
}
void moveT(int count,int st1,int st2,int temp)
{
  if (count != 0)
  {
  moveT(count-1,st1,temp,st2);
  move(st1,st2);
  moveT(count-1,temp,st2,st1);
  }
}
int main()
{
  moveT(3,1,2,3);
  return 0;
}
