#include <iostream>
using namespace std;
int main()
{
  setlocale(LC_ALL,"Ru");
  int const size = 4;
  int a[size][size]; 
  int K, L;
  srand(time(0));
  cout << "Исходная матрица:" << endl;
  for(int i = 0; i < size; ++i)
  {
    for(int j = 0; j < size; ++j)
    {
      a[i][j] = rand() % 101;
      cout.width(5);
      cout << a[i][j];
    }
    cout << endl;
  }
  cout << "Введите номер столбца от 1 до 4" << endl;
  cin >> K;
  cout << "Введите номер строки от 1 до 4" << endl;
  cin >> L;
  --K;
  --L;
  cout << endl << endl;
  if ( K == L)
  {
    int temp;
    for(int i = 0; i< size; i++)
    {
      for(int j = 0; j< size; j++)
      {
        temp = a[i][K];
        a[i][K] = a[L][j];
        a[L][j] = temp;
        i++;
      }
    }
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        cout.width(5);
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
  else if (size - 1 - L == K)
  {
    int temp;
    for(int i = 0; i< size; i++)
    {
      temp = a[i][K];
      a[i][K] = a[L][size-1-i];
      a[L][size-1-i] = temp;
    }
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        cout.width(5);
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
  else
  {
    int temp;
    int a2[size];
    for(int i = 0; i < size; i++)
    {
      a2[i]=a[L][i];
    }
    if ( K < L)
    {
      for(int i = K; i < L; i++)
      {
        int zam;
        zam = a2[i];
        a2[i] = a2[i+1];
        a2[i+1] = zam;
      }
    }
    else
    {
      for(int i = L; i < K; i++)
      {
        int zam;
        zam = a2[i];
        a2[i] = a2[i+1];
        a2[i+1] = zam;
      }
    }
    for(int i = 0; i< size; i++)
    {
      temp = a[i][K];
      a[i][K] = a[L][size-1-i];
      a[L][size-1-i] = temp;
    }
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        cout.width(5);
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
