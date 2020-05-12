class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> m;             //数字出现的次数
        vector<int> num;                      //无重复数组
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]] = 1;
                num.push_back(nums[i]);
            }
            else{
                m[nums[i]]++;
            }
        }
        sort(num.begin(),num.end());
        int N = num.size();
        vector<vector<int>> ans;
        for(int i=0;i<N;i++)
        {
            for(int j=i;j<N;j++)
            {
                if(j==i&&m[num[j]]==1)           //如果这个数只有1个
                    continue;
                if(2*num[j]+num[i]>0)            //保证在j之后寻找满足和为0的target
                    continue;
                int target = -num[i]-num[j];
                if(m.find(target)!=m.end())
                {
                    if(2*num[j]+num[i]==0)       //target和num[j]相等时判断各数字可用个数
                    {
                        if(num[j]==num[i])
                        {
                            if(m[num[j]]<=2)
                                continue;
                        }
                        else{
                            if(m[num[j]]==1)
                                continue;
                        }
                    }
                    ans.push_back(vector<int>{num[i],num[j],target});
                }
            }
        }
        return ans;
    }
};
