using namespace std;

// Function to heapify a subtree rooted at index i (for Min Heap)
void minHeapify(int arr[], int n, int i) {
    int smallest = i;        // Assume root is smallest
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than current smallest
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);  // Recursively heapify affected subtree
    }
}

// Heap Sort for decreasing order
void heapSortDescending(int arr[], int n) {
    // Step 1: Build a min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move smallest element (root) to end
        swap(arr[0], arr[i]);

        // Heapify the reduced heap
        minHeapify(arr, i, 0);
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    heapSortDescending(arr, n);

    cout << "Sorted array (decreasing order):\n";
    printArray(arr, n);

    return 0;
}