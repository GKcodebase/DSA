#include "./../../stdc++.h"
using namespace std;
int getMinDiffernce(int a[] ,int n ,int k){
    sort(a,a+n);
    int tempMin = a[0];
    int tempMax = a[n-1];
    int minDiff =tempMax-tempMin;
    for(int i=1;i<n;i++){
        if(a[i]-k<0)
            continue;
        tempMax = max(a[n-1]-k,a[i-1]+k);
        tempMin = min(a[0]+k,a[i]-k);
        minDiff = min(minDiff,tempMax-tempMin);
    }
  return minDiff;

}
int main(){
    int k = 6, n = 6;
    int arr[] = { 7, 4, 8, 8, 8, 9 };
    int ans = getMinDiffernce(arr, n, k);
    cout << ans;
}