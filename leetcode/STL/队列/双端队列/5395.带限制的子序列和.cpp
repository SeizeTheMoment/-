class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp;
        dp.resize(N);
        dp[0] = nums[0];
        int ans = dp[0];
        deque<int> st;
        st.push_front(0);
        for(int i=1;i<N;i++)
        {
            dp[i] = max(nums[i],nums[i]+dp[st.front()]);
            if(i-st.front()==k)              
                st.pop_front();
            while(st.size()&&dp[st.back()]<dp[i])             //保持单调性
                st.pop_back();
            st.push_back(i);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
