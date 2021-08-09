#pragma once
#include "TreeNodeRecord.h"

template <class T>
class BST
{
private: // Internal Representation
     TreeNodeRecord<T>* root;

public:
    //Generic Tree functions
     BST();
     ~BST();
     void clear(void);
     void transferFrom(BST& source);
     BST& operator = (BST& rhs);

    //Tree specific functions
    //public interfaces do not allow access to root
     void insertElement(T& x); //already implemented
     void inorderTraversal(); //already implemented

     //You have to implement the following public functions
     void deleteElement(T& x); //Client specify what element to be deleted
     bool searchElement(T& x); //Client specify what element to be searched
     void preorderTraversal();
     void postorderTraversal();
     int inorderPredecessor(T& x);//Client specify what element to be searched for predecessor
     int maxTreeHeight();
     int numberOfLeaves();


private: // Internal operations are private since root is private
     TreeNodeRecord<T>* insertElement(T& x, TreeNodeRecord<T>*& root);//already implemented
     void reclaimAllNodes(TreeNodeRecord<T>*& root);//already implemented
     void inorderTraversal(TreeNodeRecord<T>*& root);//already implemented

     //You have to implement the following private functions.
     bool searchElement(T& x, TreeNodeRecord<T>*& root);
     void deleteElement(T& x, TreeNodeRecord<T>*& root);
     TreeNodeRecord<T>* inorderPredecessor(T& x, TreeNodeRecord<T>*& root);
     void preorderTraversal(TreeNodeRecord<T>*& root);
     void postorderTraversal(TreeNodeRecord<T>*& root);
     int maxTreeHeight(TreeNodeRecord<T>*& root);
     int numberOfLeaves(TreeNodeRecord<T>*& root);

};
