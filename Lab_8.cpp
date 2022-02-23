#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Auto {
  string brand;
  string serial_number;
  string register_number;
  int year;
};

void failzap(Auto* mass, int size) {
  fstream file;
  file.open("D:\\text.txt", fstream::out);
  file.write((char*)&size, sizeof(size));
  for (int i = 0; i < size; i++)
  {
    file.write((char*)&mass[i], sizeof(mass[i]));
  }
  file.close();
}

Auto zapol()
{
  Auto Car;
  cout << "Введите марку автомобиля: " << endl;
  getline(cin, Car.brand);
  cout << "Введите серийный номер автомобиля: " << endl;
  getline(cin, Car.serial_number);
  cout << "Введите регистрационный номер автомобиля: " << endl;
  getline(cin, Car.register_number);
  cout << "Введите год автомобиля: " << endl;
  cin >> Car.year;
  cin.get();
  return Car;
}

void vivod(Auto* mass2, int size2)
{
  for (int i = 0; i < size2; i++)
  {
    cout << mass2[i].brand << ' ' << mass2[i].serial_number << ' ' << mass2[i].register_number << ' ' << mass2[i].year << endl;
  }
}

void del(Auto* mass2, int size2, int num)
{
  for (int i = num; i < size2 - 1; i++)
  {
    Auto temp = mass2[i];
    mass2[i] = mass2[i + 1];
    mass2[i + 1] = temp;
  }
}

int main()
{
  setlocale(LC_ALL, "Ru");
  system("chcp1251");
  system("cls");
  int size, size2;
  cout << "Кол-во элементов: ";
  cin >> size;
  cin.get();
  Auto* mass = new Auto[size];
  for (int i = 0; i < size; i++)
  {
    mass[i] = zapol();
  }
  failzap(mass, size);
  fstream file;
  file.open("D:\\text.txt", fstream::in);
  file.read((char*)&size2, sizeof(size2));
  Auto* mass2 = new Auto[size2];
  for (int i = 0; i < size2; i++)
  {
    file.read((char*)&mass2[i], sizeof(mass2[i]));
  }
  vivod(mass2, size2);
  del(mass2, size2, 2);
  del(mass2, size2, 1);
  del(mass2, size2, 0);
  size2 -= 3;
  vivod(mass2, size2);
  size2++;
  mass2[size2 - 1] = zapol();
  failzap(mass2, size2);
  return 0;
}
