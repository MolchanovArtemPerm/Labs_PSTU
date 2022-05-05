#include <iostream>
using namespace std;
const int Max_size = 6;

class Error {
public:
  virtual void what(){};
};

class IndexError : public Error {
protected:
  string message;

public:
  IndexError() { message = "Index Error\n"; }
  virtual void what() { cout << message; };
};

class SizeError : public Error {
protected:
  string message;

public:
  SizeError() { message = "Size Error\n"; }
  virtual void what() { cout << message; };
};

class MaxSizeError : public SizeError {
protected:
  string message_;

public:
  MaxSizeError() {
    SizeError();
    message_ = "Size > Max\n";
  }
  virtual void what() { cout << message << message_; };
};

class EmptySizeError : public SizeError {
protected:
  string message_;

public:
  EmptySizeError() {
    SizeError();
    message_ = "Vector empty\n";
  }
  virtual void what() { cout << message << message_; };
};

class IndexError1 : public IndexError {
protected:
  string message_;

public:
  IndexError1() {
    IndexError();
    message_ = "Index < 0\n";
  }
  virtual void what() { cout << message << message_; };
};

class IndexError2 : public IndexError {
protected:
  string message_;

public:
  IndexError2() {
    IndexError();
    message_ = "Index > size\n";
  }
  virtual void what() { cout << message << message_; };
};

class Iteration {
  friend class Many;

protected:
  int *elem;

public:
  Iteration() { elem = 0; }
  Iteration(const Iteration &t) { elem = t.elem; }
  bool operator==(const Iteration &t) { return elem == t.elem; }
  bool operator!=(const Iteration &t) { return elem != t.elem; }
  void operator-=(int k) {
    for (int i = 0; i <= k; i++)
      --elem;
  }
  void operator++() { ++elem; }
  int &operator*() { return *elem; }
};

class Many : public Iteration {
protected:
  int size;
  int *data;
  Iteration beg;
  Iteration end;

public:
  Iteration first() { return beg; }
  Iteration last() { return end; }
  Many() {
    size = 0;
    data = 0;
  }
  Many(int s) {
    if (s > Max_size)
      throw MaxSizeError();
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = 0;
    }
    beg.elem = &data[0];
    end.elem = &data[size];
  }
  Many(int s, int *mas) {
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = mas[i];
    }
    beg.elem = &data[0];
    end.elem = &data[size];
  }
  Many(const Many &t) {
    size = t.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = t.data[i];
    }
    beg = t.beg;
    end = t.end;
  }
  ~Many() {
    delete[] data;
    data = 0;
  }
  Many operator--() {
    if (size == 0)
      throw EmptySizeError();
    if (size == 1) {
      size = 0;
      delete[] data;
      data = 0;
      return *this;
    }
    Many temp(size, data);
    delete[] data;
    size--;
    data = new int[size];
    for (int i = 0; i < size; i++)
      data[i] = temp.data[i];
    return *this;
  }
  Many &operator=(const Many &t) {
    if (this == &t)
      return *this;
    if (data != 0)
      delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = t.data[i];
    }
    beg = t.beg;
    end = t.end;
    return *this;
  }
  int &operator[](int index) {
    if (index < 0)
      IndexError1();
    if (index >= size)
      IndexError2();
    if (index >= 0) {
      if (index < size)
        return data[index];
      else
        cout << "Ошибка";
    } else
      cout << "Ошибка";
  }
  Many operator+(const int k) {
    if (size + 1 == Max_size)
      throw MaxSizeError();
    Many temp(size);
    for (int i = 0; i < size; i++) {
      temp.data[i] += data[i] + k;
    }
    return temp;
  }
  bool operator>(const int k) {
    for (int i = 0; i < k; i++) {
      if (data[i] == k)
        return true;
    }
    return false;
  }
  friend istream &operator>>(istream &in, Many &t);
  friend ostream &operator<<(ostream &out, const Many &t);
};

istream &operator>>(istream &in, Many &t) {
  for (int i = 0; i < t.size; i++) {
    in >> t.data[i];
  }
  return in;
}
ostream &operator<<(ostream &out, const Many &t) {
  for (int i = 0; i < t.size; i++) {
    out << t.data[i] << ' ';
  }
  return out;
}

int main() {
  setlocale(LC_ALL, "Rus");
  try {
    Many a(7);
    cin >> a;
    Iteration i = a.last();
    i -= 2;
    cout << endl << *i << endl;
    for (i = a.first(); i != a.last(); ++i)
      cout << *i << ' ';
    cout << endl;
    cout << (a > 2);
  } catch (Error e) {
    e.what();
  }
  return 0;
}
