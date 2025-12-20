// quick sort when pivot element is first element

#include <bits/stdc++.h>
using namespace std;

// Function to place pivot at correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[low];     // choose first element as pivot
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    // place pivot at correct position
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);   // left part
        quickSort(arr, p + 1, high);  // right part
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}