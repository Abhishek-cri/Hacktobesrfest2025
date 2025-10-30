#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node* root) {
    if (root == nullptr)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of tree: " << height(root);
}


// output
// Height of tree: 3
