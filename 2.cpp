#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    const int number = rand() % 100;
    const int maxpoint = 6;
    cout << "Угадайте загаданное число в диапозоне от 1 до 100" << endl;
    int point = 0;
    int trys = 0;
    while(point < maxpoint && trys!= number)
    {
        cout << point + 1 << ". Введите число: " << endl;
        cin >> trys;
        if(trys != number)
        {
            cout << "Загаданное число " << ((trys < number) ? "больше" : "меньше") << " " << trys << endl;
        }
        point = point + 1;
    }
    if(trys == number)
        {
            cout << "С " << point << " Попытки" <<
            " Вы смогли отгадать загаданное число: " << number << endl;
        }
    else
       {
           cout << "За отведенные " << maxpoint << " попыток Вы не смогли отгадать число: " 
            << number << endl;
       }
}
