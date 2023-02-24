// Given the root of an n-ary tree, return the preorder traversal of its nodes' 
// values.Nary-Tree input serialization is represented in their level order traversal.


#include<iostream>
#include "./../../../stdc++.h"
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {  //Preorder Traversal of N-ary Tree 

 public:  //Function to print the preorder traversal of the tree 

   void preOrder(Node* root, vector<int>& result) 

   { 

       if (root == NULL) 

           return; 

       result.push_back(root->val); //Push the root node's value in the result array. 

       for (int i = 0; i < root->children.size(); i++) //Recursively traverse through all the child nodes of the root node. 

           preOrder(root->children[i], result); 

   } 

   vector<int> preorder(Node* root) { //Function to return the preorder traversal of the tree as an array. 

       vector<int> result; //Declare an empty array to store the values of all nodes in preorder traversal. 

       preOrder(root, result); //Call to recursive function to traverse through all nodes and push their values in result array. 

       return result; //Return the array containing all node values in preorder traversal order.  

   }  
};