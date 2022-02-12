#include <iostream>
using namespace std;
int i, j, n, d, count;
void Shell(int a[], int n)
{
  d=n;
  d=d/2;
  while (d>0)
  {
    for (i=0; i<n-d; i++)
    {
      j=i;
      while (j>=0 && a[j]>a[j+d])
      {
        count=a[j];
        a[j]=a[j+d];
        a[j+d]=count;
        j--;
      }
    }
    d=d/2;
  }
  for (i=0; i<n; i++) 
    cout<<a[i]<<" ";
}
int main()
{
  setlocale(LC_ALL,"Rus");
  srand(time(0));
  cout<<"Размер массива = "; 
  cin>>n;
  int *a= new int[n];
  for (i=0; i<n; i++)
  {  
    a[i] = rand() % 101;
    cout<<a[i]<<" ";
  }
  cout<<endl<<"Результирующий массив: ";
  Shell(a, n);
  delete [] a;
  return 0;
}