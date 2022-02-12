#include <iostream>
using namespace std;
 
void bubbleSort(int mas[], const int size)
{
  int zam = 0;
  for (int i = 0; i < size - 1; i++) 
  {
    for (int j = size - 1; j > i; j--) 
    {
      if (mas[j] < mas[j - 1])
        {
          zam = mas[j - 1];
          mas[j - 1] = mas[j];
          mas[j] = zam;
        }
    }
  }
}
 
int main()
{ 
  setlocale(LC_ALL, "rus");
  srand(time(0));
  const int size = 5;
  int mas[size];
  for (int i = 0; i < size; i++)
  {
    mas[i] = rand() % 101; 
    cout << mas[i] << endl;
  }
  
  bubbleSort(mas, size);
  
  cout << endl << "Массив после сортировки:"<< endl;
  for (int i = 0; i < size; i++)
  {
    cout << mas[i] << endl;
  }
  return 0;
}