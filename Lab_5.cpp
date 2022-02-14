#include <iostream>
using namespace std;
int main()
{
  const int n = 5;
  int a[n][n];
 
  srand(time(0));
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      a[i][j] = rand() % 101;
      cout.width(5);
      cout << a[i][j];
    }
    cout << endl;
  }
  for(int j = 1; j < n; ++j)
  {
    double sum = 0;
    for(int i = 0; i < n; ++i)
      sum += a[i][j-1];
    double average = sum / n;
    int count = 0;
    for(int i = 0; i < n; ++i)
      if(a[i][j] > average)
        ++count;
      cout << "среднее арифметическое элементов " << j << "-го столбца: " << average;
      cout << endl << "количство элементов " << j + 1 << "-го столбца больших " << average;
      cout << ": " << count << endl << endl;
   }
  return 0;
}
