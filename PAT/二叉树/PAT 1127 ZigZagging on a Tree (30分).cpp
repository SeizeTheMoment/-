#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 32
using namespace std;
int N;
int in[MAX];
int post[MAX];
vector<int> ans[MAX];
struct Node
{
    int val;
    int lc=-1;
    int rc=-1;
}node[MAX];
void rebuild(int iL,int iR,int pL,int pR,int rindex,bool flag)
{
    if(iL>iR||pL>pR)
        return;
    int rootval = post[pR];
    int m = find(in,in+N,rootval)-in;
    if(flag)
        node[rindex].lc = m;
    else node[rindex].rc = m;
    rebuild(iL,m-1,pL,pL+m-iL-1,m,true);
    rebuild(m+1,iR,pL+m-iL,pR-1,m,false);
}
int deep = 0;
void bfs()
{
    int root = find(in,in+N,post[N-1])-in;
    queue<pair<int,int> > que;
    que.push(make_pair(root,0));
    bool space = false;
    while(que.size())
    {
        int next = que.front().first;
        int step = que.front().second;
        que.pop();
        if(next<0)
            continue;
        int val = node[next].val;
        ans[step].push_back(val);
        deep = max(deep,step);
        int lc = node[next].lc;
        int rc = node[next].rc;
        int newstep = (step+1);
        que.push(make_pair(lc,newstep));
        que.push(make_pair(rc,newstep));
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&in[i]);
        node[i].val = in[i];
    }
    for(int i=0;i<N;i++)
        scanf("%d",&post[i]);
    rebuild(0,N-1,0,N-1,N,true);
    bfs();
    bool space = false;
    for(int i=0;i<=deep;i++)
    {
        if(i%2==0)
        {
            for(int j=ans[i].size()-1;j>=0;j--)
            {
                if(space)
                    printf(" ");
                else space = true;
                printf("%d",ans[i][j]);
            }
        }
        else{
            for(int j=0;j<ans[i].size();j++)
            {
                printf(" ");
                printf("%d",ans[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}
