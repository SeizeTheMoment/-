class Solution {
vector<int> father;
int find(int x)
{
    if(father[x]!=x)
    {
        father[x] = find(father[x]);
    }
    return father[x];
}
int getCost1(int n, vector<vector<int>>&edges, int k)
{
    for(int i=0;i<n;i++)
        father[i] = i;
    int res = 0, cnt=n;
    for(auto &edge : edges)
    {
        int a = edge[0], b=edge[1], w=edge[2];
        if(edge[3] == k)
            continue;
        int fx = find(a);
        int fy = find(b);
        if(fx != fy)
        {
            father[fx] = fy;
            res += w;
            cnt--;
        }
        
    }
    if(cnt>1)
        res = INT_MAX;
    return res; 
}
int getCost2(int n,vector<vector<int>>&edges, int k)
{
    for(int i=0;i<n;i++)
        father[i] = i;
    int res = 0, cnt = n;
    for(auto &edge : edges)
    {
        if(edge[3]==k)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            int fx = find(a);
            int fy = find(b);
            if(fx!=fy)
            {
                father[fx] = fy;
                res += w;
                cnt--;
            }
            break;
        }
    }
    for(auto &edge : edges)
    {
        int a = edge[0], b = edge[1], w = edge[2];
        int fx = find(a);
        int fy = find(b);
        if(fx!=fy){
            father[fx] = fy;
            res += w;
            cnt--;
        }
    }
    if(cnt>1)
        res = INT_MAX;
    return res;
}
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int M = edges.size();
        for(int i=0;i<M;i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](vector<int> A, vector<int> B){return A[2]<B[2];});
        father = vector<int>(n);
        
        int cost = getCost1(n, edges, -1);
        vector<vector<int>> ans = vector<vector<int>>(2);
        for(int k=0;k<M;k++)
        {
            if(getCost1(n,edges,k)!=cost)
                ans[0].push_back(k);
            else if(getCost2(n,edges,k)==cost)
                ans[1].push_back(k);
        }
        return ans;
    }
};