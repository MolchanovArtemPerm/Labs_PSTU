#include <iostream>
using namespace std;
int main()
{
    int f;
    int c;
    cout << "Введите температуру по Фаренгейту: ";
    cin >> f;
    c = (5 * (f - 32))/9;
    cout << f << " градусов по Фаренгейту = " << c << " градусов по Цельсию.";
}
