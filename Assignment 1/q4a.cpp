#include <iostream>
using namespace std;
void reverse (int *arr, int size) {
    int start = 0, end = size-1;
    while (start<=end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return;
}
int main () {
    // taking input of array from user
    int size;
    cout<<"Enter size of the array : ";
    cin>>size;
    int a[size]={0};
    cout<<"Enter array elements : ";
    for (int i=0; i<size; i++) {
        cin>>a[i];
    }
    reverse(a, size);
    // displaying reversed array
    cout<<"Reversed array : ";
    for (int i=0; i<size; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}