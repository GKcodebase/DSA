#include<iostream>
using namespace std;
/**
 * @brief Union of two sorted array 
 * O(n) time and O(n) extra space;
 * 
 * @param arr1 
 * @param size1 
 * @param arr2 
 * @param size2 
 */
void unionOfArray(int arr1[],int size1,int arr2[],int size2){
    int i = 0,j=0,size=0;
    int arr[size1+size2];
    //Check which array has the smallest element and add to the new one.
    while(i<size1&&j<size2){
        if(arr1[i]<arr2[j])
            arr[size++]=arr1[i++];
        else
            arr[size++]=arr2[j++];
    }
    while(i<size1)
        arr[size++] = arr1[i++];
    while(j<size2)
        arr[size++]=arr2[j++];
    cout<<"New array after union of two sorted array."<<endl;
    for(int i : arr)
        cout<<i<<" ";
}
int main(){
    //Driver code to check the method.
    int arr1[] = {1,4,6,8,9,10,34,55,77,90};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {-3,-1,0,3,5,7,11,22,36,56,79,98,100,120};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    unionOfArray(arr1,size1,arr2,size2);
}