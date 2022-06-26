#include<iostream>
#include<algorithm>
using namespace std;
/**
 * @brief Group positive numbers and neagtive numbers in an array
 *  O(n) time and O(1) space complexity
 * 
 * @param a 
 * @param l 
 */
void groupNumbers(int a[],int l){
    int s = 0,e=l-1;
    //check whether number is positive or negative and swap accordingly
    while(s<e){
        //if both numbers are on wrong position swap and change pointer, if not only change pointer
        if(a[s]>=0 && a[e]<0)
            swap(a[s++],a[e--]);
        else if(a[s]<0)
            s++;
        else if(a[e]>=0)
            e--;
        else{
            s++;
            e--;
        }
    }
    for(int i =0;i<l;i++)
        cout<<a[i]<<" ";
}
int main(){
    //Driver code to group numbers
    int a[] = {-2,0,-4,9,-8,0,2,3,-4,10,-39,-3,2,44,51,98,-100};
    int l = sizeof(a)/sizeof(a[0]);
    groupNumbers(a,l);
}