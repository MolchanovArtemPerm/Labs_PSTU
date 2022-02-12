#include <iostream>
using namespace std;

int main()
{
  const int n = 6;
  int a[n] = {4,1,2,6,5,9};
  for(int i = 0;i < n;i++)
  {
    cout<<a[i];
  }
  cout<<endl<<endl;
  for(int i = 1;i<n;i++)
  {
    int y = a[i];
    int j=i-1;
    bool f;
    for (int i = 1; i < n; ++i)
    {
        j = i - 1;
        y = a[i];
        f = false;
        while ((j >= 0) && (!f))
        {
            if (y < a[j])
            {
                a[j + 1] = a[j];
                --j;
            }
            else
                f = true;
        }
        a[j + 1] = y;
    }
  }
  for(int i = 0;i < n;i++)
  {
    cout<<a[i];
  }
  return 0;
}