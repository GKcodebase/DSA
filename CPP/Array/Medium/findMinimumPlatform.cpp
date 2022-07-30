#include "./../../stdc++.h"
using namespace std;
/**
 * @brief find the minimum number of platform required when n number of trains arival and departure time is given.
 * O(n) space and O(n*logn) time.
 * 
 * @param arr 
 * @param dep 
 * @param n 
 * @return int 
 */
int findMinimumPlatform(int arr[], int dep[], int n)
{
    /*Make list of pair (arrival time , departure time)*/
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = make_pair(arr[i], dep[i]);
    }
    sort(a.begin(), a.end());
    /*Create a priority queue.
      Keep track of departure time and increment count they are overlapping.
    */
    priority_queue<int, vector<int>, greater<int> > p;
    int count = 1;
    p.push(a[0].second);
    for (int i = 0; i < n; i++)
    {
        if (p.top() >= a[i].first)
        {
            count++;
        }
        else
            p.pop();
        p.push(a[i].second);
    }
    return count;
}
int main()
{
    /*Driver code to run the method.*/
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of platform required is :: " << findMinimumPlatform(arr, dep, n);
    return 0;
}