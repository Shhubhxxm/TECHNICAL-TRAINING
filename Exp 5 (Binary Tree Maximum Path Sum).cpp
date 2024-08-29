#include <iostream>
#include <climits>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to find the maximum path sum and update the global maximum
int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (!root) return 0;

    // Compute the maximum path sum for the left and right subtrees
    int left = std::max(maxPathSumHelper(root->left, maxSum), 0);
    int right = std::max(maxPathSumHelper(root->right, maxSum), 0);

    // Calculate the maximum path sum with the current node as the highest node in the path
    int currentPathSum = root->val + left + right;

    // Update the global maximum path sum
    maxSum = std::max(maxSum, currentPathSum);

    // Return the maximum sum of a path starting from the current node and extending to one of its children
    return root->val + std::max(left, right);
}

// Function to find the maximum path sum in a binary tree
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int result = maxPathSum(root);
    std::cout << "Maximum path sum: " << result << std::endl;

    // Free allocated memory (not shown here for brevity)
    return 0;
}
