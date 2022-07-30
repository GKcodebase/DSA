#include <iostream>
#include <algorithm>
using namespace std;
/**
 * @brief Find the sub array with maximum product value.
 * Modified kadane algorithm, where we track max prod and min prod after every value.
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int maxProdSubArray(int arr[], int size)
{
    int prod_max = arr[0], temp_max = arr[0], temp_min = arr[0];
    for(int i=1;i<size;i++)
    {
        int temp = max(arr[i], max(temp_max * arr[i], temp_min * arr[i]));
        temp_min = min(arr[i], min(temp_max * arr[i], temp_min * arr[i]));
        temp_max = temp;
        prod_max = max(prod_max, temp_max);
    }
    return prod_max;
}
int main()
{
    /*Driver code to run the program.*/
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is :: "<< maxProdSubArray(arr, size);
}