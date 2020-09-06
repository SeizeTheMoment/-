class Solution {
public:
    vector<int> pa, pb;
    int find(vector<int>&p, int x)
    {
        return p[x] == x ? x : p[x] = find(p, p[x]);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        pa.resize(n+1);
        pb.resize(n+1);
        for(int i=1;i<=n;i++)
            pa[i] = pb[i] = i;
        int res = 0;
        int ca = n;
        int cb = n;
        for(auto edge:edges)
        {
            if(edge[0]==3)
            {
                int x = edge[1];
                int y = edge[2];
                int fax = find(pa,x), fay = find(pa, y);
                int fbx = find(pb,x), fby = find(pb, y);
                if(fax!=fay)
                {
                    pa[fax] = fay;
                    ca--;
                    pb[fbx] = fby;
                    cb--;
                }else{
                    res++;
                }
            }
        }
        for(auto edge:edges)
        {
            if(edge[0]==3)
                continue;
            int x = edge[1];
            int y = edge[2];
            if(edge[0]==1)
            {
                int fax = find(pa, x), fay = find(pa, y);
                if(fax != fay)
                {
                    pa[fax] = fay;
                    ca--;
                }
                else res++;
            }
            else{
                int fbx = find(pb, x), fby = find(pb, y);
                if(fbx != fby)
                {
                    pb[fbx] = fby;
                    cb--;
                }
                else res++;
            }
        }
        if(ca>1||cb>1)
            return  -1;
        return res;
    }
};
