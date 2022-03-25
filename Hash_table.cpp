#include <iostream>
#include <cmath>
using namespace std;
int collision_count = 0;
string names[30] = { "Автоном","Авудим","Авундий","Агав","Агавва","Агамемнон","Аганя","Агап","Агапий","Агапит","Агапон","Агафангел","Агафодор","Агафон","Агафоник","Агафоника","Агафопон","Агафопус","Агелай","Агенор","Агзам","Агрий","Адад","Адам","Адиб","Аднан","Адольф","Адонис","Адриан","Адыль" };
string father[30] = { "Ааронович","Абрамович","Августович","Авдеевич","Аверьянович","Адамович","Адрианович","Акимович","Аксёнович","Александрович","Алексеевич","Анатольевич","Андреевич","Андроникович","Анисимович","Антипович","Антонович","Ануфриевич","Аркадьевич","Арсенович","Арсеньевич","Артёмович","Артемьевич","Артурович","Архипович","Афанасьевич","Давидович","Давыдович","Даниилович","Данилович" };
string surnames[30] = { "Аалферова","Ааль","Ааман","Аамана","Ааманая","Ааманий","Аандреев","Аандреева","Аарон","Ааронов","Ааронова","Аб","Абабакиров","Абабакирова","Абабилов","Абабилова","Абабков","Абабкова","Абагаев","Абагаева","Абаган","Абагов","Абагова","Абагян","Абадаев","Абадаева","Абадашев","Абадашева","Абадеев","Абадеева" };
string pass[30] = { "005-9659150","785-2054477","292-5612303","621-2228225","771-2260092","176-2093330","428-6119636","597-1970271","341-2745810","062-2585231","022-8345459","617-1752763","850-7131251","707-2527424","954-4821179","778-1806044","266-5417887","222-5332300","819-9894207","623-7015858","734-1672680","806-8488184","124-3728636","785-5024102","605-5963305","583-8792499","452-6037343","093-6367823","524-4483408","359-6221661" };
string dates[30] = { "12.09.1988","22.03.1988","11.03.2014","15.03.2001","25.01.1996","15.06.1998","21.08.2007","16.03.2022","05.06.2017","02.06.1995","07.12.2006","12.12.2019","06.12.2012","10.01.1997","11.10.2021","27.06.2002","06.03.2019","14.08.2012","30.08.2013","09.07.1997","19.10.2020","14.08.2002","11.10.2002","24.01.2000","28.05.2010","17.02.2000","29.10.2014","27.10.2005","21.01.2015","02.07.2010" };
unsigned long long phones[30] = { 3173567912,4209192883,2299895056,2968759944,4334512844,3493098610,7943937352,8620915428,2292063130,7401236405,2614156949,4120444552,6329060683,0736430355,8692058254,7464423853,9902048597,9025850317,8221506865,6880730450,8533565343,7408194770,6139285224,5722267614,2221699755,9517149515,4860522934,5695670160,8792744378,4976160696 };
 
struct Human // Структура человека
{
    Human()
    {
        full_name = "NULL";
        data_birthday = "NULL";
        phone_number = 0;
        pass_number = "NULL";
    }
    string full_name, data_birthday, pass_number;
    unsigned long long phone_number;
};
 
struct Hash_table // Структура хеш-таблицы
{
    Human* mass;
    Hash_table(int size)
    {
        mass = new Human[size];
    }
    ~Hash_table()
    {
        delete[] mass;
    }
    void Find_index(unsigned long long phone_number, const int size);
    void Add(Human temp, const int size);
    void Pop(unsigned long long del_phone_number, const int size);
};
 
int Random() // Рандом чисел
{
    return rand() % 30;
}
string Random_data() // Случайная дата
{
    return dates[Random()];
}
string Random_name() // Случайная имя
{
    return (surnames[Random()] + ' ' + names[Random()] + ' ' + father[Random()]);
}
unsigned long long Random_phone() // Случайная номер телефона
{
    return phones[Random()];
}
string Random_pass() // Случайная номер паспорта
{
    return pass[Random()];
}
int Hash_function(unsigned long long key, const int size) // Формула
{
    return key % size;
}
 
