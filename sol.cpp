class Solution {
private:
    int countPaths(TreeNode* root, long long targetSum) {
        if (!root) return 0;

        int count = 0;
        if (root->val == targetSum) count++;

        count += countPaths(root->left, targetSum - root->val);
        count += countPaths(root->right, targetSum - root->val);

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        // Count paths starting from root
        int count = countPaths(root, targetSum);

        // Recursively check for paths in left and right subtrees
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};