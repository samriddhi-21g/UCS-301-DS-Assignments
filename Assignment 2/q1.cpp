#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cout<<"Enter length of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for (int i=0; i<n; i++) { // array should be sorted
        cin>>arr[i];
    }

    int element;
    cout<<"Enter element to be searched : ";
    cin>>element;
    int low = 0, high = n-1;
    
    while (low<=high) {
        int mid = low +((high-low)/2);
        if (arr[mid]==element) {
            cout<<"Element found at "<<mid+1<<" position";
           return 0;
        }
        else if (arr[mid]>element) high--;
        else low++;
    }
    cout<<"Element not found";
    return 0;
}