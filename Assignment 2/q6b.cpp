#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m;
    cout<<"Enter number of rows : ";
    cin>>n;
    cout<<"Enter number of columns : ";
    cin>>m;
    cout<<"Enter Matrix : ";
    int mat1[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>mat1[i][j];
        }
    }


    //count nonzero elements 
    int nonzero=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat1[i][j]!=0) nonzero++;
        }
    }

    //sparse matrix 1
    int s1[nonzero][3];
    int k=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat1[i][j]!=0) {
                s1[k][0]=i;
                s1[k][1]=j;
                s1[k][2]=mat1[i][j];
                k++;
            }
        }
    }

    //2nd Matrix
    int p,q;
    cout<<"Enter number of rows for matrix 2 : ";
    cin>>p;
    cout<<"Enter number of columns for matrix 2 : ";
    cin>>q;
    if (n!=p || m!=q) {
        cout<<"Addition not possible.";
        return 0;
    }
    cout<<"Enter Matrix : ";
    int mat2[p][q];
    for (int i=0; i<p; i++) {
        for (int j=0; j<q; j++) {
            cin>>mat2[i][j];
        }
    }

    //count nonzero elements 
    int nonzero2=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat2[i][j]!=0) nonzero2++;
        }
    }

    //sparse matrix 2
    int s2[nonzero2][3];
    k=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat2[i][j]!=0) {
                s2[k][0]=i;
                s2[k][1]=j;
                s2[k][2]=mat2[i][j];
                k++;
            }
        }
    }


    // Creating matrix for addition
    int add[nonzero+nonzero2+1][3];
    int i=0, j=0;
    k=1;
    add[0][0]=n; add[0][1]=m;

    while (i<nonzero && j<nonzero2) {
        if (s1[i][0]<s2[j][0] || (s1[i][0]==s2[j][0] && s1[i][1]<s2[j][1])) {
            add[k][0]=s1[i][0];
            add[k][1]=s1[i][1];
            add[k][2]=s1[i][2];
            i++; k++;
        } else if (s1[i][0]>s2[j][0] || (s1[i][0]==s2[j][0] && s1[i][1]>s2[j][1])) {
            add[k][0]=s2[j][0];
            add[k][1]=s2[j][1];
            add[k][2]=s2[j][2];
            j++; k++;
        } else {
            int sum = s1[i][2]+s2[j][2];
            if (sum!=0) {
                add[k][0]=s2[j][0];
                add[k][1]=s2[j][1];
                add[k][2]=sum;
                k++;
            }
            j++; i++;
        }
    }

    // leftover elements
    while (i<nonzero) {
        add[k][0]=s1[i][0];
        add[k][1]=s1[i][1];
        add[k][2]=s1[i][2];
        i++; k++;
    }
    while (j<nonzero2) {
        add[k][0]=s2[j][0];
        add[k][1]=s2[j][1];
        add[k][2]=s2[j][2];
        j++; k++;
    }

    add[0][2] = k-1;

    //printing added sparse matrix
    for (int i=0; i<k; i++) {
        cout<<add[i][0]<<" ";
        cout<<add[i][1]<<" ";
        cout<<add[i][2]<<" "<<endl;
    }
    
    return 0;
}