// Reverse string using stack

#include <bits/stdc++.h>
using namespace std;

string reverseString (string& s) {
    stack<int> st;
    for (auto& i : s) {
        st.push(i);
    }
    for (auto& i : s) {
        i=st.top();
        st.pop();
    }
    return s;
}

int main () {
    string s = "Data structures";
    reverseString(s);
    cout<<s;
    return 0;
}