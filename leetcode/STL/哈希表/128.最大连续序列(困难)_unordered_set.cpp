class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> st;
        for(int x:nums)
        {
            st.insert(x);
        }
        int ans = 1;
        for(int x:nums)
        {
            if(st.count(x-1))
                continue;
            int cnt = 1;
            int t = x;
            while(st.count(t+1))
            {
                cnt++;
                t++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
