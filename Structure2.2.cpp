#include <iostream>
using namespace std;
int main()
{
    const double g = 7.481;
    int f;
    cout << "Введите число галлонов: " << endl;
    cin >> f;
    cout << "Объем " << f << " галлонов в кубических футах = " << f / g;
}
