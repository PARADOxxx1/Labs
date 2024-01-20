#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

struct Node{
    ll data;
    Node *next;
    Node(ll data) : data(data), next(nullptr){}
};

struct List {
    Node *first;
    Node *last;
    List() : first(nullptr), last(nullptr) {}

    bool emty() {
        return first == nullptr;
    }

    void add(ll data) {
        Node *p = new Node(data);
        if (emty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (emty()) return;
        Node *p = first;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream F;
    F.open("matr.txt", ios::in);
    ll n;
    F >> n;
    List *a = new List[n]();
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            ll b;
            F >> b;
            if (b == 1){
                a[i].add(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        a[i].print();
    }
}
