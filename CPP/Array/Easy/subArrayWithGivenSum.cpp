#include<iostream>
using namespace std;
/**
 * @brief checking given sum is present in the array
 * Only works with array of positive numbers.
 * Time complexity is O(n)
 * 
 * @param arr 
 * @param size 
 * @param sum 
 */
void subArraySum(int arr[],int size, int sum){
    /**
     * @brief There is an idea if all the elements of the array are positive. 
     * If a subarray has sum greater than the given sum then there is no possibility that adding 
     * elements to the current subarray the sum will be x (given sum). Idea is to use a similar 
     * approach to a sliding window. Start with an empty subarray, add elements to the subarray until the 
     * sum is less than x. If the sum is greater than x, remove elements from the start of the current subarray.
        Algorithm:  

        Create two variables, l=0, sum = 0
        Traverse the array from start to end.
        Update the variable sum by adding current element, sum = sum + array[i]
        If the sum is greater than the given sum, update the variable sum as sum = sum – array[l], and update l as, l++.
        If the sum is equal to given sum, print the subarray and break the loop.
     * 
     */
    int curr_sum = arr[0],start=0,i;
    for(i=1;i<=size;i++){
        while(curr_sum > sum && start < i-1){
            curr_sum -= arr[start];
            start++;
        }
        if(curr_sum == sum){
            cout<<"Sum found between indexes "
                 << start << " and " << i - 1;
            return;
        }
        if (i < size)
            curr_sum = curr_sum + arr[i];

    }
    cout << "No subarray found";
    return;
}
int main(){
    //Driver code to run the method
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, size, sum);
    return 0;
}