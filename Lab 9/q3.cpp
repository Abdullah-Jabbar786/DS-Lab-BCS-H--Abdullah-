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

int height(Node* n){ return n ? n->height : 0;}
int balanceFactor(Node* n){ return n ? height(n->left) - height(n->right) : 0;}
void updateHeight(Node* n){ n->height = 1 + max(height(n->left), height(n->right));}

Node* rightRotate(Node* y){
    cout << "Rotation: RIGHT (LL Case)\n";
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x){
    cout << "Rotation: LEFT (RR Case)\n";
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

    if(bf > 1){
        if (key < node->left->key)
            return rightRotate(node);
        cout << "Rotation: LEFT-RIGHT (LR)\n";
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(bf < -1){
        if (key > node->right->key)
            return leftRotate(node);
        cout << "Rotation: RIGHT-LEFT (RL)\n";
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* insertNode(Node* node, int key){
    if(!node){
        cout << "Inserted severity: " << key << endl;
        return new Node(key);
    }

    if(key < node->key) node->left = insertNode(node->left, key);
    else if(key > node->key) node->right = insertNode(node->right, key);

    Node* newRoot = balance(node, key);
    cout << "Tree height: " << height(newRoot) << "\n";
    return newRoot;
}

Node* rightmost(Node* root){
    while(root->right) root = root->right;
    return root;
}

Node* maxValue(Node* r){return rightmost(r);}

Node* minValue(Node* r){
    while (r->left) r = r->left;
    return r;
}

Node* deleteNode(Node* root, int key){
    if(!root) return root;

    if(key < root->key) root->left = deleteNode(root->left, key);
    else if(key > root->key) root->right = deleteNode(root->right, key);
    else{
        cout << "Discharged patient score: " << key << endl;

        if(!root->left || !root->right){
            Node* temp = root->left ? root->left : root->right;
            if(!temp) root = NULL;
            else *root = *temp;
            delete temp;
        } 
        else{
            Node* temp = minValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;
    updateHeight(root);

    int bf = balanceFactor(root);
    cout << "Balance factor after delete: " << bf << endl;

    if(bf > 1 && balanceFactor(root->left) >= 0){
        cout << "Rotation: RIGHT\n";
        return rightRotate(root);
    }
    if(bf > 1 && balanceFactor(root->left) < 0){
        cout << "Rotation: LEFT-RIGHT\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf < -1 && balanceFactor(root->right) <= 0){
        cout << "Rotation: LEFT\n";
        return leftRotate(root);
    }
    if(bf < -1 && balanceFactor(root->right) > 0){
        cout << "Rotation: RIGHT-LEFT\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    cout << "Tree height: " << height(root) << endl;
    return root;
}

int main(){
    Node* root = NULL;

    int arrivals[] = {50, 30, 70, 20, 40, 80, 90};
    for(int s : arrivals){
        cout << "\nNew patient severity: " << s << endl;
        root = insertNode(root, s);
        cout << "Highest severity now: " << maxValue(root)->key << "\n";
    }

    int discharged[] = {30, 80};
    for(int d : discharged){
        cout << "\nDischarge patient with score: " << d << endl;
        root = deleteNode(root, d);
        if(root) cout << "Highest severity now: " << maxValue(root)->key << "\n";
    }

    return 0;
}