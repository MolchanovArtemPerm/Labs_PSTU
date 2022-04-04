#include <iostream>
using namespace std;

class Money{
  private:
    long int rubles;
    int kopecks;
  public:

  Money() // Конструктор
  {
    this->rubles = 0;
    this->kopecks = 0;
  }
  Money(long rubles,int kopecks) // Конструктор с параметрами
  {
    this->rubles = rubles;
    this->kopecks = kopecks;
  }
  Money(const Money &t) // Конструктор копирования
  {
    this->rubles = t.rubles;
    this->kopecks = t.kopecks;
  }
  ~Money() // Деструктор
  {
  }
  int Get_rubles() // Вывод рубля
  {
    return rubles;
  }
  int Get_kopecks() // Вывод копейки
  {
    return kopecks;
  }
  void Set_rubles(int NewRubles)
  {
    rubles = NewRubles;
  }
  void Set_kopecks(int NewKopecks)
  {
    kopecks = NewKopecks;
  }
  Money operator++();
  Money operator++(int);
  Money operator+(const Money& t);
  bool operator<(const Money& t);
  bool operator>(const Money& t);
  bool operator==(const Money& t);
  friend istream& operator>>(istream&in,Money& t);
  friend ostream& operator<<(ostream&out, const Money& t);
};

  bool Money::operator<(const Money& t)
  {
    if(this->rubles < t.rubles)
      if(this->kopecks < t.kopecks)
        return true;
    else
      return false;
  }
  bool Money::operator==(const Money& t)
  {
    if(this->rubles == t.rubles)
      if(this->kopecks == t.kopecks)
        return true;
    else
      return false;
  }

  bool Money::operator>(const Money& t)
  {
    if(this->rubles > t.rubles)
      if(this->kopecks > t.kopecks)
        return true;
    else
      return false;
  }
  
  Money Money::operator++()
  {
    int temp = rubles*100 + kopecks;
    ++temp;
    rubles = temp / 100;
    kopecks = temp % 100;
    return *this;
  }

  Money Money::operator++(int)
  {
    int temp = rubles*100 + kopecks;
    temp++;
    Money t(rubles,kopecks);
    rubles = temp / 100;
    kopecks = temp % 100;
    return t;
  }

  Money Money::operator+(const Money& t)
  {
    int temp1 = rubles*100 + kopecks;
    int temp2 = t.rubles*100 + t.kopecks;
    Money p;
    p.rubles = (temp1 + temp2) / 100;
    p.kopecks = (temp1 + temp2) % 100;
    return p;
  }

  ostream&operator<<(ostream&out, const Money& t)
  {
    return (out<<t.rubles<<","<<t.kopecks);
  }

  istream& operator>>(istream&in,Money& t)
  {
    cout << "rubles: ";
    in>>t.rubles;
    cout << "kopecks: ";
    in>>t.kopecks;
    return in;
  }
int main()
{
  Money a;
  Money b;
  Money c;
  Money d;
  cin>>a;
  cin>>b;
  ++a;
  c = b++;
  d = a + c;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  bool result1 = a < b;
  bool result2 = d > a;
  bool result3 = a == c;
  cout << "< : " << result1 << endl;
  cout << "> : " << result2 << endl;
  cout << "== : " << result3 << endl;
  return 0;
}
