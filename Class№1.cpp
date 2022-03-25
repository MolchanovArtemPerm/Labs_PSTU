#include <iostream>
#include <cmath>
using namespace std;
class Function
{
  private:
    double first = 0;
    double second = 0;
  public:
  void Print()
  {
    cout << "x = " << first << endl << "y = " << second << endl;
  }
  void Set(double SetX,double SetY)
  {
    first = SetX;
    second = SetY;
  }
  double Distance(double x1,double y1)
  {
    double x = first - x1;
    double y = second - y1;
    double dis = pow(x * x + y * y,0.5);
    return dis;
  }
};
int main() {
  setlocale(LC_ALL,"Rus");
  Function a;
  a.Set(2,3);
  a.Print();
  cout << "Дистанция между точек = " << a.Distance(4,6);
  return 0;
}
