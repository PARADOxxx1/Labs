#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

size_t MAX_DEPTH;
size_t MAX_NUM_LEN = 0;

struct Node {
    ll value_;
    Node* left_;
    Node* right_;

    Node (ll value) : value_(value) {
    }
};

size_t NumLen(ll x) {
    if (x == 0) {
        return 1;
    }
    size_t d = 0;
    while (x) {
        ++d;
        x /= 10;
    }
    return d;
}

Node* InputTree(size_t cur_depth, str str) {
    if (cur_depth == MAX_DEPTH) {
        return nullptr;
    } else {
        if (cur_depth == 0) {
            cout << "Enter the tree from left to right (first go down to the left, then to the right). enter -1 if you want to stop entering this branch of the tree" << std::endl; // HELP INFO
        }
        ll x;
        cout << "Input " << str << " node: ";
        cin >> x;
        if (x == -1) {
            return nullptr;
        }
        MAX_NUM_LEN = max(NumLen(x), MAX_NUM_LEN);
        Node *cur_node = new Node(x);
        cur_node->left_ = InputTree(cur_depth + 1, "left");
        cur_node->right_ = InputTree(cur_depth + 1, "right");
        return cur_node;
    }
}

void PrintNum(ll x) {
    size_t cur_len = NumLen(x);
    for (ll i = 0; i < MAX_NUM_LEN + 1 - cur_len; ++i) {
        cout << ' ';
    }
    cout << x;
}

void PrintTree(Node *root) {
    queue<pair<Node*, pair<ll, ll> > > q;
    q.push({root, {0, 0}});
    ll last_pos = 0;
    ll last_depth = -1;
    while (!q.empty()) {
        auto tmp = q.front();
        Node *cur = tmp.first;
        ll cur_pos = tmp.second.first;
        ll cur_depth = tmp.second.second;
        q.pop();
        if (!cur) {
            continue;
        }
        if (last_depth != cur_depth) {
            if (cur_depth) {
                cout << endl;
            }
            for (ll i = 0; i < (MAX_DEPTH - cur_depth) * (MAX_NUM_LEN + 1) / 2; ++i) {
                cout << ' ';
            }
            PrintNum(cur->value_);
        }
        else {
            for (ll i = 0; i < (MAX_NUM_LEN + 1) * (cur_pos - last_pos - 1); ++i) {
                cout << ' ';
            }
            PrintNum(cur->value_);
        }
        last_depth = cur_depth;
        last_pos = cur_pos;
        q.push({cur->left_, {cur_pos * 2, cur_depth + 1}});
        q.push({cur->right_, {cur_pos * 2 + 1, cur_depth + 1}});
    }
}

void DeleteTree(Node* cur_node) {
    if (cur_node) {
        DeleteTree(cur_node->left_);
        DeleteTree(cur_node->right_);
        delete cur_node;
    }
}

int main() {
    cout << "Input max depth" << '\n';
    cin >> MAX_DEPTH;
    Node* root = InputTree(0, "root");
    PrintTree(root);
    cout << endl;
    DeleteTree(root);
    return 0;
}
