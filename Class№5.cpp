#include <iostream>
using namespace std;

class Object
{
  public:
  Object(){}
  ~Object(){}
  virtual void Show() = 0;
};

class Triad : public Object
{
  protected:
  int first = 0;
  int second = 0;
  int third = 0;

  public:
  Triad(){}; // Конструктор без параметров
  Triad(int first,int second,int third) // Конструктор с параметрами
  {
    this->first = first;
    this->second = second;
    this->third = third;
  }
  Triad(const Triad &t) // Конструктор копирования
  {
    this->first = t.first;
    this->second = t.second;
    this->third = t.third;
  }
  virtual ~Triad(){} // Деструктор
  int Get_first() // Вывод первого
  {
    return first;
  }
  int Get_second() // Вывод второго
  {
    return second;
  }
  int Get_third() // Вывод третьего
  {
    return third;
  }
  void Set_first(int first) // Вставка первого
  {
    this->first = first;
  }
  void Set_second(int second) // Вставка второго
  {
    this->second = second;
  }
  void Set_third(int third) // Вставка третьего
  {
    this->third = third;
  }
  void Show()
  {
    cout << "first = " << first << endl << "second = " << second << endl << "third = " << third;
  }
  void Comparsion()
  {
    if(first > second && first > third)
    {
      cout << "Наибольшее значение у first" << endl;
      if(second > third)
      {
        cout << "Среднее значение у second" << endl;
        cout << "Наименьшее значение у third" << endl;
      }
      else
      {
        cout << "Наименьшее значение у second" << endl;
        cout << "Среднее значение у third" << endl;
      }
    }
    if(second > first && second > third)
    {
      cout << "Наибольшее значение у second" << endl;
      if(first > third)
      {
        cout << "Среднее значение у first" << endl;
        cout << "Наименьшее значение у third" << endl;
      }
      else
      {
        cout << "Наименьшее значение у first" << endl;
        cout << "Среднее значение у third" << endl;
      }
    }
    if(third > first && third > second)
    {
      cout << "Наибольшее значение у third" << endl;
      if(first > second)
      {
        cout << "Среднее значение у first" << endl;
        cout << "Наименьшее значение у second" << endl;
      }
      else
      {
        cout << "Наименьшее значение у second" << endl;
        cout << "Среднее значение у first" << endl;
      }
    }
  }
  Triad& operator=(const Triad& t);
  friend istream& operator>>(istream&in,Triad& t);
  friend ostream& operator<<(ostream&out, const Triad& t);
};

Triad& Triad::operator=(const Triad &t) // Перегрузка присвоения
{
  if(&t == this)
    return *this;
  first = t.first;
  second = t.second;
  third = t.third;
  return *this;
}
ostream&operator<<(ostream&out, const Triad& t) // Перегрузка вывода
{
  return (out << "first = " << t.first << endl << "second = " << t.second << endl << "third = " << t.third);
}
istream&operator>>(istream&in,Triad& t) // Перегрузка ввода
{
  cout << "first: ";
  in>>t.first;
  cout << "second: ";
  in>>t.second;
  cout << "third: ";
  in>>t.third;
  return in;
}

