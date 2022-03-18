//Тип информационного поля int.Удалить из очереди все элементы с четными информационными полями.
#include <iostream>
#include <queue>
using namespace std;
int main(){
  srand(time(0));
  queue <int> Queue;
  queue <int> Queue2;
  int m;
  for(int i = 0; i < 10;i++)
  {
    m = rand()%101;
    cout << m << ' ';
    Queue.push(m);
  }
  while(!Queue.empty())
  {
    if(Queue.front() % 2 == 0)
    {
      Queue.pop();
    }
    else
    {
    Queue2.push(Queue.front());
    Queue.pop();
    }
  }
  cout << endl << endl;
  while(!Queue2.empty())
  {
    cout << Queue2.front() << ' ';
    Queue2.pop();
  }
  return 0;
}
