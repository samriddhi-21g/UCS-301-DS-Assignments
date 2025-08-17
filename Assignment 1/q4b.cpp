#include <iostream>
using namespace std;
int main () {
    int mat1[100][100];
    int mat2[100][100];
    int multipliedmat[100][100];
    // taking input for matrix 1
    int a,b,c,d;
    cout<<"Enter number of rows for first matrix : ";
    cin>>a;
    cout<<"Enter number of columns for first matrix : ";
    cin>>b;
    cout<<"Elements of first matrix : ";
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            cin>>mat1[i][j];
        }
    }
    // taking input for matrix 2
    cout<<"Enter number of rows for second matrix : ";
    cin>>c;
    if (b!=c) {
        cout<<"Multiplication not possible";
        return 0;
    }
    cout<<"Enter number of columns for second matrix : ";
    cin>>d;
    cout<<"Elements of second matrix : ";
    for (int i=0; i<c; i++) {
        for (int j=0; j<d; j++) {
            cin>>mat2[i][j];
        }
    }
   // performing multiplication
    for (int i=0; i<a; i++) {
        for (int j=0; j<d; j++) {
            for (int k=0; k<b; k++) {
                multipliedmat[i][j]+=mat1[i][k]*mat2[k][j];
            }
    }
        }
    // displaying multiplied matrix
    for (int i=0; i<a; i++) {
        for (int j=0; j<d; j++) {
            cout<<multipliedmat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}