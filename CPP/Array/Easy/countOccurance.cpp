#include<iostream>
using namespace std;
/**
 * @brief Count number of keys in sorted array.
 * O(1) size and O(logn + count(k))
 * 
 * @param a sorted array with duplicate
 * @param s size of array
 * @param k key to find count
 * @return int 
 */
int countNumber(int arr[],int size,int key){
        int first =0,last=size ,mid = first + (last-first)/2;;
        int count = 1;
        //Solution making use of binary search
        //finding one of the index of key using binary search
        while(first<last){
            mid = first + (last-first)/2;
            if(arr[mid] == key)
                break;
            else if(arr[mid]>key)
                last = mid-1;
            else
               first = mid+1;
            if(first>=last)
                return -1;
        }
    //Count occurance of key towards left of found index
    int left = mid - 1;
    while (left >= 0 && arr[left] == key)
        count++, left--;
    //Count occurance of key towards right of found index
    int right = mid + 1;
    while (right < size && arr[right] == key)
        count++, right++;
  
    return count;

}
int main(){
    //Driver code to run method
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2; 
    cout<<"The occurnance of "<<x<<" is "<<countNumber(arr,n,x); 
}