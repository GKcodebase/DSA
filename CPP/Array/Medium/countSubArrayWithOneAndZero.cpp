#include<iostream>
#include<map>
using namespace std;
/**
 * @brief Count the subarray with equal number of zero.
 * O(n) space and O(n) time complexity
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int countSubArray(int arr[],int size){
    /*Convert all zero's to -1 and count the sum for zeros
    Check the frequency of sum and add frquency-1 to the count to include all subarrays*/
    map<int,int> mp;
    int sum =0;
    int count =0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)
            arr[i] = -1;
        sum+= arr[i];
        if(sum == 0)
            count++;
        if(mp[sum])
            count+=mp[sum];
        if(mp[sum] ==0)
            mp[sum]=1;
        else
            mp[sum]++;
    }
    return count;
}
int main(){
    /*Driver code to test method.*/
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "count of subArray :: "
         << countSubArray(arr, n);

}