#include <iostream> 
using namespace std;

int main () {
	char s[100] = "mnbvcxzasdfghjklpoiuytrewq";
	
	int len=0;
	while (s[len]!='\0') {                 // finding length of the string;
		len++;
	}
	
	for (int i=0; i<len-1; i++) {
		for (int j=0; j<len-i-1; j++) {
			if (s[j]>s[j+1]) {
				char temp = s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	
	cout<<s;
	return 0;
}