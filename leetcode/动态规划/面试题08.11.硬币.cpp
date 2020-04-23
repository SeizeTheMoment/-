//https://leetcode-cn.com/problems/coin-lcci
const int MOD = 1e9+7;
class Solution {
public:
    int waysToChange(int n) {
          vector<long long> dp;
          int val[4] = {25, 10, 5, 1};
          dp.resize(n+1);
          dp[0] = 1;
          for(int x:val)
          {
              for(int i=x;i<=n;i++)
              {
                  dp[i] = (dp[i]+dp[i-x])%MOD;
              }
          }
          return dp[n];
    }
};