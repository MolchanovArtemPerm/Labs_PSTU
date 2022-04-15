#include <iostream>
using namespace std;

class Iteration
{
  friend class Many;
  private:
  int *elem;

  public:
  Iteration()
  {
    elem = 0;
  }
  Iteration(const Iteration& t)
  {
    elem = t.elem;
  }
  bool operator==(const Iteration& t)
  {
    return elem == t.elem;
  }
  bool operator!=(const Iteration& t)
  {
    return elem != t.elem;
  }
  void operator-=(int k)
  {
    for(int i = 0; i <= k;i++)
      --elem;
  }
  void operator++()
  {
    ++elem;
  }
  void operator--()
  {
    --elem;
  }
  int& operator*()
  {
    return *elem;
  }
};

class Many
{
  private:
  int size;
  int* data;
  Iteration beg;
  Iteration end;

  public:
  Iteration first()
  {
    return beg;
  }
  Iteration last()
  {
    return end;
  }
  Many(int s,int k = 0)
  {
    size = s;
    data = new int[size];
    for(int i = 0;i < size;i++)
    {
      data[i] = k;
    }
    beg.elem = &data[0];
    end.elem = &data[size];
  }
  Many(const Many& t)
  {
    size = t.size;
    data = new int[size];
    for(int i = 0;i < size;i++)
    {
      data[i] = t.data[i];
    }
    beg = t.beg;
    end = t.end;
  }
  ~Many()
  {
    delete [] data;
    data = 0;
  }
  Many& operator=(const Many& t)
  {
    if(this == &t)
      return *this;
    if(data != 0)
      delete [] data;
    data = new int[size];
    for(int i = 0;i < size;i++)
    {
      data[i] = t.data[i];
    }
    beg = t.beg;
    end = t.end;
    return *this;
  }
  int& operator[](int index)
  {
    if(index >= 0)
    {
      if(index < size)
        return data[index];
      else
        cout << "Ошибка";
    }
    else
      cout << "Ошибка";
  }
  Many operator+(const int k)
  {
    Many temp(size);
    for(int i = 0;i < size;i++)
    {
      temp.data[i] += data[i] + k;
    }
    return temp;
  }
  int& operator()()
  {
    return size;
  }
  bool operator>(const int k)
  {
    for(int i = 0;i < k;i++)
    {
      if(data[i] == k)
        return true;
    }
    return false;
  }
  friend istream& operator>>(istream&in,Many& t);
  friend ostream& operator<<(ostream&out, const Many& t);
};

istream& operator>>(istream&in,Many& t)
{
  for(int i = 0;i < t.size;i++)
  {
    in >> t.data[i];
  }
  return in;
}
ostream& operator<<(ostream&out, const Many& t)
{
  for(int i = 0;i < t.size;i++)
  {
    out << t.data[i] << ' ';
  }
  return out;
}

int main()
{
  setlocale(LC_ALL,"Rus");
  Many a(5);
  cout << a() << endl;
  cin >> a;
  a[3] = 100;
  cout << a;
  Iteration i = a.last();
  i -= 2;
  cout << endl << *i << endl;
  for(i = a.first();i != a.last();++i)
    cout << *i << ' ';
  cout << endl;
  cout << (a > 2);
  return 0;
}
