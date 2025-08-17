#include <iostream>
using namespace std;
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
    // sorting the array using bubble sort
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-1; j++) {
            if (a[j]>a[j+1]) {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    // removing duplicates
    int cnt =0;
    int i=0;
    for (int j=0; j<size; j++) {
        if (a[i]!=a[j]) {
            a[i+1]=a[j];
            i++;
            cnt++;
        }
    }
    // reducing the size of array and displaying it
    size=cnt+1;
    for (int i=0; i<size; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
 }