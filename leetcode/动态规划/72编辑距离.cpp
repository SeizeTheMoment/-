class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.length();
        int M = word2.length();
        if(N==0)
        {
            if(M==0)
                return 0;
            return 1;
        }
        if(M==0)
            return 1;
        int dp[1100][1100];
        dp[0][0] = word1[0]==word2[0] ? 0:1;
        bool flag1 = false;
        bool flag2 = false;
        for(int j=1;j<M;j++)
        {
            if(!flag1&&word1[0]==word2[j])
            {
                flag1 = true;
                dp[0][j] = dp[0][j-1];
            }
            else dp[0][j] = dp[0][j-1]+1;
        }
        for(int i=1;i<N;i++)
        {
            if(!flag2&&word1[i]==word2[0])
            {
                flag2 = true;
                dp[i][0] = dp[i-1][0];
            }
           else dp[i][0] = dp[i-1][0]+1;
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(word1[i]==word2[j])
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
        }
        return dp[N-1][M-1];

    }
};