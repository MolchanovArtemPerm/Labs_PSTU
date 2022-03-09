#include <iostream>
using namespace std;

struct ELEM {
	int data;
	ELEM *pNext = nullptr;
  ELEM *pBack = nullptr;
};

struct list {
  ELEM *data = nullptr; 
};

char Search(list &spisok,int index){
  ELEM *elem = new ELEM();
  elem = spisok.data;
  for(int i = 0; i < index;i++)
  {
    elem = elem->pNext;
  }
  return elem->data;
}

void AddItem(list &spisok,char data)
{
	ELEM *element = new ELEM();
  element->data = data;
  if(spisok.data == nullptr){
    spisok.data = element;
  }
  else{
    ELEM *elem = new ELEM();
    elem = spisok.data;
    while(elem->pNext != nullptr)
    {
      elem = elem->pNext;
    }
    element->pBack = elem;
    elem->pNext = element;
  }  
}

void PrintList(list &spisok)
{
	ELEM *elem = new ELEM();
  elem = spisok.data;
  while(elem->pNext != nullptr)
  {
    cout << elem->data << ' ';
    elem = elem->pNext;
  }
  cout << elem->data << ' ';
}

void DelItem(list &spisok,int index){
  ELEM *elem = new ELEM();
  elem = spisok.data;
  if(index == 0){
    spisok.data = spisok.data->pNext;
  }
  else{
  for(int i = 0; i < index-1;i++)
  {
    elem = elem->pNext;
  }
  elem->pNext = elem->pNext->pNext;
  elem->pNext->pBack = elem;
  }
}

int main()
{
	list spisok;
  for(int i = 0; i < 10; i++)
    AddItem(spisok,i+2);
  PrintList(spisok);
  int size = 10;
  for(int i = 0;i < size;i++){
    if(Search(spisok,i) % 2 == 0){
      DelItem(spisok,i);
      size--;
      i--;
    }
  }
  cout << endl;
  PrintList(spisok);
	return 0;
}
