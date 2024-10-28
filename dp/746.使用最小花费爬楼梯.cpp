/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include<vector>
#include<iostream>
// @lc code=start
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) 
//     {
//         int n=cost.size();
//         vector<int> dp(n+1);
//         if(n==2) return (cost[0]<=cost[1]?cost[0]:cost[1]);
//         dp[0]=0;
//         dp[1]=0;
//         for(int i=2;i<=n;i++)
//         {

//             dp[i]=((dp[i-1]+cost[i-1])<=(dp[i-2]+cost[i-2])?(dp[i-1]+cost[i-1]):(dp[i-2]+cost[i-2]));
//         }
//         return dp[n];
//     }
// };



//反向推导
//到达i位置，要么i-1走一步，要么i-2走两步（即比较cost[i-1]和cost[i-2])
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int> dp(n);
        if(n==2) return (cost[0]<=cost[1]?cost[0]:cost[1]);
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];
        for(int i=n-3;i>=0;i--)
        {
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
           
        }
        return min(dp[0],dp[1]);
    }
};
// @lc code=end

