#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
/**
 * @brief Find the longest continous subsequence that can be made
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int findLongestConseqSubseq(int arr[], int size)
{
    /*Store the elements in a set and query, for the sequence.*/
    set<int> myset;
    for (int i = 0; i < size; i++)
        myset.insert(arr[i]);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (myset.find(arr[i] + 1) != myset.end())
        {
            int j = arr[i];
            while (myset.find(j) != myset.end())
                j++;
            count = max(count, j - arr[i]);
        }
    }
    return count;
}
int main()
{
    /*Driver to run the method.*/
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int size = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence is :: "
         << findLongestConseqSubseq(arr, size);
    return 0;
}