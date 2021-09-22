#define MAX 10100
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        int dp[MAX];
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i] = max(dp[j]+1,dp[i]);
                    
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};