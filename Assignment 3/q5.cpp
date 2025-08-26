// Evaluate Postfix expression

#include <bits/stdc++.h>
using namespace std;

int solvePostfix (string s) {
    stack<int> st;
    
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (c>='1' && c<='9') st.push(c-'0');
        else {
            int t1 = st.top(); st.pop();
            int t2 = st.top(); st.pop();
            switch (c) {
                case '+' : st.push(t2+t1);
                break;
                case '-' : st.push(t2-t1);
                break;
                case '*' : st.push(t2*t1);
                break;
                case '/' : st.push(t2/t1);
                break;
                case '^' : st.push(pow(t2,t1));
                break;
            }
        }
    }
    return st.top();
} 

int main () {
    string s = "21+42-*";
    cout<<"Postfix Expression : "<<s<<endl;
    cout<<"Evaluated: "<<solvePostfix(s);
    return 0;
}