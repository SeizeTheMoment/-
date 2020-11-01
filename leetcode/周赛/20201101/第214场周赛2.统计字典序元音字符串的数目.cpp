class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> cnt(n+1, vector<int>(5));
        for(int i=0;i<5;i++)
            cnt[1][i] = 1;
        int ans = 0;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<5;j++)
            {
                cnt[i][j] = cnt[i-1][j];
                if(j>0)
                    cnt[i][j] += cnt[i][j-1];
            }
        }
        for(int i=0;i<5;i++)
            ans += cnt[n][i];
        return ans;
        
        
    }
};
