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
/**
 * @brief Find the starting of loop
 * Loop the ll with fast and slow pointer when they are same break loop
 * jump head and slow by one step when they are same you have reached start
 * 
 * @param head 
 */
void findWhereLoopStarts(Node* head){
     Node* fast = head;
    Node* slow = head;
    while(fast!= NULL && slow != NULL && fast->next != NULL && slow->next != NULL){
            fast= fast->next->next;
            slow= slow->next;
            if(fast == slow)
                break;
    }
    if (fast == NULL || fast->next == NULL){
        cout<<"There is no loop present "<<endl;
                return;
    };
    //loop till head and slow pointer are same
    while(head!=slow){
        head=head->next;
        slow=slow->next;
    }
    cout<<"The loop starts at :: "<<head->val<<endl;
}
int main(){
    /*Driver code to check methods.*/
    Node *root =  new Node(10);
    root->next = new Node(20);
    root->next->next = new Node(30);
    root->next->next->next = new Node(40);
    cout<<"check loop present :: "<<isCyclePresent(root)<<endl;
    findWhereLoopStarts(root);
    root->next->next->next = root->next;
    cout<<"check loop present :: "<<isCyclePresent(root)<<endl;
    findWhereLoopStarts(root);
    return 0;
}