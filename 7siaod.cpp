

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <stack>
using namespace std;
void printsteck(double steck[10],int size) {
    
    for (int i = 0; i <= size; i++) {
        cout << steck[i]<<" ";
    }
   
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    getline(cin, s);
    double steck[10];
    int size = -1;
    for (int i = 0; i < s.size() ; i++) {

        if (s[i] == ' ')
            continue;
        cout << s[i] << "\t";
        if (s[i] >= '1' and s[i] <= '9') {
            size++;
            
            
            steck[size] = int(s[i]) - 48;

        }
        else if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*' or s[i] == '^') {
            double x2 = steck[size];
            size--;
            double x1 = steck[size];
            size--;
            if (s[i] == '+')
                x1 = x1 + x2;

            else if (s[i] == '-')
                x1 = x1 - x2;
            else if (s[i] == '*')
                x1 = x2 * x1;
            else if(s[i]=='/')
                x1 = x1 / x2;
            else {
                x1 = pow(x1, x2);
            }
            size++;
            steck[size] = x1;
        }
        printsteck(steck, size);
        cout << endl;
    }
    cout<<steck[0];


}