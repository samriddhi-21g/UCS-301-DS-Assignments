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
    if (m!=p) {
        cout<<"Multiplication not possible.";
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
    for (int i=0; i<p; i++) {
        for (int j=0; j<q; j++) {
            if (mat2[i][j]!=0) nonzero2++;
        }
    }

    //sparse matrix 2
    int s2[nonzero2][3];
    k=0;
    for (int i=0; i<p; i++) {
        for (int j=0; j<q; j++) {
            if (mat2[i][j]!=0) {
                s2[k][0]=i;
                s2[k][1]=j;
                s2[k][2]=mat2[i][j];
                k++;
            }
        }
    }

    vector<vector<int>> temp(n, vector<int>(q, 0));
    for (int i=0; i<nonzero; i++) {
        for (int j=0; j<nonzero2; j++) {
            if (s1[i][1]==s2[j][0]) {
                temp[s1[i][0]][s2[j][1]] += s1[i][2]*s2[j][2];
            }
        }
    }
    
     //Multiplication Sparse Matrix
    vector <vector<int>> multi;
   
    for (int i=0; i<n; i++) {
        for (int j=0; j<q; j++) {
            if (temp[i][j]!=0) {
                multi.push_back({i,j,temp[i][j]});
            }
        }
    } 

    for (int i=0; i<multi.size(); i++) {
        cout<<multi[i][0]<<" ";
        cout<<multi[i][1]<<" ";
        cout<<multi[i][2]<<" "<<endl;
    }

    return 0;
}