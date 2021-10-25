#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number = "";

    bool f = false;

    do {
        cout << "Введите число от 100 до 999: " << endl;

        cin >> number;

        if(number[0] != '0' && number.length() == 3)
        {
            f = number[0] != number[1] && number[0] != number[2] && number[1] != number[2];

            for(int i = 0; i < number.length() && f; i++);
                
        }

        if(!f)
            cout << "Число " << number
                        << " Число не соответстует условиям. Введите новое число по условям." << endl;
    } while(!f);

    int max = 0;
    string s;
    for(int i = 0, a; i < number.length(); i++)
    {
        if(number[i] != '0')
            s.append(number.substr(i, 1));

        for(int j = 0; j < number.length(); j++)
        {

            if(number[i] != number[j]) {
                s.append(number.substr(j, 1));

                for(int x = 0; x < number.length(); x++)
                {
                    if(number[i] != number[x] && number[j] != number[x])
                    {
                        s.append(number.substr(x, 1));

                        cout << s << endl;

                        if(max < atoi(s.c_str()))
                            max = atoi(s.c_str());

                        s.erase(s.length() - 1);
                    }
                }

                s.erase(s.length() - 1);
            }
        }

        s.clear();
    }

    cout << "Максимальное число " << max << endl;
}
