#include<iostream>
#include<algorithm>
using namespace std;
/**
 * @brief Helper function to build array
 * 
 * @param arr 
 * @param size 
 */
void printArray(int arr[],int size,string msg){
    cout<<msg<<endl;
    for(int i = 0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
/**
 * @brief Arrange the elements as alternative positive and negative.
 * 
 * @param arr 
 * @param size 
 */
void alternateArrangement(int arr[],int size){
    int i =0,j=size-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i+=2;
        j-=2;
    }
    printArray(arr,size,"Grouping alternate +ve and -ve element : ");
}
/**
 * @brief Group the positive element and right element.
 * 
 * @param arr 
 * @param size 
 */
void reArrangeArray(int arr[],int size){
    printArray(arr,size,"Original String :");
    int i =0,j=size-1;
    while(i<j){
        if(arr[i]>0 && arr[j]<0){
            swap(arr[i++],arr[j--]);
        }
        if(arr[i]<0)
            i++;
        if(arr[j]>0)
            j--;
    }
    printArray(arr,size,"Array after grouping -ve and +ve element : ");
    alternateArrangement(arr,size);
}
int main(){
    /*Driver code to run the method.*/
    int arr[] = {2,3,-1,44,-44,3,24,-21,-56,2,-55,24,1,6,7,-47,-54,78};
    int size = sizeof(arr)/sizeof(arr[0]);
    reArrangeArray(arr,size);

}