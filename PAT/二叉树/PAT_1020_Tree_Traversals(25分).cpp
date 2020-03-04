#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 10010
int post[MAX];
int in[MAX];
int node[MAX];
void rebuild(int pL,int pR, int iL, int iR, int n)
{
    if(iL>iR)
    {
        node[n] = -1;
        return;
    }
    int root = post[pR];
    node[n] = root;
    int m = find(in,in+iR,root) - in;

    int cnt = m-iL;
    rebuild(pL,pL+cnt-1,iL,m-1,2*n);
    rebuild(pL+cnt,pR-1,m+1,iR,2*n+1);
}
void bfs()
{
    queue<int> q;
    q.push(1);
    bool space = false;
    while(q.size())
    {
        int n = q.front();
        int val = node[n];
        q.pop();
        if(val>0)
        {
            if(space)
                printf(" ");
            else space = true;
            printf("%d",val);
            q.push(2*n);
            q.push(2*n+1);
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&post[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&in[i]);
    rebuild(0,N-1,0,N-1,1);

    bfs();
    return 0;
}
