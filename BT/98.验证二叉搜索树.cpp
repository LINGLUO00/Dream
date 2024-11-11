/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
class Solution {
public:
    long prev= LONG_MIN;
    bool isValidBST(TreeNode* root) 
    {

        if(root==nullptr) return true;
        bool left = isValidBST(root->left);
        if(left==false) return false;
        bool cur = false;
        if(root->val >prev)
            cur=true;
        if(cur==false) return false;
        prev = root->val;
        bool right = isValidBST(root->right);
        return left && cur && right;
        
    }
};
// @lc code=end

