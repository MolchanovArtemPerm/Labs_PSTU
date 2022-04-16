#include <iostream>
using namespace std;

template <class T> class Many;
template <class T> istream& operator>> (istream&, Many<T>&);
template <class T> ostream& operator<< (ostream&, const Many<T>&);

template <class T>
class Many
{
  private:
  int size;
  T* data;
  
  public:
  Many(int s, T k)
  {
    size = s;
    data = new T[size];
    for (int i = 0; i < size; i++)
    data[i] = k;
  }
  Many(const Many<T>& t)
  {
    size = t.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
      data[i] = t.data[i];
  }
  ~Many()
  {
    delete[] data;
    data = 0;
  }
  Many& operator=(const Many<T>& t)
  {
    if (this == &t)
      return *this;
    if (data != 0)
      delete[] data;
    data = new T[size];
    for (int i = 0; i < size; i++)
      data[i] = t.data[i];
    return *this;
  }
  T& operator[](int index)
  {
    if (index >= 0)
    {
      if (index < size)
        return data[index];
      else
        cout << "Ошибка";
    }
    else
      cout << "Ошибка";
  }
  Many operator+(const T& k)
  {
    Many<T> temp(size, k);
    for (int i = 0; i < size; i++)
      temp.data[i] = data[i] + k;
    return temp;
  }
  int operator()()
  {
    return size;
  }
  bool operator>(const T& k)
  {
    for (int i = 0; i < k; i++)
    {
    if (data[i] == k)
      return true;
    }
    return false;
  }
  bool operator==(const T& k)
  {
    for (int i = 0; i < k; i++)
    {
      if (data[i] != k[i])
        return false;
    }
    return true;
  }
  friend istream& operator>> <>(istream& in, Many<T>& t);
  friend ostream& operator<< <>(ostream& out, const Many<T>& t);
};

template <class T>
istream& operator>>(istream& in, Many<T>& t)
{
  for (int i = 0; i < t.size; i++)
    in >> t.data[i];
  return in;
}

template <class T>
ostream& operator<<(ostream& out, const Many<T>& t)
{
  for (int i = 0; i < t.size; i++)
    out << t.data[i] << ' ';
  return out;
}


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
  Money& operator++()
  {
    ++kopecks;
    return *this;
  }
  Money operator++(int)
  {
    Money t(rubles,kopecks);
    ++kopecks;
    return t;
  }
   Money operator+(const Money& t)
  {
    int temp1 = rubles*100 + kopecks;
    int temp2 = t.rubles*100 + t.kopecks;
    Money p;
    p.rubles = (temp1 + temp2) / 100;
    p.kopecks = (temp1 + temp2) % 100;
    return p;
  }
  friend istream& operator>> (istream&in,Money& t);
  friend ostream& operator<< (ostream& out, const Money& t);
};

ostream& operator<< (ostream& out, const Money& t)
{
    return (out<<t.rubles<<","<<t.kopecks);
  }
istream& operator>> (istream&in,Money& t)
{
    cout << "rubles: ";
    in>>t.rubles;
    cout << "kopecks: ";
    in>>t.kopecks;
    return in;
  }

int main()
{
  setlocale(LC_ALL, "Rus");
  Money t;
  cin >> t;
  cout << t << endl;
  Many <Money> a(2,t);
  cin >> a;
  Many <Money> b(4,t);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  b = a;
  cout << "b1 = " << b << endl;
  //cout << "A[2] = " << a[2] << endl;
  //cout << "size = " << a() << endl;
  b = a + t;
  cout << "a + t = " << b;
  return 0;
}
