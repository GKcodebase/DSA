#include<iostream>
using namespace std;
/**
 * @brief Missing Number in a stream of integers
 * Make use of formula to find sum of first n number
 * O(n) time and O(1) space
 * 
 * @return int 
 */
int main(){
    int a[] = {1,2,3,4,5,6,7,9,10};
    int sum =0;
    int count=0;
    for(int i:a){
        sum+=i;
        count++;
    }
    count++;
    int actual_sum = count*(count+1)/2;
    int missing_number = actual_sum-sum;
    cout<<"Missing number is :: "<<missing_number;
}