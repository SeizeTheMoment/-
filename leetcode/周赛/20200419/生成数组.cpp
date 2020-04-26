const long long MOD = 1e9+7;
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long dp[60][110][60];
        for(int i=1;i<=m;i++)
        {
            dp[1][i][1] = 1;
        }
        for(int p=2;p<=n;p++)
        {
            for(int q=1;q<=m;q++)
            {
                for(int r=1;r<=p&&r<=k;r++)
                {
                    dp[p][q][r] = (q*dp[p-1][q][r])%MOD;
                    for(int j=1;j<=q-1;j++)
                    {
                        dp[p][q][r]+=dp[p-1][j][r-1];
                        dp[p][q][r] %= MOD;
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=1;i<=m;i++)
        {
            ans+=dp[n][i][k];
            ans%=MOD;
        }
        return ans;
    }
};
