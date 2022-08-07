#include "./../../../stdc++.h"
using namespace std;
/**
 * @brief Given an integer N, the task is to obtain N, starting from 1 using minimum number of operations.
 *  The operations that can be performed in one step are as follows:
 *      Multiply the number by 2.
 *      Multiply the number by 3.
 *      Add 1 to the number.
 * @param N 
 * @return int 
 */
int minNOperation(int N)
{
    // dp[x] = min(dp[x-1], dp[x/2], dp[x/3]) 

    //To store minimum operations till N
    int dp[N + 1];
    //Initial state
    //Starting value is kept as 1 so operation is 0
    if(N==1)
        return 1;
    dp[1] = 0;
    //1 - 1
    //2 - 2
    //3 - 3
    //4 - 2
    //5 - 3
    //6 - 2
    //count the remaining operation till n
    for (int i = 2; i <= N; i++)
    {
        
        dp[i] = INT_MAX;
        // i as multiple of 2
        if (i % 2 == 0)
        {
            int x = dp[i / 2];
            if (x + 1 < dp[i])
                dp[i] = x + 1;
        }
        // i as multiple of 3
        if (i % 3 == 0)
        {
            int x = dp[i / 3];
            if (x + 1 < dp[i])
                dp[i] = x + 1;
        }
        // i as sum of i and 1
        int x = dp[i - 1];
        if (x + 1 < dp[i])
            dp[i] = x + 1;
    }
    return dp[N];
}
//Driver code.
int main()
{
    int n = 15;
    cout <<"Number of steps rweuired for "<<n<<" is :: "<< minNOperation(2);
    return 0;
}