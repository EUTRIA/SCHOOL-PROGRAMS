//Edward Utria 

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


template <class T>
BST<T>::BST ()
{
    root = NULL;
}    // Queue0

template <class T>
BST<T>::~BST ()
{
    reclaimAllNodes(root);
}

template <class T>
void BST<T>::transferFrom (BST& source)
{
    reclaimAllNodes(root);
    root = source.root;
    source.root = NULL;
} // transferFrom

template <class T>
BST<T>& BST<T>::operator=(BST& rhs)
{
    reclaimAllNodes(root);
    root=rhs.root;
    return *this;
}    // operator =

template <class T>
void BST<T>::clear (void)
{
    reclaimAllNodes(root);
    root = NULL;
} // clear

template <class T>
void BST<T>::reclaimAllNodes (TreeNodeRecord<T>*& root)
// requires: Null(root)  or  Alive(root)
//  ensures: all nodes in BST
//           beginning with root are reclaimed
{
    if (root != NULL) {
        reclaimAllNodes(root->left);
        reclaimAllNodes(root->right);
        root->parent = NULL;
        delete (root);
    } // end if
} // reclaimAllNodes

//----------------------------------------

//publc
template <class T>
void BST<T>:: inorderTraversal(){
    inorderTraversal(root);
}

template<class T>
inline void BST<T>::deleteElement(T& x)
{
    deleteElement(x, root);
}

template<class T>
inline bool BST<T>::searchElement(T& x)
{
    return searchElement(x, root);
}

template<class T>
inline void BST<T>::preorderTraversal()
{
    preorderTraversal(root);
}

template<class T>
inline void BST<T>::postorderTraversal()
{
    postorderTraversal(root);
}

template<class T>
inline int BST<T>::inorderPredecessor(T& x)
{
    inorderPredecessor(x, root);
        return x; 
}

template<class T>
inline int BST<T>::maxTreeHeight()
{
    return maxTreeHeight(root);
}

template<class T>
inline int BST<T>::numberOfLeaves()
{
    return numberOfLeaves(root);
}



//private 
template<class T>
inline bool BST<T>::searchElement(T& x, TreeNodeRecord<T>*& root)
{
    //restores x, root
    //ensures : x is or is not in the binary search tree
        
    bool element = false;
    TreeNodeRecord<T> * temp = root;
    while (temp->left != NULL && temp->right!=NULL && x != temp->value) {
         if (x > temp->value)
            temp = temp->right;
         if (x < temp->value)
             temp = temp->left;
    }

    if (x == temp->value) {
        element = true;
        cout<< "\n" << x << " is found in tree";
    }
    else
    {
        cout <<"\n"<< x << " is not found in the tree";
    }

    return element;
}

template<class T>
inline void BST<T>::deleteElement(T& x, TreeNodeRecord<T>*& root) //source used https://www.techiedelight.com/deletion-from-bst/
{   //restores x  
    //updates root
    //requires: x is an address to a node in root
    //ensures : root = #root with node x removed

    TreeNodeRecord <T>* temp = NULL;
    TreeNodeRecord <T>* current = root;

    while (current != NULL && x != current->value) {
        if (current->value > x) {
            current = current->left;
        }
        else current = current->right;
    }

    if (current->left == NULL && current->right == NULL) {
        if (current != root) {
            if (current->parent->left == current)
                current->parent->left = NULL;
            else current->parent->right = NULL;
        }
        else root = NULL;   
    }

    else if(current->left && current->right)
    {
        int q = x;
        static T value = inorderPredecessor(q);
    deleteElement(value, root);
    current->value = q;
    }
   else
    {
        if (current != root)
        {
        if (current == current->parent->left) {
            if (current->left == NULL)
                current->parent->left = current->right;
            else
            {
                current->parent->left = current->left;
            }
        }
            else
        {
            if (current->left == NULL)
                current->parent->right = current->right;
            else
            {
                current->parent->right = current->left;
            }
        }
        }
    else
    {
        if (current->left == NULL)
            root = current->left;
        else
        {
            root = current->right;
        } 
    }
   }
}

