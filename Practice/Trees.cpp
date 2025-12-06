void preorder (Node* root) {
    if (root!=nullptr) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// rest inorder postorder you can do it

Node* bstSearch (Node* root, int key) {
    if (root->data==key || root==nullptr) return root;
    if (root->data>key) return (root->left, key);
    else return (root->right, key);
}

Node* findMin (Node* root) {
    if (root==nullptr) return nullptr;
    while (root->left!=nullptr) root=root->left;
    return root;
}

// similarly find max (right me jana hai)

Node* successor (Node* root, Node* target) {
    if (Node->right!=NULL) return findmin(root->right);

    Node* succssor = NULL;
    while (root!=NULL) {
        if (root->data<target->data) {
            root=root->right;
        } else if (root->data>target->data) {
            successor = root->data;
            root=root->left;
        } else break;
    }
    return successor;
}

Node* dleteNode (Node* root, Node* target) {
    if (root==NULL) return node;

    if (root->data>target) root->left = deleteNode(root->left,key);
    if (root->data<target) root->right = deleteNode(root->right,key);
    else {
        if (root->left==NULL) {
            Node*temp = root->right;
            delete root;
            return temp;
        } else if (root->right==NULL) {
            Node* temp = root->left;
            delete root;
            reurn temp;
        }
        Node* temp = findMin(root->right,target);
        root->data=temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}