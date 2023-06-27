#include "BinaryTree.h"

/*
 * Input/Output
 * ------------
 *
 * Unlike certain kinds of specific binary trees, there is no natural
 * method of inserting elements incrementally into a general binary
 * tree.  Most often they are built up from subtrees.  That makes it
 * difficult to define a constructor that constructs a binary tree
 * all at once from a collection of elements, e.g., an array.  So
 * array-based construction works assuming the tree is a complete
 * binary tree.
 *
 * Recall that a *perfect* (or full) binary tree has all the levels
 * completely filled.  A *complete* binary tree has all the levels
 * full, except that a segment of leaves at the right may be missing.
 * There is exactly one complete binary tree structure having n elements.
 * The sequence of complete binary trees looks like this:
 *
 *          1
 *      
 *
 *          1       1     
 *         /       / \   
 *        2       2   3  
 *                           
 *			     
 *          1                 1                 1                 1        
 *        /   \             /   \    	      /   \             /   \    
 *      2       3         2       3  	    2       3         2       3  
 *     /                 / \         	   / \     /   	     / \     / \ 
 *    4                 4   5        	  4   5   6    	    4   5   6   7
 *
 *
 * The nodes of a complete binary tree thus have a natural linear order;
 * in fact, a complete binary tree is suited for representation in a
 * flat array:
 *
 *            1
 *          /   \                +---+---+---+---+---+---+---+---+- -
 *        2       3        -->   | X | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
 *       / \     / \             +---+---+---+---+---+---+---+---+- -
 *      4   5   6   7              0   1   2   3   4   5   6   7   
 *
 * For computational convenience, the root element is stored at index 1
 * in the array (the cell at index 0 is unused).  In this arrangement
 * the index of the children and parents of the node at index 'i'
 * have clean formulas:
 *
 *   parent of node i:       i/2  (rounding down, as usual)
 *   left child of node i:   2*i
 *   right child of node i:  2*i + 1
 *
 * Of course, in the present implementation the tree is stored as
 * linked nodes rather than a flat array.  However, the flat array
 * interpretation is useful for input and output: a tree is constructed
 * from an array assuming it is a complete tree with elements given
 * by the array in the natural complete-tree ordering.
 *
 * NOTE:  For consistency, this code assumes that the element at index 0
 *        is unused, so if there are 'n' elements, the array has 'n + 1'
 *        cells.
 */



/****************************************************************************/
/***                    Implementation of BinaryTree			  ***/
/****************************************************************************/

/****************/
/* Construction */ //good
/****************/

