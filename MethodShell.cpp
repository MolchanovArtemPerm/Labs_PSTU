#include <iostream>
using namespace std;
int shell(int *a,int size) {
	int t;
	int d = (size+1) / 2;
	while (d > 0) {
		for (int i = 0; i < size - d; i++) {
			if (a[i] > a[i + d]) {
				t = a[i + d];
				a[i + d] = a[i];
				a[i] = t;
			}
		}
		d = d / 2;
	}
  cout << endl << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << ' ';
	return 0;
}
int main()
{
	setlocale(LC_ALL, "ru");
  srand(time(0));
	int const size = 7;
	int* a = new int[size];
	for (int i = 0; i<size; i++){
    a[i] = rand() % 101;
    cout<<a[i] << " ";
  }
	shell(a, size);
	delete[] a;
	return 0;
}
