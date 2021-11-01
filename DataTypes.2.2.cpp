#include <iostream>
using namespace std;
int main()
{
    int h1;
    int m1;
    int s1;
    int h2;
    int m2;
    int s2;
    cout << "Введите начало в часах,минутах и секундах: " << endl;
    cin >> h1;
    cin >> m1;
    cin >> s1;
    cout << "Введите конец в часах,минутах и секундах: " << endl;
    cin >> h2;
    cin >> m2;
    cin >> s2;
    h1 = h2 - h1;
    m1 = m2 - m1;
    s1 = s2 - s1;
cout << "Разница между началом и концом времени составляет: " << h1 << " часов " << m1 << " минут " << s1 << " секунд.";
}
