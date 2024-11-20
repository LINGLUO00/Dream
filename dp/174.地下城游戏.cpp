/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m][n-1]=dp[m-1][n]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                dp[i][j]=max(1,dp[i][j]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

