class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int N = nums.size();
        vector<int> f(N), g(N);
        if(nums[0] > 0)
            f[0] = 1;
        else if(nums[0] < 0)
            g[0] = 1;
        int res = f[0];
        for(int i = 1; i < N; i++)
        {
            if(nums[i]>0)
            {
                f[i] = f[i-1] + 1;
                if(g[i-1])
                    g[i] = g[i-1] + 1;
            }
            else if(nums[i] < 0)
            {
                g[i] = f[i-1] + 1;
                if(g[i-1])
                    f[i] = g[i-1] + 1;
            }
            res = max(res,f[i]);
        }
        return res;
        
    }
};
