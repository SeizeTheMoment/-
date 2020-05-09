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
int ministep = INF;
void bfs(int src,int dest)
{
    queue<Node> que;
    //for(int i=0;i<loc[src].size();i++)
    que.push(Node{src,loc[src][0].first,loc[src][0].second,0});
    visited[src] = true;
    while(que.size())
    {
        Node next = que.front();
        que.pop();
        int lineid = next.lineid;
        int ind = next.ind;
        int nowstep = next.step;
        int nowid = next.id;
        if(nowid==dest)
        {
            ministep = nowstep;
            return;
        }
        //遍历该节点所有线路
        for(int i=0;i<loc[nowid].size();i++)
        {
            //该节点的lineid和在该线路的下标ind
            int lineid = loc[nowid][i].first;
            int ind = loc[nowid][i].second;
            //向前、向后遍历
            for(int d=-1;d<=1;d+=2)
            {
                int newind = ind+d;
                if(newind>=0&&newind<lines[lineid].size()&&!visited[lines[lineid][newind]])
                {
                    que.push(Node{lines[lineid][newind],lineid,newind,nowstep+1});
                    visited[lines[lineid][newind]] = true;
                }
            }
        }
    }
}
int minitrans = INF;
vector<Node> path;
void dfs(int curid, int dest,int lineid, int ind,int step,int trans,vector<Node>& route, map<int,bool>&vis)
{
    if(step>ministep)
        return;
    if(step==ministep&&curid==dest)
    {
        if(trans<minitrans)
        {
            path = route;
            minitrans = trans;
        }
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
        ministep = INF;
        visited.clear();
        bfs(src,dest);
        printf("%d\n",ministep);
        vector<Node> route;
        map<int,bool> vis;
        minitrans = INF;
        vis[src] = true;
        dfs(src,dest,loc[src][0].first,loc[src][0].second,0,0,route,vis);
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