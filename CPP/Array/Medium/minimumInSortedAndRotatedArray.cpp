#include<iostream>
using namespace std;
/**
 * @brief Find the minimum element in a rotated sorted array.
 * O(n) time and O(1) space complexity
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int findMinElement(int arr[],int size){
    int first = 0,last=size-1;
    /*The minimum element is the only element whose previous is greater than it.
     If there is no previous element, then there is no rotation (the first element is minimum). 
     We check this condition for the middle element by comparing it with (mid-1)th and (mid+1)th elements.
        If the minimum element is not at the middle (neither mid nor mid + 1), then: 
            If the middle element is smaller than the last element, then the minimum element lies in the left half
            Else minimum element lies in the right half.*/
    while(first<last){
        int mid = first + (last-first)/2;
        if(arr[mid] == arr[last])
            last++;
        else if(arr[mid]>arr[last])
            first=mid+1;
        else
            last=mid;
    }
    return arr[last];
}
int main(){
    /*Driver code to run method.*/
    int arr[] = { 5, 6, 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum element is "
         << findMinElement(arr, n) << endl;
}