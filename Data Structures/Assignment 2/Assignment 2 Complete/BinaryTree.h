#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <sstream>
#include <queue>
#include "PDF.h" // for the PDF display

using namespace std;

/* A lightweight structure implementing a general binary tree node */
template <class T>
struct BTNode {
  T       elem;  // element contained in the node
  BTNode *left;  // pointer to the left child (can be NULL)
  BTNode *right; // pointer to the right child (can be NULL)

  // Constructors
  BTNode() { left = right = NULL; }
  BTNode( T elem, BTNode* left = NULL, BTNode* right = NULL ) {
    this->elem = elem;
    this->left = left;
    this->right = right;
  }
  BTNode( const BTNode& src ) {
    this->elem = src.elem;
    this->left = src.left;
    this->right = src.right;
  }
  
  // Simple tests
  bool is_leaf() const { return (left == NULL && right == NULL); }
};

/**************************************************************************** 
 * 
 * CLASS:  BinaryTree
 * 
 ****************************************************************************/

/* A 'BinaryTree' class implements a basic binary tree.  It serves
 * as a superclass for more specific types of binary trees, such as
 * a binary search tree.
 */

template <class T>
class BinaryTree {
public:
  BinaryTree();
  BinaryTree(T* elements, int n_elements);
  BinaryTree(const BinaryTree& src);
  ~BinaryTree();

  bool is_empty() const;
  int height() const;
  int node_count() const;
  int leaf_count() const;

  bool empty_this();
  void init_complete(T* elements, int n_elements);
  int to_flat_array(T* elements, int max) const;

  void preorder(void (*f)(const T&), BTNode<T> *node) const;
  void inorder(void (*f)(const T&), BTNode<T> *node) const;
  void postorder(void (*f)(const T&), BTNode<T> *node) const;
  void preorder( void (*f)(const T&) )  const { return preorder(f, root); }
  void inorder( void (*f)(const T&) )   const { return inorder(f, root); } 
  void postorder( void (*f)(const T&) ) const { return postorder(f, root); }

  bool operator==(const BinaryTree& src) const;
  bool operator!=(const BinaryTree& src) const;
  BinaryTree& operator=(const BinaryTree& src);

  template <class S>
  friend std::ostream& operator<<(std::ostream& out, const BinaryTree<S>& src);

  void display(PDF* pdf, const std::string& annotation = "") const;

  //custom functions for user input
  void insert(const T& ch);
  void remove(const T& ch);
  BTNode<T>* findNode(BTNode<T>* node, const T& character);

protected:
  BTNode<T>* root;

  bool equalCheck(BTNode<T>* node1, BTNode<T>* node2) const;
  BTNode<T>* clone(BTNode<T>* node);
  int height(BTNode<T>* node) const;
  int balance_factor(BTNode<T>* node) const;
  int node_count(BTNode<T>* node) const;
  int leaf_count(BTNode<T>* node) const;
  void empty(BTNode<T>* node);
  BTNode<T>* init_complete(T* elements, int n_elements, int index);
  int to_flat_array(T* elements, int max, BTNode<T>* node, int index, int& max_index) const;
  void display(PDF* pdf, BTNode<T>* node, int leaf_dist, double x, double y, double scale) const;
};

#include "BinaryTree.cpp"

#endif