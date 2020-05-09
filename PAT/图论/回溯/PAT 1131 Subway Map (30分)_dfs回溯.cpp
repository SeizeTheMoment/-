#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f;
using namespace std;
int N,M;
vector<vector<int> > lines;
map<int, vector<pair<int,int> >> loc;
map<int, bool> visited;
struct Node
{
    int id;
    int lineid;
    int ind;
    int step;
};
int minitrans = INF;
vector<Node> path;
int ministep = INF;
void dfs(int curid, int dest,int lineid, int ind,int step,int trans,vector<Node>& route, map<int,bool>&vis)
{
    if(step>ministep)
        return;
    if(curid==dest)
    {
        if(step<ministep)
        {
            path = route;
            ministep = step;
            minitrans = trans;
        }
        else if(step==ministep)
        {
            if(trans<minitrans)
            {
                path = route;
                minitrans = trans;
            }
        }
        return;
    }
    for(int i=0;i<loc[curid].size();i++)
    {
        int newlineid = loc[curid][i].first;
        int ind = loc[curid][i].second;
        for(int d=-1;d<=1;d+=2)
        {
            int newind = ind+d;
            if(newind>=0&&newind<lines[newlineid].size()&&!vis[lines[newlineid][newind]])
            {
                int newid = lines[newlineid][newind];
                vis[newid] = true;
                route.push_back(Node{newid,newlineid,newind,step+1});
                if(newlineid!=lineid)
                    dfs(newid,dest,newlineid, newind,step+1,trans+1,route,vis);
                else dfs(newid,dest,newlineid, newind,step+1,trans,route,vis);
                vis[newid] = false;
                route.pop_back();
            }
        }
    }
}
int main()
{
    scanf("%d",&N);
    lines.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        int M;
        scanf("%d",&M);
        lines[i].resize(M);
        for(int j=0;j<M;j++)
        {
            int x;
            scanf("%d",&x);
            lines[i][j] = x;
            loc[x].push_back(make_pair(i,j));
        }
    }
    int K;
    scanf("%d",&K);
    while(K--)
    {
        int src,dest;
        scanf("%d%d",&src,&dest);
        vector<Node> route;
        map<int,bool> vis;
        minitrans = INF;
        ministep = INF;
        vis[src] = true;
        dfs(src,dest,loc[src][0].first,loc[src][0].second,0,0,route,vis);
        printf("%d\n",ministep);
        int nowline = path[0].lineid;
        int s = src;
        int e = path[0].id;
        for(int i=1;i<path.size();i++)
        {
            if(path[i].lineid!=nowline)
            {
                printf("Take Line#%d from %04d to %04d.\n",nowline,s,e);
                s = e;
                e = path[i].id;
                nowline = path[i].lineid;
            }
            else{
                e = path[i].id;
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",nowline,s,e);
    }
    return 0;
}