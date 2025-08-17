#include <iostream> 
using namespace std;

int main () {
	char s1[100] = "Hello World";
	int length=0;
	
	while (s1[length]!='\0') {                 // finding length of the string;
		length++;
	}
	
	int left = 0;
	int right = length - 1;
	
	while (left<=right) {
		char temp = s1[left];                // swapping
		s1[left]=s1[right];
		s1[right]=temp;
		left++;
		right--;
	}
	
	cout<<s1;
	
	return 0;
}