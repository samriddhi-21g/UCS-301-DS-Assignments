#include<bits/stdc++.h>
using namespace std;

class Queue {
    int size;
    int currsize;
    int *q;
    int start, end;

    public :
    Queue () {
        size = 100;
        currsize = 0;
        q = new int[size];
        start = -1; end = -1;
    }

    void Enqueue () {        
        if (size==currsize) {
            cout<<"Queue is Full.";
            return;
        } else {
            int n;
            cout<<"Enter the number to be entered : ";
            cin>>n;
            if (currsize==0) {
            start++; end++;
            } else {
                end = (end+1)%size;
            }
            q[end]=n;
            currsize++;
        }
        return;
    }

    void Dequeue () {
        if (currsize==0) {
            cout<<"Stack is already empty.";
            return;
        } else {
            if (start==0 && end==0) {
                start--; end--;
            } else {
                start = (start+1)%size;
            }
            currsize--;
        }
        return;
    }
    

    bool isEmpty () {
        if (currsize==0) return true;
        return false;
    }

    bool isFull () {
        if (currsize==size) return true;
        return false;
    } 

    void display () {
        int top = start;
        cout<<"Queue elements are : ";
        for (int i = 0; i<currsize; i++) {
            cout<<q[top]<<" ";
            top = (top+1)%size;
        }
        return;
    }

    int Peek () {
        if (currsize==0) {
            cout<<"Stack is empty.";
            return -1;
        } 
        int n = q[start];
        return n;
    }
};

int main () {
    int n;
    Queue q;
    do {
        cout<<endl<<"----------MENU-----------"<<endl
            <<"1.Enqueue"<<endl
            <<"2.Dequeue"<<endl
            <<"3.Is empty?"<<endl
            <<"4.Is Full?"<<endl
            <<"5.Display"<<endl
            <<"6.Peek"<<endl
            <<"7.exit"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>n;
        switch (n) {
            case 1 : q.Enqueue(); cout<<endl; break;
            case 2 : q.Dequeue(); cout<<endl; break;
            case 3 : cout<<q.isEmpty()<<endl; break;
            case 4 : cout<<q.isEmpty()<<endl; break;
            case 5 : q.display(); cout<<endl; break;
            case 6 : cout<<q.Peek()<<endl; break;
            case 7 : cout<<"Exited"; break;
            default : cout<<"Wrong choice."; break;
        } 
    } while (n!=7);
    return 0;
}