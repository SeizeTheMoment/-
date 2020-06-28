class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int val:arr)
        {
            int modules = (val%k+k)%k;
            m[modules]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            int modules = it->first;
            int cnt1 = it->second;
            if(modules==0)
            {
                if(cnt1%2==1)
                    return false;
            }
            else{
                int modules2 = (k-modules);
                int cnt2 = m[modules2];
                if(cnt1!=cnt2)
                    return false;
            }
        }
        return true;
    }
};
