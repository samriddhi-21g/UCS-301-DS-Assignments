// Insert Node, Delete Node, max depth, min depth

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

Node* findmin (Node* root) {
    if (root==nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* insertNode (Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    } 
    if (value<root->data) root->left = insertNode (root->left, value);
    else if (value>root->data) root->right = insertNode (root->right, value);
    else {
        cout<<"Duplicate value.";
    }
    return root;
}

Node* deleteNode (Node* root, int key) {
    if (root==NULL) {
        return root;
    }
    if (key<root->data) {
        root->left = deleteNode(root->left,key);
    } else if (key>root->data) {
        root->right = deleteNode(root->right,key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left; 
            delete root;
            return temp;
        } 
        Node* temp = findMin (root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth (Node* root) {
    if (root==NULL) return 0;
    return 1 + max(maxDepth(root->left),maxDepth(root->right));
}

int minDepth (Node* root) {
    if (root==NULL) return 0;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left),minDepth(root->right));
}

int main () {
    return 0;
}