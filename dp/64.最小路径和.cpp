/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1,INT_MAX));//直接全部初始化为INT_MAX，不用单独初始化0行和0列
        // for (int k = 0; k <= n; k++)
        // {
        //     dp[0][k] = INT_MAX;
        // }
        dp[0][1]=0;
        // for (int k = 0; k <= m; k++)
        // {
        //     dp[k][0] = INT_MAX;
        // }
        dp[1][0]=0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int minroad = min(dp[i][j-1], dp[i-1][j]);
                dp[i][j] = minroad + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
