/*Дан линейный однонаправленный список L
1)	Разработать функцию, которая проверяет, есть ли в списке L два одинаковых элемента.
2)	Разработать функцию, которая удаляет из списка L максимальное значение.
3)	Разработать функцию, которая вставляет в список L новое значение перед каждым узлом в четной позиции.
*/
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

struct Node //Узел
{
    Node* pNext; //указатель на следующий элемент
    int data; //значение узла

    Node(int s, Node* ptr = nullptr) //конструктор узла
    {
        data = s;
        pNext = nullptr;
    }
};
struct List //Однонаправленный список
{
    Node* first; //указатель на первый элемент
    int size = 0; //размер списка
};

void add(List& list, int s) //Добавляет в список новый элемент
{
    Node* p = new Node(s);
    if (list.size == 0)
        list.first = p;
    else
    {
        Node* current = list.first;
        while (current->pNext != nullptr)
            current = current->pNext;
        current->pNext = p;
    }
    list.size++;
}
void print(List L) //Выводит список
{
    Node* current = L.first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->pNext;
    }
    

    cout << endl;
}
void search(List& L)   //Поиск одинаковых элементов
{
    Node* current = L.first;
    Node* pp=L.first;
    Node* current1 = L.first;
    
    while(current!=nullptr){
       
        //pp = current;
        current1 = current->pNext;
       
        while(current1!=nullptr){
            
            
            if (current1->data == current->data) {
                cout << "В списке есть одинаковые числа\n";
                
                return;
            }
               /* if (current1->pNext != nullptr) {
                   pp->pNext = current1->pNext;
                    
                    //current1 = current1->pNext;
                }
               else {
                  pp->pNext = nullptr;
                  break;
                }
                L.size--;
            }
            else {
                pp = current1;
              
            }*/
            current1 = current1->pNext;
        }
        current = current->pNext;
       
    }
    
    cout << "В списке нет одинаковых элементов\n";
   
    cout << endl;
    
}
void insert(List& L) {    //Вставляет элементы перед четной позицией
    int x;

    
    Node* current = L.first;
    int i = 0;
    while (current != nullptr) {
        i++;
        if ((i % 2 != 0)&&(current->pNext!=nullptr)) {
            cout << "Введите значение которое вы хотите вставить на "<<i+1<<" позицию \n";
            cin >> x;
            Node* a = new Node(x);
            a->pNext = current->pNext;
            current->pNext = a;
            current = a->pNext;
        }
        else
        current = current->pNext;
    }
    cout << "Cписок после добаления элементов: ";
    print(L);
}
void dell(List& L) {          //Удаляет максимальное число
    Node* current;
    current = L.first;
    int max=0;

    while (current != nullptr) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->pNext;

    }
    current = L.first;
    cout << "Максимальное число: " << max << endl;
    if (current->data == max) {
        L.first = current->pNext;
    }
    else {
        while (current != nullptr) {
            if (current->pNext->data == max) {
                if (current->pNext->pNext == nullptr) {
                    current->pNext = nullptr;
                }
                else
                {
                    current->pNext = current->pNext->pNext;
                    L.size--;
                }
                break;
            }
            else {
                current = current->pNext;
            }

        }
    }
    cout << "Список после удаления максимального числа: \n";

    print(L);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    List L;
    cout << "Введите количество элементов\n";
    int k;
    cin >> size;
    cout << "Введите 1 если хотите сами заполнить список, иначе программа заполнит список рандомными числами: ";
    cin >> k;

    if (k == 1) {

        cout << "Введите элементы\n";
        for (int i = 0; i < size; i++) {
            int x;
            cin >> x;
            add(L, x);
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            int x;
            x = rand() % 100 + 1;
            add(L, x);
        }
        print(L);

    }
    cout << "Введите номер задания которое вы хотите выполнить\n1. Проверить, есть ли в списке L два одинаковых элемента\n";
    cout << "2. Удалить максимальное число\n3. Вставить в список L новое значение перед каждым узлом в четной позици\n0.Закончить программу\n";
    int x;
    cin >> x;
    while (x != 0) {
        
        
        if (x == 1) {
            search(L);
        }
        else if (x == 2) {
            dell(L);
        }
        else if (x == 3) {
            insert(L);
        }
        cout << "\n\n\nВведите номер задания которое вы хотите выполнить\n1. Проверить, есть ли в списке L два одинаковых элемента\n";
        cout << "2. Удалить максимальное число\n3. Вставить в список L новое значение перед каждым узлом в четной позици\n0.Закончить программу\n";

        cin >> x;
    }
}