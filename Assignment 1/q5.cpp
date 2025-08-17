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
    cout<<"Elements of first matrix : ";
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            cin>>mat[i][j];
        }
    }
    // calculating sum of rows and columns
    int rowsum = 0;
    int colsum = 0;
    for (int i=0; i<a; i++) {
        rowsum = 0;
        colsum = 0;
        for (int j=0; j<b; j++) {
            rowsum += mat[i][j];
            colsum += mat[j][i];
        }
        cout<<"Sum of row "<<i+1<<" is : "<<rowsum<<endl;
        cout<<"Sum of col "<<i+1<<" is : "<<colsum<<endl;
    }
    return 0;
}