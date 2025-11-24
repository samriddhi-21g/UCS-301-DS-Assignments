#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;

    public :

    void push (int x) {
        int s = q.size();
        q.push(x);
        for (int i=1; i<=s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop () {
        q.pop();
    }

    int top () {
        return q.front();
    }
};

int main () {
    MyStack s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
} 