void Show_info(const Human temp) // Показать информацию о человеке
{
    cout << "ФИО: " << temp.full_name
        << "\nДата рождения: " << temp.data_birthday
        << "\n№ Телефона : " << temp.phone_number
        << "\n№ Паспорта : " << temp.pass_number << "\n\n";
}
 
void Print_humans(const Human* const mass, const int size) // Вывод массива
{
    for (int i = 0; i < size; i++)
        Show_info(mass[i]);
}
 
void Print(Hash_table* table, const int size) // Вывод таблицы
{
    for (int i = 0; i < size; i++)
        Show_info(table->mass[i]);
}
 
Human Create_random_human() // Создание случайного человека
{
    Human temp;
    temp.full_name = Random_name();
    temp.data_birthday = Random_data();
    temp.phone_number = Random_phone();
    temp.pass_number = Random_pass();
    return temp;
}
 
void Fill_random(Human* mass, const int size) // Случайное заполнение массива
{
    for (int i = 0; i < size; i++)
        mass[i] = Create_random_human();
}
 
void Hash_table::Find_index(unsigned long long phone_number, const int size)
{
    int hash = Hash_function(phone_number, size);
    int index = hash;
    while (mass[index].phone_number != phone_number && index < size)
    {
        index++;
    }
    if (index >= size)
    {
        index = 0;
        while (mass[index].phone_number != phone_number && index < hash)
        {
            index++;
        }
        if (index >= hash)
            cout << "Человек с номером телефона " << phone_number << " Нет." << endl << endl;
        else
            cout << "Человек с номером телефона " << phone_number << " содержиться по индексу " << index << endl << endl;
    }
    else
        cout << "Человек с номером телефона " << phone_number << " содержиться по индексу " << index << endl << endl;
}
 
void Hash_table::Add(Human temp, const int size)
{
    int index = Hash_function(temp.phone_number, size);
    int hash = index;
    if (mass[index].full_name == "NULL")
    {
        mass[index] = temp;
        return;
    }
    else
    {
        while (index < size)
        {
            if (mass[index].full_name == "NULL")
            {
                mass[index] = temp;
                return;
            }
            index++;
            collision_count++;
        }
        if (index >= size)
        {
            index++;
            collision_count++;
            while (index < hash)
            {
                if (mass[index].full_name == "NULL")
                {
                    mass[index] = temp;
                    return;
                }
                index++;
                collision_count++;
            }
        }
    }
}
 
void Hash_table::Pop(unsigned long long del_phone_number, const int size)
{
    int index = Hash_function(del_phone_number, size);
    if (mass[index].phone_number == del_phone_number)
    {
        mass[index] = Human();
        return;
    }
    else
    {
        while (index < size)
        {
            if (mass[index].phone_number == del_phone_number)
            {
                mass[index] = Human();
                return;
            }
            index++;
        }
        if (index >= size)
        {
            index = 0;
            while (index < size)
            {
                if (mass[index].phone_number == del_phone_number)
                {
                    mass[index] = Human();
                    return;
                }
                index++;
            }
        }
    }
}
 
int main()
{
    setlocale(LC_ALL, "Rus");
    system("chcp1251");
    system("cls");
    collision_count = 0;
    int size;
    do
    {
        cout << "Введите кол-во элементов в массиве (не меньше 100): ";
        cin >> size;
    } while (size < 100);
    cout << endl;
    Human* mass = new Human[size];
    Hash_table table(size);
    Fill_random(mass, size);
    for (int i = 0; i < size; i++)
        table.Add(mass[i], size);
    Print(&table, size);
    table.Find_index(4209192883, size);
    table.Pop(4209192883, size);
    cout << endl << endl << "================" << endl << endl;
    Print(&table, size);
    cout << endl << "Кол-во коллизий для " << size << " записей: " << collision_count << endl << endl;
    delete[] mass;
    return 0;
}
