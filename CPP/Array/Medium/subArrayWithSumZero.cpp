#include<iostream>
#include<set>
using namespace std;
/**
 * @brief Finds out wether arr subarray with zero sum is present?
 * 
 * @param arr 
 * @param size 
 * @return true 
 * @return false 
 */
bool subArrayWithSumZero(int arr[],int size){
    int sum =0;
    set<int> mySet;
    /*The idea is to iterate over check the sum is zero 
        OR 
    the sum is already present.*/
    for(int i = 0;i<size;i++){
        sum+=arr[i];
        if(sum ==0 
        || mySet.find(arr[i]) != mySet.end())
            return true;
        mySet.insert(sum);
    }
    return false;
}
int main(){
    /*Driver code to run the method.*/
    int arr[] = { -3, 2, 3, -2, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);
    if (subArrayWithSumZero(arr, size))
        cout << "Found a subarray with zero sum";
    else
        cout << "No such subarray exists!";
    return 0;
}