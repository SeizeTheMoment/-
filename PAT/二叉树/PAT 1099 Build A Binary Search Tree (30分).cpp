#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 110
using namespace std;
int N;
struct Node
{
    int lc;
    int rc;
    int val;
}node[MAX];
int ar[MAX];
int in[MAX];
int k=0;
void getIn(int ind)
{
    if(ind<0)
        return;
    getIn(node[ind].lc);
    in[k++] = ind;
    getIn(node[ind].rc);
}
void bfs()
{
    queue<Node> que;
    que.push(node[0]);
    bool space = false;
    while(que.size())
    {
        Node next = que.front();
        que.pop();
        if(next.lc>0)
            que.push(node[next.lc]);
        if(next.rc>0)
            que.push(node[next.rc]);
        if(space)
            printf(" ");
        else space = true;
        cout<<next.val;
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        node[i].lc = a;
        node[i].rc = b;
    }
    for(int i=0;i<N;i++)
    {
        int x;
        scanf("%d",&x);
        ar[i] = x;
    }
    sort(ar,ar+N);
    getIn(0);
    for(int i=0;i<N;i++)
    {
        node[in[i]].val = ar[i];
    }
    bfs();
    printf("\n");
    return 0;
}

