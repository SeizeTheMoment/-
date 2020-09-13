#define INF 0x3f3f3f3f
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        vector<vector<int>> costs(N, vector<int>(N,INF));
        vector<int> mincost(N,INF);
        mincost[0] = 0;
        vector<bool> used(N, false);
        for(int i=0;i<N;i++)
        {
            int ix = points[i][0];
            int iy = points[i][1];
            for(int j=i+1;j<N;j++)
            {
                int jx = points[j][0];
                int jy = points[j][1];
                costs[i][j] = abs(ix-jx)+abs(iy-jy);
                costs[j][i] = costs[i][j];
            }
        }
        int res = 0;
        while(true)
        {
            int v = -1;
            for(int u=0;u<N;u++)
            {
                if(!used[u]&&(v==-1||mincost[u]<mincost[v]))
                    v=u;
            }
            if(v==-1)
                break;
            used[v] = true;
            res += mincost[v];
            for(int u=0;u<N;u++)
            {
                mincost[u] = min(mincost[u],costs[v][u]);
            }
        }
        return res;
    }
};
