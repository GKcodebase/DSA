#include<iostream>
using namespace std;
/**
 * @brief Create Template Node.
 * 
 */
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};
/**
 * @brief Check if cycle is present in LinkedList without using extra space.
 * 
 * @param head 
 * @return true 
 * @return false 
 */
bool isCyclePresent(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast!= NULL && slow != NULL && fast->next != NULL && slow->next != NULL){
            fast= fast->next->next;
            slow= slow->next;
            if(fast == slow)
                return true;
    }
    return false;
}
int main(){
    /*Driver code to check methods.*/
    Node *root =  new Node(10);
    root->next = new Node(20);
    root->next->next = new Node(30);
    root->next->next->next = new Node(40);
    cout<<"check loop present :: "<<isCyclePresent(root)<<endl;
    root->next->next->next = root;
    cout<<"check loop present :: "<<isCyclePresent(root);
    return 0;
}