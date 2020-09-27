typedef long long LL;
LL max(LL a, LL b, LL c, LL d)
{
    return max(max(a,b),max(c,d));
}
LL min(LL a,LL b, LL c, LL d)
{
    return min(min(a,b),min(c,d));
}
class Solution {
public:
    const int MOD = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<LL>> dp1(N+1, vector<LL>(M+1,1));         //最大值
        vector<vector<LL>> dp2(N+1, vector<LL>(M+1,1));         //最小值
        dp1[0][0] = dp2[0][0] = grid[0][0];
        for(int i=1;i<N;i++)
            dp1[i][0] = dp2[i][0] = dp1[i-1][0]*grid[i][0];
        for(int j=1;j<M;j++)
            dp1[0][j] = dp2[0][j] = dp1[0][j-1]*grid[0][j];
        for(int i=1; i<N; i++)
        {
            for(int j=1; j<M; j++)
            {
                int g = grid[i][j];
                dp1[i][j] = max(dp1[i-1][j]*g,dp1[i][j-1]*g,dp2[i][j-1]*g,dp2[i-1][j]*g);
                dp2[i][j] = min(dp1[i-1][j]*g,dp1[i][j-1]*g,dp2[i][j-1]*g,dp2[i-1][j]*g);
            }
        }
        if(dp1[N-1][M-1]<0)
            return -1;
        return dp1[N-1][M-1]%MOD;
    }
};
