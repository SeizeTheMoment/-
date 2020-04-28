class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp;
        dp.resize(N);
        dp[0] = nums[0];
        int ans = dp[0];
        priority_queue<pair<int,int> > que;
        que.push(make_pair(dp[0],0));
        for(int i=1;i<N;i++)
        {
            dp[i] = max(nums[i],nums[i]+que.top().first);
            while(que.size()&&i-que.top().second>=k)
                que.pop();
            que.push(make_pair(dp[i],i));
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
