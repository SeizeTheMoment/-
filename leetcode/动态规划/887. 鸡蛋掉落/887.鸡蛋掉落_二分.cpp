#define INF 0x3f3f3f3f
class Solution {
vector<vector<int> > dp;
int func(int k, int n)
{
    if(k == 1)
        return n;
    if(n == 0)
        return 0;
    if(dp[k][n] != INF)
        return dp[k][n];
    int res = INF;
    //func(k, n - i)  没碎 去i+1 ~ n 楼搜索
    //func(k - 1, i -1) 碎了，去0 ~ i-1楼搜索
    //左闭右闭
    int le = 1;
    int ri = n;
    int mid = (le + ri) / 2;
    while(le <= ri)
    {
        //表示在mid层楼扔下鸡蛋
        mid = (le + ri) / 2;
        int broken = func(k - 1, mid - 1);
        int unbroken = func(k, n - mid);
        if(broken > unbroken)
        {
            res = min(res, broken + 1);
            ri = mid - 1;

        }
        else{
            res = min(res, unbroken + 1);
            le = mid + 1;
        }
    }
    // for(int i = 1; i <= n; i++)
    // { 
    //     res = min(res, max(func(k, n - i), func(k - 1, i - 1)) + 1);
    // }
    dp[k][n] = res;
    return res;
}
public:
    int superEggDrop(int k, int n) {
        dp = vector<vector<int> >(k + 1, vector<int> (n + 1));
        for(int i = 0; i <= k; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                dp[i][j] = INF;
            }
        }
        return func(k, n);
    }
};