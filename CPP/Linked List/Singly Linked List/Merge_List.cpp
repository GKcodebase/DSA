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
int main()
{
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
}
