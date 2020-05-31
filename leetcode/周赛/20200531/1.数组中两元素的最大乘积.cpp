class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        return (nums[N-1]-1)*(nums[N-2]-1);
    }
};
