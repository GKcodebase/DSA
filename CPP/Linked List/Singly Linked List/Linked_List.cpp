/**
 * @file Linked_List.cpp
 * @author Gokul G.K
 * @brief Linked list DataStrcture and basic operation in it.
 * Printing Linked List - printLinkedList()
 * Adding element at head - addFirst()
 * Adding element at end - addLast()
 * Adding element at given index - addAtIndex()
 * Deleting element from head - deleteFirst()
 * Deleting element at end - deleteLast()
 * Deleting element at given position - deleteAtIndex()
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;
/**
 * @brief Node template
 * 
 */
class Node{
    public:
        int val;
        Node *next;
        /*Constructor*/
        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};
/*Defining head and size*/
Node *head;
int size;
/**
 * @brief Iterating through linkedlist and print 
 * O(n) time complexity
 * 
 */
void printLinkedList(){
    Node *temp = head;
    while(temp!= NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
/**
 * @brief Adding element at head
 * O(1) time complexity
 * 
 * @param val 
 */
void addFirst(int val){
    Node *n = new Node(val);
    n->next = head;
    head = n;
    size++;
}
/**
 * @brief Adding element in the end.
 * O(n) time complexity
 * 
 * @param val 
 */
void addLast(int val){
    Node *temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    Node *n = new Node(val);
    temp->next = n;
    size++;
}
/**
 * @brief Adding element in a given Index
 * O(n) time complexity
 * 
 * @param index 
 * @param val 
 */
void addAtIndex(int index,int val){
    if(index == 0)
        addFirst(val);
    size++;
    Node *temp = head;
    for(int i =0;i<index-1;i++)
        temp=temp->next;
    Node *n = new Node(val);
    n->next=temp->next;
    temp->next = n;
}
/**
 * @brief deleteFirst changing head to next element
 * O(1) time complexity
 * 
 */
void deleteFirst(){
    head=head->next;
    size--;
}
/**
 * @brief deleteLast keeping last node as null
 * O(n) time complexity
 * 
 */
void deleteLast(){
    size--;
    Node *temp = head;
    while(temp->next->next != NULL)
        temp=temp->next;
    temp->next=NULL;
}
/**
 * @brief Delete node at index
 * O(n) time complexity
 * 
 * @param index 
 */
void deleteAtIndex(int index){
    if(index == 0)
        deleteFirst();
    else if(size==index+1)
        deleteLast();
    else{
        Node *temp ,*pre = head;
        for(int i =0;i<index;i++){
            pre = temp;
            temp=temp->next;
        }
        pre->next = temp->next;
    }
    size--;
}
/**
 * @brief Get the Length linkedList
 * 
 * @return int 
 */
int getLength(){
    return size;
}
int main(){
    //Driver code to run methods.
    addFirst(30);
    addFirst(20);
    addFirst(10);
    addLast(40);
    addAtIndex(1,15);
    printLinkedList();
    deleteFirst();
    deleteLast();
    addLast(35);
    addFirst(5);
    deleteAtIndex(2);
    printLinkedList();
    cout<<"Current length of linked list :: "<<getLength()<<endl;
}