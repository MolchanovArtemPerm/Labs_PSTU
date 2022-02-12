#include <iostream>
using namespace std;
void hoarasort(double* a, int first, int last)
{
  int i = first, j = last;
  double tmp, x = a[(first + last) / 2];
  do {
    while (a[i] < x)
      i++;
    while (a[j] > x)
      j--;
  
    if (i <= j) 
    {
      if (i < j)
      {
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
      }
      i++;
      j--;
    }
  } while (i <= j);
  
  if (i < last)
    hoarasort(a, i, last);
  if (first < j)
    hoarasort(a, first,j);
}
int main()
{
  setlocale(LC_ALL,"Rus");
  srand(time(0));
  int size;
  cout<<"Размер массива = "; 
  cin>>size;
  double a[size];
  for (int i = 0; i<size; i++){
    a[i] = rand() % 101;
    cout<<a[i] << " ";
  }
  cout<<endl<<endl;
  hoarasort(a, 0, size-1);
  for (int i = 0; i<size ; i++){
    cout<<a[i] << " ";
  }
  return 0;
}