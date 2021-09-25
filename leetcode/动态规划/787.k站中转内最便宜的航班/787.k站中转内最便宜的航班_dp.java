class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        final int INF = 0x3f3f3f3f;
        int matrix[][] = new int[n][n];
        for(int[] flight : flights) {
            matrix[flight[0]][flight[1]] = flight[2];
        }
        int dp[][] = new int[k + 2][n];
        //乘t次航班到达i 需要的花费
        //dp[t][i] = min(dp[t-1][j] + cost[j][i])
        //换乘k次即乘坐k+1次
        for(int i = 0; i < k+2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dp[i][j] = INF;
            }
        }
        dp[0][src] = 0;
    
        int ans = INF;
        for(int t = 1;  t < k + 2; t++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(matrix[j][i] != 0)
                    {
                        dp[t][i] = Math.min(dp[t][i], dp[t - 1][j] + matrix[j][i]);
                    }
                }
                if(i == dst)
                    ans = Math.min(ans, dp[t][i]);
            }
        }
        if(ans == INF) return -1;
        return ans;
    }
}