/**
 * @file Linked_List.cpp
 * @author Gokul G.K
 * @brief Linked list DataStrcture and basic operation in it.
 * Printing Linked List - printLinkedList()
 * Adding element at head - addFirst()
 * Adding element at end - addLast()
 * Adding element at given index - addAtIndex()
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
int main(){
    //Driver code to run methods.
    addFirst(30);
    addFirst(20);
    addFirst(10);
    addLast(40);
    addAtIndex(1,15);
    printLinkedList();
    cout<<"Current length of linked list :: "<<size<<endl;
}