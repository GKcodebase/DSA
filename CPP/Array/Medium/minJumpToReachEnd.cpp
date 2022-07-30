#include "./../../stdc++.h"
using namespace std;
/**
 * @brief Given an array of integers where each element represents the max number of steps that can be made forward from that element.
 * Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
 * If an element is 0, they cannot move through that element. If the end isn’t reachable, return -1.
 * O(n*2) time and O(n) space complexity.
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int minJumps(int arr[], int n)
{
    int *jump = new int[n];
    jump[0] = 0;
    int i, j;
    if (arr[0] == 0 || n == 0)
        return -1;
    for (i = 1; i < n; i++)
    {
        jump[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && arr[j] != INT_MAX)
            {
                jump[i] = min(jump[i], jump[j] + 1);
                break;
            }
        }
    }
    return jump[n - 1];
}
int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr) / sizeof(int);
    cout << "Minimum number of jumps to reach end is "
         << minJumps(arr, size);
}