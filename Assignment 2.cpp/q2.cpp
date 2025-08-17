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
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>5
            arr[j+1]) {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"Sorted array : ";
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}