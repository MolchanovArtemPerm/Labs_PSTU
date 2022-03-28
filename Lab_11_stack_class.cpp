//Тип информационного поля char*.Добавить в стек элемент после элемента с заданным информационным полем.
#include <iostream>
using namespace std;

class Stack{
  private:
  struct Node
  {
    public:
    char data;
    Node *pNext = nullptr;
  };
  Node *first = nullptr;
  Node *last = nullptr;
  int size = 0;
  
  public:

  void Add(char data)
  {
    Node *elem = new Node;
    elem->data = data;
    if(first == nullptr)
    {
      last = elem;
      first = elem;
    }
    else
    {
      elem->pNext = last;
      last = elem;
    }
    size++;
  }

  char DelItem()
  {
    Node *elem = last;
    last = last->pNext;
    char q = elem->data;
    delete elem;
    size--;
    return q;
  }

  void DelAll()
  {
    for(int i = 0; i < size;i++)
    {
      Node *elem = last;
      last = last->pNext;
      delete elem;
    }
    size = 0;
  }
  
    void Print(){
      Node *elem = last;
      while(elem->pNext != nullptr)
      {
        cout << elem->data << endl;
        elem = elem->pNext;
      }
      cout << elem->data;
    }
};

int main() {
  setlocale(LC_ALL,"Rus");
  Stack stack;
  Stack stackNew;
  char m,n;
  stack.Add('A');
  stack.Add('B');
  stack.Add('C');
  stack.Add('D');
  cout <<"Введите любое значение: ";
  cin >> n;
  stack.Print();
  for(int i = 0; i < 4;i++){
    m = stack.DelItem();
    stackNew.Add(m);
    if(m == n)
      stackNew.Add('1');
  }
  cout << endl << endl;
  stackNew.Print();
  stackNew.DelAll();
  return 0;
}
