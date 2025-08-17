#include <iostream> 
using namespace std;

int main () {
	char s[100] = "Hello World";
	
	int len=0;
	while (s[len]!='\0') {                 // finding length of the string;
		len++;
	}
	
	for (int i=0; i<len; i++) {      
		if (s[i]>=97&&s[i]<=122) {                     // 97-122 ASCII values for a-z
			int curr = int(s[i]);
			s[i] = char(curr-32);
		}
		else if (s[i]>=65&&s[i]<=90) {                // 65-90 ASCII values for A-Z                    
			int curr = int(s[i]);
			s[i] = char(curr+32);
		}
	}
	
	cout<<s;
	return 0;
}