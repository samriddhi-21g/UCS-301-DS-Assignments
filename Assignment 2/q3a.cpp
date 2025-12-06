// Missing number starting from 1

#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cout<<"Enter size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array element : ";
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    for (int i=0; i<n-1; i++) {
        if (arr[i+1]!=arr[i]+1) {
            cout<<"Missing Number : "<<arr[i]+1;
            return 0;
        }
    } 
    
    cout<<"Array has all numbers of the sequence.";
    return 0;
}