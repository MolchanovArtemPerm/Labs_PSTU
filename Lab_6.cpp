#include <iostream>
#include <string>
using namespace std;
int main()
{
  setlocale(LC_ALL, "rus");
  system("chcp1251");
  system("cls");
  int mas[] = { '9', '8', '7', '6', '5', '4', '3', '2', '1', '0' };
  string s ,s1;
  getline(cin, s);
  s = ' ' + s + ' ';
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; s[j] != '\0'; j++)
    {
      if (s[j] == ' ')
      {
        if (s[j + 1] == mas[i])
        {
          while (s[j + 1] != ' ')
          {
            s1 += s[j + 1];
            s.erase(j + 1, 1);
          }
          s.erase(j + 1, 1);
          s1 += ' ';
        }
      }
    }
  }
  s1 += s;
  cout << s1;
  cin.get();
  return 0;
}
