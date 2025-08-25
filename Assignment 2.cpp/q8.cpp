#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    int distinct = 1; // 1st element will always be distinct
    for (int i=1; i<n; i++) {
        if (arr[i-1]!=arr[i]) distinct++;
    }

    cout<<"Number of distinct elements : "<<distinct;
    return 0;
}