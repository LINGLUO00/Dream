/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
         vector<vector<int>> ret;
         sort(nums.begin(),nums.end());
         int n=nums.size();
         for(int i=0;i<n;)//固定数a
         {
            for(int j=i+1;j<n;)//固定数b
            {
                int left=j+1;
                int right=n-1;
                long long aim=(long long) target -nums[i]-nums[j];
                while(left<right)
                {
                    int sum=nums[left]+nums[right];
                    
                    if(sum<aim)
                    {
                        left++;
                    }
                    else if(sum>aim)
                    {
                        right--;
                    }
                    else
                    {
                        ret.push_back({nums[i],nums[j],nums[left++],nums[right--]});
                        while(left<right && nums[left]==nums[left-1])
                        {
                            left++;
                        }
                        while(left<right && nums[right]==nums[right+1])
                        {
                            right--;
                        }
                    }
                }
                j++;
                while(j<n && nums[j]==nums[j-1])
                {
                    j++;
                }

            }
            i++;
            while(i<n && nums[i]==nums[i-1])
            {
                i++;
            }
         }
        return ret;   
    }
};
// @lc code=end

