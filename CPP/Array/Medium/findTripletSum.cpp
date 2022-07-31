#include "./../../stdc++.h"
using namespace std;
/**
 * @brief Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. 
 * If there is such a triplet present in array, then print the triplet 
 * 
 * @param arr 
 * @param n 
 * @param sum 
 */
void findTripletSum(int arr[], int n, int sum)
{
    /*Algorithm : 
        1.Sort the given array.
        2.Loop over the array and fix the first element of the possible triplet, arr[i].
        3.Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
            1.If the sum is smaller than the required sum, increment the first pointer.
            2.Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
            3.Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.
    */
    int l, r;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == sum)
            {
                cout << "Triplet sum is :: " << arr[i] << ", " << arr[l] << ", " << arr[r] << endl;
                return;
            }
            else if (arr[i] + arr[l] + arr[r] < sum)
                l++;
            else
                r--;
        }
    }
    cout << "No triplet sum is found.";
}
int main()
{
    /*Driver code to run the method.*/
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    findTripletSum(A, arr_size, sum);
    return 0;
}