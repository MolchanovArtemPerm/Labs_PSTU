//Тип информационного поля char*.Добавить в стек элемент после элемента с заданным информационным полем.
#include <iostream>
#include <stack>
using namespace std;

int main() {
  setlocale(LC_ALL,"Rus");
  stack <char> st;
  stack <char> st2;
  char zam,temp;
  srand(time(0));
  for(int i = 0; i < 10; i++)
  {
    char s = rand()% 101+20;
    st.push(s);
  }
  while(!st.empty())
  {
    cout << st.top() << endl;
    st2.push(st.top());
    st.pop();      
  }
  cout << "Введите значение которое нужно добавить: ";
  cin >> temp;
  cout << "Введите значение перед которым нужно добавить: ";
  cin >> zam;
  while(!st2.empty())
  {
    if(st2.top() == zam)
    {
      st.push(temp);
    }
    st.push(st2.top());
    st2.pop();
  }
  cout << endl << endl;
  while(!st.empty())
  {
    cout << st.top() << endl;
    st2.push(st.top());
    st.pop();      
  }
  return 0;
}
