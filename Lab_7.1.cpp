#include <iostream>
using namespace std;

float Subtraction(float r1, float r2) {
return r1 - r2;
}

double Subtractiond(double r1, double r2) {
return r1 - r2;
}

int main()
{
setlocale(LC_ALL, "RU");
float n1, n2, n3, n4;
cout << "Введи обычную первую дробь:" << endl;
cin >> n1;
cout << "-" << endl;
cin >> n2;
cout << "Введи обычную вторую дробь:" << endl;
cin >> n3;
cout << "-" << endl;
cin >> n4;
n1 = n1 / n2;
n2 = n3 / n4;
cout << "Ответ при вычитании обычных дробей = " << Subtraction(n1,n2) << endl;
double a,b;
cout << "Ведите десятичную дробь"<<endl;
cin >> a >> b;
cout << "Ответ при вычитании десятичных дробей = " << Subtractiond(a,b);
return 0;
}
