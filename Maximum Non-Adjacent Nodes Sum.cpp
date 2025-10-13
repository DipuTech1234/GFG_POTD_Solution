/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    // Helper function that returns a pair: 
    // first = maximum sum including current node
    // second = maximum sum excluding current node
    pair<int, int> solve(Node* root) {
        if (!root) return {0, 0};
        
        // Recursively solve for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        // If we include current node, we cannot include its children
        int include = root->data + left.second + right.second;
        
        // If we exclude current node, we can choose either to include or exclude children
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }
    
    int getMaxSum(Node *root) {
        pair<int, int> result = solve(root);
        return max(result.first, result.second);
    }
};
