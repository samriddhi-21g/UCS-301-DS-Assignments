#include <iostream> 
using namespace std;

int main () {
	char s1[100] = "Hello ";
	char s2[100] = "Everyone";
	int length=0,j=0;
	
	while (s1[length]!='\0') {
		length++;
	}
	
	while (s2[j]!='\0') {
		s1[length] = s2[j];
		length++;
		j++;
	}
	
	s1[length]='\0';
	cout<<"String after concatenation : ";
	puts(s1);
	return 0;
}