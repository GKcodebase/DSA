#include<iostream>
using namespace std;
/*Helper method*/
void printArray(int arr[],int size){
    for(int i =0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
/**
 * @brief Rotate array cyclicaly by one element.
 * 
 * @param arr 
 * @param size 
 */
void rotateArray(int arr[],int size){
    cout<<"Array before rotation :: ";
    printArray(arr,size);
    int temp = arr[0];
    for(int i =0;i<size-1;i++)
        arr[i] = arr[i+1];
    arr[size-1]=temp;
    cout<<"Array after rotation :: ";
    printArray(arr,size);
}
int main(){
    /*Driver code to run method*/
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    rotateArray(arr,size);
}