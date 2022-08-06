#include "./../../stdc++.h"
using namespace std;
/**
 * @brief  Given an unsorted array with both positive and negative elements. 
 * You have to find the smallest positive number missing from the array in O(n) time using constant extra space.
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int findFirstMissingNumber(int arr[], int size)
{
    /*
    The smallest positive integer is 1. 
    First we will check if 1 is present in the array or not. 
    If it is not present then 1 is the answer.
    If present then, again traverse the array. 
        The largest possible answer is N+1 where N is the size of array. 
        This will happen when array have all the elements from 1 to N. When we are traversing the array, 
        if we find any number less than 1 or greater than N, then we will change it to 1. 
        This will not change anything as answer will always between 1 to N+1. Now our array has elements from 1 to N.
    Now, for every ith number, increase arr[ (arr[i]-1) ] by N. 
        But this will increase the value more than N. 
        So, we will access the array by arr[(arr[i]-1)%N]. 
        What we have done is for each value we have increased value at that index by N.
    We will find now which index has value less than N+1. Then i+1 will be our answer.
    */
    int flag = false;
    for (int i = 0; i < size; i++)
        if (arr[i] == 1)
        {
            flag = true;
            break;
        }
    if (!flag)
        return 1;
    for (int i = 0; i < size; i++)
        if (arr[i] < 0 || arr[i] > size)
            arr[i] = 1;
    for (int i = 0; i < size; i++)
        arr[(arr[i] - 1) % size] += size;
    for (int i = 1; i < size; i++)
        if (arr[i] <= size)
            return i + 1;
    return size + 1;
}
int main()
{   
    /*Driver code to run the method.*/
    int arr[] = {2, 3, -7, 6, 8, 1, -10, 15, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "First missing positive number is :: " << findFirstMissingNumber(arr, size);
    return 0;
}