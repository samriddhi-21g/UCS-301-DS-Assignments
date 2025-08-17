#include <iostream>
 using namespace std;

 int size = 0;
 int arr[100];
 // 1.CREATE function
 void create () {
    cout<<"Enter size of the array : ";
    cin>>size;
    if (size>100) { 
        cout<<"Size exceeded maximum limit."<<endl;
        size=0;
        return;
    }
    cout<<"Enter array elements : ";
    for (int i=0; i<size; i++) {
        cin>>arr[i];
    }
    cout<<"Array created."<<endl;
 }
 // 2. DISPLAY function
 void display () {
    if (size == 0) {
        cout<<"Array is empty."<<endl;
        return;
        }    
    cout<<"Array elements are : ";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
 }
 // 3. INSERT function
 void insert () {
    if (size ==  100) {
        cout<<"Array is full. Cannot insert."<<endl;
        return;
    }
    int pos, val;
    cout<<"Enter value to be inserted : ";
    cin>>val;
    cout<<"Enter position of the value : ";
    cin>>pos;
    for (int i=size; i>=pos; i--) {
        arr[i]=arr[i-1];
    }
    size++;
    arr[pos-1]=val;
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"Element inserted."<<endl;
 }
 // 4. DELETE function
 void remove () {
    if (size == 0) {
        cout<<"Array is empty. Nothing to delete."<<endl;
        return;
    }
    int pos;
    cout<<"ENter position of the element to be deleted : ";
    cin>>pos;
    for (int i=pos-1; i<size-1; i++) {
        arr[i]=arr[i+1];
    }
    size--;
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"Element deleted."<<endl;
 }
 // 5. LinearSearch function
 void linearSearch () {
    if (size == 0) {
        cout<<"Array is empty."<<endl;
    }
    int ele;
    cout<<"Enter element to search for : ";
    cin>>ele;
    for (int i=0; i<size; i++) {
        if (arr[i]==ele) {
            cout<<"Element found at "<<i+1<<" position."<<endl;
            return;
        }
    }
    cout<<"Element not found."<<endl;
 } 
int main () {
    int choice;
    do {
        cout<<endl<<"----MENU----"<<endl;
        cout<<"1.CREATE"<<endl<<"2.DISPLAY"<<endl<<"3.INSERT"<<endl<<"4.DELETE"<<endl<<"5.LINEAR SEARCH"<<endl<<"6.EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: remove(); break;
            case 5: linearSearch(); break;
            case 6: cout<<"Exited"<<endl; break;
            default: cout<<"Invalid Choice."<<endl;
        }
    } while (choice!=6);
    return 0;
 }