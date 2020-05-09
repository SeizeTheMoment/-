class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int N = nums.size();
        if(N<1)
            return 0;
        multiset<int> ms;
        int ri = 0;
        int ans = 1;
        for(int le=0;le<N;le++)
        {
            while(ri<N)
            {
                ms.insert(nums[ri]);
                if(*ms.rbegin()-*ms.begin()>limit)
                {
                    ms.erase(ms.find(nums[ri]));
                    break;
                }
                ri++;
            }
            ans = max(ans,ri-le);
            ms.erase(ms.find(nums[le]));
        }
        return ans;
    }
};
