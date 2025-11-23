#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
    int key;
    Node *left, *right;
    int height;
    Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

int height(Node* n){return n ? n->height : 0;}

int balanceFactor(Node* n){
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(Node* n){
    n->height = 1 + max(height(n->left), height(n->right));
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* balance(Node* node, int key){
    updateHeight(node);
    int bf = balanceFactor(node);

    if(bf > 1 && key < node->left->key) return rightRotate(node);

    if(bf < -1 && key > node->right->key) return leftRotate(node);

    if(bf > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(bf < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* insertNode(Node* node, int key){
    if(!node) return new Node(key);

    if(key < node->key) node->left = insertNode(node->left, key);
    else if (key > node->key) node->right = insertNode(node->right, key);

    return balance(node, key);
}

void rangeQuery(Node* root, int X, int Y){
    if(!root) return;

    if(root->key > X) rangeQuery(root->left, X, Y);

    if(root->key >= X && root->key <= Y) cout << root->key << " ";

    if(root->key < Y) rangeQuery(root->right, X, Y);
}

int main(){
    Node* root = NULL;

    int prices[] = {500, 1200, 300, 900, 1500, 750, 1100};
    for(int p : prices) root = insertNode(root, p);

    int X = 700, Y = 1300;
    cout << "Prices between " << X << " and " << Y << ": ";
    rangeQuery(root, X, Y);
    cout << endl;

    return 0;
}