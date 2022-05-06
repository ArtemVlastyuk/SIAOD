
#include <iostream>
#include <Windows.h>
#include <string>
#include<algorithm>
using namespace std;
string a = "ЁЙЦУКЕНГШЩЗХФЫВАПРОЛДЖЭЯЧСИТЬБЮ";
struct US
{
public:
    int code;
    string nameUn="";

};
void fillUS(US* arr, int size) {

    for (int i = 0; i < size; i++) {
        arr[i].code = i;
        //for (int i1 = 0; i1 < rand() % 3 + 3; i1++)
        arr[i].nameUn += a[rand() % (a.size() - 1)];
        //cout << arr[i].code << "   " << arr[i].nameUn << endl;
    }
}
void Search(US* arr, int size, int query) {
    for (int i = 0; i < size; i++)
        if (arr[i].code == query) {
            cout << i << "   " << arr[i].nameUn << endl;
            break;
        }
}
void barrierSearch(US* arr, int size, int query) {
    US last = arr[size - 1];
    arr[size - 1].code = query;
    int i = 0;
    for (i; arr[i].code != query; i++);
    if (i != size-1 or last.code==query)
        cout <<i<<" " <<arr[i].nameUn<<endl;
    else
        cout << "Код не найден";


}
void interpolatingSeach(US* arr, int size, int query) {
    unsigned int mid, left = 0, right = size - 1;
    while (left!=right)
    {
     
        mid = left + ((query - arr[left].code) * (right - left)) / (arr[right].code - arr[left].code);
     
        if (arr[mid].code < query) left = left + 1;
        else if (arr[mid].code > query) right = right - 1;
        else {
            cout << mid << " " << arr[mid].nameUn << endl;
            return;
        }
    }
    
    if (arr[left].code == query) cout<<left<<" "<<arr[left].code<<endl;
    if (arr[right].code == query) cout << right << " " << arr[right].code << endl;
    
}
void heapify(US* arr, int n, int i)
{
    int most = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && arr[left].code > arr[most].code)
        most = left;


    if (right < n && arr[right].code > arr[most].code)
        most = right;


    if (most != i)
    {
        swap(arr[i], arr[most]);


        heapify(arr, n, most);
    }
}
void heapSort(US* arr, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    US* arr;
    int size;
    int query;
    cin >> size;
    
    arr = new US[size];
    fillUS(arr, size);
    cout << arr[size/2].code << endl;
    cin >> query;
    //Search(arr, size, query);
    //heapSort(arr, size);
    //cout << 1;
    //for (int i = 0; i < size; i++)
      //  cout << arr[i].code << " " << arr[i].nameUn << endl;
    unsigned int start_time = clock();
    //Search(arr, size, query);
    interpolatingSeach(arr, size, query);
    //barrierSearch(arr, size, query);
    cout << clock() - start_time;
    delete[]arr;
}