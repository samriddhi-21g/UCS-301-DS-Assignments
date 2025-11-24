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

Node* deleteHead (Node* head) {
    Node* temp = head;
    head=head->next;
    delete(temp);
    return head;
}

void deleteTail (Node* temp, Node* prev) {
    Node* del = temp;
    prev->next = nullptr;
    delete(del);
    return;
}

void deleteNode (Node* temp, Node* prev) {
    Node* del = temp;
    prev->next = temp->next;
    delete (del);
    return;
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

Node* countAndDeleteOccurrences (Node* head, int val) {
    Node* temp = head;
    Node* prev = NULL;
    int count=0;
    while (temp!=NULL) {
        if (temp->val==val) {
            count++;
            if (prev==NULL && temp->next==NULL){ cout<<"Number of occurrences : "<<count; delete (temp); return nullptr;} 
            else if (prev==NULL) { head=deleteHead(temp); temp=head; continue; }
            else if (temp->next==NULL) { deleteTail(temp, prev); break; }
            else { deleteNode(temp, prev); temp=prev->next; continue; }
        }
        prev = temp;
        temp = temp->next;
    }
    cout<<"Number of occurrneces : "<<count<<endl;
    displayLL(head);
    return head;
}

int main () {
    Node* head = createLL();
    int val;
    cout<<"Enter value : ";
    cin>>val;

    countAndDeleteOccurrences(head, val);
    
    return 0;
}
