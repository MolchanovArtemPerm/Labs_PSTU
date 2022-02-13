#include <iostream>
using namespace std;
int z,p;
void delElement(int *a,int size){
  int k,c;
  bool f = false;
  cout<<"Введите элемент который нужно удалить: ";
  cin>>z;
  for (int i = 0; !f ; i++)
  {
    if (a[i] == z){
      k = i;
      f = true;
    }
  }
  for(int i = k; i < size-1; i++){
    a[i]=a[i+1];
  }
  for (int i = 0; i < size-1 ; i++){
    cout << a[i] << " ";
  }
  cout<<endl<<endl<<"Введите индекс на который нужно вставить элемент: "; 
  cin>>p;
  a[p]=z;
  for (int i = 0; i < size-1 ; i++){
    cout << a[i] << " ";
  }
}
int main()
{
  setlocale(LC_ALL,"Rus");
  srand(time(0));
  int const size = 7;
  int *a = new int[size];
  for (int i = 0; i < size; i++){
    a[i] = rand() % 100;
    cout << a[i] << " ";
  }
  cout<<endl<<endl;
  delElement(a,size);
  return 0;
}
