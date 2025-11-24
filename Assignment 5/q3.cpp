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
        cout<<i+1<<" element : ";
        cin>> node;
        Node* newnode = new Node(node);
        
        if (prev==NULL) head = newnode;
        else prev->next =newnode;
        prev = newnode;
    }
    return head;
}

int findMiddle (Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

int main () {
    Node* head = createLL();
    cout<<"Middle of LL is : "<<findMiddle(head);
    return 0;
}