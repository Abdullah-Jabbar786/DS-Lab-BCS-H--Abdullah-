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

int height(Node* n){
    return n ? n->height : 0;
}

int balanceFactor(Node* n){
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(Node* n){
    if(n) n->height = 1 + max(height(n->left), height(n->right));
}

Node* rightRotate(Node* y){
    cout << "Rotation performed: RIGHT ROTATION (LL Case)\n";
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x){
    cout << "Rotation performed: LEFT ROTATION (RR Case)\n";
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* balance(Node* node, int key){
    updateHeight(node);
    int bf = balanceFactor(node);

    cout << "Balance factor of node (" << node->key << ") = " << bf << endl;

    if(bf > 1 && key < node->left->key) return rightRotate(node);

    if(bf < -1 && key > node->right->key) return leftRotate(node);

    if(bf > 1 && key > node->left->key){
        cout << "Rotation performed: LEFT-RIGHT (LR Case)\n";
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(bf < -1 && key < node->right->key){
        cout << "Rotation performed: RIGHT-LEFT (RL Case)\n";
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* insertNode(Node* node, int key){
    if(!node){
        cout << "\nInserted: " << key << endl;
        return new Node(key);
    }

    if(key < node->key) node->left = insertNode(node->left, key);
    else if(key > node->key) node->right = insertNode(node->right, key);
    else return node;

    Node* newRoot = balance(node, key);
    cout << "Current tree height = " << height(newRoot) << "\n";
    return newRoot;
}

Node* minValueNode(Node* node){
    Node* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}

Node* deleteNode(Node* root, int key){
    if (!root) return root;

    if(key < root->key) root->left = deleteNode(root->left, key);
    else if(key > root->key) root->right = deleteNode(root->right, key);
    else{
        cout << "\nDeleting: " << key << endl;

        if(!root->left || !root->right){
            Node* temp = root->left ? root->left : root->right;
            if(!temp){
                temp = root;
                root = NULL;
            } 
            else *root = *temp;
            delete temp;
        }
        else{
            Node* temp = minValueNode(root->left);
            root->key = temp->key;
            root->left = deleteNode(root->left, temp->key);
        }
    }

    if(!root) return root;

    updateHeight(root);
    int bf = balanceFactor(root);
    cout << "Balance factor after delete (" << root->key << ") = " << bf << endl;

    if(bf > 1 && balanceFactor(root->left) >= 0){
        cout << "Rotation performed: RIGHT ROTATION\n";
        return rightRotate(root);
    }
    if(bf > 1 && balanceFactor(root->left) < 0){
        cout << "Rotation performed: LEFT-RIGHT\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf < -1 && balanceFactor(root->right) <= 0){
        cout << "Rotation performed: LEFT ROTATION\n";
        return leftRotate(root);
    }
    if(bf < -1 && balanceFactor(root->right) > 0){
        cout << "Rotation performed: RIGHT-LEFT\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    cout << "Current tree height = " << height(root) << endl;
    return root;
}

int main(){
    Node* root = NULL;

    int rollNumbers[] = {40, 20, 10, 25, 50, 60};
    for (int r : rollNumbers) root = insertNode(root, r);

    root = deleteNode(root, 20);
    root = deleteNode(root, 50);
    root = deleteNode(root, 25);

    return 0;
}
