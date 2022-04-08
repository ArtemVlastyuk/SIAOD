
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <vector>
using namespace std;
struct organizations
{
public:
    int id;
    string name;
    int codeposition;
    string date;

};
void Coutcatalog() {
    string* catalog = new string[5]{ "11 - Специалист по подбору персонала ","12- Менеджер по персоалу ","13 - бухгалтер ","14- Зам. начальника","15- Началиник " };

    cout << "Справочник\n";

    for (int i = 0; i < 5; i++)
        cout << catalog[i] << endl;
    delete[] catalog;
}

void Couta(vector<organizations> a) {
    for (int i = 0; i <= 43; i++)
        cout << "==";

    cout << endl << setw(20) << left << "| Номер сотрудника" << setw(20) << left << "| Фамилия и инициалы" << setw(20) << left << "| Код сотрудника" << setw(20) << left << "| Дата принятия на работу |" << endl;
    for (int i = 0; i <= 43; i++)
        cout << "==";
    for (int i = 0; i < a.size(); i++) {



        cout << endl << "| " << setw(18) << a[i].id << "| " << setw(17) << a[i].name << " | " << setw(17) << a[i].codeposition << " | " << setw(23) << a[i].date << " |" << endl;
        for (int i = 0; i <= 43; i++)
            cout << "--";
    }
    cout << endl;

}
void del(vector<organizations> a)
{

    cout << "Введите номер должности\n";
    int n;
    cin >> n;
    int k1 = 1;
    while (k1 > 0) {
        k1 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].codeposition == n) { a.erase(a.begin() + i ); k1++; break; }
        }
    }
    Couta(a);

}
void zamena(vector<organizations> a)
{


    cout << "\n\n\n";

    Coutcatalog();
    for (int i = 0; i < a.size(); i++) {
        cout << "Имя Сотрудника " << a[i].name << endl;
        cout << "Старая должность " << a[i].codeposition << endl << "Введите код новой должности:";
        cin >> a[i].codeposition;


    }
    Couta(a);
    del(a);
}
void zapolnenie(vector<organizations> a) {
    organizations news;
    cout << "Заполните данные о сотруднике" << endl;
    cout << "Введите номер сотрудника: ";

    cin >> news.id;

    cin.ignore();
    cout << "Введите имя и инициалы сотрудника: ";
    getline(cin, news.name);
    Coutcatalog();
    cout << "Введите код должности сотрудника(справочник представлен выше): ";
    cin >> news.codeposition;
    cout << "Введите дату поступления на работу: ";
    cin >> news.date;
    int x;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].codeposition == news.codeposition) {
            x = i;
            break;
        }
    }
    a.push_back(news);
    
    for (int i = a.size() - 2; i > x; i--) {

        a[i + 1] = a[i];
    }
    

    a[x + 1] = news;
    
    Couta(a);

    zamena(a);
}


void zapolneniea() {
    ifstream f;
    f.open("a.txt");
    if (!f.is_open()) {
        cout << "Ошибка чтения файла";
           exit;
    }
    int k = 0;
    string str[100];
    while (getline(f, str[k])) {


        k++;
    }

    vector<organizations> a(k);

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
       
    }
    
    Couta(a);
    zapolnenie(a);
}

int main()
{
   
    vector<organizations> a;
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Coutcatalog(catalog);
    zapolneniea();
    
    
    
    

}
