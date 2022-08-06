#include "./../../../stdc++.h"
using namespace std;
/**
 * @brief Catalan numbers are a sequence of natural numbers that occurs in many interesting counting
 * T(1) =1 ,T(2) =1;
 * T(n) = sum from 0 to n-1 , T(i)*T(n-i-1)
 * 
 * @param n 
 */
void catlanNumberUsingDP(int n)
{
    int catlan[n + 1];
    catlan[0] = catlan[1] = 1;
    int i;
    for (i = 2; i <= n; i++)
    {
        catlan[i] = 0;
        for (int j = 0; j < i; j++)
        {
            catlan[i] += catlan[j] * catlan[i - j - 1];
        }
       //T(2) = T(1)*T(0) + T(1)*T(0) = 2
       //T(3) = T(0)*T(2) + T(1)*T(1) + T(2)*T(0) = 5
       //T(4) = T()0*T(3) + T(1)*T(2) + T(2)*T(1) + T(3)*T(0) = 14
    }
    cout << "First " << n << " catlan numbers :: ";
    for (int i : catlan)
        cout << i << " ";
}
int main()
{
    catlanNumberUsingDP(10);
}