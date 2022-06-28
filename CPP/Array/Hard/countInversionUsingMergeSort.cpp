/**
 * @file countInversionUsingMergeSort.cpp
 * @author Respective authors 
 * Orginal solution : https://www.geeksforgeeks.org/counting-inversions/
 * @brief : Inversion Count for an array indicates – how far (or close) the array is from being sorted.
 *  If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum
 * @date 2022-06-28
 * 
 * 
 */
#include<iostream>
using namespace std;
/**
 * @brief Merge method to left and right sub array.
 * 
 * @param arr 
 * @param temp 
 * @param left 
 * @param mid 
 * @param right 
 * @return int 
 */
int merge(int arr[],int temp[],int left,int mid,int right){
    int i = left,j=mid,k=left;
    int count =0;
    //Copy right or left value to temp array.
    while(i<=(mid-1) && j<= right){
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else{
            temp[k++]=arr[j++];
            /**
             * @brief In merge process, let i is used for indexing left sub-array and j for right sub-array.
             *  At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions.
             *  Because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]
             * 
             */
            count+= mid-i;
        }
    }
    //Copy remaining elements to temp array.
    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
          arr[i] = temp[i];
    return count;
}
/**
 * @brief Classic merge sort , keep track inversions during merging.
 * 
 * @param arr 
 * @param temp 
 * @param left 
 * @param right 
 * @return int 
 */
int mergeSort(int arr[],int temp[],int left, int right){
    int count =0;int mid =0;
    if(left<right){
        mid = (right+left)/2;
        //Sub array splitting and merging
        count+=mergeSort(arr,temp,left,mid);
        count+=mergeSort(arr,temp,mid+1,right);

        count += merge(arr,temp,left,mid+1,right);
    }

    return count;
}
/**
 * @brief Main method , create extra space of O(n) an calls mergesort method.
 * O(nlogn) time and O(n) space complexity.
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int countInversions(int arr[],int size){
    int temp[size];
    int count =  mergeSort(arr,temp,0,size-1);
    cout<<"Sorted Array :: ";
    for (int i : temp)
        cout<<i<<" ";
    return count;
}
int main(){
    //Driver code to run method
    /**
     * @brief Inversion in the given array
     * { 1, 20, 6, 4, 5 }
     *  (20,6) , (20,4) , (20,5) , (6,4) , (6,5)
     */
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = countInversions(arr, n);
    cout <<endl<< " Number of inversions are " << ans;
    return 0;
}