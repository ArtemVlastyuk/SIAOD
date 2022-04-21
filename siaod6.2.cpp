// siaod6.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct q
{
    q* pNext;
    int data;
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
void print(List list)
{
    q* current;
    current = list.first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->pNext;
    }
}
void queue(List& L) {
    if (L.first != nullptr) {
        cout << "Очередь: ";
        print(L);
        cout << endl;
        cout << "\nИз очереди вышел: " << L.first->data << endl;
        L.first = L.first->pNext;
        L.size--;

        queue(L);
    }
    else {
        delete L.first;
        L.size = 0;

    }

}

void add(List& list, int x)
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
    if (x++ != 12) {
        add(list, x++);
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    List list;
    add(list, 1);
    queue(list);

    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
