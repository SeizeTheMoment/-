class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.length();
        unordered_set<char> occ;
        int rk = -1;
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(i!=0)
                occ.erase(s[i-1]);
            while(rk+1<N&&!occ.count(s[rk+1]))
            {
                occ.insert(s[rk+1]);
                rk++;
            }
            ans = max(ans,rk-i+1);
        }
        return ans;
    }
};
