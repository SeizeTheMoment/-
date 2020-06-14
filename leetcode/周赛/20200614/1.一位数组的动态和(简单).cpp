class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        int N = nums.size();
        sum.resize(N);
        sum[0] = nums[0];
        for(int i=1;i<N;i++)
        {
            sum[i] = sum[i-1]+nums[i];
            //tot+= sum[i];
        }
        return sum;
        
    }
};
