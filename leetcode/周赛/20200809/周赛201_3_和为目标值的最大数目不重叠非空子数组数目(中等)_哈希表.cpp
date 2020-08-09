class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int N = nums.size();
        unordered_map<int,int> m;
        m[0] = -1;
        int presum = 0;
        int ends = -1;
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            presum += nums[i];
            if(m.find(presum-target)!=m.end())
            {
                if(m[presum-target]+1>ends)
                {
                    ans++;
                    ends = i;
                }
            }
            m[presum] = i;
        }
        return ans;
    }
};
