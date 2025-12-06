// Transpose of a matrix

#include <iostream>
using namespace std;

int main () {
    int mat[100][100];
    // taking input for matrix 
    int a,b;
    cout<<"Enter number of rows for matrix : ";
    cin>>a;
    cout<<"Enter number of columns for matrix : ";
    cin>>b;
    if (a!=b) {
        cout<<"Transpose not possible.";
        return 0;
    }
    cout<<"Elements of first matrix : ";
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            cin>>mat[i][j];
        }
    }
    // transposing
    for (int i=0; i<a-1; i++) {
        for (int j=i+1; j<a; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    // displaying transpose
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}