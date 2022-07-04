/**
 * @file bst.cpp
 * @brief Basic Binary search tree operations
 * @version 0.1
 * @date 2022-07-02
 * Insertion - insert(int,Node*)
 * Search -  search(Node*,int)
 * Get Height - height(Node*)
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
#include<math.h>
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
 * @param root 
 * @return Node* 
 */
Node* insert(int val,Node *root){
    Node *n = new Node(val);
    if(root == NULL)
        return n;
    if(val > root->val)
        root->right = insert(val,root->right);
    else
        root->left = insert(val,root->left);
    return root;   
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
/**
 * @brief Search element in BST in recursive way
 * O(logn) time complexity.
 * 
 * @param root 
 * @param val 
 * @return true 
 * @return false 
 */
bool search(Node *root,int val){
    if(root == NULL)
        return false;
    else if(val == root->val)
        return true;
    if(root->val > val)
        return search(root->left,val);
    else
        return search(root->right,val);
}
/**
 * @brief Check height using recurssion.
 * 
 * @param root 
 * @return int 
 */
int height(Node *root){
    int h =0;
    if(root == NULL)
        return h;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight,rheight)+1;
}
int main(){
    /**
     * @brief Driver code to test method
     *      50
     *   30     70
     * 20  40 60  80
     */
    Node *root = insert(50,NULL);
    root = insert(30,root);
    root = insert(20,root);
    root = insert(40,root);
    root = insert(70,root);
    root = insert(60,root);
    root = insert(80,root);
    printLevelOrder(root);
    cout<<"Search element in 50 :: "<<search(root,50)<<endl;
    cout<<"Search element in 10 :: "<<search(root,10)<<endl;
    cout<<"Height of BST is :: "<<height(root);

}