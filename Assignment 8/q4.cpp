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

bool isBSTUtil (Node* root, int minVal, int maxVal) {
    if (root==NULL) return true;
    if (root->data<=minVal || root->data>=maxVal) return false;
    return isBSTUtil(root->left,minVal,root->data) && isBSTUtil(root->right,root->data,maxVal);
}

bool isBST (Node* root) {
    return isBSTUtil(root,INT_MIN,INT_MAX);
}

int main () {
    return 0;
}
