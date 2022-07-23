#include<iostream>
using namespace std;
/**
 * @brief Given three sorted array find the common elements
 * O(n) time and O(1) space complexity
 * 
 * @param arr1 
 * @param size1 
 * @param arr2 
 * @param size2 
 * @param arr3 
 * @param size3 
 */
void commonElements(int arr1[],int size1,int arr2[],int size2,int arr3[],int size3){
    int i =0,j=0,k=0;
    /*Check and increment the pointers to each array.*/
    while(i<size1 && j<size2 && k<size3){
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
            cout<<arr1[i]<<" ";
            i++,j++,k++;
        }
        else if(arr1[i]<arr2[j])
            i++;
        else if(arr2[j]<arr3[k])
            j++;
        else
            k++;
    }
}
int main(){
    /*Driver code to run the method.*/
    int ar1[] = { 1, 5, 10, 20, 40, 80 };
    int ar2[] = { 6, 7, 20, 80, 100 };
    int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int size2 = sizeof(ar2) / sizeof(ar2[0]);
    int size3 = sizeof(ar3) / sizeof(ar3[0]);
 
    cout << "Common Elements are :: ";
    commonElements(ar1, n1,ar2, size2, ar3, size3);
}