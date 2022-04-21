

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

void add(List& list, char x)
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
    while (current != nullptr) {
        cout << current->data;
        current = current->pNext;
    }
    for (int i = 0; i < 25 - list.size; i++)
        cout << " ";
}
void printsteck(stack<string> steck) {
    int size = steck.size();
    string a[10];
    for (int i = 0; i < size; i++) {
        cout << steck.top();
        a[i]= steck.top();
        steck.pop();
    }
    /*for (int i = 0; i < size; i++)
        cout << a[size - i];*/
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List l;
    l.first = nullptr;
    string s = "x y z ^ + m n k/-*p+ ";
    stack <string> steck;
    for (int i = 0; i < s.size()-1; i++) {
        
        if (s[i] == ' ')
            continue;
        cout << s[i] << "\t";
        if (s[i] >= 'a' and s[i] <= 'z') {
            
            string ss ="";
            ss += s[i];
           
            steck.push(ss);
            
        }
        else if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*' or s[i] == '^') {
            string x2 = steck.top();
            steck.pop();
            string x1 = steck.top();
            steck.pop();
            if (i == s.size() - 2) {
                x2 = x1 + s[i] + x2;
                steck.push(x2);
            }
            else if ((s[i] == '*' or s[i] == '/' or s[i]=='^' or s[i] == '+' or s[i] == '-') and (s[i+2] == '+' or s[i+2] == '-' or s[i+1]=='+' or s[i+1]=='-')) {
                x2 = x1 + s[i] + x2;
                steck.push(x2);
            }
            else {
                x2 = "(" + x1 + s[i] + x2 + ")";
                steck.push(x2);
            }
        }
        printsteck(steck);
        cout << endl;
    }
    printsteck(steck);
   
    
}