#include "./../../stdc++.h"
using namespace std;
/**
 * @brief The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
 * and we need to calculate the span of the stock’s price for all n days. 
 * The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
 * for which the price of the stock on the current day is less than its price on the given day. 
 * 
 * @param arr 
 * @param size 
 */
void stockSpan(int arr[], int size)
{
    int *stockSpan = new int[size];
    stack<int> st;
    stockSpan[0] = 1;
    st.push(0);
    /*Push the index to a stack and track the index of local maxima to left*/
    for (int i = 1; i < size; i++)
    {
        /*Check the the element in the top is smaller than the current element, then remove it.*/
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        /
        stockSpan[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    for (int i = 0; i < size; i++)
        cout << stockSpan[i] << " ";
}
int main()
{
    /*Driver code to run the method.*/
    int price[] = {10, 4, 5, 90, 120, 80};
    int size = sizeof(price) / sizeof(price[0]);
    stockSpan(price, size);
}