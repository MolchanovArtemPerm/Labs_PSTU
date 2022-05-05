#include <iostream>
#include <string>
using namespace std;

class Abiturient;
class Person;
class Vector;
class Dialog;
struct TEvent;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmMid = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;

struct TEvent {
  int what;
  int command;
};

class Object {
public:
  Object(){};
  virtual void Show() = 0;
  virtual void Input() = 0;
  virtual int Get_age() = 0;
  virtual ~Object(){};
};

class Person : public Object {
protected:
  string name;
  int age;

public:
  // Конструкторы
  Person() {
    name = "NULL";
    age = 0;
  }
  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }
  Person(const Person &t) {
    this->name = t.name;
    this->age = t.age;
  }
  virtual ~Person() {}
  // Модификаторы
  void Set_name(string name) { this->name = name; }
  void Set_age(int age) { this->age = age; }
  // Селекторы
  string Get_name() { return name; }
  int Get_age() { return age; }
  Person &operator=(const Person &t) {
    if (&t == this)
      return *this;
    name = t.name;
    age = t.age;
    return *this;
  }
  void Show() { cout << endl << "Имя: " << name << "\nВозраст: " << age; }
  void Input() {
    cout << endl << "Введите имя: ";
    cin >> name;
    cout << "Возраст: ";
    cin >> age;
  }
};

class Abiturient : public Person {
protected:
  int point;
  string speciality;

public:
  // Конструкторы
  Abiturient() {
    point = 0;
    speciality = "NULL";
  }
  Abiturient(int point, string speciality) {
    this->point = point;
    this->speciality = speciality;
  }
  Abiturient(const Abiturient &t) {
    point = t.point;
    speciality = t.speciality;
  }
  ~Abiturient(){};
  // Модификаторы
  void Set_point(int point) { this->point = point; }
  void Set_speciality(string speciality) { this->speciality = speciality; }
  // Селекторы
  int Get_point() { return point; }
  string Get_speciality() { return speciality; }
  Abiturient &operator=(const Abiturient &t) {
    if (&t == this)
      return *this;
    point = t.point;
    speciality = t.speciality;
    return *this;
  }
  void Show() {
    cout << endl
         << "Баллы: " << point << endl
         << "Специальность: " << speciality;
  }
  void Input() {
    cout << endl << "Введите количество баллов: ";
    cin >> point;
    cout << "Введите специальность: ";
    cin >> speciality;
  }
};

class Vector {
protected:
  Object **beg;
  int size;
  int current;

public:
  Vector() {
    beg = 0;
    size = 0;
    current = 0;
  }
  Vector(int n) {
    beg = new Object *[n];
    current = 0;
    size = n;
  }
  ~Vector() {
    if (beg != 0)
      delete[] beg;
    beg = 0;
  }
  void Add() {
    Object *p;
    cout << "1 - Person" << endl << "2 - Abiturient" << endl;
    int y;
    cin >> y;
    if (y == 1) {
      Person *a = new Person;
      a->Input();
      p = a;
      if (current < size) {
        beg[current] = p;
        current++;
      }
    } else if (y == 2) {
      Abiturient *b = new Abiturient;
      b->Input();
      p = b;
      if (current < size) {
        beg[current] = p;
        current++;
      }
    } else
      return;
  }
  void Show() {
    if (current == 0)
      cout << endl << "Пусто" << endl;
    Object **p = beg;
    for (int i = 0; i < current; i++) {
      (*p)->Show();
      p++;
    }
  }
  int operator()() { return current; }
  void Del() {
    if (current == 0)
      return;
    current--;
  }
  void Mid() {
    double middle = 0;
    for (int i = 0; i < current; i++) {
      middle += beg[i]->Get_age();
    }
    cout << "Средний возраст = " << middle / current;
  }
};

class Dialog : public Vector {
protected:
  int EndState;

public:
  // Конструктор
  Dialog() { EndState = 0; }
  virtual ~Dialog(){};
  void GetEvent(TEvent &t) {
    string Oper = "+-mqzs";
    string s;
    string param;
    cout << endl << "Введите: ";
    cin >> s;
    char code = s[0];
    if (Oper.find(code) >= 0) {
      t.what = evMessage;
      switch (code) {
      case 'm':
        t.command = cmMake;
        break; // Создание
      case '+':
        t.command = cmAdd;
        break; // Добавить
      case '-':
        t.command = cmDel;
        break; // Удалить
      case 's':
        t.command = cmShow;
        break; // Вывести элементы
      case 'z':
        t.command = cmMid;
        break; // Вывести сред.возраст
      case 'q':
        t.command = cmQuit;
        break; // Конец
      }
    } else
      t.what = evNothing;
  }
  int Execute() {
    TEvent event;
    do {
      EndState = 0;
      GetEvent(event);
      HandleEvent(event);
    } while (Valid());
    return EndState;
  }
  bool Valid() { return EndState == 0; }
  void ClearEvent(TEvent &t) { t.what = evNothing; }
  void EndExec() { EndState = 1; }
  void HandleEvent(TEvent &t) {
    if (t.what == evMessage) {
      switch (t.command) {
      case cmMake:
        cout << endl << "Введите размер: ";
        cin >> size;
        beg = new Object *[size];
        current = 0;
        ClearEvent(t);
        break;
      case cmAdd:
        Add();
        ClearEvent(t);
        break;
      case cmDel:
        Del();
        ClearEvent(t);
        break;
      case cmMid:
        Mid();
        ClearEvent(t);
        break;
      case cmShow:
        Show();
        ClearEvent(t);
        break;
      case cmQuit:
        EndExec();
        ClearEvent(t);
        break;
      };
    };
  }
};

int main() {
  setlocale(LC_ALL, "Rus");
  Dialog D;
  D.Execute();
  return 0;
}
