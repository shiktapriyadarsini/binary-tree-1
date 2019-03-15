Due Mar 15
Week 6 : Binary Search Tree - I
Subhankar Mishra Mar 8 (Edited Mar 8)
Implement Binary Search Tree
1. insert()
2. display()
3. search()

About Tree ->
https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm

Optional : You may want to see the code for FancyInsert() as well as implement fancyDisplay().

[Hint: For FancyDisplay() -> https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ ]
bst.cpp
C++
tbst.cpp
C++
Your work
Assigned
Files you add or create can be viewed and edited by your teacher
Mark as done or attach work to turn in
Week 6 : Binary Search Tree - I

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }  
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insertHelper(int value){
        insert(root, value);
    }
    void insert(Node *curr, int value){
        // If root is NULL, then create a node and make it root. 
        if (root == NULL) root = new Node(value);
        // Else Decide to move left or right. 
        else if (value < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL) curr->left = new Node(value);
            // Move left and call insert there. 
            else insert(curr->left, value);
        }
        else {
            // if right is already NULL, create a new node and link it. 
            if (curr->right == NULL) curr->right = new Node(value);
            // Move right and call insert there. 
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->left);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);
    }
    Node * searchHelper(int value){
        return search(root, value);
    }
    Node * search(Node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data) return search(curr->left, value);
        // Right
        else  return search(curr->right, value);
    }

};

int main(){
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(1);
    bst1.insertHelper(3);
    bst1.insertHelper(5);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
}
