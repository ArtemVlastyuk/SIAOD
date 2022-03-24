/*
1.	Найти индекс элемента массива, цифровой корень которого равен 7.
Подсказка. Цифровой корень – это однозначное число. Алгоритм определения цифрового корня: дано число 277, сумма его цифр 16 – двухзначное; снова сумма но уже 16 равна 7 – уже однозначное – это цифровой корень числа 277.
2.	Вставить новый элемент перед элементом, цифровой корень которого равен 7. Считать, что такое число одно. 
3.	Удалить элементы массива цифровой корень которых равен 7.
*/
#include <iostream>
#include <vector>

using namespace std;
void del(int mas[],int n)
{
	int x, s;
	for (int i = 0; i < n; i++) {
		x = mas[i];
		s = 11;
		while (s > 10) {
			s = 0;
			while (x > 0) {
				s = s + (x % 10);
				x = x / 10;
			}
			if (s==7){
				n = n - 1;
				for (int i1 = i; i1 < n; i1++) {
					mas[i1] = mas[i1 + 1];
				}
				i = i - 1;
			 }
		}
	}
	cout << "Массив после удаления элементов, цифровой корень которых равен 7\n";
	for (int i = 0; i < n ; i++) {
		cout <<mas[i] << "\n";
	}

}
void pl(int mas[], int n, int i)
{  for (int i1 = n; i1 > i; i1--) {
		mas[i1] = mas[i1 - 1];
	}
	cout << "Введите число, которое вы хотите вставить\n";
	cin >> mas[i];
	cout << "Массив после добавления элемента" << endl;
	n = n + 1;
	for (int i = 0; i < n ; i++) {
		cout << mas[i] << "\n";
	}
	del(mas, n);
}
void staticc(int mas[100], int n) {
	int x, s;
	for (int i = 0; i < n; i++) {
		x = mas[i];
		s = 11;
		while (s > 10) {
			s = 0;
			while (x > 0) {
				s = s + (x % 10);
				x = x / 10;
			}

		}

		if (s == 7) {
			cout << "Цифровой корень элемента под номером " << i +1<< " равен 7." << endl;
			pl(mas, n, i);
			break;
		}
	}

}

void deld(int* mas, int n) {
	int x, s;
	for (int i = 0; i < n; i++) {
		x = mas[i];
		s = 11;
		while (s > 10) {
			s = 0;
			while (x > 0) {
				s = s + (x % 10);
				x = x / 10;
			}
			if (s == 7) {
				for (int j = i; j < n - 1; j++)
					mas[j] = mas[j + 1];
				n--;
				mas = (int*)realloc(mas, n * sizeof(int));
				
				
				i = i - 1;
			
			}
		}
		
	}
	cout << "Массив после удаления элементов, цифровой корень которых равен 7\n";
	for (int i1 = 0; i1 < n; i1++) {
		cout << mas[i1] << "\n";
	}

}
void pld(int *&mass, int n,int i) {
	n++;
	int* mas = new int[n];
	for (int i1 = 0; i1 < i; i1++) {
		mas[i1] = mass[i1];
	}
	cout << "Введите число, которое вы хотите вставить\n";
	cin >> mas[i];
	for (int i1 = i + 1; i1 < n; i1++) {
		mas[i1] = mass[i1 - 1];
	}
	for (int i1 = 0; i1 < n; i1++)
		cout << mas[i1] << endl;
	deld(mas, n);
}
void dinamic(int* mass, int n) {
	int x, s;
	for (int i = 0; i < n; i++) {
		x = mass[i];
		s = 11;
		while (s > 10) {
			s = 0;
			while (x > 0) {
				s = s + (x % 10);
				x = x / 10;
			}

		}

		if (s == 7) {
			cout << "Цифровой корень элемента под номером " << i + 1 << " равен 7." << endl;
			pld(mass, n, i);
			break;
		}
	}
}
void delv(vector<int>& mas)
{
	int x, s;
	for (int i = 0; i < mas.size(); i++) {
		x = mas[i];
		s = 11;
		while (s > 10) {
			s = 0;
			while (x > 0) {
				s = s + (x % 10);
				x = x / 10;
			}

		}

		if (s == 7) {
			mas.erase(mas.begin() + i);
			i--;
		}
		
	}
	cout << "Массив после удаления элементов, цифровой корень которых равен 7\n";
	for (int i = 0; i < mas.size(); i++) cout << mas[i] << endl;
}
void plv(vector<int>& mas, int i) {
	vector<int>::iterator it;
	int x;
	cout << "Введите число, которое вы хотите вставить\n";
	cin >> x;

	it = mas.begin() + i;
	mas.insert(it, x);
	cout << "Массив после добавления элемента" << endl;
	for (int i = 0; i < mas.size(); i++) cout << mas[i]<<endl;
	delv(mas);
}
void vec(vector<int>& mas)
{
	int x, s;

	for (int i = 0; i < mas.size(); i++) {
		x = mas[i];
		s = 11;
		while (s > 10) {
			s = 0;
			while (x > 0) {
				s = s + (x % 10);
				x = x / 10;
			}

		}

		if (s == 7) {
			cout << "Цифровой корень элемента под номером " << i + 1 << " равен 7." << endl;
			plv(mas, i);
			break;
		}
	}
	




}int main()
{
	int n,x,s=12;
	int mas[100];
	setlocale(LC_ALL, "Rus");
	
	cout << "Выберите с чем вы хотите работать\n1.Статический массив\n2.Динамический массив\n3.vector\n";

	cin >> x;
	if (x==1){ 
		cout << "Введите количество элементов массива\n";
		cin >> n;
		cout << "Введите элементы массива\n";
		for (int i = 0; i < n; i++)
			cin >> mas[i];
		
		 staticc(mas, n);
	}
	if (x==2){
		
		cout << "Введите количество элементов массива\n";
		cin >> n;
		int* mass = new int[n];
		cout << "Введите элементы массива\n";
		
		for (int i = 0; i < n; i++)
			cin >> mass[i];
		dinamic(mass, n);
	}
	if (x==3){
		vector<int> mas_vector;
		cout << "Введите количество элементов массива\n";
		cin >> n;
		cout << "Введите элементы массива\n";
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			mas_vector.push_back(x);
		}
		vec(mas_vector);
	}
}
