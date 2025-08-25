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

    int size = 3*n-2;
    int arr[size];
    int k=0;

    //lower Diagonal
    for (int i=1; i<n; i++) {
        arr[k++]=mat[i][i-1];
    }

    //main diagonal
    for (int i=0; i<n; i++) {
        arr[k++]=mat[i][i];
    }

    //upper diagonal
    for (int i=0; i<n-1; i++) {
        arr[k++]=mat[i][i+1];
    }    

    cout<<"Space optimized representation of tridiagonal matrix : ";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}