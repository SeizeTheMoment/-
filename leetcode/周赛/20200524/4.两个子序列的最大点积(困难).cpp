#define INF 0x3f3f3f3f;
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int M = nums2.size();
        vector<vector<int>> dp;
        dp.resize(N+1);
        for(int i=0;i<=N;i++)
            dp[i].resize(M+1);
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=M;j++)
            {
                dp[i][j] = -INF;
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                dp[i][j] = max(dp[i][j],nums1[i-1]*nums2[j-1]);
                dp[i][j] = max(max(dp[i][j],dp[i-1][j]),max(dp[i][j-1],dp[i-1][j-1]+nums1[i-1]*nums2[j-1]));
            }
        }
        return dp[N][M];
    }
};
