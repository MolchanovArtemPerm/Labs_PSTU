#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL,"Rus");
  srand(time(0));
  int size;
  cout<<"Размер массива: "; 
  cin>>size;
  int a[size];
  for (int i = 0; i < size; i++){
    a[i] = rand() % 100;
    cout << a[i] << " ";
  }
  cout<<endl<<endl;
	for (int i = 0; i < size - 1; ++i)
	{
		int small = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (a[j] < a[small])
				small = j;
		} 
		swap(a[i], a[small]);
	}
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";
	return 0;
}