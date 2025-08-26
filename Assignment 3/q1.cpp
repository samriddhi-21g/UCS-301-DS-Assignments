//Implement Stack using Array

#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int* st;

    public: 
    Stack () {
        top = -1;
        size = 100;
        st = new int[size];
    }

    void push () {
        if (top==size) {
            cout<<"Stack is Full. Size limit exceeded.";
            return;
        }
        cout<<"Enter element to be pushed.";
        int n;
        cin>>n;
        top+=1;
        st[top]=n;
        return;
    }

    int pop () {
        if (top==-1) {
            cout<<"Stack is already empty. Nothing to pop."<<endl;
            return -1;
        }
        int x = st[top];
        top-=1;
        return x;
    }

    bool isEmpty() {
        if (top==-1) return true;
        return false;
    }

    bool isFull() {
        if (top==100) return true;
        return false;
    }

    void display() {
        if (top==-1) {
            cout<<"Stack is empty."<<endl;
            return;
        }
        for (int i=0; i<=top; i++) {
            cout<<st[i]<<" ";
        }
        cout<<endl;
        return;
    }

    int peek() {
        if (top==-1) {
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        return st[top];
    }
};

int main () {
    Stack st;
    int n;
    do {
        cout<<"----------MENU----------"<<endl
            <<"1.Push"<<endl
            <<"2.Pop"<<endl
            <<"3.isEmpty"<<endl
            <<"4.isFull"<<endl
            <<"5.Display"<<endl
            <<"6.Peek"<<endl
            <<"7.Exit"<<endl
            <<"Enter your choice : ";
        cin>>n;
        switch (n) {
            case 1 : st.push();
            break;
            case 2 : cout<<st.pop()<<endl;
            break;
            case 3 : cout<<st.isEmpty()<<endl;
            break;
            case 4 : cout<<st.isFull()<<endl;
            break;
            case 5 : st.display();
            break;
            case 6 : cout<<st.peek()<<endl;
            break;
            case 7 : cout<<"Exited"<<endl;
            break;
            default : cout<<"Wrong choice."<<endl;
            break;
        } 
    } while (n!=7);
    return 0;
}