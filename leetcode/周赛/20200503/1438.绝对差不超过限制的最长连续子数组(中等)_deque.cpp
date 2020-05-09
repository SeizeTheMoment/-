class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int N = nums.size();
        if(N<1)
            return 0;
        deque<int> maxique;
        deque<int> minique;
        maxique.push_back(0);
        minique.push_back(0);
        int le = 0;
        int ri = 0;
        int ans = 0;
        while(ri<N)
        {
            int maxind = maxique.front();
            int minind = minique.front();
            if(nums[maxind]-nums[minind]<=limit)
            {
                ans = max(ans,ri-le+1);
                ri++;
                while(ri<N && minique.size() && nums[ri]<nums[minique.back()])
                {
                    minique.pop_back();
                }
                minique.push_back(ri);
                while(ri<N && maxique.size() && nums[ri]>nums[maxique.back()])
                {
                    maxique.pop_back();
                }
                maxique.push_back(ri);
            }
            else{
                le = min(maxind,minind)+1;
                while(minique.size() && minique.front()<le)
                    minique.pop_front();
                while(maxique.size() && maxique.front()<le)
                    maxique.pop_front();
            }
        }
        return ans;
    }
};
