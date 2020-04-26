class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> sum;
        int N = cardPoints.size();
        sum.resize(N+1);
        for(int i=0;i<N;i++)
        {
            sum[i+1] = sum[i] + cardPoints[i];
        }
        int ans = 0;
        for(int i=0;i<=k;i++)
        {
            int right = N-k+i;
            ans = max(ans, sum[N]-sum[right]+sum[i]);
        }
        return ans;
    }
};
