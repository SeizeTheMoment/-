/* 
递归法
class Solution {
    int coins[];
    int dp[];
    int func(int n)
    {
        if(n < 0)
            return -1;
        if(n == 0)
            return 0;
        if(dp[n] != -2)
            return dp[n];
        int res = Integer.MAX_VALUE;
        for(int coin : coins){
            int sub = func(n - coin);
            if(sub >= 0)
            {
                res = Math.min(res, sub + 1);
            }
        }
        if(res != Integer.MAX_VALUE){
            dp[n] = res;
        }
        else dp[n] = -1;
        return dp[n];
    }
    public int coinChange(int[] coins, int amount) {
        this.coins = coins;
        dp = new int[amount + 1];
        for(int i = 0; i <= amount; i++)
            dp[i] = -2;
        return func(amount);
    }
   
}*/
//dp
class Solution {
    public int coinChange(int[] coins, int amount) {
        int dp[] = new int[amount + 1];
        for(int i = 0; i <= amount; i++)
            dp[i] = amount + 1;
        // dp[i] = min(dp[i - coin]) + 1
        dp[0] = 0;
        for(int i = 0; i <= amount; i++)
        {
            for(int coin : coins)
            {
                if(i - coin >= 0)
                {
                    dp[i] = Math.min(dp[i], dp[i-coin] + 1);
                }
                
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
}
