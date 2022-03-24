//Дана квадратная матрица. Вывести ее элементы, обходя матрицу по часовой стрелке, начиная первой строки.
//Даны два множества точек на плоскости. Из первого множества выбрать три различные точки так, чтобы треугольник с вершинами в этих точках,
//содержал (строго внутри себя) равное количество точек первого и второго множества.
#include <iostream>
#include <vector>
#include <math.h>
const int Rows = 100, Cols = 100;
using namespace std;
void zap(int mas[][Rows], int n) {
	cout << "Введите элменты матрицы\n";
		for (int i = 0; i < n; i++) {
						for (int i1 = 0; i1 < n; i1++)
							cin >> mas[i][i1];
		}
}
void zapd(int **mas, int n) {
	cout << "Введите элменты матрицы\n";
	for (int i = 0; i < n; i++) {
		for (int i1 = 0; i1 < n; i1++)
			cin >> mas[i][i1];
	}
}
void zaprand(int mas[][Rows], int n) {
	cout << "Матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int i1 = 0; i1 < n; i1++) {
			mas[i][i1] = 1 + rand() % 100;
			cout << mas[i][i1] << " ";
		}
		cout << endl;			
	}
}
void zaprandd(int **mas, int n) {
	cout << "Матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int i1 = 0; i1 < n; i1++) {
			mas[i][i1] = 1 + rand() % 100;
			cout << mas[i][i1] << " ";
		}
		cout << endl;
	}
}
void staticc(int mas[][Rows], int n) {            // Вывод статической матрицы 
	cout << "Элементы матрицы, выведенные по часовой стрелки: ";
	for (int i = 0; i < n; i++) {
		for (int i1 = i; i1 < n; i1++)
			cout << mas[i][i1] << " ";
		for (int i1 = i + 1; i1 < n; i1++)
			cout << mas[i1][n - 1] << " ";
		for (int i1 = n - 2; i1 >= i; i1--)
			cout << mas[n - 1][i1] << " ";
		for (int i1 = n - 2; i1 > i; i1--) {
			cout << mas[i1][i] << " ";
		}
		n--;
	}
	cout << endl;
}
void dinamicc(int **mas,int n){                  // Вывод динамической матрицы 
	cout << "Элементы матрицы, выведенные по часовой стрелки: ";
	for (int i = 0; i < n; i++) {
		for (int i1 = i; i1 < n; i1++)
			cout << mas[i][i1] << " ";
		for (int i1 = i + 1; i1 < n; i1++)
			cout << mas[i1][n - 1] << " ";
		for (int i1 = n - 2; i1 >= i; i1--)
			cout << mas[n - 1][i1] << " ";
		for (int i1 = n - 2; i1 > i; i1--) 
			cout << mas[i1][i] << " ";
		
		n--;
	}
	cout << endl;
}
vector<vector<int>> vecc() {      //Заполнение vector
	int n1,x;
	vector<vector<int>> vec1;
	cout << "Введите количество точек множества\n";
	cin >> n1;
	cout << "Вводите координаты плоскости через пробел, а потом нажимайте enter\n";
	for (int i = 0; i < n1; i++) {
		vector<int> vec11;
		for (int i1 = 0; i1 < 2; i1++) {
			cin >> x;
			vec11.push_back(x);
		}
		vec1.push_back(vec11);
	}
	return vec1;
}
double s(vector<int> t1, vector<int> t2, vector<int> t3) {  //Нахождение площади треугольника по 3 точкам
	double ss;
	
	ss = 0.5 * abs((t1[0] - t3[0]) * (t2[1] - t3[1]) - (t1[1] - t3[1]) * (t2[0] - t3[0]));
	
	return ss;
}
void vecccout(vector<vector<int>> vec) {   //Вывод множеств
	cout << "x\ty\n";
	for (int i = 0; i < vec.size(); i++) {

		for (int i1 = 0; i1 < 2; i1++) {

			cout << vec[i][i1] << "\t";
		}
		cout << "\n";
	}

}
int mn(vector<int> t1,vector<int> t2,vector<int> t3, vector<vector<int>> vec) {      //Посчет колва точек которые входят в треугольник
	int k = 0;
	for (int i = 0; i < vec.size(); i++) {
	
		if ((s(t1, t2, vec[i]) + s(t1, t3, vec[i]) + s(t2, t3, vec[i]) == s(t1, t2, t3)) && (s(t1, t2, vec[i]) > 0) && (s(t1, t3, vec[i]) > 0) && (s(t2, t3, vec[i]) > 0))
		{
			k++;
		}
	}
	return k;
}
void z2() {       
	vector<vector<int>> vec1;
	vector<vector<int>> vec2;
	cout << "Заполните первое множество\n";
	int k = 0;
	vec1 = vecc();
	cout << "Заполните второе множество\n";

	vec2 = vecc();
	cout << "Первое множество:\n";

	vecccout(vec1);
	cout << "Второе множество:\n";

	vecccout(vec2);
	for (int i = 0; i < vec1.size(); i++) {
		for (int i1 = i + 1; i1 < vec1.size(); i1++) {
			for (int i2 = i1 + 1; i2 < vec1.size(); i2++) {

				mn(vec1[i], vec1[i1], vec1[i2], vec2);
				if (mn(vec1[i], vec1[i1], vec1[i2], vec1) == mn(vec1[i], vec1[i1], vec1[i2], vec2) && (mn(vec1[i], vec1[i1], vec1[i2], vec1) > 0)) {
					cout << "Точки, которые образуют треугольник с вершинами в этих точках,так что он содержит (строго внутри себя) равное количество точек первого и второго множества." << endl;
					cout << vec1[i][0] << "\t" << vec1[i][1] << endl << vec1[i1][0] << "\t" << vec1[i1][1] << endl << vec1[i2][0] << "\t" << vec1[i2][1] << endl;
					k = 1;
				}
			}
		}


	}
	if (k == 0) {
		cout << "Таких точек не нашлось\n";
	}
}

