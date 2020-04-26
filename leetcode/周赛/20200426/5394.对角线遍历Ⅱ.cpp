typedef pair<long long,int> P;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<P> p;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                long long val = (long long)(i+j)*(long long)(i+j+1)/2+j+1;
                p.push_back(make_pair(val,nums[i][j]));
            }
        }
        sort(p.begin(),p.end());
        vector<int> ans;
        for(int i=0;i<p.size();i++)
            ans.push_back(p[i].second);
        return ans;
    }
};
