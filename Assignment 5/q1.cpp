#include <bits/stdc++.h>
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

Node* insertAtStart (Node* head) {
    int value;
    cout<<"Enter value to be inserted : ";
    cin>>value;
    Node* newnode = new Node(value, head);
    return newnode;
}

void insertAtEnd (Node* head) {
    int value;
    cout<<"Enter value to be inserted : ";
    cin>>value;
    Node* temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    Node* newnode = new Node(value);
    temp->next=newnode;
}

void insertInMiddleAfter (Node* head) {
    int value, aftervalue;
    cout<<"Enter value to be inserted : ";
    cin>>value;
    cout<<"Enter after which ele this is to be inserted : ";
    cin>>aftervalue;
    Node* temp = head;
    while (temp->val!=aftervalue) {
        temp=temp->next;
    }
    Node* newnode = new Node(value,temp->next);
    temp->next = newnode;
    return;
}

void insertInMiddleBefore (Node* head) {
    int value,beforevalue;
    cout<<"Enter value to be inserted : ";
    cin>>value;
    cout<<"Enter element before it has to be inserted : ";
    cin>>beforevalue;
    Node* temp = head;
    Node* prev;
    while (temp->val!=beforevalue) {
        prev = temp;
        temp=temp->next;
    }
    Node* newnode = new Node(value,temp);
    prev->next = newnode;
    return; 
}

Node* deleteAtStart (Node* head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deleteAtEnd (Node* head) {
    Node* temp = head;
    while (temp->next->next!=NULL) {
        temp = temp->next;
    }
    Node* dnode = temp->next;
    temp->next = NULL;
    free (dnode);
    return;
}

void deleteNode (Node* head) {
    int value;
    cout<<"Enter value to be deleted : ";
    cin>>value;
    Node* temp = head;
    Node* prev;
    while (temp->val!=value) {
        prev = temp;
        temp=temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

void searchNode (Node* head) {
    int value;
    cout<<"Enter value to be inserted : ";
    cin>>value;
    int count = 0;
    Node* temp = head;
    while (temp!=NULL && temp->val!=value) {
        temp=temp->next;
        count++;
    }
    if (!temp) {
        cout<<"Element not found."<<endl;
        return;
    }
    cout<<"The position of node from head is : "<<count; 
    return;
}

void displayElements (Node* head) {
    Node* temp = head;
    cout<<"LL elements are : ";
    while (temp!=NULL) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main () {
    int n;
    cout<<"Create your LL"<<endl;
    Node* head = createLL();
    cout<<endl;
    do {
        cout<<endl<<"--------MENU-------"<<endl
            <<"1.Insert in the beginning"<<endl
            <<"2.Insert at the end"<<endl
            <<"3.Insert after element"<<endl
            <<"4.Insert before element"<<endl
            <<"5.Delete at start"<<endl
            <<"6.Delete at end"<<endl
            <<"7.Delete given node"<<endl
            <<"8.Search node"<<endl
            <<"9.Display LL"<<endl
            <<"10. exit"<<endl;
        cout<<endl<<"Enter your choice : ";
        cin>>n;

        switch (n) {
            case 1 : head = insertAtStart(head); break;
            case 2 : insertAtEnd(head); break;
            case 3 : insertInMiddleAfter(head); break;
            case 4 : insertInMiddleBefore(head); break;
            case 5 : head = deleteAtStart(head); break;
            case 6 : deleteAtEnd(head); break;
            case 7 : deleteNode(head); break;
            case 8 : searchNode(head); break;
            case 9 : displayElements(head); break;
            case 10 : cout<<"Exited"<<endl;; break;
            default : cout<<"Invalid choice"<<endl;
        }
    } while (n!=10);
    return 0;
}