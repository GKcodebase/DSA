#include<iostream>
#include<algorithm>
using namespace std;
/**
 * @brief Group Numbers to -ve ,0 and +ve.
 * 
 * @param a 
 * @param l 
 */
void groupNumbers(int a[],int l){
    //Have three pointer to first ,mid and last.
    int f =0;
    int mid =0;
    int e = l-1;
    //Loop till mid is less than last
    while(mid<e){
        //If element in mid is negative swap elements and increment pointer
        if(a[mid]<0){
            swap(a[f++],a[mid++]);
        } 
        //If element is zero increment pointer
        else if(a[mid] == 0){
            mid++;
        }
        //If element is positive swap with last element and decrement end pointer
        else{
            swap(a[mid],a[e--]);
        }
    }
    for(int i =0 ; i<l ; i++)
        cout<<a[i]<<" ";

}
int main(){
    //Driver code to run function.
    int a[] = {-4,5,-22,-80,0,4,5,22,34,0,45,29,-9,0,-123,0,68,9};
    int l = sizeof(a)/sizeof(a[0]);
    groupNumbers(a,l);
}