#include <iostream>
using namespace std;
void shellsort(int *a, int size)
{
  int i,j,t;
  int d=size/2;
  while (d>0)
  {
    for (i=0; i<size-d; i++)
    {
      j=i;
      while (j>=0)
      {
        if(a[j]>a[j+d]){
          t=a[j];
          a[j]=a[j+d];
          a[j+d]=t;
        }
        j--;
      }
    }
    d=d/2;
  }
  cout << endl << endl;
  for (i=0; i<size; i++) 
   cout<<a[i]<<" ";
}
int main()
{
	setlocale(LC_ALL, "ru");
  srand(time(0));
	int const size = 5;
	int* a = new int[size];
	for (int i = 0; i<size; i++){
    a[i] = rand() % 101;
    cout<<a[i] << " ";
  }
	shellsort(a, size);
	delete[] a;
	return 0;
}
