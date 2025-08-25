#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m;
    cout<<"Enter number of rows : ";
    cin>>n;
    cout<<"Enter number of columns : ";
    cin>>m;
    cout<<"Enter Matrix : ";
    int mat[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>mat[i][j];
        }
    }

    //count nonzero elements 
    int nonzero=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j]!=0) nonzero++;
        }
    }

    int sparse[nonzero][3];
    int k=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j]!=0) {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=mat[i][j];
                k++;
            }
        }
    }

    //transposing
    for (int i=0; i<nonzero; i++) {
        swap(sparse[i][0],sparse[i][1]);
    }

    //sort columns
    for (int i=0; i<nonzero-1; i++) {
        for (int j=0; j<nonzero-i-1; j++) {
            if (sparse[j][0]>sparse[j+1][0] || (sparse[j][0]==sparse[j+1][0] && sparse[j][1]>sparse[j+1][1])) {
                swap (sparse[j][0],sparse[j+1][0]);
                swap (sparse[j][1],sparse[j+1][1]);
                swap (sparse[j][2],sparse[j+1][2]);
            }
        }
    }

    for (int i=0; i<nonzero; i++) {
        cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
    }

    
    return 0;
}