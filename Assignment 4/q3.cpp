//Interleave first half of the queue with the second half

#include<bits/stdc++.h>
using namespace std;

void interleave (queue<int> &q, int n) {
    queue<int> firsthalf;

    for (int i=0; i<n/2; i++) {
        firsthalf.push(q.front());
        q.pop();
    } 
    
    while (!firsthalf.empty()) {
        q.push(firsthalf.front());
        firsthalf.pop();
        q.push(q.front());
        q.pop();
    }
}

void display (queue<int> q) {
    while (!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main () {
    queue<int> q;

    int n, x;
    cout << "Enter even number of elements: ";
    cin >> n;
    if (n%2!=0) {
        cout<<"Interleaving not possible."<<endl;
        return 0;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    cout<<"Original Queue : ";
    display(q);

    interleave(q,n);

    cout<<"Interleaved Queue : ";
    display(q);
    return 0;
}