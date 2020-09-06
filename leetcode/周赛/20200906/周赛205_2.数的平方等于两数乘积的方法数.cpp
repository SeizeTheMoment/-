typedef long long LL;
class Solution {
public:
    int work(vector<int>& v1, vector<int>& v2)
    {
        int res = 0;
        unordered_map<LL, int> hash;
        for(int x : v1)
            hash[(LL)x*x]++;
        for(int j=0;j<v2.size();j++)
        {
            for(int k=j+1;k<v2.size();k++)
            {
                res += hash[(LL)v2[j]*v2[k]];
            }
        }
        return res;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ans = work(nums1,nums2) + work(nums2,nums1);
        return ans;
    }
};
