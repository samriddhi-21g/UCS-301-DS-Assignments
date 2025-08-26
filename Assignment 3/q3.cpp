// valid parenthese

#include <bits/stdc++.h>
using namespace std;

bool balancedParentheses (string s) {
    stack<char> st;

    for (auto it : s) {
        if (it=='(' || it=='{' || it=='[') st.push(it);
        else {
            if (st.empty()) return false;
            char ch = st.top(); st.pop();
            if ((it==')' && ch=='(') || (it=='}' && ch=='{') || (it==']' && ch=='[')) {
                continue;
            }
            else return false;
        }
    }
    return st.empty();
}

int main() {
    string s = "{([])}";
    cout<<"String 1 : "<<s<<endl;
    cout<<balancedParentheses(s)<<endl;
    string s2 = "{(})";
    cout<<"String 2 : "<<s2<<endl;
    cout<<balancedParentheses(s2);
    return 0;
}