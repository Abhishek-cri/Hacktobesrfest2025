#include <bits/stdc++.h>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Helper function: returns height and updates diameter
int diameterUtil(Node* root, int &diameter) {
    if (root == NULL)
        return 0;

    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Update diameter if the path through root is longer
    diameter = max(diameter, leftHeight + rightHeight);

    // Return height of current subtree
    return 1 + max(leftHeight, rightHeight);
}

// Main function to calculate diameter
int diameterOfTree(Node* root) {
    int diameter = 0;
    diameterUtil(root, diameter);
    return diameter;
}

// Example
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

    cout << "Diameter of Tree: " << diameterOfTree(root) << endl;
    return 0;
}
