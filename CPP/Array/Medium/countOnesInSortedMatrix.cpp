#include "./../../stdc++.h"
using namespace std;
#define R 4
#define C 4
/**
 * @brief Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s. 
 * Time complexity is O(m+n) and space complexity is O(1).
 * 
 * @param mat 
 * @return int 
 */
int countOnes(bool mat[R][C])
{
    /*Step1: Get the index of first (or leftmost) 1 in the first row.
      Step2: Do following for every row after the first row 
        …IF the element on left of previous leftmost 1 is 0, ignore this row. 
        …ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.
        The time complexity is O(m+n) because we can possibly go as far left as we came ahead in the first step.
    */
    int j = C - 1, max_index = 0;
    for (int i = 0; i < R; i++)
    {
        bool flag = false;
        while (j >= 0 && mat[i][j] == 1)
        {
            j = j - 1;
            flag = true;
        }
        if (flag)
            max_index = i;
    }
    if (max_index == 0 && mat[0][C - 1] == 0)
        return -1;
    return max_index;
}
int main()
{
    /*Driver code to run the methos.*/
    bool mat[R][C] = {{0, 0, 0, 1},
                      {0, 1, 1, 1},
                      {1, 1, 1, 1},
                      {0, 0, 0, 0}};

    cout << "Index of row with maximum 1's is :: " << countOnes(mat);
}