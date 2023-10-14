#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

struct List{
    str data;
    List *next;

    List() {
        next = nullptr;
    }

    List(const string& s) {
        data = s;
        next = nullptr;
    }
};

void Print(List *head) {
	List *temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

List *add(List *p, str s)  {
    if (!p) {
        return new List(s);
    }
    List *q = p;
    List *prev = p;
    while (q) {
        if ((q->data) < s) {
            prev = q;
            q = q->next;
        }
        else {
            List *new_elem = new List(s);
            if (q != p) {
                new_elem->next = prev->next;
                prev->next = new_elem;
            }
            else {
                new_elem->next = p;
                p = new_elem;
            }
            break;
        }
    }
    if (!q) {
        List *new_elem = new List(s);
        new_elem->next = prev->next;
        prev->next = new_elem;
    }
    return p;
}

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream F;
    F.open("input1.txt", ios::in);
    List *s1 = nullptr, *s2 = nullptr, *s3;
    str x;
    while (!F.eof()){
        F >> x;
        s1 = add(s1, x);
    }
    F.close();
    cout << "Упорядоченный список для файла input1.txt:\n";
    Print(s1);
    cout << endl;
    List *s = s1;
    F.open("input2.txt", ios::in);
    while (!F.eof()){
        F >> x;
        s2 = add(s2, x);
        s = add(s, x);
    }
    F.close();
    cout << "Упорядоченный список для файла input2.txt:\n";
    Print(s2);
    cout << endl;
    cout << "Единый упорядоченный список:\n";
    Print(s);

    //Очистка памяти
    while (s1) {
        s3 = s1->next;
        delete s1;
        s1 = s3;
    }
    while (s2) {
        s3 = s2->next;
        delete s2;
        s2 = s3;
    }
    while (s) {
        s3 = s->next;
        delete s;
        s = s3;
    }
}
