class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int dp[];
        int N = envelopes.length;
        dp = new int[N];
        Arrays.sort(envelopes, (int[] o1, int[] o2) -> {
            if(o1[0] == o2[0])
                return o2[1] - o1[1];
            return o1[0] - o2[0];
        });
        //实际上就是最长递增子序列问题
        int ans = 1;
        for(int i = 0; i < N; i++)
        {
            dp[i] = 1;
            for(int  j = 0; j < i; j++)
            {
                if(envelopes[j][1] < envelopes[i][1])
                {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
                ans = Math.max(ans, dp[i]);
            }
        }
        return ans;
    }
}