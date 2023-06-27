#include <iostream>
#include "BinaryTree.h"

using namespace std;

template <class T>
void func( const T& src )
  // A test function for the function-based 
{
  cout << src << " ";
}

int complete_tree_height( int n )
  // Returns the height of a complete binary tree having 'n' nodes
{
  int h = 0;
  // essentially, take the base-2 logarithm of 'n'
  while (n > 0) {
    n /= 2;
    h++;
  }
  return h;
}


/********/
/* Main */
/********/

int main( int argc, char *argv[] )
{
  // Set up an array of integers, to serve as node elements
  int max_nodes = 255;
  int elements[max_nodes + 1];
  for (int k = 1; k <= max_nodes; k++)
    elements[k] = k;

  // Construct a PDF object to write the tree output
  PDF *pdf = new PDF("trees.pdf");
  
  // Create a new binary tree, having 'n' elements
  int n = 12;  // <-- try changing the value of 'n'
  BinaryTree<int> tree(elements, n);

  // Output the tree
  cout << "tree output via << operator:\n" << tree << "\n";
  
  // Draw the tree
  ostringstream ostring;
  ostring << "Complete tree having " << n << " nodes";
  tree.display(pdf, ostring.str());

  // Check 'is_empty()'
  if (tree.is_empty() && n > 0) 
    cerr << "tree is not empty, but is_empty() returned true\n";
  if (!tree.is_empty() && n == 0)
    cerr << "expected is_empty() to be true\n";

  // Check the height() method
  int h = tree.height();
  int h_expected = complete_tree_height(n);
  if (h != h_expected) {
    cerr << "height() mismatch: expected " << h_expected
	 << ", got " << h << "\n";
  }

  // Check the node count
  int n_nodes = tree.node_count();
  if (n_nodes != n) {
    cerr << "node_count() mismatch: expected " << n
	 << ", got " << n_nodes << "\n";
  }
  
  // Check the leaf count
  int n_leaves = tree.leaf_count();
  int n_leaves_expected = (n == 0 ? 0 : 1 + (n-1)/2);
  if (n_leaves != n_leaves_expected) {
    cerr << "n_leaves() mismatch: expected " << n_leaves_expected
	 << ", got " << n_leaves << "\n";      
  }
  
  // Use the copy constructor to create a duplicate of 'tree'
  BinaryTree<int> tree_copy(tree);
  
  // Check equality
  if (!(tree_copy == tree)) {
    cerr << "== operator: expected true, got false\n";
  }
  if (tree_copy != tree) {
    cerr << "!= operator: expected false, got true\n";
  }

  // Empty the copy, and initialize
  tree_copy.empty_this();
  tree_copy.init_complete(elements, n);
  if (!(tree_copy == tree)) {
    cerr << "== operator: expected true, got false\n";
  }

  // Check the "=" operator
  BinaryTree<int> tree2;
  tree2 = tree;
  if (!(tree2 == tree)) {
    cerr << "== operator: expected true, got false\n";
  }
   
  // Check the 'to_flat_array' method
  int elements2[max_nodes + 1];
  tree2.to_flat_array(elements2, n);
  for (int k = 1; k < n; k++) {
    if (elements2[k] != elements[k])
      cerr << "to_flat_array() element mismatch\n";
  }

  // Check the traversals
  cout << "Preorder traversal:\n";
  tree.preorder(func);
  cout << "\n";

  cout << "Inorder traversal:\n";  
  tree.inorder(func);
  cout << "\n";  

  cout << "Postorder traversal:\n";  
  tree.postorder(func);
  cout << "\n";

  // Finish the PDF object
  pdf->finish();
  delete pdf;

  /* The output should look like this:
  
  tree output via << operator:
  8 4 9 2 10 5 11 1 12 6 3 7 
  Preorder traversal:
  1 2 4 8 9 5 10 11 3 6 12 7 
  Inorder traversal:
  8 4 9 2 10 5 11 1 12 6 3 7 
  Postorder traversal:
  8 9 4 10 11 5 2 12 6 7 3 1 

  */

  /***********************/
  /* Start of user input */
  /***********************/

  //variables for user input
  char array[100];
  char code;
  char ch;
  int i = 1;
  int j;
  string name;

  cout << "Enter Expression of Characters (don't include spaces): ";
  while (i < 100) {
    ch = cin.get();

    if (ch == '\n')
      break;
    
    array[i] = ch;
    i++;
  }

  BinaryTree<char> inputTree(array, i - 1);

  cout << "Choose Operation:\n";
  cout << "\t'p' for Preorder;\n";
  cout << "\t'i' for Inorder;\n";
  cout << "\t'o' for Postorder;\n";
  cout << "\t'a' to add element;\n";
  cout << "\t'd' to delete element;\n";
  cout << "\t'c' to create pdf;\n";
  cout << "\t'q' to quit program;\n\n";

  for (;;){
    cin >> code;
    switch (code) {
		  case 'p':
        cout << "Preorder traversal:\n";
        inputTree.preorder(func);
        cout << "\n";
			  break;
		  case 'i':
			  cout << "Inorder traversal:\n";
        inputTree.inorder(func);
        cout << "\n";
			  break;
		  case 'o':
        cout << "Postorder traversal:\n";
        inputTree.postorder(func);
        cout << "\n";
			  break;
      case 'a': {
        cout << "Enter character to be added:\n";
        cin >> ch;

        inputTree.insert(ch);
        array[i] = ch;
        i++;

        cout << "Done.\n";
			  break;
      }
      case 'd': {
        if (inputTree.is_empty()) {
          cout << "Tree is already empty.\n";
          break;
        }

        cout << "Enter character to be deleted (character must currently be in the tree):\n";
        cin >> ch;

        inputTree.remove(ch);
        i--;
        cout << "Done.\n";
        break;
      }
      case 'c': {
        PDF *pdf = new PDF("trees.pdf");
        ostringstream ostring;

        ostring << "Complete tree having " << i - 1 << " nodes";
        inputTree.display(pdf, ostring.str());
        pdf->finish();
        delete pdf;

        cout << "Done.\n";
			  break;
      }
      case 'q':
        cout << "Quitting program.\n";
        return 0;
		  default:
			  printf("Illegal operation code.\n");
    }
	}
}

