class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        int N = nums.size();
        while(i<N)
        {
            if(nums[i]!=i)
            {
                int x = nums[i];
                if(nums[i]==x)
                    return x;
                swap(nums[i],nums[x]);
            }
            else i++;
        }
        return -1;
    }
};
