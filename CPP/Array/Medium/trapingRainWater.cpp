#include "./../../stdc++.h"
using namespace std;
/**
 * @brief Given an array of N non-negative integers arr[] representing an elevation map
 *  where the width of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int trappingRainWater(int arr[], int n)
{
    int size = n - 1;
    int prev = arr[0];
    int prev_index = 0;
    int water = 0;
    int temp = 0;
    //Start from first and check the dips/space where water can be stored.
    for (int i = 1; i <= size; i++)
    {
        /*If the current element is larger than the previous element
            Update its height ,index , and temp
        Else
            Its a dip, so calculate water stored  and temp
        */
        if (arr[i] >= prev)
        {
            prev = arr[i];
            prev_index = i;
            temp = 0;
        }
        else
        {
            water += prev - arr[i];
            temp += prev - arr[i];
        }
    }
    //If the last bar is not higher
    if (prev_index < size)
    {
        //Remove the temp from actual value
        water -= temp;
        prev = arr[size];
        //Start from right and check for dips
        for (int i = size; i >= prev_index; i--)
        {
            if (arr[i] >= prev)
            {
                prev = arr[i];
            }
            else
            {
                water += prev - arr[i];
            }
        }
    }
    return water;
}
int main()
{
    //Driver code
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "The amount of water trapped :: "<<trappingRainWater(arr, N);
    return 0;
}