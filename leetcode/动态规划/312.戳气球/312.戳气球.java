class Solution {
    //状态：戳破(i, j)的气球
    //选择：剩下标为k的气球等待被戳破
    public int maxCoins(int[] nums) {
        int N = nums.length;
        int[] points = new int[N + 2];
        points[0] = points[N + 1] = 1;
        for(int i = 1; i <= N; i++)
            points[i] = nums[i -1];
        int[][] dp = new int[N + 2][N + 2];
        //转移方程 设k为最后一个被戳破的
        //从左到右，从下往上遍历
        
        for(int i = N + 1; i >= 0; i--)
        {
            for(int j = i + 1; j <= N + 1; j++)
            {
                int mul = points[i] * points[j];
                //戳破k，k应该在i到j的开区间里
                for(int k = i + 1; k < j; k++)
                {
                    dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k][j] + mul * points[k]);
                }
            }
        }
        return dp[0][N + 1];
    }
   
}