

#include <iostream>
using namespace std;
void maxx(int* a, int max, int n, int i) {
    
    if (max < a[i]) {
        max = a[i];
    }
    if (i != n - 1) {
        i++;
        maxx(a, max, n, i);
    }
    else
        cout << max;
}
int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите кол-во элементов: ";
    cin >> n;
    int* a = new int[n];

    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        a[i]=rand()%100+1;
        cout << a[i] << " ";
    }

    int max = 0;

    
    cout << "\n\n\nМаксимальное число: ";
    maxx(a, max,n,0);
   

}