template<class T>
 TreeNodeRecord<T>* BST<T>::inorderPredecessor(T& x, TreeNodeRecord<T>*& root)
 {
     // restores x, root
     // requires : x !=NULL
     // ensures : inorderPredecessor = NULL if x is a leaf 
     // if not, x is the the value immediatly before itself in inorder traversal 

     TreeNodeRecord <T>* temp = root;
     TreeNodeRecord <T>* y;
     T z = x;

     while (temp != NULL && x != temp->value) {
         if (temp->value > x) {
             temp = temp->left;
         }
         else temp = temp->right;
    }

     if (temp->left != NULL) {
         temp = temp->left;
         while (temp->right != NULL) {
             temp = temp->right;
         }
         x = temp->value;
         cout << "\npredecessor of " << z << " is " << x << "\n";
         return temp;
     }

     y = temp->parent;
         while (y != NULL && temp == y->left) {
             temp = y;
             y = y->parent;
    }
         if (y != NULL) {
             x = y->value;
         }
         else
         {
             x = NULL;
         }

         if (x != NULL)
         cout << "predecessor of " << z << " is " << x<<"\n";
         else
         {
          cout << "predecessor of " << z << " is null\n";
         }
     return y;



}


template <class T>
void BST<T>:: inorderTraversal(TreeNodeRecord<T>*& root){
    //restores root
    //ensures #root is outputted in inorder
    if(root!=NULL){

        inorderTraversal(root->left);
        cout<<root->value<<", ";
        inorderTraversal(root->right);

    }
}

template<class T>
void BST<T>::preorderTraversal(TreeNodeRecord<T>*& root)
    //restores root
{   // ensures #root is outputted in preorder
    if (root != NULL) {
        cout << root->value << ", ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
    }
}

template<class T>
void BST<T>::postorderTraversal(TreeNodeRecord<T>*& root)
{   //restores root 
    //ensures #root is outputted in postorder
    if (root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << ", ";
    }
}

template<class T>
 int BST<T>::maxTreeHeight(TreeNodeRecord<T>*& root)
{    //restores root
     //requires root != NULL
     // ensures maxTreeHeight = #rootheight 

    TreeNodeRecord<T>* temp = root;
    TreeNodeRecord<T>* temp2 = root;

    int leftHeight = 0;
    int rightHeight = 0;

    
    int x = 1;
    while (x == 1) {
        if (temp->right == NULL ^ temp->left == NULL) {
            if (temp->right == NULL) {
                temp = temp->left;
                rightHeight++;
            }
            if (temp->left == NULL) {
                temp = temp->right;
                rightHeight++;
            }
        }

        if (temp->right == NULL && temp->left ==NULL)
            x = 0;

        else if (temp->right == NULL) {
            temp = temp->left;
            rightHeight++;
        }
        else
        {
            temp = temp->right;
            rightHeight++;
        }
    }

    x = 1;
    while (x == 1) {

        if (temp2->right == NULL ^ temp2->left == NULL) {

            if (temp2->right == NULL) {
                temp2 = temp2->left;
                leftHeight++;
            }
            if (temp2->left == NULL) {
                temp2 = temp2->right;
                leftHeight++;
            }
        }

        if (temp2->right ==NULL && temp2->left ==NULL)
            x = 0;
        else if(temp2->left == NULL){
            temp2 = temp2->right;
            leftHeight++;
        }
        else
        {
            temp2 = temp2->left;
            leftHeight++;
        }
    }


    if (rightHeight > leftHeight) 
        return rightHeight;
    else
        return leftHeight;
 
 }

        

template<class T>
int BST<T>::numberOfLeaves(TreeNodeRecord<T>*& root)
{   //restores root
    //ensures numberOfLeaves = # number of leaves in root 
    if (root == NULL) {

        return 0;
    }
    if (root->left != NULL || root->right!=NULL) {
        numberOfLeaves(root->left);
        numberOfLeaves(root->right);
    }
    else {
       static int leafCount;
       return leafCount += 1;
    }
}

// This is the public interface of the insert
// Client (main) has no access to root
template <class T>
void BST<T>::insertElement(T& x) {
     root = insertElement(x, root);
}

//private insert function that has access to root.
//recursive implementation
template <class T>
TreeNodeRecord<T>* BST<T>::insertElement(T& x, TreeNodeRecord<T>*& root) {
     TreeNodeRecord<T>* n = new TreeNodeRecord<T>;
     n->parent = NULL;
     n->left = NULL;
     n->right = NULL;

     if (root == NULL) {
          n->value = x;
          return n;
     }
     else if (x < root->value) {
          root->left = insertElement(x, root->left);
          root->left->parent = root;
     }
     else {
          root->right = insertElement(x, root->right);
          root->right->parent = root;
     }
     return root;
}//insert
