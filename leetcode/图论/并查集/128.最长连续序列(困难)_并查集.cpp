class Solution {
    unordered_map<int,int> father,cnt;
    int Find(int x)
    {
        int r = x;
        while(r!=father[r])
        {
            r = father[r];
        }
        int i = x;
        int j;
        while(father[i]!=i)
        {
            j = father[i];
            father[i] = r;
            i = j;
        }
        return r;
    }
    int Union(int x, int y)
    {
        int fx = Find(x);
        int fy = Find(y);
        if(fx==fy)
            return cnt[fx];
        if(fx<fy)
        {
            father[fy] = fx;
            cnt[fx] += cnt[fy];
            return cnt[fx];
        }
        else {
            father[fx] = fy;
            cnt[fy] += cnt[fx];
            return cnt[fy];
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        if(N<1)
            return 0;
        for(auto x:nums)
        {
            father[x] = x;
            cnt[x] = 1;
        }
        int ans = 1;
        for(auto x : nums)
        {
            if(father.find(x+1)!=father.end())
            {
                ans = max(ans,Union(x,x+1));
            }
        }
        return ans;
    }
};
