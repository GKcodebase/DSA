#include<iostream>
#include<math.h>
using namespace std;
/**
 * @brief find minimum and maximum element in array.
 * 
 * @return prints minimum and maximum element. 
 */
void findMinAndMax(int a[],int l){
    int mine = a[0];
    int maxe = a[0];
    for(int i = 1;i<l; i++){
        mine = min(mine,a[i]);
        maxe = max(maxe,a[i]);
    }
    cout<<"Max element :: "<<maxe<<" Min element :: "<<mine<<endl;
}
int main(){
    //Drive code to run findMinAndMax method.
    int a1[] = {-99,2,3,59,0,29.,1000,34,0,3000,2,-100};
    int l = sizeof(a1)/sizeof(a1[0]);
    findMinAndMax(a1,l);
}