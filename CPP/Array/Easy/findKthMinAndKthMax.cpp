#include<iostream>
#include<queue>
using namespace std;
/**
 * @brief Find kth smallest and kth largest element
 * Time and space complexity is O(n)
 * 
 * @param a 
 * @param l 
 * @param k 
 */
void kthElement(int a[],int l,int k){
    //Solution is created using priority queue.
    //Priority queue hold elements in decreasing order.
    priority_queue<int> pq;
    for(int i =0;i<l;i++)
        pq.push(a[i]);
    int kmax = l-k;int kmin;
    //Check the cardinality of the queue by decrementing size.
    while(l--){
        if(kmax == l)
            kmax = pq.top();
        else if(k-1==l)
            kmin = pq.top();
        pq.pop();
    }
    cout<<"Kth Max element is :: "<<kmax<<", kth Min element is :: "<<kmin;
}
int main(){
    //Driver code to check the method.
    int a[] = {1,9,3,8,2,4,6,5,10,12,11,14,13,15};
    int l = sizeof(a)/sizeof(a[0]);
    kthElement(a,l,3);
}