class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0;
        int j=0;
        long long ans = 2147483647;
        while(i<a.size()&&j<b.size())
        {
            if(a[i]==b[j])
                return 0;
            if(a[i]>b[j])
            {
                ans = min(ans,((long long)a[i]-(long long)b[j]));
                j++;
            }
            else{
                ans = min(ans,((long long)b[j]-(long long)a[i]));
                i++;
            }
        }
        return ans;
    }
};
