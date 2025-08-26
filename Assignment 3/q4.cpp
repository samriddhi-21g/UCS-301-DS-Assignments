// Infix to postfix

#include <bits/stdc++.h>
using namespace std;

// precedence of operator
int prec (char ch) {
    if (ch=='^') return 3;
    if (ch=='/' || ch=='*') return 2;
    if (ch=='+' || ch=='-') return 1;
    return -1;
}

void infixToPostfix (string s) {
    stack<char> st;
    string result;

    for (int i=0; i<s.length(); i++) {
        char c = s[i];

        if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) result+=c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (!st.empty() && st.top()!='(') {
                result+=st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top())>=prec(c)) {
                result+=st.top(); st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result+=st.top(); st.pop();
    }

    cout<<"Postfix Expression : "<<result;
}

int main () {
    string s = "(A+B)*(C-D)";
    cout<<"Infix expression : "<<s<<endl;
    infixToPostfix(s);
    return 0;
}