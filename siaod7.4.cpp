#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <stack>
using namespace std;
void printsteck(stack<int> steck) {
    int size = steck.size();
    int a[10];
    for (int i = 0; i < size; i++) {
        
        a[i] = steck.top();
        steck.pop();
    }
    for (int i = 0; i < size; i++)
        cout << a[size - i-1]<<" ";
}
int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s = "+5/*2,8,4";
    stack <int> steck;
    
    for (int i = s.size()-1; i >=0; i--) {

        
        cout << s[i]<<"\t";
        if (s[i] >= '1' and s[i] <= '9') {

           

            steck.push(int(s[i])-48);

        }
        else if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*' ) {
            int x2 = steck.top();
            steck.pop();
            int x1 = steck.top();
            steck.pop();
            if (s[i] == '+')
                x2 = x1 + x2;

            else if (s[i] == '-')
                x2 = x2 - x1;
            else if (s[i] == '*')
                x2 = x2 * x1;
            else
                x2 = x2 / x1;
            steck.push(x2);



        }
        printsteck(steck);
        cout << endl;
       
    }
    cout<<steck.top();

    
}