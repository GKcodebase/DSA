/**
 * @file bst.cpp
 * @brief Basic Binary search tree operations
 * @version 0.1
 * @date 2022-07-02
 * Insertion - insert(int,Node*)
 * Search -  search(Node*,int)
 * Get Height - height(Node*)
 * Traversal- 
 *          preorder - preOreder(Node*)
 *          inorder - inOrder(Node*)
 *          postorder - postOrder(Node*)
 *          levelorder - printLevelOrder(Node*)
 * Deletion - deleteNode(Node*,int)
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
/**
 * @brief preorder traversal using recurssion.
 * 
 * @param root 
 */
void preOreder(Node *root){
    if(root == NULL)
        return;
    cout<<root->val<<" ";
    preOreder(root->left);
    preOreder(root->right);
}
/**
 * @brief inorder traversal using recurssion.
 * 
 * @param root 
 */
void inOrder(Node *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
/**
 * @brief postorder taversal using recurssion.
 * 
 * @param root 
 */
void postOrder(Node *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}
/**
 * @brief Finiding inorder successor
 * 
 * @param root 
 * @return Node* 
 */
Node* minValueNode(Node *root){
    Node *current = root;
    /*Loop till left most element.*/
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
/**
 * @brief   Deleting an element in BST
 * if leaf node simply remove the node.
 * if node has only one element copy that to node and remove node
 * if node has many children find the inorder predecessor and replace it
 * 
 * @param root 
 * @param key 
 * @return Node* 
 */
Node* deleteNode(Node* root , int key){
    if(root == NULL)
        return root;
    if(key > root->val)
        root->right = deleteNode(root->right,key);
    else if(key < root->val)
        root->left = deleteNode(root->left,key);
    else{
        /*Leaf Node.*/
        if (root->left==NULL and root->right==NULL)
            return NULL;
        /*Node with one child.*/
        else if(root->left == NULL){
            Node* temp = root->right;
            root = NULL;
            return temp;
        }/*Node with one child.*/
         else if(root->right == NULL){
            Node* temp = root->left;
            root = NULL;
            return temp;
        }    /*Node with many children.*/
        Node* temp = minValueNode(root->right);
        root->val= temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
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
    cout<<"Height of BST is :: "<<height(root)<<endl;
    cout<<endl<<"Preorder traversal : ";
    preOreder(root);
    cout<<endl<<"Inorder traversal : ";
    inOrder(root);
    cout<<endl<<"Postrorder traversal : ";
    postOrder(root);
    deleteNode(root,50); 
    deleteNode(root,80);
    cout<<endl<<"Level order traversal after deletion"<<endl;
    printLevelOrder(root);


}