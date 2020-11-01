class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int le = 0;
        int ri = nums.size();
        int mid;
        while(le<ri)
        {
            mid = (le+ri)/2;
            if(nums[mid]==mid)
                le = mid + 1;
            else ri = mid;    
        }
        return le;
    }
};