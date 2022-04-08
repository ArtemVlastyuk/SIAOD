
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
void Couta(organizations *a, int k) {
    for (int i = 0; i <= 43; i++)
        cout << "==";

    cout << endl << setw(20) << left << "| Номер сотрудника" << setw(20) << left << "| Фамилия и инициалы" << setw(20) << left << "| Код сотрудника" << setw(20) << left << "| Дата принятия на работу |" << endl;
    for (int i = 0; i <= 43; i++)
        cout << "==";
    for (int i = 0; i < k; i++) {



        cout << endl << "| " << setw(18) << a[i].id << "| " << setw(17) << a[i].name << " | " << setw(17) << a[i].codeposition << " | " << setw(23) << a[i].date << " |" << endl;
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

organizations* zapolnenie(organizations *a, int k) {
    int id, code;
    string date, name;
    cout << "Заполните данные о сотруднике" << endl;
    cout << "Введите номер сотрудника: ";
    organizations* b = new organizations[k + 1];
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
    for (int i = 0; i < k; i++) {
        if (a[i].codeposition == code) {
            x = i;
            break;
        }
    }

    for (int i = k - 1; i > x; i--)
        b[i + 1] = a[i];
    b[x + 1]={id,name,code,date};
    
    for (int i = 0; i <= x; i++) {
        b[i] = a[i];
    }
    delete [] a;
    return b;


}

void zamena(organizations *a, int k)
{

    
    cout << "\n\n\n";

    Coutcatalog();
    for (int i = 0; i < k; i++) {
        cout << "Имя Сотрудника " << a[i].name << endl;
        cout << "Старая должность " << a[i].codeposition << endl << "Введите код новой должности:";
        cin >> a[i].codeposition;


    }
    Couta(a, k);
}
struct Get
{
    organizations* a;
    int k;

};
Get del(organizations *a, int k)
{
    
    cout << "Введите номер должности\n";
    int n;
    cin >> n;
    int k1 = 0;
    for (int i = 0; i < k; i++) {
        if (a[i].codeposition != n) { a[k1] = a[i]; k1++; }
    }
    k = k1;
    organizations* b=new organizations[k];
    for (int i = 0; i < k; i++)
        b[i] = a[i];
    
    Get g;
    g.a = b;
    g.k = k;
    return g;
}

Get zapolneniea() {
    ifstream f;
    f.open("a.txt");
    if (!f.is_open()) {
        cout << "Ошибка чтения файла";
        
    }
    int k = 0;
    string str[100];
    while (getline(f, str[k])) {


        k++;
    }
    organizations* a;
    a = new organizations[k];


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
    Get g;
    g.a = a;
    g.k = k;
    return g;
}

int main()
{
    
    organizations* a;
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Coutcatalog(catalog);
    Get g;
    int k;
    g = zapolneniea();
    a = g.a;
    k = g.k;
    Couta(a, k);
    
    
    a= zapolnenie(a, k);
    k++;
    Couta(a, k);
   
    zamena(a, k);
    g= del(a, k);
    a = g.a;
    k = g.k;
    Couta(a, k);


}
