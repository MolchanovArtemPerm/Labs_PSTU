#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    string number;
    bool f = false;
    do {
        cout << "Введите число от 100 до 999: " << endl;
        cin >> number;
        if(number[0] != '0' && number.length() == 3)
        {
            f = true;
        }
        if(!f)
        {
           cout << "Число " << number << " не удовлетворяет условию. Повторите с другим числом." << endl; 
        }
    }while (!f);
    int a = stoi(number) / 100;
    int b = ((stoi(number)) / 10) % 10;
    int c = stoi(number) % 10;
    if ((a != b) && (b != c) && (a != c))
    {
        cout << a << b << c << endl;
        cout << a << c << b << endl;
        cout << b << a << c << endl;
        cout << b << c << a << endl;
        cout << c << a << b << endl;
        cout << c << b << a << endl;
    }
    if ((a > b) && (a > c)) 
		{
			if (b > c) { 
				cout << "Максимальное число:  " << a << b << c << endl; 
			}
			else
			{
				cout << "Максимальное число: " << a << c << b << endl;	
			}
		}
	if ((b > a) && (b > c)) 
	{
		if (a > c) 
		{
			cout << "Максимальное число: " << b << a << c << endl; 
		}
		else
		{
			cout << "Максимальное число: " << b << c << a << endl;
		}
	}
	if ((c > a) && (c > b)) 
	{
		if (a > b) 
		{
			cout << "Максимальное число: " << c << a << b << endl;
		}
		else		
		{
		cout << "Максимальное число: " << c << b << a << endl;
		}
	}
}
