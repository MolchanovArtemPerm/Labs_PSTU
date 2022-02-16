#include <iostream>
using namespace std;
int size = 5;
void del(int *steck,int size)
{
  cout << endl << "Стек состоит из:" << endl;
  for (int i = 0; i < size-1 ; i++)
  {
    cout << steck[i] << " ";
  }
}

void dob(int *steck,int size)
{
  int temp,zam;
  cout << endl << "Введите число для добавления в стек: " << endl;
  cin >> temp;
  for(int i = size; i > 0; i--)
  {
    steck[i] = steck[i-1];
  }
  steck[0] = temp;
  cout << endl << "Стек состоит из:" << endl;
  for (int i = 0; i < size ; i++)
  {
    cout << steck[i] << " ";
  }
}

int main()
{
  setlocale(LC_ALL,"Rus");
  int* steck = new int[size];
  int s,e;
  bool f = true;
  cout << "Введите элемент для заполнение стека" << endl;
  for (int i = 0; i < size; ++i) 
  {
    cin >> e;
    steck[i] = e;
  } 
  cout << endl << "Стек состоит из: " << endl;
  for (int i = 0; i < size; ++i) 
  {
    cout << steck[i] << " ";
  }
  while(f)
  {
    cout << endl << endl
    << "Выберете операцию:\n"
    << "1. Удаление элемента\n"
    << "2. Добавление элемента\n"
    << "3. Остановка" << endl;
    cout << "Ваш выбор: ";
    cin >> s;
    switch(s)
    {
      case 1:
      {
        del(steck,size);
        size--;
        break;
      }
      case 2:
      {
        size++;
        dob(steck,size);
        break;
      }
      case 3: 
      {
        f = false; 
        break;
      }
      default: 
      {
      cout << "ERORR" << endl << "Введите значение из списка " ;
      }
    }
  }
  return 0;
}
