/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 2,INT_MAX));
        for (int k = 0; k <= (n + 1); k++)
        {
            dp[0][k] = 0;
        }
        // for (int k = 1; k <= m; k++)
        // {
        //     dp[k][0] = 10000;
        //     dp[k][n + 1] = 10000;
        // }
        int min_valuel = INT_MAX;//这里不能加static，因为OJ是批量检测的，上一个矩阵测试结束后，再次调用这个类，min_value已经不是INT_MAX了
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
                //注，这样用if，不满足解耦和健壮性，没必要
                if ((i == m) && (j >=0))
                {

                    min_valuel = min(dp[m][j], min_valuel);
                }
            }
        }
        return min_valuel;
        // int ret=INT_MAX;
        // for(int j=0;j<=n;j++)
        // {
        //     ret=min(ret,dp[n][j]);
        // }
        // return ret;
    }
};
// @lc code=end
