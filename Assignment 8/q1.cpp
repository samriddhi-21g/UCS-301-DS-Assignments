// preorder, inorder, postorder traversal of trees

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

void preorder (Node* root) {
    if (root!=nullptr) {
        cout<<root->data<<" ";
        preorder (root->left);
        preorder (root->right);
    }
}

void inorder (Node* root) {
    if (root!=nullptr) {
        inorder (root->left);
        cout<<root->data<<" ";
        inorder (root->right);
    }
}

void postorder (Node* root) {
    if (root!=nullptr) {
        postorder (root->left);
        postorder (root->right);
        cout<<root->data<<" ";
    }
}

int main () {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7); 

    cout<<"Preorder : ";
    preorder(root);
    cout<<endl<<"Inorder : ";
    inorder(root);
    cout<<endl<<"Postorder : ";
    postorder(root);
    return 0;
}

