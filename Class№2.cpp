#include <iostream>
#include <string>
using namespace std;

class Apartment
{
  private:
  string address = "NULL"; // Адрес
  double area = 0; // Площадь
  int count_room = 0; // Кол-во комнат
  public:
  Apartment(); // Конструктор без параметров
  Apartment(string,double,int); // Конструктор с параметрами
  Apartment(const Apartment&); // Конструктор копирования
  ~Apartment(); // Деструктор
  string Get_address(); // Возвращает адрес
  double Get_area(); // Возвращает площадь
  int Get_count_room(); // Возвращает кол-во комнат
  void Set_address(string N); // Заполняет адрес
  void Set_area(double S); // Заполняет площадь
  void Set_count_room(int C); // Заполняет кол-во комнат
  void Show(); // Выводит структуру
};

Apartment::Apartment()
{
  string address = "NULL"; // Адрес
  double area = 0; // Площадь
  int count_room = 0; // Кол-во комнат
  cout << endl << "Без параметров" << endl;
}

Apartment::Apartment(string New_address,double New_area,int New_count_room)
{
  address = New_address; // Адрес
  area = New_area; // Площадь
  count_room = New_count_room; // Кол-во комнат
  cout << endl << "С параметрами" << endl;
}

Apartment::Apartment(const Apartment &copy)
{
  address = copy.address; // Адрес
  area = copy.area; // Площадь
  count_room = copy.count_room; // Кол-во комнат
}

Apartment::~Apartment()
{
  //cout << "Деструктор для " << this << endl;
}
  
string Apartment::Get_address()
{
  return address;
}

double Apartment::Get_area()
{
  return area;
}

int Apartment::Get_count_room()
{
  return count_room;
}

void Apartment::Set_address(string N)
{
  address = N;
}

void Apartment::Set_area(double S)
{
  area = S;
}

void Apartment::Set_count_room(int C)
{
  count_room = C;
}

void Apartment::Show()
{
  cout << "Адрес: " << address << endl;
  cout << "Площадь: " << area << endl;
  cout << "Кол-во комнат: " << count_room << endl;
}

void Print(Apartment a)
{
  a.Show();
}

Apartment Make_apartment()
{
  string a;
  double s;
  int c;
  cout << "Введите адрес: ";
  cin.ignore();
  getline(cin,a);
  cout << endl << "Введите площадь: ";
  cin >> s;
  cout << endl << "Введите кол-во комнат: ";
  cin >> c;
  Apartment a1(a,s,c);
  return a1;
}

int main() {
  setlocale(LC_ALL,"Rus");
  Apartment a1; // Конструктор без параметров
  a1.Show();
  Apartment a2("Уинская",30.5,2); // Конструктор с параметрами
  a2.Show();
  cout << endl;
  Apartment a3 = a2; // Конструктор копирования
  Print(a3);
  cout << endl;
  Apartment a4;
  a4.Set_address("Максима Горького"); // Конструктор
  a4.Set_area(43.7);
  a4.Set_count_room(3);
  Print(a4);
  cout << endl;
  a1 = Make_apartment();
  a1.Show();
  return 0;
}
