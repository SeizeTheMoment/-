/*
    著名打家劫舍问题
      dp[i][0] = max(dp[i-1][0], dp[i-1][1])
      dp[i][1] = max(dp[i-1][0], dp[i-2][1]) + nums[i]
      dp[i] = max(dp[i-1], dp[i-2];)
    =>
      dp[i] = max(dp[i-1], dp[i-2] + nums[i])
*/
class Solution {
    public int rob(int[] nums) {
        int N = nums.length;
        if(N == 0)
            return 0;
        int dp = nums[0];
        int first = dp;
        int second = 0;
        for(int i = 1; i < N; i++){
            dp = Math.max(first,  second + nums[i]);
            int tmp  = first;
            first = dp;
            second = tmp;
        }
        return dp;
    }
}