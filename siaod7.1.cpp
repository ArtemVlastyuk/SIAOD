// siaod7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <stack>
using namespace std;
struct q
{
    q* pNext;
    char data;
    q(int data, q* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;

    }


};
struct List
{
    q* first;
    q* last;
    int size = 0;
};

void add(List& list,char x)
{

    q* p = new q(x);
    if (list.size == 0) {
        list.first = p;
        list.last = p;

    }
    else
    {

        list.last->pNext = p;
        list.last = p;
    }
    list.size++;
   
}
void print(List list)
{
    q* current;
    current = list.first;
    while (current!= nullptr) {
        cout << current->data;
        current = current->pNext;
    }
    for (int i = 0; i < 25 - list.size; i++)
        cout << " ";
}
void printsteck(stack<char> steck) {
    string a;
    int size = steck.size();
    for (int i = 0; i < size; i++) {
        a+= steck.top();
        steck.pop();
    }
    for (int i = 0; i < size; i++)
        cout << a[size - i];
} 

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List l;
    l.first = nullptr;
    string s ="(a*(d-e)+(f+g)/c)+(k*l-s/m)" ;
    stack <char> steck;
    cout << "Элемент" <<setw(20)<< "состоние очереди"<<setw(30) << "состояние стека" << endl;
    cout << "Выражения" << endl;

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << "\t\t";
             
        if (s[i] >= 'a' and s[i] <= 'z') {
            add(l, s[i]);
        
        }
        else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
            if (steck.empty() or steck.top() == '(')
                steck.push(s[i]);
            else if ((s[i] == '*' or s[i] == '/') and (steck.top() == '+' or steck.top() == '-')) {
                steck.push(s[i]);
            }
            else {
               

                while (true) {
                    add(l, steck.top());
                    steck.pop();
                    if (((s[i] == '*' or s[i] == '/') and (steck.top() == '+' or steck.top() == '-')) or (steck.top() == '(')) {
                        steck.push(s[i]);
                        break;
                    }
                }
            }
        }
        else if (s[i] == '(') {
            steck.push(s[i]);
        }
        else if (s[i] == ')') {
            while (true) {
                
                add(l, steck.top());
                steck.pop();
                if (steck.top() == '(') {
                    steck.pop();
                    
                    break;
                }
            }
        }
        
        if (i==s.size()-1){
            while (!steck.empty()) {
                add(l, steck.top());
                steck.pop();
            }

        }
        print(l);
        cout << "\t";
        printsteck(steck);
        cout << endl;
    }
    cout <<endl<<endl<<"Результат: ";
    print(l);
    cout << "\n\n\n\n";

}
