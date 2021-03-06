#include <iostream>
using namespace std;

int interpol(char* mass,int size,char key)
{
  int left = 0;
  int right = size-1;
  int mid = 0;
  bool f = false;
  while((left <= right) && f != true)
  {
    mid = left + ((key - mass[left])*(right - left)) / (mass[right] - mass[left]);
    cout << mid;
    if(mass[mid] < key)
      left = mid + 1;
    else if(mass[mid] > key)
      right = mid + 1;
    else
      f = true;
  }
  if (mass[left] == key)
    return left;
  else if(mass[right] == key)
    return right;
  else 
    return mid;
}

int main(){
  setlocale(LC_ALL,"Rus");
  system("chcp1251");
  system("cls");
  int size = 6;
  char *mass = new char[size];
  char *mass2 = new char[size];
  char n;
  for(int i = 0; i < size; i++)
  {
    cout << "Введите любое значение: ";
    cin >> n;
    mass[i] = n;
  }
  char zam;
  for (int i = 0; i < size - 1; i++) 
  {
    for (int j = size - 1; j > i; j--) 
    {
      if (mass[j] < mass[j - 1])
      {
        zam = mass[j - 1];
        mass[j - 1] = mass[j];
        mass[j] = zam;
      }
    }
  }
  for(int i = 0; i < size; i++)
    cout << mass[i] << ' ';
  cout << endl << endl;
  int temp = interpol(mass,size,'a');
  cout << temp << endl;
  size++;
  for(int i = 0; i <= temp; i++)
    mass2[i] = mass[i];
  mass2[temp+1] = 'E';
  for(int i = temp+2; i < size; i++)
    mass2[i] = mass[i-1];
  for(int i = 0; i < size; i++)
    cout << mass2[i] << ' ';
  return 0;
}
