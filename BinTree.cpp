#include <iostream>
using namespace std;

int tabs = 0;
int kol_vo = 0;

struct Point {
  char data;    //информационное поле
  Point *left;  //адрес левого поддерева
  Point *right; //адрес правого поддерева
};

void Add(char NewData, Point *&p) {
  if (!p) {
    p = new Point;
    p->data = NewData;
    p->left = 0;
    p->right = 0;
    return;
  } else {
    if (p->data > NewData)
      Add(NewData, p->left);
    else
      Add(NewData, p->right);
  }
}

void Add_elem(char NewData, Point *&p) {
  if (!p) {
    p = new Point;
    p->data = NewData;
    p->left = 0;
    p->right = 0;
    return;
  } else {
    if (p->data > NewData)
      Add_elem(NewData, p->left);
    else
      Add_elem(NewData, p->right);
  }
}

Point *Del_elem(char NewData, Point *&p) {
  if (p == NULL)
    return p;
  if (NewData == p->data) {
    Point *temp;
    if (p->right == NULL)
      temp = p->left;
    else {
      Point *ptr = p->right;
      if (ptr->left == NULL) {
        ptr->left = p->left;
        temp = ptr;
      } else {
        Point *pmin = ptr->left;
        while (pmin->left != NULL) {
          ptr = pmin;
          pmin = ptr->left;
        }
        ptr->left = pmin->right;
        pmin->left = p->left;
        pmin->right = p->right;
        temp = pmin;
      }
    }
    delete p;
    return temp;
  } else if (NewData < p->data)
    p->left = Del_elem(NewData, p->left);
  else
    p->right = Del_elem(NewData, p->right);
  return p;
}

void is_Empty(Point *&p) {
  if (!p) {
    cout << "Дерево пустое";
  } else {
    cout << "Дерево не пустое";
  }
}

void Print(Point *p) {
  if (!p)
    return;
	tabs += 5; 
	Print(p->left);
	for (int i = 0; i <= tabs; i++)
    cout << " "; 
	cout << p->data << endl;
	Print(p->right);
	tabs-= 5; 
	return;
}


void Obhod(Point *p) {
  if (p == NULL)
    return;
  cout << p->data << endl;
  Obhod(p->left);
  Obhod(p->right);
}

int Count(Point *&p, char Key) {
  if (p == NULL)
    return 0; //Если дерева нет, выходим
  if (p->data == Key) {
    kol_vo++;
  }
  Count(p->left, Key);  //Обошли левое поддерево
  Count(p->right, Key); //Обошли правое поддерево
  return kol_vo;
}

int main() {
  setlocale(LC_ALL, "Rus");
  Point *tree = 0;
  char key = 0;
  srand(time(0));
  for (int i = 0; i < 6; i++) {
    Add(rand() % 25 + 97, tree);
  }
  cout << "Вывод бинарного дерева: " << endl;
  Print(tree);
  cout << endl;
  cout << "Введите значение для поиска: ";
  cin >> key;
  cout << "Количество схожих элементов: " << Count(tree, key) << endl;
  cout << "Вся динамическая память очищена" << endl;
  return 0;
}
