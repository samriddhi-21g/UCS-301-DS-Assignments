#include<bits/stdc++.h>
using namespace std;

void heapifydown (int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = (2*i)+1;

    if (left<n && arr[left]>arr[largest]) largest = left;
    if (right<n && arr[right]>arr[largest]) largest = right;

    if (largest!=i) {
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort (int arr[], int n) {
    for (int i=(n/2)-1; i>=0; i--) heapify (arr,n,i);

    for (i=n-1; i>0; i--) {
        swap(arr[0],arr[i]);
        heapify (arr,i,0);
    }
}

void heapifyUp (int index) {
    int parent = index/2;
    while (index>0 && arr[parent]<arr[index]) {
        swap (arr[parent],arr[index]);
        index = parent;
        parent = index/2;
    }
}