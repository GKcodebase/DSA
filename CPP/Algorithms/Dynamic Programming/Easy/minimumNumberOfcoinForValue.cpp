#include "./../../../stdc++.h"
using namespace std;
/**
 * @brief Given a value V, if we want to make a change for V cents,
 *  and we have an infinite supply of each of C = { C1, C2, .., Cm} valued coins,
 *  what is the minimum number of coins to make the change? If it’s not possible to make a change,
 *  print -1.
 * 
 * @param coins 
 * @param size 
 * @param value 
 * @return int 
 */
int minimimuNoOfCoin(int coins[], int size, int value)
{
    //Intialize dp array
    int dp[value + 1];
    dp[0] = 0;
    for (int i = 1; i <= value; i++)
        dp[i] = INT_MAX;
    for (int i = 1; i <= value; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
               // Check for INT_MAX to avoid overflow and see if result can minimized
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
        }
    }
    return dp[value] == INT_MAX ? -1 : dp[value];
}
//Driver code
int main()
{
    int coins[] = {9, 6, 5, 1};
    int size = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is : "
         << minimimuNoOfCoin(coins, size, V);
}