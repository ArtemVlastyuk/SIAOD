
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;
struct organizations
{
public:
    int id;
    string name;
    int codeposition;
    string date;
    
};
void Couta(organizations a[100], int k) {
    for (int i = 0; i <= 43; i++)
        cout << "==";

    cout <<endl<< setw(20) << left << "| Номер сотрудника" << setw(20) << left << "| Фамилия и инициалы" << setw(20) << left << "| Код сотрудника" << setw(20) << left << "| Дата принятия на работу |" << endl;
    for (int i = 0; i <= 43; i++)
        cout << "==";
    for (int i = 0; i < k; i++) {
        
            

        cout << endl <<"| " << setw(18) << a[i].id<<"| " << setw(17)<<a[i].name<<" | " << setw(17) << a[i].codeposition<<" | " << setw(23)<< a[i].date<<" |" << endl;
        for (int i = 0; i <= 43; i++)
            cout << "--";
    }
    cout << endl;

}
void Coutcatalog() {
    string* catalog = new string[5]{ "11 - Специалист по подбору персонала ","12- Менеджер по персоалу ","13 - бухгалтер ","14- Зам. начальника","15- Началиник " };

    cout << "Справочник\n";

    for (int i = 0; i < 5; i++)
        cout << catalog[i] << endl;
    delete[] catalog;
}
void zapolnenie(organizations a[100],int k) {
    int id, code;
    string date, name;
    cout << "Заполните данные о сотруднике" << endl;
    cout << "Введите номер сотрудника: ";

    cin >> id;

    cin.ignore();
    cout << "Введите имя и инициалы сотрудника: ";
    getline(cin, name);
    Coutcatalog();
    cout << "Введите код должности сотрудника(справочник представлен выше): ";
    cin >> code;
    cout << "Введите дату поступления на работу: ";
    cin >> date;
    int x;
    for (int i = 0; i <k; i++) {
        if (a[i].codeposition == code) {
            x = i;
            break;
        }
    }
    
    for (int i = k - 1; i > x; i--)
        a[i + 1] = a[i];
    a[x + 1]={id,name,code,date};
    
}
void zamena(organizations a[100], int k) 
{
    
    Couta(a, k);
    cout << "\n\n\n";

    Coutcatalog();
    for (int i = 0; i < k; i++) {
        cout << "Имя Сотрудника " << a[i].name << endl;
        cout << "Старая должность " << a[i].codeposition << endl<<"Введите код новой должности:";
        cin >> a[i].codeposition;

        
    }
    Couta(a, k);
}
void del(organizations a[100], int k)
{
    organizations b[100];
    cout << "Введите номер должности\n";
    int n;
    cin >> n;
    int k1 = 0;
    for (int i = 0; i < k; i++) {
        if (a[i].codeposition != n) { b[k1] = a[i]; k1++; }
    }
    k = k1;
    Couta(b, k);
   
}
int zapolneniea(organizations a[100]) {
    ifstream f;
    f.open("a.txt");
    if (!f.is_open()) {
        cout << "Ошибка чтения файла";
        return 0;
    }
    int k = 0;
    string str[100];
    while (getline(f, str[k])) {


        k++;
    }

    

    int kk = 0;
    string ss;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < str[i].length(); j++) {
            if (str[i][j] == '|') {

                kk++;
            }
            else {
                ss += str[i][j];
                continue;
            }
            if (kk == 1) {
                a[i].id = stoi(ss);
                ss = "";
                continue;
            }
            else if (kk == 2) {
                a[i].name = ss;
                ss = "";
                continue;
            }
            else if (kk = 3) {
                a[i].codeposition = stoi(ss);
                ss = "";
                continue;

            }

        }
        a[i].date = ss;
        ss = "";
        kk = 0;
       // cout << a[i].id << "   " << a[i].name << "   " << a[i].codeposition << "  " << a[i].date << endl;
    }
    return k;
}

int main()
{
    organizations a[100];
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Coutcatalog(catalog);
    int k;
    k = zapolneniea(a);
    
    Couta(a, k);
    
    zapolnenie(a, k);
    k++;
    
    zamena(a,k);
    del(a, k);
    
       
}
                                                                                