int main()
{
	int n,x=1;
	int mas[Cols][Rows];
	setlocale(LC_ALL, "Rus");
	while (x != 0) {
		cout << "Какое задание вы хотите выполнить:\n" << "1.Вывод элементов матрицы, обходя ее по часовой стрелке, начиная первой строки.\n";
		cout << "2.Даны два множества точек на плоскости.Из первого множества выбрать три различные точки так, чтобы треугольник с вершинами в этих точках, содержал(строго внутри себя) равное количество точек первого и второго множества.\n";
		cout << "0.Закончить програму\n";
		cin >> x;
		if (x == 2) {
			z2();
			cout << endl << endl;
		}
		else if (x == 1) {
			cout << "На каком типе массива вы хотите выполнить данную задачу\n1. Двумерный статический массив\n2. Двумерный динамический массив\n3.Вернуться к выбору задания\n0. Закончить программу\n";
			cin >> x;
			if (x == 1) {
				cout << "Введите размер квадратной матрицы\n";
				cin >> n;
				cout << "Хотите заполнить матрицу вручную?Нажмите 1, если да. А если хотите чтобы она заполнилась рандомными числами введите 2.\n";
				cin >> x;
				if (x == 1) {
					zap(mas, n);

					
					cout << endl << endl;
				}
				else { zaprand(mas, n); }
				staticc(mas, n);
			}
			else if (x == 2) {
				cout << "Введите размер квадратной матрицы\n";
				cin >> n;
				int** arr = new int* [n]; 
				for (int i = 0; i < n; i++)
					arr[i] = new int[n];
				cout << "Хотите заполнить матрицу вручную?Нажмите 1, если да. А если хотите чтобы она заполнилась рандомными числами введите 2.\n";
				cin >> x;
				if (x == 1) {
					zapd(arr, n);


					cout << endl << endl;
				}
				else { zaprandd(arr, n); }
				
				dinamicc(arr, n);
				cout << endl << endl;
			}
			else if (x == 0) { return 0; }
			else if (x == 3) { cout << endl << endl; }
			else {
				cout << "Попробуйте ввести значение заново\n"; cout << endl << endl;
			}
		}
		else if (x == 0) { return 0; }

		else {
			cout << "Попробуйте ввести значение заново\n";
			cout << endl << endl;
		}
	}

}
