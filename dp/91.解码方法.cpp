/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start


// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();

//         // 1创建dp表
//         vector<int> dp(n);
//         // 2状态转移方程：
//         // 2.1dp[i]单独解码
//         // 2.2dp[i]和dp[i-1]解码
//         // 初始化和特殊情况

//         //n==1
//         dp[0]=s[0]!='0';//s[0]会返回true or false，即1 or 0
//         if(n==1) return dp[0];
//         //n==2
//         //单独解码
//         if(s[0] != '0' && s[1]!='0') dp[1]+=1;
//         //一起解码
//         int t=(s[0]-'0') *10+s[1]-'0';
//         if( t>=10 && t<=26) dp[1]+=1;
//         if(n==2) return dp[1];
//         for (int i = 2; i < n; i++) {
//             //第i能不能单独解码
//             if(s[i]!='0')dp[i]+=dp[i-1];
//             //和i-1一起解码
//             if((s[i-1]-'0') *10+(s[i]-'0')  >=10 && (s[i-1]-'0') *10+(s[i]-'0')<=26)dp[i]+=dp[i-2];
//         }
//         return dp[n - 1];
//     }
// };


//优化：虚拟一个节点dp[0-1]来替换dp[0],以达到不用计算dp[1]
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        // 1创建dp表
        vector<int> dp(n+1);//多虚拟了1位

        //n==1
        dp[0]=1;//这里是1，不是0，只有1，才能保证后面的推导是对的
        dp[1]=s[1-1]!='0';//这个的初始化看的是s[0]
        //这样处理完之后，整个dp表的元素向后移动1位
        for (int i = 2; i <= n; i++) {
            //第i能不能单独解码
            if(s[i-1]!='0')dp[i]+=dp[i-1];
            //和i-1一起解码
            if((s[i-1-1]-'0') *10+(s[i-1]-'0')  >=10 && (s[i-1-1]-'0') *10+(s[i-1]-'0')<=26)dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end
