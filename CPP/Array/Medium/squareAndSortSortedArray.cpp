#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
/**
 * @brief Sqaure and sort an array which is already sorted
 * O(n) time and O(n) size
 * 
 * @param a array can contain duplicate and -ve values
 * @param s size
 */
void squareAndSortSortedArray(int a[], int s){
    int l = 0,r=s-1;
    int result[s];
    //Iterate over the array
    for(int index =s-1;index>=0;index--){
        //if left element's absolute value is larger than right
        // -> then sqaure and store it in new array ,increment left pointer 
        if(abs(a[l])>a[r]){
            result[index] = a[l]*a[l];
            l++;
        }
        //else do the same with right element.
        else {
            result[index] = a[r]*a[r];
            r--;
        }
    }
    for(int i : result){
        cout<<i<<" ";
    }
}
int main(){

    //Driver code to run squareAndSortSortedArray
    int a[] = {-6,-5,-1,0,3,8,8,9};
    int l = sizeof(a)/sizeof(a[0]);
    squareAndSortSortedArray(a,l);
}