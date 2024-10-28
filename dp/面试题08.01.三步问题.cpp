class Solution {
public:
    int waysToStep(int n) 
    {
        const int MOD=1e9+7;
        vector<long> dp(n+1);
        //1状态表示：dp[i]代表到i有多少种方法
        //2状态转移方程
        //3初始化和处理特殊情况
        if(n==1)return 1;
        if(n==2)return 2;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=((dp[i-1]+dp[i-2])%MOD+dp[i-3])%MOD;
        }
        return dp[n];
    }
};