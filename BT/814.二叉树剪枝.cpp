/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        //注释掉的是错误的
        
        // if (root->left == nullptr && root->val==0 && root->right == nullptr)
        // {
        //     root=nullptr;
        //     return nullptr;
        // }
        if (root == nullptr)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        // if (root->left == 0 && root->left != nullptr)
        //     root->left = nullptr;
        // if (root->right == 0 && root->right != nullptr)
        //     root->right = nullptr;
        if (root->left == nullptr && root->right == nullptr && root->val == 0)
        {
            //delete root;(可能是数组搞出来的数，不一定能delete)
            root = nullptr;
        }
        return root;
    }
};
// @lc code=end
