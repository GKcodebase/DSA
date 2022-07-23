#include<iostream>
#include<map>
using namespace std;
/**
 * @brief finf the first non repeated element in an array
 * Solution using arr map
 * O(size) space and O(size) time complexity
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int findFirstRepeatingElement(int arr[],int size){
    map<int,int> hashMap;
    for(int i=0;i<size;i++){
        hashMap[arr[i]]++;
    }
    for(int i =0;i<size;i++){
        if(hashMap[arr[i]] == 1)
            return arr[i];
    }
    return -1;
}
int main(){
        /*Driver code to run the method.*/
        int arr[] = { 9, 4, 9, 6, 7, 4 };
        int size = sizeof(arr)/sizeof(arr[0]);
        cout<<"First non repeating element : "<<findFirstRepeatingElement(arr,size);
}