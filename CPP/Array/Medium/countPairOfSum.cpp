#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
/**
 * @brief Counting pair of sum using sorting
 * O(n*logn) time ang O(1) space complexity.
 * 
 * @param arr 
 * @param size 
 * @param sum 
 * @return int 
 */
int countPairUsingsorting(int arr[], int size , int sum){
    sort(arr,arr+size);
    int count=0,lowerBound,upperBound,tempNum;
    for(int i =0;i<size-1;i++){
        tempNum = sum - arr[i];
        // Lower bound from i+1
        lowerBound = lower_bound(arr+i+1,arr+size,tempNum)-arr;
        // Upper bound from i+1
        upperBound = upper_bound(arr+i+1,arr+size,tempNum)-arr;
        count =  count + upperBound-lowerBound;
    }
    return count;
}
/**
 * @brief Counting pairs of sum using map
 * O(n) time and O(n) space complexity.
 * 
 * @param arr 
 * @param size 
 * @param sum 
 * @return int 
 */
int countPairUsingMap(int arr[],int size,int sum){
    map<int,int> map;
    //count occurance of an integer in map
    for(int i =0;i<size;i++)
        map[arr[i]]++;
    int count=0;
    for(int i =0;i<size;i++){
        count+=map[sum-arr[i]];
        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (sum - arr[i] == arr[i])
            count--;

    }
    // return the half of the count
    return count/2;
}
int main(){
    /*Driver code to rum methods*/
    int arr[] = { 1, 5, 7, -1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout << "Count of pairs using sorting :: "
         << countPairUsingsorting(arr, size, sum)<<endl;
    cout << "Count of pairs using map :: "
         << countPairUsingMap(arr, size, sum)<<endl;
    return 0;   
}