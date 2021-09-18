class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        if(N<1)
            return 0;
        vector<int> dp;
        dp.resize(N);
        dp[0] = nums[0];
        int maxi = dp[0];
        for(int i=1;i<N;i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            maxi = max(dp[i],maxi);
        }
        return maxi;        
    }
};