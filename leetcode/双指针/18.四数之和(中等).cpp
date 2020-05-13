class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int N = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<N;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<N;j++)
            {
                if(j!=i+1&&nums[j]==nums[j-1])
                    continue;   
                int le = j+1;
                int ri = N-1;
                while(le<ri)
                {
                    int sum = nums[i]+nums[j]+nums[le]+nums[ri];
                    if(sum==target)
                    {
                        ans.push_back(vector<int>{nums[i],nums[j],nums[le],nums[ri]});
                        while(le<ri&&nums[le+1]==nums[le])
                            le++;
                        while(le<ri&&nums[ri-1]==nums[ri])
                            ri--;
                        le++;
                        ri--;
                    }
                    else if(sum>target)
                        ri--;
                    else le++;
                }
            }
        }
        return ans;
    }
};
