class Solution {
    public int rob(int[] nums) {
        int N = nums.length;
        //打劫第一家
        int dp = nums[0];
        int first = dp;
        int second = 0;
        int ans = 0;
        for(int i = 1; i < N-1; i++){
            dp = Math.max(first, second + nums[i]);
            int tmp = first;
            first = dp;
            second = tmp;
        }
        ans = Math.max(ans, dp);
        dp = 0;
        first = 0;
        second = 0;
        for(int i = 1; i < N; i++){
            dp = Math.max(first, second + nums[i]);
            int tmp = first;
            first = dp;
            second = tmp;
        }
        return Math.max(ans, dp);
    }
}