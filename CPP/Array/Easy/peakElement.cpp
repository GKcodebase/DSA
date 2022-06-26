#include<iostream>
using namespace std;
/**
 * @brief find peak element,peak element will be larger than near by elements
 * 
 * @return prints all peak elements.
 */
void peakElement(int a[],int l){
    cout<<"The peak elements are :: ";
    //check i with i-1 and i+1 exclude first and last element.
    for(int i = 1;i<l-1; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1])
            cout<<a[i]<<endl;
    }
}
int main(){
    //Drive code to run peakElement method.
    int a1[] = {-99,2,3,59,0,29.,1000,34,0,3000,2,-100};
    int l = sizeof(a1)/sizeof(a1[0]);
    peakElement(a1,l);
}