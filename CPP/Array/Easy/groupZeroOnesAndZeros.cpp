#include<iostream>
#include<algorithm>
using namespace std;
/**
 * @brief Group for one's two's and zero's
 * 
 * @param a 
 * @param l 
 */
void groupNumbers(int *a,int l){
    //Use three ponter , first = 0, mid =0 and end =l-1
    int f =0;
    int mid =0;
    int e = l-1;
    //Swap and increment decrement pointer based on values
    while(mid<e){
        if(a[mid] == 0)
            swap(a[f++],a[mid++]);
        else if(a[mid] == 1)
            mid++;
        else
            swap(a[mid],a[e--]);
    }
    for(int i =0;i<l;i++)
        cout<<a[i]<<" ";
}
int main(){
    //Driver code to run the method.
    int a[] = {0,2,1,1,2,0,0,2,2,1,1,2,1,0,0,2,0,1};
    int l = sizeof(a)/sizeof(a[0]);
    groupNumbers(a,l);

}