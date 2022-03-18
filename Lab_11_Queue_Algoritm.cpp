//Тип информационного поля int.Удалить из очереди все элементы с четными информационными полями.
#include <iostream>
using namespace std;

struct Node{
  int data;
  Node *pNext = nullptr;
};

struct Queue{
  Node *first = nullptr;
  Node *last = nullptr;
  int size = 0;
};

void Add(Queue& och,int data){
  Node *elem = new Node;
  elem->data = data;
  if(och.first == nullptr){
    och.first = elem;
    och.last = elem;
  }
  else{
    och.last->pNext = elem;
    och.last = elem;
  } 
  och.size++;
}

int DelItem(Queue& och){
  Node *elem = och.first;
  och.first = och.first->pNext;
  int q = elem->data;
  delete elem;
  och.size--;
  return q;
}

void DelAll(Queue& och){
  for(int i = 0; i < och.size;i++){
    Node *elem = och.first;
    och.first = och.first->pNext;
    delete elem;
  }
  och.size = 0;
}

void Print(Queue& och){
  Node *elem = och.first;
  while(elem->pNext != nullptr)
  {
    cout << elem->data << ' ';
    elem = elem->pNext;
  }
  cout << elem->data << ' ';
}

int main() {
  Queue och;
  Queue ochNew;
  int z;
  srand(time(0));
  for(int i = 0; i < 9; i++)
    Add(och,rand()%101);
  Print(och);
  cout << endl;
  for(int i = 0; i < 9; i++)
  {
    z = DelItem(och);
    if(z % 2 != 0)
      Add(ochNew,z);
  }
  Print(ochNew);
  DelAll(ochNew);
  return 0;
}
