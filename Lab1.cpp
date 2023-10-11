#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

void InsertionSort(vector <str> &a){
    ll ind = a.size() - 1;
    str key = a[ind];
    ll i = ind - 1;
    while (i >= 0 && a[i] > key){
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = key;
}

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream F;
    F.open("input1.txt", ios::in);
    vector <str> s1, s2;
    str x;
    while (!F.eof()){
        F >> x;
        s1.push_back(x);
        InsertionSort(s1);
    }
    F.close();
    F.open("input2.txt", ios::in);
    while (!F.eof()){
        F >> x;
        s2.push_back(x);
        InsertionSort(s2);
    }
    F.close();
    cout << "Упорядоченный список для файла input1.txt:\n";
    for (ll i = 0; i < s1.size(); i++) cout << s1[i] << " ";
    cout << endl << endl;
    cout << "Упорядоченный список для файла input2.txt:\n";
    for (ll i = 0; i < s2.size(); i++) cout << s2[i] << " ";
    cout << endl << endl;
    vector <str> s = s1;
    for (ll i = 0; i < s2.size(); i++){
        s.push_back(s2[i]);
        InsertionSort(s);
    }
    cout << "Единый упорядоченный список:\n";
    for (ll i = 0; i < s.size(); i++) cout << s[i] << " ";
    cout << endl;
}
