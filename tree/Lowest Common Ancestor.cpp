#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find LCA
Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If current node matches any of the two nodes
    if (root->data == n1 || root->data == n2)
        return root;

    // Recur for left and right subtrees
    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    // If both sides return non-null, current node is LCA
    if (leftLCA && rightLCA)
        return root;

    // Otherwise, return the non-null side
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

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

    Node* lca1 = LCA(root, 4, 5);
    cout << "LCA of 4 and 5: " << lca1->data << endl;

    Node* lca2 = LCA(root, 4, 3);
    cout << "LCA of 4 and 3: " << lca2->data << endl;

    return 0;
}


// output
// LCA of 4 and 5: 2
// LCA of 4 and 3: 1
