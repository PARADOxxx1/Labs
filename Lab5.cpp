#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

struct Node {
    str word;
    vector<ll> pos_;
    Node* left, * right;
};

Node* createNode(str item, ll pos) {
    Node* temp = new Node;
    temp->word = item;
    temp->pos_.push_back(pos);
    temp->left = temp->right = NULL;
    return temp;
}

Node* ins(Node* node, str word, ll pos) {
    if (node == NULL) return createNode(word, pos);
    if (word < node->word)
        node->left = ins(node->left, word, pos);
    else if (word > node->word)
        node->right = ins(node->right, word, pos);
    else
        node->pos_.push_back(pos);
    return node;
}

void order(Node* root) {
    if (root != NULL) {
        order(root->left);
        cout << root->word << ": ";
        for (ll i = 0; i < root->pos_.size(); i++)
            cout << root->pos_[i] + 1 << " ";
        cout << endl;
        order(root->right);
    }
}

void print(Node* root){
    Node* temp = root;
    if (temp != nullptr){
        cout << temp->word << endl;
        print(temp->left);
        print(temp->right);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* root = nullptr;
    str word;
    ll pos = 0;
    ifstream F;
    F.open("input.txt");
    while (F >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        root = ins(root, word, pos);
        pos++;
    }
    F.close();
    //print(root);
    order(root);
}
