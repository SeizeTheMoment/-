const int MOD = 10e8+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int N = horizontalCuts.size();
        int M = verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxi = horizontalCuts[0];
        int maxj = verticalCuts[0];
        for(int i=1;i<N;i++)
            maxi = max(maxi,horizontalCuts[i] - horizontalCuts[i-1]);
        maxi = max(maxi,h - horizontalCuts[N-1]);
        for(int j=1;j<M;j++)
            maxj = max(maxj, verticalCuts[j] - verticalCuts[j-1]);
        maxj = max(maxj, w - verticalCuts[M-1]);
        //return maxi;
        return ((long long)maxi*(long long)maxj)%MOD;
        
    }
};
