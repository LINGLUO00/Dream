/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        return n < 0 ? 1.0 / pow(x, -(long long)n) : pow(x, (long long)n);
    }
    double pow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        double ans = pow(x, n / 2);
        return n % 2 == 0 ? ans * ans : ans * ans * x;
    }
};
// @lc code=end
