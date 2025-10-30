#include <bits/stdc++.h>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to mirror the tree
void mirror(Node* root) {
    if (root == NULL)
        return;

    // Swap the left and right pointers
    swap(root->left, root->right);

    // Recursively mirror left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder Traversal (to show before/after mirror)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder before mirror: ";
    inorder(root);
    cout << endl;

    mirror(root);

    cout << "Inorder after mirror: ";
    inorder(root);
    cout << endl;

    return 0;
}


// output
// Inorder before mirror: 4 2 5 1 3 
// Inorder after mirror: 3 1 5 2 4 