template <class T>
BinaryTree<T>::BinaryTree() {
  root = nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(T* elements, int n_elements) {
  root = nullptr;
  init_complete(elements, n_elements);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree& src) { 
  root = clone(src.root);
}

template <class T>
BinaryTree<T>::~BinaryTree() {
  empty_this();
}

/********************/
/* Access and Tests */ //good
/********************/

template <class T>
bool BinaryTree<T>::is_empty() const {
  return (root == nullptr);
}

template <class T>
int BinaryTree<T>::height() const {
  return height(root);
}

template <class T>
int BinaryTree<T>::node_count() const {
  return node_count(root);
}

template <class T>
int BinaryTree<T>::leaf_count() const {
  return leaf_count(root);
}

template <class T>
bool BinaryTree<T>::empty_this() {
  empty(root);
  root = nullptr;
  return true;
}

template <class T>
void BinaryTree<T>::init_complete(T* elements, int n_elements) {
  root = init_complete(elements, n_elements, 1);
}

template <class T>
int BinaryTree<T>::to_flat_array(T* elements, int max) const {
  // PRE: This is a complete binary tree
  // Copies the elements contained in the nodes of this tree to
  // 'elements' in complete-tree order (see above).  At most
  // 'max' elements are actually copied; the return value is
  // the total number of nodes.
  // The elements are copied starting at 'elements[1]' (see above)
  // so 'elements' must have at least 'max + 1' cells available

  // call the helper
  int max_index = 1;
  return to_flat_array(elements, max, root, 1, max_index);
}

/*************/
/* Traversal */ //good
/*************/

template <class T>
void BinaryTree<T>::preorder(void (*f)(const T&), BTNode<T> *node) const {
  if (!node)
    return;
  f(node->elem);
  preorder(f, node->left);
  preorder(f, node->right);
}

template <class T>
void BinaryTree<T>::inorder(void (*f)(const T&), BTNode<T> *node) const {
  if (!node)
    return;
  inorder(f, node->left);
  f(node->elem);
  inorder(f, node->right); 
}

template <class T>
void BinaryTree<T>::postorder(void (*f)(const T&), BTNode<T> *node) const {
  if (!node)
    return;
  postorder(f, node->left);
  postorder(f, node->right);
  f(node->elem); 
}

/**************************/
/* Input/Output Operators */
/**************************/

template <class T>
bool BinaryTree<T>::operator==(const BinaryTree& src) const {
  return equalCheck(root, src.root);
}

template <class T>
bool BinaryTree<T>::operator!=(const BinaryTree& src) const {
  return !equalCheck(root, src.root);
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& src) {
  if (this != &src) {
    empty_this();
    root = clone(src.root);
  }
  return *this;
}

template <class S>
std::ostream& operator<<(std::ostream& out, const BinaryTree<S>& src) { 
  // Writes the elements contained in the nodes of this tree,
  // by way of an inorder traversal

  // make a call to the recursive helper function
  out << src.root;
  return out;
}

//helper for operator<<
template<class T>
ostream& operator<<( ostream& out, const BTNode<T>* node )
  // Helper for the 'operator<<' above
{
  // don't write a NULL node
  if (!node)
    return out;
  
  // write, using an inorder traversal  
  out << node->left;  // (recursive)
  out << node->elem;  // (nonrecursive)
  out << " ";
  out << node->right; // (recursive)

  return out;
}

static const double font_scale = 20;
static const double level_sep = 90;
static const double node_sep = 30;
static const double node_box_margin = 6;
static const double node_box_r = 6;

template <class T>
void BinaryTree<T>::display(PDF* pdf, const std::string& annotation) const {
  double scale = 1;

  // the overall scale is based on the height of the tree
  int h = height();
  if (h >= 4) 
    scale = 16.0/double(1<<h);

  // start a new page
  pdf->new_page(annotation.c_str());
  
  // regardless of the scale, place the root node at the center
  // of the page, one inch below the top margin
  double x = pdf->get_width()/2;
  double y = pdf->get_height() - 72;

  // set the font to Helvetica, 12 point (times the scale)
  pdf->selectfont(Helvetica, font_scale*scale);
  // set the non-stroke color to light gray
  pdf->setcolor_nonstroke(PDFColor(0.75));
  pdf->setlinewidth(scale);

  // run the "helper"
  display(pdf, root, h - 1, x, y, scale);
}

template <class T>
void BinaryTree<T>::insert(const T& ch) {
  //if tree is empty, inserts ch to the root
  if (root == nullptr) {
    root = new BTNode<T>(ch);
    return;
  }

  //initializes a queue and inserts root
  queue<BTNode<T>*> insertQueue;
  insertQueue.push(root);

  //goes through left and right sides until a nullptr is found (starting from left to keep complete or perfect)
  while (!insertQueue.empty()) {
    BTNode<T>* tempNode = insertQueue.front();
    insertQueue.pop();

    //left side of tree
    if (tempNode->left == nullptr) {
      tempNode->left = new BTNode<T>(ch);
      return;
    }else
      insertQueue.push(tempNode->left);

    //right side of tree
    if (tempNode->right == nullptr) {
      tempNode->right = new BTNode<T>(ch);
      return;
    }else
      insertQueue.push(tempNode->right);
  }
}

template <class T>
void BinaryTree<T>::remove(const T& ch) {
  //finds node with the desired character value
  BTNode<T>* node = findNode(root, ch);

  //checks if tree is already empty
  if (root == nullptr)
    return;

  BTNode<T>* lastNode = nullptr;
  BTNode<T>* parentNode = nullptr;

  //finds the last node of the tree
  queue<BTNode<T>*> deleteQueue;
  deleteQueue.push(root);

  while (!deleteQueue.empty()) {
    BTNode<T>* current = deleteQueue.front();
    deleteQueue.pop();

    if (current->left != nullptr) {
      deleteQueue.push(current->left);
      parentNode = current;
    }
    if (current->right != nullptr) {
      deleteQueue.push(current->right);
      parentNode = current;
    }

    lastNode = current;
  }

  //swaps the nodes
  if (node != lastNode)
    swap(node->elem, lastNode->elem);

  //updates pointers
  if (parentNode != nullptr) {
    if (parentNode->left == lastNode)
      parentNode->left = nullptr;
    else
      parentNode->right = nullptr;
  } else
    root = nullptr;
  
  delete lastNode;
}

template <class T>
BTNode<T>* BinaryTree<T>::findNode(BTNode<T>* node, const T& ch) {
  //recursion used to find node corresponding with ch
  if (node == nullptr || node->elem == ch)
    return node;

  BTNode<T>* tempNode = findNode(node->left, ch);
  if (tempNode != nullptr)
    return tempNode;

  return findNode(node->right, ch);
}

//helper for operator== and operator!=
template <class T>
bool BinaryTree<T>::equalCheck(BTNode<T>* node1, BTNode<T>* node2) const {
  //checks if two trees are equal with recursions
  if (node1 == nullptr && node2 == nullptr)
    return true;
  if (node1 == nullptr || node2 == nullptr)
    return false;
  return (node1->elem == node2->elem) && equalCheck(node1->left, node2->left) && equalCheck(node1->right, node2->right);
}

template <class T>
BTNode<T>* BinaryTree<T>::clone(BTNode<T>* node) {
  //if tree is empty, returns nullptr
  if (node == nullptr)
    return nullptr;

  //copies root to newNode
  BTNode<T>* newNode = new BTNode<T>(node->elem);

  //recursively copies left and right subtrees to newNode
  newNode->left = clone(node->left);
  newNode->right = clone(node->right);

  return newNode;
}

template <class T>
int BinaryTree<T>::height(BTNode<T>* node) const {
  //checks if tree is empty
  if (node == nullptr)
    return 0;

  //finds the height of left and right subtrees with recursion
  int left_height = height(node->left);
  int right_height = height(node->right);

  //returns the highest height (+ 1 to include root)
  return 1 + max(left_height, right_height);
}

template <class T>
int BinaryTree<T>::balance_factor(BTNode<T>* node) const {
  //checks if tree is empty
  if (node == nullptr)
    return 0;

  //finds left and right heights with recursion
  int left_height = height(node->left);
  int right_height = height(node->right);

  //balance factor is left - right
  return left_height - right_height;
}

template <class T>
int BinaryTree<T>::node_count(BTNode<T>* node) const {
  if (node == NULL)
    return 0;

  return 1 + node_count(node->left) + node_count(node->right);
}

template <class T>
int BinaryTree<T>::leaf_count(BTNode<T>* node) const {
  //checks if tree is empty
  if (node == nullptr)
    return 0;

  //checks if root is only node
  if (node->is_leaf())
    return 1;

  //finds total number of leaves on left and right side of tree with recursion
  int leftLeaves = leaf_count(node->left);
  int rightLeaves = leaf_count(node->right);

  return leftLeaves + rightLeaves;
}

template <class T>
void BinaryTree<T>::empty(BTNode<T>* node) {
  //checks if tree is empty
  if (node == nullptr)
    return;

  //empties both sides of tree with recursion
  empty(node->left);
  empty(node->right);

  //Deletes root at the end
  delete node;
}

template <class T>
BTNode<T>* BinaryTree<T>::init_complete(T* elements, int n_elements, int index) {
  // Initializes this tree, regarding it as a complete binary tree,
  // starting at the array node at 'index'

  // check for the end of the array 
  if (index > n_elements)
    return NULL;

  // create a new node, with left and right children assigned by
  // the recursive call
  return new BTNode<T>(elements[index],
		       init_complete(elements, n_elements, 2*index),
		       init_complete(elements, n_elements, 2*index + 1));
}

template <class T>
int BinaryTree<T>::to_flat_array(T* elements, int max, BTNode<T>* node, int index, int& max_index) const {
  // PRE: this is a complete binary tree
  // Helper function for the 'to_flat_array' function above
  // 'node' is the current node, 'index' is the index of the node
  // in the flat array (complete tree array) representation, and
  // 'max_index' is the largest index yet encountered; it is updated
  // accordingly by this call
  
  // skip a NULL node
  if (node == NULL)
    return 0;

  // update the maximum index
  if (index > max_index)
    max_index = index;

  // as long as we're not past the maximum number of cells,
  // (and the node is not NULL) the code can be copied
  if (index < max)
    elements[index] = node->elem;

  // make a recursive call, even if we're already past the max
  // (in order to keep the 'max_index' updated)
  to_flat_array(elements, max, node->left, 2*index, max_index);
  to_flat_array(elements, max, node->right, 2*index + 1, max_index);

  return max_index;
}

template <class T>
void BinaryTree<T>::display(PDF* pdf, BTNode<T>* node, int leaf_dist, double x, double y, double scale) const {
  // don't draw a NULL node
  if (node == NULL)
    return;

  // if there is a left node, add a line to it and make a recursive call
  if (node->left) {
    double x_left = x - (1<<leaf_dist)*node_sep*scale/2;
    double y_left = y - level_sep*scale;
    pdf->moveto(x, y);
    pdf->lineto(x_left, y_left);
    pdf->stroke();
    display(pdf, node->left, leaf_dist - 1, x_left, y_left, scale);
  }

  // if there is a right node, add a line to it and make a recursive call
  if (node->right) {
    double x_right = x + (1<<leaf_dist)*node_sep*scale/2;
    double y_right = y - level_sep*scale;
    pdf->moveto(x, y);
    pdf->lineto(x_right, y_right);
    pdf->stroke();    
    display(pdf, node->right, leaf_dist - 1, x_right, y_right, scale);
  }

  // Now draw 'node' at (x, y)
  // This is done last so that the box covers the line
  // A text representation is obtained by converting the element to a
  // C-style stringusing an 'ostringstream' instance
  ostringstream str;
  str << node->elem;
  pdf->text_box(str.str().c_str(), x, y,
		scale*node_box_margin, scale*node_box_r,
		0, scale*font_scale); 
}

/* Notes */

//delete and shuffle

//BinaryTree& operator=( const BinaryTree& src ) -> BinaryTree<T>& operator=( const BinaryTree<T>& src ) Why??

//put test.cc before main.cc
//then, ask for expression from user
//ask to choose pre, in, or post -> output in pdf format
//ask for insert or delete (multiple times) until done -> output in pdf format

//can call pdf print anytime
//delete can delete any node in tree
//need a shuffle function
//all trees should be perfect or complete
//allow use for preorder, inorder, postorder, insert, delete, and pdf
