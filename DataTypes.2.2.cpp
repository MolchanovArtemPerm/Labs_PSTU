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
    cout << "������� ������ � �����,������� � ��������: " << endl;
    cin >> h1;
    cin >> m1;
    cin >> s1;
    cout << "������� ����� � �����,������� � ��������: " << endl;
    cin >> h2;
    cin >> m2;
    cin >> s2;
    h1 = h2 - h1;
    m1 = m2 - m1;
    s1 = s2 - s1;
cout << "������� ����� ������� � ������ ������� ����������: " << h1 << " ����� " << m1 << " ����� " << s1 << " ������.";
}
