/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
// class Solution 
// {
// public:
//     int tribonacci(int n) 
//     {
        
//         if(n==0)return 0;
//         if(n==1||n==2)return 1;
//         //1状态表示：创建dp表
//         vector<int> dp(n+1);
//         //2状态转移方程：dp[1]=?
//         //3初始化（处理细节，n较小）
//         dp[0]=0;
//         dp[1]=1;
//         dp[2]=1;
//         for(int i=3;i<=n;i++)
//         {
//             dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//         }


//         //4填表顺序
//         //5返回值
//         return dp[n];

//     }
// };


//空间优化版本(滚动数组/变量)
class Solution 
{
public:
    int tribonacci(int n) 
    {
        
        if(n==0)return 0;
        if(n==1||n==2)return 1;
        int a=0,b=1,c=1,d=0;
        for(int i=3;i<=n;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }


        //4填表顺序
        //5返回值
        return d;

    }
};

// @lc code=end

