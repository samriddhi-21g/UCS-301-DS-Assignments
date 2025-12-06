// BST search, find min, find max, successor, predecessor

#include <iostream>
using namespace std;

class Node {
    
    public:
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* bstsearch (Node* root, int key) {
    if (root==nullptr || root->data==key) return root;
    if (key < root->data) return bstsearch(root->left, key);
    else return bstsearch(root->right, key);
}

Node* findmin (Node* root) {
    if (root==nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* findmax (Node* root) {
    if (root==nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}

Node* successor (Node* root, Node* target) {
    if (target->right!=NULL) return findmin(target->right);
    Node* successor = NULL;
    while (root!=NULL) {
        if (target->data<root->data) {
            successor = root;
            root=root->left;
        } else if (target->data>root->data) {
            root=root->right;
        } else {
            break;
        }
    }
    return successor;
}

Node* predecessor (Node* root, Node* target) {
    if (target->left!=NULL) return findmax(target->left);
    Node* predecessor= NULL;
    while (root!=NULL) {
        if (target->data>root->data) {
            predecessor = root;
            root=root->right;
        } else if (target->data<root->data) {
            root=root->left;
        } else {
            break;
        }
    }
    return predecessor;
}
 
int main () {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80); 

    int key;
    cout<<"Enter the value to be searched : ";
    cin>>key;

    if (bstsearch(root, key)==nullptr) {
        cout<<"Key not found";
    } else {
        cout<<"Key found";
    }

    cout<<endl;
    cout<<"Min : "<<(findmin(root))->data;

    cout<<endl;
    cout<<"Max : "<<(findmax(root))->data;

    return 0;
}
   