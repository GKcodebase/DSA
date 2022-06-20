#include<iostream>
using namespace std;
//Helper function
void printArray(int a[], int l){
    for(int i =0;i<l;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
/**
 * @brief Reverse an array in O(n) time
 * 
 * @param a array
 * @param l length of array
 */
void reverse(int a[], int l){
    int s =0,e=l-1;
    cout<<"Array before reversing :: "<<endl;
    printArray(a,l);
    while(s<e){
        int temp = a[s];
        a[s++] = a[e];
        a[e--] = temp;
    }
    cout<<"Array after reversing :: "<<endl;
    printArray(a,l);
}
int main(){
    //Driver Code to reverse an array
    int a[] = {10,20,30,40,50,60,70,80,90,100};
    int l = sizeof(a)/sizeof(a[0]);
    reverse(a,l);
}