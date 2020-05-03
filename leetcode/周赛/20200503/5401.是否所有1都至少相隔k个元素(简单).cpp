class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastone = -1;
        bool ans = true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                if(lastone<0)
                {
                    lastone = i;
                    continue;
                }
                if(i-lastone>=k+1)
                {
                    lastone = i;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};
