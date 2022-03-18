//Тип информационного поля char*.Добавить в стек элемент после элемента с заданным информационным полем.
#include <iostream>
using namespace std;

struct Node{
  char data;
  Node *pNext = nullptr;
};

struct Stack{
  Node *first = nullptr;
  Node *last = nullptr;
  int size = 0;
};

void Add(Stack& stack,char data){
  Node *elem = new Node;
  elem->data = data;
  if(stack.first == nullptr)
  {
    stack.last = elem;
    stack.first = elem;
  }
  else
  {
    elem->pNext = stack.last;
    stack.last = elem;
  }
  stack.size++;
}

char DelItem(Stack& stack){
  Node *elem = stack.last;
  stack.last = stack.last->pNext;
  char q = elem->data;
  delete elem;
  stack.size--;
  return q;
}

void DelAll(Stack& stack){
  for(int i = 0; i < stack.size;i++){
    Node *elem = stack.last;
    stack.last = stack.last->pNext;
    delete elem;
  }
  stack.size = 0;
}

void Print(Stack& stack){
  Node *elem = stack.last;
  while(elem->pNext != nullptr)
  {
    cout << elem->data << endl;
    elem = elem->pNext;
  }
  cout << elem->data;
}

int main() {
  setlocale(LC_ALL,"Rus");
  Stack stack;
  Stack stackNew;
  char m,n;
  Add(stack,'A');
  Add(stack,'B');
  Add(stack,'C');
  Add(stack,'D');
  cout <<"Введите любое значение: ";
  cin >> n;
  Print(stack);
  for(int i = 0; i < 4;i++){
    m = DelItem(stack);
    Add(stackNew,m);
    if(m == n)
      Add(stackNew,'1');
  }
  cout << endl << endl;
  Print(stackNew);
  DelAll(stackNew);
  return 0;
}
