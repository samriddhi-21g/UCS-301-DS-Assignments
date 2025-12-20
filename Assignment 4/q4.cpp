// first non repeating char

#include <bits/stdc++.h>
using namespace std;

string firstNonRepeatingChar (string s) {
    string result;
    queue<char> q;

    int i = 0;
    while (s[i] != '\0') {
       char c = s[i];
       int count = 0;
       while (!q.empty() && q.front()==c) {q.pop(); count++;}

        if (count==0) q.push(c);

        if (!q.empty()) {
            result+=q.front();
        } else {
            result+="-1";
        }
    i++;
    }

return result;
} 

int main () {
    string s = "aabc";
    string result = firstNonRepeatingChar(s);
    cout<<result;
    return 0;
}