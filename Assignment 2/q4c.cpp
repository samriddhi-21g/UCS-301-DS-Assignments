#include <iostream> 
using namespace std;

int main () {
	char s[100] = "Hello World";
	
	int len=0;
	while (s[len]!='\0') {                 // finding length of the string;
		len++;
	}
	
	for (int i=0; i<len; i++) {
		if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
			for (int j=i; j<len; j++) {              // shifting elements including '\0' to left
				s[j]=s[j+1];
			}
			len--;
			i--;
		}
	}
	
	cout<<s;
	return 0;
}