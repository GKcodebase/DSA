#include<iostream>
#include<set>
using namespace std;
/**
 * @brief Find first repeating element in array
 * O(n) time and O(n) space complexity
 * 
 * @param a 
 * @param n 
 * @return int 
 */
int findRepeatingElement(int a[],int n){
    set<int> hashSet;
    for(int i =0;i<n;i++){
        if(hashSet.empty() == true || hashSet.find(a[i]) == hashSet.end())
            hashSet.insert(a[i]);
        else
            return a[i];
    }
    return -1;
}
int main(){
    /*Driver code to test the method.*/
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findRepeatingElement(arr, n);
}