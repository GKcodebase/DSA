#include <iostream>
#include <algorithm>
using namespace std;
/**
 * @brief Find maximum of SUM(i*a[i]) after each rotation.
 * O(n) time and O(1) space solution.
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int maxSumConfiguration(int arr[], int size)
{
    int sum = 0, curr_value = 0;
    /*Calculate sum and SUM(i*a[i])*/
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        curr_value += i * arr[i];
    }
    int maxSum = 0;
    /*Use nextSum = curr_value - (sum - arr[i-1]) + arr[i-1] * (n-1);
      and update curr_value*/
    for (int i = 1; i < size; i++)
    {
        int nextSum = curr_value - (sum - arr[i - 1]) + arr[i - 1] * (size - 1);
        curr_value = nextSum;
        maxSum = max(curr_value, maxSum);
    }
    return maxSum;
}
int main()
{
    /*Driver code to run method.*/
    int arr[] = {8, 3, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum configuration after rotation is :: " << maxSumConfiguration(arr, size) << endl;
    return 0;
}