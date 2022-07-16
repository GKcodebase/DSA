#include<iostream>
#include<math.h>
using namespace std;
/**
 * @brief Kadane’s Algorithm
 * O(n) time and O(1) space complexity
 * @param arr 
 * @param size 
 */
void largestSumSubArray(int arr[],int size){
    int temp_sum = arr[0];
    int sum = arr[0];
    /*Update temp sum with current element.*/
    for(int i =1;i<size;i++){
        temp_sum = max(arr[i],temp_sum+arr[i]);
        sum = max(temp_sum,sum);
    }
    cout<<"Max sum of continous subarray is :: "<<sum<<endl;
}
int main(){
    //Driver code to check the method.
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    largestSumSubArray(arr,size);
}