class Solution {
    //状态 dp[i] 表示 凑金额i方法的个数
    //转移方程 dp[i] = sum(dp[i - coin]);
    //需要先遍历coin再遍历amount，这样做就确定了排列的顺序，不会重复计算
    public int change(int amount, int[] coins) {
        int dp[];
        dp = new int[amount + 1];
        //base case:
        dp[0] = 1;
        for(int coin : coins)
        {
            for(int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
}