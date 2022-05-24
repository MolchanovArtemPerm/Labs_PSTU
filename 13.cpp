#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
class Money {
private:
  long int rubles;
  int kopecks;

public:
  Money() // Конструктор
  {
    this->rubles = 0;
    this->kopecks = 0;
  }
  Money(long rubles, int kopecks) // Конструктор с параметрами
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
  {}
  int Get_rubles() // Вывод рубля
  {
    return rubles;
  }
  int Get_kopecks() // Вывод копейки
  {
    return kopecks;
  }
  void Set_rubles(int NewRubles) { rubles = NewRubles; }
  void Set_kopecks(int NewKopecks) { kopecks = NewKopecks; }
  Money &operator++();
  Money operator++(int);
  Money operator+(const Money &t);
  bool operator<(const Money &t);
  bool operator>(const Money &t);
  bool operator==(const Money &t);
  friend istream &operator>>(istream &in, Money &t);
  friend ostream &operator<<(ostream &out, const Money &t);
};
bool Money::operator<(const Money &t) {
  if (this->rubles < t.rubles) {
    if (this->kopecks < t.kopecks)
      return true;
  } else
    return false;
}
bool Money::operator==(const Money &t) {
  if (this->rubles == t.rubles) {
    if (this->kopecks == t.kopecks)
      return true;
  } else
    return false;
}
bool Money::operator>(const Money &t) {
  if (this->rubles > t.rubles) {
    if (this->kopecks > t.kopecks)
      return true;
  } else
    return false;
}
Money &Money::operator++() {
  ++kopecks;
  return *this;
}
Money Money::operator++(int) {
  Money t(rubles, kopecks);
  ++kopecks;
  return t;
}
Money Money::operator+(const Money &t) {
  int temp1 = rubles * 100 + kopecks;
  int temp2 = t.rubles * 100 + t.kopecks;
  Money p;
  p.rubles = (temp1 + temp2) / 100;
  p.kopecks = (temp1 + temp2) % 100;
  return p;
}
ostream &operator<<(ostream &out, const Money &t) {
  return (out << t.rubles << "," << t.kopecks);
}
istream &operator>>(istream &in, Money &t) {
  cout << "rubles: ";
  in >> t.rubles;
  cout << "kopecks: ";
  in >> t.kopecks;
  return in;
}

int main() {
  setlocale(LC_ALL,"RUS");
  list<Money> mass;
  int size = 5;
  Money temp;
  // Заполнение
  for(int i = 0;i < size;i++){
    cout << "Введите деньги: ";
    cin >> temp;
    mass.push_back(temp);
  }
  for(list<Money>::iterator index2 = mass.begin();index2 != mass.end();index2++){
    cout << *index2 << " ";
  }
  // 3
  int index;
  cout << endl << "Введите индекс: ";
  cin >> index;
  list<Money>::iterator mass2 = next(mass.begin(),index); 
  cout << "Введите индекс для вставки: ";
  cin >> index;
  mass.insert(next(mass.begin(),index),*mass2);
  for(list<Money>::iterator index2 = mass.begin();index2 != mass.end();index2++){
    cout << *index2 << " ";
  }
  // 4
  cout << endl << "Введите индекс для удаления: ";
  cin >> index;
  list<Money>::iterator massDel = next(mass.begin(),index);
  mass.erase(massDel);
  for(list<Money>::iterator index2 = mass.begin();index2 != mass.end();index2++){
    cout << *index2 << " ";
  }
  // 5
  sort(mass.begin(),mass.end(),[](Money money,Money money2){return money > money2;});
  for(list<Money>::iterator index2 = mass.begin();index2 != mass.end();index2++){
    cout << *index2 << " ";
  }
  return 0;
}
