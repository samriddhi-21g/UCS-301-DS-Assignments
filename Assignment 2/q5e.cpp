#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m;
    cout<<"Enter number of rows : ";
    cin>>n;
    cout<<"Enter number of columns : ";
    cin>>m;
    cout<<"Enter symmetric Matrix : ";
    int mat[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>mat[i][j];
        }
    }

    int size = n*(n+1)/2;
    int arr[size];
    int k=0;

    //storing symmetric elements where m[i][j]=m[j][i]
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            arr[k++]=mat[i][j];
        }
    }

    cout<<"Space optimized representation of symmetric matrix : ";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}