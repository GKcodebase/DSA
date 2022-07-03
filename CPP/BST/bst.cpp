/**
 * @file bst.cpp
 * @brief Basic Binary search tree operations
 * @version 0.1
 * @date 2022-07-02
 * Insertion - insert(int,Node*)
 * Search
 * Get Height
 * Traversal- 
 *          preorder
 *          inorder
 *          postorder
 *          levelorder - printLevelOrder(Node*)
 * Deletion
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<queue>
using namespace std;
/**
 * @brief Node template class
 * 
 */
class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
/**
 * @brief Insert a value in BST
 * 
 * @param val 
 * @param head 
 * @return Node* 
 */
Node* insert(int val,Node *head){
    Node *n = new Node(val);
    if(head == NULL)
        return n;
    if(val > head->val)
        head->right = insert(val,head->right);
    else
        head->left = insert(val,head->left);
    return head;   
}
/**
 * @brief prints level order traversal of BST
 * O(n) time and O(n) space complexity
 * 
 * @param root 
 */
void printLevelOrder(Node *root){
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    cout<<"Level order traversal : ";
    while(!q.empty()){
        Node *temp = q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    cout<<endl;
}
int main(){
    /**
     * @brief Driver code to test method
     *      50
     *   30     70
     * 20  40 60  80
     */
    Node *head = insert(50,NULL);
    head = insert(30,head);
    head = insert(20,head);
    head = insert(40,head);
    head = insert(70,head);
    head = insert(60,head);
    head = insert(80,head);
    printLevelOrder(head);
}