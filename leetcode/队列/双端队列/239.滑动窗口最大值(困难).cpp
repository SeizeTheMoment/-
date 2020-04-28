class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> ans;
        if(N<1)
            return ans;
        deque<int> que;
        for(int i=0;i<N;i++)
        {
            while(que.size()&&nums[i]>nums[que.back()])
                que.pop_back();
            que.push_back(i);
            if(i>=k-1)
                ans.push_back(nums[que.front()]);
            while(que.size()&&i-que.front()+1>=k)
                que.pop_front();
        }
        return ans;
    }
};
