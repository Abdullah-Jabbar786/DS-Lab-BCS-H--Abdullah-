#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    Person* mother; // left child
    Person* father; // right child

    Person(string n){
        name = n;
        mother = nullptr;
        father = nullptr;
    }
};

class FamilyTree{
public:
    Person* root;

    void displayLeafNodes(Person* node){
        if (node==nullptr) return;

        if(node->mother==nullptr && node->father==nullptr){
            cout<<node->name<<" ";
            return;
        }
        displayLeafNodes(node->mother);
        displayLeafNodes(node->father);
    }

    int height(Person* node){
        if(node==nullptr) return 0;
        int leftH = height(node->mother);
        int rightH = height(node->father);
        return (leftH>rightH ? leftH : rightH) + 1;
    }

    void printLevel(Person* node, int level){
        if(node==nullptr) return;
        if(level==1) cout << node->name << " ";
        else{
            printLevel(node->mother, level - 1);
            printLevel(node->father, level - 1);
        }
    }

    FamilyTree(){
        root = nullptr;
    }

    void createFamily(){
        root = new Person("Emma"); // youngest
        root->mother = new Person("Sophia");
        root->father = new Person("Liam");

        root->mother->mother = new Person("Olivia");
        root->mother->father = new Person("James");
        root->father->mother = new Person("Ava");
        root->father->father = new Person("Noah");
    }

    void displayRoot(){
        if(root) cout<<"Youngest person (Root): "<<root->name<<endl;
    }

    void showAncestors(){
        cout<<"\nAncestors with no known parents (Leaf Nodes): ";
        displayLeafNodes(root);
        cout<<endl;
    }

    void showHeight(){
        cout<<"\nHeight of the Family Tree: "<<height(root)<<endl;
    }

    void showLevels(){ 
        int h = height(root);
        cout<<"\nLevels (Generations):\n";
        for (int i = 1; i <= h; i++){
            cout << "Generation " << i << ": ";
            printLevel(root, i);
            cout<<endl;
        }
    }
};

int main(){
    FamilyTree family;
    family.createFamily();

    cout<<"-----FAMILY TREE DETAILS-----\n"<<endl;
    family.displayRoot();
    family.showAncestors();
    family.showHeight();
    family.showLevels();

    return 0;
}
