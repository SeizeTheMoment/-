class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(N+2, vector<int>(N+2));
        //棍长由短至长
        for(int cnt=2;cnt<=N+1;cnt++)
        {
            for(int i=0;i+cnt<=N+1;i++)
            {
                int j = i+cnt;
                dp[i][j] = INT_MAX;
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
                }
            }
        }
        return dp[0][N+1];
    }
};
