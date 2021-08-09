//Edward Utria
#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;

int main(){
    BST<int> tree;
    int x = 15;
    tree.insertElement(x);
    x = 12;
    tree.insertElement(x);
    x = 5;
    tree.insertElement(x);
    x = 19;
    tree.insertElement(x);
    x = 17;
    tree.insertElement(x);
    x = 14;
    tree.insertElement(x);
    x = 24;
    tree.insertElement(x);
    x = 34;
    tree.insertElement(x);
    x = 9;
    tree.insertElement(x);
    x = 21;
    tree.insertElement(x);
  
 
  //  tree.inorederTraversal(); //Output is : 5, 9, 12, 14, 15, 17, 19, 21, 24, 34,
    tree.inorderTraversal();
    cout << "\nPreorder output: ";
     tree.preorderTraversal();
     cout << "\nPosteorder output: ";
     tree.postorderTraversal();
     x = 17;
     tree.searchElement(x);
     x = 55;
     tree.searchElement(x);
     cout << "\n" << "Number of leaves are " << tree.numberOfLeaves();
     cout << "\n" << "Max tree height " << tree.maxTreeHeight();

     x = 15;
     tree.inorderPredecessor(x);
     x = 5;
      tree.inorderPredecessor(x);
     x = 17;
     tree.inorderPredecessor(x);

     x = 17;
     tree.deleteElement(x);
     cout << "\nDeleted 17 \ninorder output: ";
    tree.inorderTraversal();
     cout << "\npreorder output: ";
     tree.preorderTraversal();

     x = 5;
     tree.deleteElement(x);
     cout << "\n\nDeleted 5 \ninorder output: ";
     tree.inorderTraversal();
     cout << "\npreorder output: ";
     tree.preorderTraversal();

     x = 15;
     tree.deleteElement(x);
     cout << "\n\nDeleted 15 \ninorder output: ";
     tree.inorderTraversal();
     cout << "\npreorder output: ";
     tree.preorderTraversal();

    

   
    /* You must test all remaining functions of your program in the following order.
       Your program should produce the given outputs.
     
     Test preorder traversal: output should be 15, 12, 5, 9, 14, 19, 17, 24, 21, 34,
     
     Test postorder traversal: output should be 9, 5, 14, 12, 17, 21, 34, 24, 19, 15,
     
     Test search for element 17: output should be, "17 is found in the tree""
     
     Test search for element 55: output should be, "55 is not found in the tree"
     
     Test Number of leaves: output should be, Number of leaves are 5
     
     Test max tree height : output should be, Max tree height is 3
     
     Test inorder predecessor for elelment 15: output should be, predecessor of 15 is 14
     
     Test inorder predecessor for elelment 5: output should be, predecessor of 5 is null
     
     Test inorder predecessor for elelment 17: output should be, predecessor of 17 is 15
     
     
     Test delete element 17 (leaf node):  output inorder : 5, 9, 12, 14, 15, 19, 21, 24, 34,
                                          output preorder: 15, 12, 5, 9, 14, 19, 24, 21, 34,
     
     Test delete element 5 :    output inorder : 9, 12, 14, 15, 19, 21, 24, 34,
     (node with a single child) output preorder: 15, 12, 9, 14, 19, 24, 21, 34,
     
     Test delete element 15 :      output inorder : 9, 12, 14, 19, 21, 24, 34,
     (root node with two children) output preorder: 14, 12, 9, 19, 24, 21, 34,
     
     If your program does not produce above outputs, then your program is NOT correct.
     
     */
    
   // return 0;
}

