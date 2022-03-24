//Дано предложение, состоящее из слов, разделенных запятой или пробелами.Вывести слова предложения предварительно преобразовав их следующим образом :
//-перенести последнюю букву в начало слова;
//-удалить из слова повторные вхождения каждой буквы.

#include <iostream>
#include <string>
using namespace std;
void charr() {
	
	char str[100], s[100];
	int k = 0, prov, a[10];
	cout << "Введите предложение:\n";
	cin.getline(str, 100);
	str[strlen(str) + 1] = '\0';
	str[strlen(str)] = ' ';




	for (int i = 0; i < strlen(str); i++) {
		if ((str[i] == ' ') || (str[i] == ',') || ((str[i] == '.') && (i = strlen(str) - 2))) {

			s[k + 1] = '\0';
			s[k] = ' ';

			for (int i1 = strlen(s) - 2; i1 >= 0; i1--) {

				s[i1 + 1] = s[i1];
			}
			s[0] = s[strlen(s) - 1];
			s[strlen(s) - 1] = '\0';



			k = 0;
			int kk = 0;

			char ss[10];
			for (int i1 = 0; i1 < strlen(s); i1++) {
				prov = 0;
				for (int i2 = 0; i2 < k; i2++) {

					if (a[i2] == i1) {
						prov = 1;
						break;
					}
				}

				if (prov == 1)
					continue;
				else {
					ss[kk] = s[i1];
					kk++;
				}
				for (int i2 = i1 + 1; i2 < strlen(s); i2++) {
					if ((s[i1] == s[i2]) || (int(s[i1]) - 32 == int(s[i2])) || (int(s[i1]) == int(s[i2]) - 32)) {
						a[k] = i2; k++;
					}
				}


			}


			ss[kk] = '\0';

			cout << ss << " ";





			k = 0;
			s[0] = '\0';

		}
		else {

			s[k] = str[i];

			k++;
		}
	}



}
void strr() {

	
	string s, str, ss = "";
	int a[100], k;
	cout << "Введите предложение:\n";
	getline(cin, s);
	s += " ";
	int prov;
	cout << "Преобразованные слова:\n";
	for (int i = 0; i < s.length(); i++) {

		if ((s[i] == ' ') || (s[i] == ',') || ((s[i] == '.') && (i = s.length() - 2))) {

			str = str + " ";
			for (int i1 = str.length() - 1; i1 >= 0; i1--) {
				str[i1 + 1] = str[i1];
			}
			str[0] = str[str.length() - 1];
			str.pop_back();
			k = 0;



			ss = "";
			for (int i1 = 0; i1 < str.length(); i1++) {


				prov = 0;
				for (int i2 = 0; i2 < k; i2++) {

					if (a[i2] == i1) {
						prov = 1;
						break;
					}
				}

				if (prov == 1)
					continue;
				else
					ss += str[i1];
				for (int i2 = i1 + 1; i2 < str.length(); i2++) {
					if ((str[i1] == str[i2]) || (int(str[i1]) - 32 == int(str[i2])) || (int(str[i1]) == int(str[i2]) - 32)) {
						a[k] = i2; k++;
					}
				}


			}




			cout << ss << " ";


			str = "";
			continue;
		}
		else
			str = str + s[i];

	}

}
int main()
{ 
	int k;
	setlocale(LC_ALL, "Rus");
	cout << "Введите на каком типе данных хотите выполнить задачу\n1. Нуль терминальная строка\n2.string\n";
	cin >> k;
	cin.ignore();
	if (k == 1)
		charr();
	else
		strr();

	

}