class Date: public Triad
{
  public:
  Date(){}; // Конструктор без параметров
  Date(int first,int second,int third) // Конструктор с параметрами
  {
    this->first = first;
    this->second = second;
    this->third = third;
  }
  Date(const Date &t) // Конструктор копирования
  {
    this->first = t.first;
    this->second = t.second;
    this->third = t.third;
  }
  virtual ~Date(){} // Деструктор
  void Show()
  {
    cout << "День = " << first << endl << "Месяц = " << second << endl << "Год = " << third;
  }
  int Get_first() // Вывод дня
  {
    return first;
  }
  int Get_second() // Вывод месяца
  {
    return second;
  }
  int Get_third() // Вывод года
  {
    return third;
  }
  void Set_first(int first) // Вставка дня
  {
    bool f = false; // можно через do while лень переделывать
    while(!f)
    {
      if(first > 0 && first <= 30)
      {
        this->first = first;
        f = true;
      }
      else
        cout << "Не правильно указан день." << endl;
    }
  }
  void Set_second(int second) // Вставка месяца
  {
    bool f = false; // можно через do while лень переделывать
    while(!f)
    {
      if(second > 0 && second <= 12)
      {
        this->second = second;
        f = true;
      }
      else
        cout << "Не правильно указан месяц." << endl;
    }
  }
  void Set_third(int third) // Вставка года
  {
    bool f = false; // можно через do while лень переделывать
    while(!f)
    {
      if(third >= 0)
      {
        this->third = third;
        f = true;
      }
      else
        cout << "Не правильно указан год." << endl;
    }
  }
  bool operator>(const Date& t)
  {
    if(third > t.third)
      return true;
    else if(third < t.third)
      return false;
    else
    {
      if(second > t.second)
        return true;
      else if(second < t.second)
        return false;
      else
      {
        if(first > t.first)
          return true;
        else if(first < t.first)
          return false;
        else
          return false;
      }
    }
  }
  bool operator<(const Date& t)
  {
    if(third > t.third)
      return false;
    else if(third < t.third)
      return true;
    else
    {
      if(second > t.second)
        return false;
      else if(second < t.second)
        return true;
      else
      {
        if(first > t.first)
          return false;
        else if(first < t.first)
          return true;
        else
          return false;
      }
    }
  }
  bool operator==(const Date& t)
  {
    if(third > t.third)
      return false;
    else if(third < t.third)
      return false;
    else
    {
      if(second > t.second)
        return false;
      else if(second < t.second)
        return false;
      else
      {
        if(first > t.first)
          return false;
        else if(first < t.first)
          return false;
        else
          return true;
      }
    }
  }
  Date& operator=(const Date& t);
  friend istream& operator>>(istream&in,Date& t);
  friend ostream& operator<<(ostream&out, const Date& t);
};

Date& Date::operator=(const Date &t) // Перегрузка присвоения
{
  if(&t == this)
    return *this;
  first = t.first;
  second = t.second;
  third = t.third;
  return *this;
}
ostream&operator<<(ostream&out, const Date& t) // Перегрузка вывода
{
  return (out << "День = " << t.first << endl << "Месяц = " << t.second << endl << "Год = " << t.third);
}
istream&operator>>(istream&in,Date& t) // Перегрузка ввода
{
  do{
    cout << "День: ";
    in>>t.first;
    if(t.first < 0 || t.first > 31)
      cout << "Не правильно указан день." << endl;
  }while(t.first < 0 || t.first > 31);
  do{
    cout << "Месяц: ";
    in>>t.second;
    if(t.second < 0 || t.second > 12)
      cout << "Не правильно указан месяц." << endl;
  }while(t.second < 0 || t.second > 12);
  do{
    cout << "Год: ";
    in>>t.third;
    if(t.third < 0)
      cout << "Не правильно указан год." << endl;
  }while(t.third < 0);
  return in;
}

class Vector
{
  private:
  Object**beg;
  int size;
  int current;

  public:
  Vector()
  {
    beg = 0;
    size = 0;
    current = 0;
  }
  Vector(int n)
  {
    beg = new Object* [n];
    current = 0;
    size = n;
  }
  ~Vector()
  {
    if(beg!=0)
      delete [] beg;
    beg = 0;
  }
  void Add(Object *p)
  {
    if(current < size)
    {
      beg[current] = p;
      current++;
    }
  }
  friend ostream&operator<<(ostream&out,const Vector&);
};

ostream&operator<<(ostream&out, const Vector& v)
{
  if(v.size == 0)
    out << "Пусто";
  Object** p = v.beg;
  for(int i = 0;i < v.current;i++)
  {
    (*p)->Show();
    cout << endl;
    p++;
  }
  return out;
}

int main()
{
  setlocale(LC_ALL,"Rus");
  Vector v(5);
  Triad a;
  cin >> a;
  Object* p = &a;
  v.Add(p);
  Date b;
  cin >> b;
  p = &b;
  v.Add(p);
  cout << endl << endl << v;
  return 0;
}
