/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> ret;
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string path;
        dfs(root,path);
        return ret;
    }
    void dfs(TreeNode* root, string path)
    {
        path += to_string(root->val);

        if(root->left==nullptr && root->right==nullptr) 
        {
            //path += to_string(root->val);
            ret.push_back(path);
            return;
        }
        //path += to_string(root->val);
        path += "->";
        if(root->left) dfs(root->left,path);
        if(root->right) dfs(root->right,path);
    }
};
// @lc code=end

