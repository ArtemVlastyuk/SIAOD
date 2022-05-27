#include <iostream>
#include<string>
#include <vector>
#include <regex>
using namespace std;
int KMPSearch(string strin, string substring, int d[]) {
    int  sl, ssl;
    int res = -1;
    sl = strin.size();
    ssl = substring.size();
   
    int  i = 1, j = 0;
   
    
    d[0] = 0;
    while (j < ssl && i<ssl) {



        if (substring[i] == substring[j]) {
            d[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0) {
            d[i] = 0;
            i++;
        }
        else j = d[j - 1];
    }
    
    
    int k = 0;
    int l = 0;
   
    while (k < sl && l < ssl) {
        if (substring[l] == strin[k]) {
            k++;
            l++;
            if (l == ssl)
                return k-ssl;

        }
        else if (l == 0) {
            k++;
            if (k == sl)
                return -1;

        }
        else
            l = d[l - 1];
    }
    
    return res;
}
vector<string> prov(vector<string> arr) {
    
    regex regular("^([0-9A-Za-z]{8,15})$");
    vector<string> strarr;
    for (int i = 0; i < arr.size(); i++) {
        cmatch result;
        if (regex_match(arr[i].c_str(), result, regular))
            strarr.push_back(arr[i]);


    }
    return strarr;

}
void m() {
    vector<string> strarr = { "artem2003","aaabbbccc", " aanaanana","aaaabbbb ","1111aqaaaa","qqqq1111//","artteeme"};
    cout << "Список с паролями: \n";
    for (int i = 0; i < strarr.size(); i++)
        cout << strarr[i] << endl;
    strarr = prov(strarr);
    cout << "Подходящие пароли:\n";
    for (int i = 0; i < strarr.size(); i++)
        cout << strarr[i] << endl;

}
int main() {
    setlocale(LC_ALL, "Ru");
    cout << "Введите 2 если хотите выполнить 2 задание, иначе выполниться первое\n";

    int y;
    cin >> y;
    if (y == 2) {
        m();
        return 0;
    }
    string str;
    cin >> str;
    cout << "Исходная строка " << str << " \nРазмер:" << str.size() << endl;
    //string str = "asduhsbcfdyuavyufvhvdfuaasduhsbcfdyuavyufvhvdfuaasduhsbcfdyuavyufvhvdfuaasduhsbcfdyuavyufvhvdfuaasduhsbcfdyuavyufvhvdfua";
    for (int i = 0; i < rand() % 4 + 2; i++) {
        str += str;
    }
   
    int x = rand() % str.size();
    string strsub = str.substr(x, str.size() - x - rand() % x);
    
    cout << "Подстрока: " << strsub<<endl;
    int d[1000];
    int k = KMPSearch(str, strsub,d);
    //cout << k;

    vector<int> a;

    

    a.push_back(k);
    str = str.substr(k + 1, str.size() - k);
    //cout << str << endl;
  
    while (true) {
        int k = KMPSearch(str, strsub,d);
        if (k==-1)
            break;
        
        a.push_back(k+a.back()+1);
        str=str.substr(k+1, str.size() - k);
        
    

    }
    
    
  
    if (a.size() > 2) {
        for (int i = 1; i < a.size(); i++) {
            bool check = true;
            for (int i1 = 0; i1 < i; i1++) {
                if (!(a[a.size() - (-i1 + i)] - a[a.size() - 2 * (-i1 + i)] == a[a.size() - 2 * (-i1 + i)] - a[a.size() - 3 * (-i1 + i)]))
                    check = false;
            }
            if (check == true) {
                cout <<"Размер исходной строки: "<<  a[a.size() - (+i)] - a[a.size() - 2 * (+i)];
                break;
            }
        }
    }
    else
        for (int i = strsub.size()-2; i > 0; i--)
            if (d[i] == 0) {
                cout <<"Размер исходной строки: " << i + 1;
                break;
            }
}