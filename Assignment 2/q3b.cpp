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

    int low=1, high=n-1;
    while (low<=high) {
        int mid = low + (high-low)/2;
        if (arr[mid]!=(arr[mid-1]+1)) {
            cout<<"Missing Number : "<<arr[mid-1]+1;
            return 0;
        }
        else if (arr[mid]-arr[low]==mid-low) low=mid+1;
        else high=mid-1;  
    }
    
    cout<<"Array has all numbers of the sequence.";
    return 0;
}