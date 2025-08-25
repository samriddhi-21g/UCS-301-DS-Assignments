#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m;
    cout<<"Enter number of rows : ";
    cin>>n;
    cout<<"Enter number of columns : ";
    cin>>m;
    cout<<"Enter Diagonal Matrix : ";
    int mat[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>mat[i][j];
        }
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i]=mat[i][i];
    }

    cout<<"Space optimized representation of diagonal matrix : ";
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}