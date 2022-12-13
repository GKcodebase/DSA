/**
 * @file Merge_List.cpp
 * @author Gokul
 * @brief Merging two sorted list
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;
/**
 * @brief Node Template class
 * 
 */
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

Node *head1 = new Node(3);
Node *head2 = new Node(9);
/**
 * @brief printLinkedList
 * printing linked list
 * 
 * @param head 
 */
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
/**
 * @brief addLast, adding element in last.
 * 
 * @param val 
 * @param head 
 */
void addLast(int val, Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *n = new Node(val);
    temp->next = n;
}
/**
 * @brief mergingLinkedList
 * 
 * Merging two sorted list ,
 * space - O(n1+n2)
 * time - O(n1+n2)
 * 
 * @param head1 
 * @param head2 
 * @return Node* 
 */
Node* mergingLinkedList(Node *head1, Node *head2){
    Node *dummy = new Node(0);
    Node *root = dummy;
    //Iterate over these list and check these values and create new list
    while(head1 != NULL && head2 != NULL){
        if(head1->val > head2->val){
            root->next = head2;
            head2 = head2->next;
        }else{
            root->next = head1;
            head1 = head1->next;          
        }
        root=root->next;

    }
    // Add remaining elements in the end.
        while(head1 != NULL){
            root->next = head1;
            root=root->next;
            head1 = head1->next; 
        }

        while(head2 != NULL){
            root->next = head2;
            root=root->next;
            head2 = head2->next; 
        }
    
    return dummy->next;
}
int main()
{
    //Driver code to run method.
    addLast(10, head1);
    addLast(20, head1);
    addLast(30, head1);
    addLast(40, head1);
    addLast(45, head1);
    addLast(100, head1);
    addLast(380, head1);
    addLast(500, head1);
    addLast(10, head2);
    addLast(30, head2);
    addLast(60, head2);
    addLast(109, head2);
    addLast(307, head2);
    addLast(453, head2);
    addLast(567, head2);
    cout << "First list" << endl;
    printLinkedList(head1);
    cout << "Second list" << endl;
    printLinkedList(head2);
    cout << "List after merging" << endl;
    Node *root = mergingLinkedList(head1,head2);
    printLinkedList(root);

}
