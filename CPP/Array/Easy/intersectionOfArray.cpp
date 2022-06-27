#include<iostream>
#include<math.h>
using namespace std;
/**
 * @brief Intersection of two sorted array.
 * O(n) time and O(n) space complexity
 * 
 * @param arr1 
 * @param size1 
 * @param arr2 
 * @param size2 
 */
void intersection(int arr1[],int size1,int arr2[],int size2){
    int i =0,j=0,size = min(size1,size2);
    int arr[size];
    int length=0;
    //If common values are there copy it and iterate both pointer.
    //If element is smaller than the other increment only that pointer.
    while(i<size1 && j<size2){
        if(arr1[i]==arr2[j]){
            arr[length++] = arr1[i++];
            j++;
        }else if(arr1[i]<arr2[j])
            i++;
        else
            j++;
    }
    for( i = 0;i<length;i++)
        cout<<arr[i]<<" ";
}
int main(){
    //Driver code to check the method.
    int arr1[] = {0,1,4,6,8,9,10,34,55,77,90,100};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {-3,-1,0,3,5,6,7,8,11,22,36,56,77,79,98,100,120};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    intersection(arr1,size1,arr2,size2);
}