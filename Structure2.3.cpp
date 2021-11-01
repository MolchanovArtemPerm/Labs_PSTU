#include <iostream>
using namespace std;
int main()
{
    const int i = 10;
    int p = i + i;
    int g = p;
    cout << i << endl << p << endl << --p;
}
