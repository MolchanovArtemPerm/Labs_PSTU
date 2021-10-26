#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    const int trypoint = rand() % 100;
    const int maxpoint = 6;

    cout << "Угадайте загаданное число в диапозоне от 1 до 100" << endl;

    int maxpoints = 0;
    int trys = 0;

    while(maxpoints < maxpoint && trys!= trypoint)
    {
        cout << maxpoints + 1 << ". Введите число: " << endl;

        cin >> trys;

        if(trys != trypoint)
            cout << "Загаданное число " << ((trys < trypoint) ? "больше" : "меньше") << " " << trys << endl;

        maxpoints++;
    }

    if(trys == trypoint)
        {
            cout << "С " << maxpoints << " Попытки" <<
            " Вы смогли отгадать загаданное число: " << trypoint << endl;
        }
    else
       {
           cout << "за отведенные " << maxpoint << " попыток Вы не смогли отгадать число: " 
            << trypoint << endl;
       }
}
