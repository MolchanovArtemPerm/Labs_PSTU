#include <iostream>
using namespace std;
int main()
{
    int f,c; //Инициалиризую целочисленный тип f,c
    cout << "Введите температуру по Фаренгейту: "; //Вывод на экран
    cin >> f; //Ввод строки пользователя для f
    c = (5 * (f - 32))/9; //Уравнения заданное для нахождения Цельсия
    cout << f << " градусов по Фаренгейту = " << c << " градусов по Цельсию."; //Вывод на экран
}
