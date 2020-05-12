class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<N;i++)
        {
            if(nums[i]>0)
                break;
            int le = i+1;
            int ri = N-1;
            if(i>0&&nums[i]==nums[i-1])               //去重
                continue;
            while(le<ri)
            {
                int sum = nums[i]+nums[le]+nums[ri];
                if(sum==0)
                {
                    ans.push_back(vector<int>{nums[i],nums[le],nums[ri]});
                    while(le<ri&&nums[le+1]==nums[le])        //去重
                        le++; 
                    while(le<ri&&nums[ri-1]==nums[ri])        //去重
                        ri--;
                    le++;
                    ri--;
                }
                else if(sum>0)
                    ri--;
                else le++;
            }
        }
        return ans;
    }
};
