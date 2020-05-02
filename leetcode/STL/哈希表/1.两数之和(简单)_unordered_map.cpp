class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pos;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
             if(pos.find(target-nums[i])!=pos.end())
            {
                ans.push_back(pos[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            pos[nums[i]] = i;
        }
        return ans;
    }
};
