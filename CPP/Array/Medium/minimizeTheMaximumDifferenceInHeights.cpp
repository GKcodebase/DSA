#include "./../../stdc++.h"
using namespace std;
/**
 * @brief Get the Min Differnce object
 * 
 * Given heights of n towers and a value k. 
 * We need to either increase or decrease the height of every tower by k (only once) where k > 0.
 * The task is to minimize the difference between the heights of the longest and the shortest tower 
 * after modifications and output this difference.
 * 
 * @param arr 
 * @param size 
 * @param k 
 * @return int 
 */
int getMinDiffernce(int arr[], int size, int k)
{
    /*First, we try to sort the array and make each height of the tower maximum.
    We do this by decreasing the height of all the towers towards the right by k and increasing all the height of the towers towards the left (by k).
    It is also possible that the tower you are trying to increase the height doesn’t have the maximum height.
    Therefore we only need to check whether it has the maximum height or not by comparing it with the last element on the right side which is a[n]-k.
    Since the array is sorted if the tower’s height is greater than the [n]-k then it’s the tallest tower available. Similar reasoning can also be applied to finding the shortest tower.  */
    sort(arr, arr + size);
    int tempMin = arr[0];
    int tempMax = arr[size - 1];
    int minDiff = tempMax - tempMin;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] - k < 0)
            continue;
        tempMax = max(arr[size - 1] - k, arr[i - 1] + k);
        tempMin = min(arr[0] + k, arr[i] - k);
        minDiff = min(minDiff, tempMax - tempMin);
    }
    return minDiff;
}
int main()
{
    /*Driver code to run the method.*/
    int k = 6, size = 6;
    int arr[] = {7, 4, 8, 8, 8, 9};
    int ans = getMinDiffernce(arr, size, k);
    cout << "Get minimum differnce :: " << ans;
}