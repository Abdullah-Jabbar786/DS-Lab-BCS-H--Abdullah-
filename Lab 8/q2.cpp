#include <iostream>
#include <string>
using namespace std;

class Song{
public:
    int playCount;
    string title;
    Song* left;
    Song* right;

    Song(int count, string name){
        playCount = count;
        title = name;
        left = right = nullptr;
    }
};

class MusicBST{
public:
    Song* root;

    MusicBST(){
        root = nullptr;
    }

    Song* insert(Song* node, int count, string name){
        if(node == nullptr) return new Song(count, name);

        if(count<node->playCount) node->left = insert(node->left, count, name);
        else if (count > node->playCount) node->right = insert(node->right, count, name);

        return node;
    }

    void insertSong(int count, string name){
        root = insert(root, count, name);
    }

    Song* search(Song* node, int count){
        if(node == nullptr || node->playCount == count) return node;

        if(count < node->playCount) return search(node->left, count);
        else return search(node->right, count);
    }

    void inorder(Song* node){
        if(node == nullptr) return;
        inorder(node->left);
        cout<<node->title<<" ("<<node->playCount<<" plays)"<<endl;
        inorder(node->right);
    }

    void postorder(Song* node){
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->title<<" ("<<node->playCount<<" plays)"<<endl;
    }

    Song* findMin(Song* node){
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    Song* deleteNode(Song* root, int count){
        if(root == nullptr) return root;

        if(count < root->playCount) root->left = deleteNode(root->left, count);
        else if (count > root->playCount) root->right = deleteNode(root->right, count);
        else{
            if(root->left == nullptr){
                Song* temp = root->right;
                delete root;
                return temp;
            } 
            else if(root->right == nullptr){
                Song* temp = root->left;
                delete root;
                return temp;
            }

            Song* temp = findMin(root->right);
            root->playCount = temp->playCount;
            root->title = temp->title;
            root->right = deleteNode(root->right, temp->playCount);
        }
        return root;
    }

    void showInorder(){
        cout<<"\n Songs (Least → Most Played):"<<endl;
        inorder(root);
    }

    void showPostorder(){
        cout<<"\nSongs Removed (Reverse Popularity Order):"<<endl;
        postorder(root);
    }

    void deleteSong(int count){
        root = deleteNode(root, count);
    }
};

int main(){
    MusicBST bst;

    bst.insertSong(50, "Mjhe Tum Nazar Se Gira To Rahe Ho");
    bst.insertSong(100, "Tujh Ko Dariya Dili Ki Qasam");
    bst.insertSong(20, "X's");
    bst.insertSong(30, "Let Her Go");
    bst.insertSong(40, "To Kya Ye Tay Hai");
    bst.insertSong(60, "Am I that Easy To Forget?");
    bst.insertSong(70, "They're Hanging Me Tonight");

    bst.showInorder();

    cout<<"\nSearching for song with 60 plays..."<<endl;
    Song* found = bst.search(bst.root, 60);
    if(found) cout<<"Found: "<<found->title<<" ("<<found->playCount<<" plays)"<<endl;
    else cout<<"Song not found."<<endl;

    bst.showPostorder();

    cout<<"\nDeleting song with 70 plays..."<<endl;
    bst.deleteSong(70);
    bst.showInorder();

    return 0;
}