#include <iostream>
#include <string.h>
using namespace std;

int* prefixFunction(const string& strl){
  int length = strl.size();
  int* prefixMap = new int[length] {0};
  string prefix, suffix;
  int maxEqual;
  for(int i = 0; i < length; ++i){
    maxEqual = 0;
    for(int j = 1; j <= i; j++){
      prefix = strl.substr(0, j);
      suffix = strl.substr(i - j + 1, j);
      if(prefix == suffix) maxEqual = max(maxEqual, j);
    }
    prefixMap[i] = maxEqual;
  }
  return prefixMap;
}

int Search(const string& str,const string& strl)
{
  int strsize = str.size();
  int strlsize = strl.size();
  int *prefixMap = prefixFunction(strl);
  for(int i = 0, j = 0; i < strsize; i++, j++)
  {
    if(str[i] != strl[j])
    {
      if(j != 0)
        j = prefixMap[j - 1];
      else
        --j;
    }
    if(j == (strlsize - 1))
      return i - j;
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
  int* prefixMap = prefixFunction(strl);
  cout << endl << endl << "Индекс первого символа подстроки в строке: " << Search(str,strl) << endl;
  return 0;
}
