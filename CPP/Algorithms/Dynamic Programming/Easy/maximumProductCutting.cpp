#include "./../../../stdc++.h"
using namespace std;
/**
 * @brief Given a rope of length n meters, 
 * cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts
 * 
 * @param n 
 * @return int 
 */
int maximumProductCutting(int n)
{
    //Intialize the dp array
    int dp[n + 1];
    dp[0] = 0, dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int max_value = 0;
        for (int j = 0; j < i; j++)
        {
            //Maximum value will be either (i - j) * j or  j * dp[i - j]
            //eg : for 5 - (2,3) 
            max_value = max(max_value, max((i - j) * j, j * dp[i - j]));
        }
        dp[i] = max_value;
    }
    return dp[n];
}
//Driver code
int main()
{
    cout << "Maximum cutting of rope :: " << maximumProductCutting(5);
}