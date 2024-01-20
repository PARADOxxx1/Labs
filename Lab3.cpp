#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

struct Node{
    ll x, y;
    Node *next;
    Node(ll x, ll y) : x(x), y(y), next(nullptr){}
};

struct List {
    Node *first;
    Node *last;
    List() : first(nullptr), last(nullptr) {}

    bool emty() {
        return first == nullptr;
    }

    void add(ll x, ll y) {
        Node *p = new Node(x, y);
        if (emty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void remove_first(){
        if (emty()) return;
        Node *p = first;
        first = p->next;
        delete p;
    }

    void print() {
        if (emty()) return;
        Node *p = first;
        while (p) {
            cout << p->x << " " << p->y << endl;
            p = p->next;
        }
        cout << endl;
    }
};

int shortest_path(ll **labyrinth, ll sx, ll sy, ll m, ll n) {
    if (labyrinth[sx][sy] == 1) {
        return -1;
    }
    List a;
    ll dx[] = { -1, 0, 1, 0 };
    ll dy[] = { 0, 1, 0, -1 };
    ll **dist = new ll *[n];
    for (ll i = 0; i < n; i++) {
        dist[i] = new ll[m];
        for (ll j = 0; j < m; j++){
            dist[i][j] = 1e9;
        }
    }
    dist[sx][sy] = 0;
    a.add(sx, sy);
    while (a.emty() != 1) {
        ll x = a.first->x, y = a.first->y;
        a.remove_first();
        for (ll i = 0; i < 4; i++) {
            ll new_x = x + dx[i], new_y = y + dy[i];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && labyrinth[new_y][new_x] == 0 && dist[new_x][new_y] > dist[x][y] + 1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                a.add(new_x, new_y);
            }
        }
    }
    ll min_dist = 1e9;
    for (ll i = 0; i < n; i++) {
        min_dist = min(min_dist, dist[i][0]);
        min_dist = min(min_dist, dist[i][m - 1]);
    }
    for (ll i = 0; i < m; i++) {
        min_dist = min(min_dist, dist[0][i]);
        min_dist = min(min_dist, dist[n - 1][i]);
    }
    return (min_dist == 1e9) ? -1 : min_dist;
}

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream F;
    F.open("labyrinth.txt", ios::in);
    ll m, n;
    F >> m;
    F >> n;
    ll** labyrinth = new ll* [m];
    for (ll i = 0; i < m; i++) {
        labyrinth[i] = new ll[n];
    }
    for (ll i = 0; i < m; i++){
        for (ll j = 0; j < n; j++){
            ll x;
            F >> x;
            labyrinth[i][j] = x;
        }
    }
    ll shortest_distance = shortest_path(labyrinth, 2, 2, m, n);
    cout << "The shortest path length is " << shortest_distance << endl;
}
