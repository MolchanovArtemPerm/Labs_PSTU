#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  setlocale(LC_ALL, "Ru");
  system("chcp1251");
  system("cls");
  int size = 0;
  char mass[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  string row,stroka;
  ifstream input("File1.txt");
  ofstream output("File2.txt");
  int q = 0;
  while(!input.eof())
  {
    getline(input, row);
    for (int i=0; row[i]!=' ';i++)
    {
        stroka = stroka + row[i];
        row.erase(i,1);
        i--;
    }
    if(row.find(stroka)!= -1)
    {
        output << stroka+row << endl;
        size++;
    }
    stroka = "";
  }
  input.close();
  output.close();
  ifstream input2("File2.txt");
  for(int i = 0; i < size ; i++)
  {
    getline(input2, row);
  }
  for(int i = 0; i < row.length();i++)
  {
    for(int j = 0; j < 42;j++)
    {
      if(row[i] == mass[j])
      {
        q++;
      }
    }
  }
  cout << "Согласных в последней строке файла = " << q;
  input2.close();
  return 0;
}
