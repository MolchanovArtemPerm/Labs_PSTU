#include <iostream>
#include <string>
using namespace std;

int GetShift(const string& strl,char symbol)
{
  if(strl[strl.size() - 1] == symbol)
    return strl.size();
  int count = 1;
  for(int i = strl.size() - 2; i >= 0; i--)
  {
    if(strl[i] == symbol)  
      return count;
    count++;
  }
  return strl.size();
}

int Search(const string& strl,const string& str,int size)
{
  int n = strl.size();
  bool f;
  for(int i = 0;i < size;)
  {
    f = false;
    for(int j = n - 1;(j >= 0) && (!f);j--)
    {
      if(strl[j] != str[i+j])
      {
        i += GetShift(strl,str[i+j]);
        f = true;
      }
    }
    if(!f)
      return i;
  }
  return -1;
}

int main()
{
  setlocale(LC_ALL,"Rus");
  system("chcp 1251");
  system("cls");
  string str,strl;
  int size = 15;
  srand(time(0));
  for(int i = 0; i < size; i++)
  {
    char s = rand() % 25 + 97;
    str += s;
  }
  cout << str << endl;
  cout << "Введите искомую строку: ";
  getline(cin,strl);
  int j = Search(strl,str,size);
  cout << j << endl;
  str.erase(j,strl.size());
  cout << str;
  return 0;
}
