class Solution {
    final int INF = 0x3f3f3f3f;
    int dp[][];
    int func(int k, int n){
        if(n == 0)
            return 0;
        if(k == 1)
            return n;
        if(dp[k][n] != INF)
        {
            return dp[k][n];
        }
        int le = 1;
        int ri = n;
        int mid = (le + ri) / 2;
        int res = INF;
        while(le <= ri)
        {
            mid = (le + ri) / 2;
            int broken = func(k - 1, mid - 1);
            int unbroken = func(k, n - mid);
            if(broken > unbroken){
                res = Math.min(res, broken + 1);
                ri = mid - 1;
            }
            else {
                res = Math.min(res, unbroken + 1);
                le = mid + 1;
            }
        }
        dp[k][n] = res;
        return res;
    }
    public int superEggDrop(int k, int n) {
        dp = new int[k + 1][n + 1];
        for(int i = 0; i <= k; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j] = INF;
        return func(k, n);       
    }
}