/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int count = 0;
    int target=0;
    int kthSmallest(TreeNode *root, int k)
    {
        count=k;
        dfs(root);
        return target;
        
    }
    void dfs(TreeNode* root)
    {
        //count=k;
        if(0==count || root==nullptr) return ;
        dfs(root->left);
        count--;

        if(count==0) target=root->val;
        kthSmallest(root->right, count--);
    }
    
};
// @lc code=end
