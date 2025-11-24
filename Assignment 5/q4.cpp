#include <iostream>
using namespace std;

class Node {
    public :
    int val;
    Node* next;

    public :
    Node (int val1, Node* next1 = nullptr) {
        val = val1;
        next = next1;
    }
};

Node* createLL () {
    int n;
    cout<<"Enter Number of elements : ";
    cin>>n;
    cout<<endl<<"Enter elements : ";
    Node* prev = nullptr;
    Node* head;
    for (int i=0; i<n; i++) {
        int node;
        cin>> node;
        Node* newnode = new Node(node);
        
        if (prev==NULL) head = newnode;
        else prev->next =newnode;
        prev = newnode;
    }
    return head;
}

void displayLL (Node* head) {
    Node* temp = head;
    cout<<"LL elements are : ";
    while (temp!=NULL) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverseLL (Node* head) {
    Node* prev = NULL;
    Node* temp = head;
    Node* front = head;

    while (temp!=NULL) {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

int main () {
    Node* head = createLL();
    head = reverseLL(head);
    cout<<"Reversed : "<<endl;
    displayLL(head);
    return 0;
}