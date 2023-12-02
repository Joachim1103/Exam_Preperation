#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
    }
    else {
        if (value < root->data) {
            insert(root->left, value);
        }
        else {
            insert(root->right, value);
        }
    }
}

void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    int elements[] = { 15, 8, 12, 27, 11, 32, 9, 50 };
    int numElements = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < numElements; ++i) {
        insert(root, elements[i]);
    }

    std::cout << "In-order traversal of the Binary Tree: ";
    inOrderTraversal(root);

    return 0;
}