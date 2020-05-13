class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        int mini = 0x3f3f3f3f;
        int ans = -1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<N;i++)
        {
            int le = i+1;
            int ri = N-1;
            while(le<ri)
            {
                int sum = nums[i] + nums[le] + nums[ri];
                if(abs(sum-target)<mini)
                {
                    mini = abs(sum-target);
                    ans = sum;
                }
                if(sum==target)
                    return target;
                else if(sum<target)
                {
                    le++;
                }
                else ri--;
            }
        }
        return ans;
    }
};
