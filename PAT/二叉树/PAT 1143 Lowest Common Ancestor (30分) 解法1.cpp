#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 10100
using namespace std;

int N,M;
int pre[MAX];
int in[MAX];
map<int,int> pos;
vector<int> ancestor[MAX];
//int father[MAX];
struct Node
{
    int val;
    int father=-1;
}node[MAX];
void rebuild(int iL,int iR,int pL,int pR,int rindex)
{
    if(iL>iR||pL>pR)
        return;
    int root = pre[pL];
    int m = pos[root];
    node[m].father = rindex;
    rebuild(iL,m-1,pL+1,pL+m-iL,m);
    rebuild(m+1,iR,pL+m-iL+1,pR,m);
}
int main()
{
    scanf("%d%d",&M,&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&pre[i]);
        in[i] = pre[i];
    }
    sort(in,in+N);
    for(int i=0;i<N;i++)
    {
        node[i].val = in[i];
        pos[node[i].val] = i;
    }
    rebuild(0,N-1,0,N-1,-1);
    for(int i=0;i<M;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(pos.find(a)==pos.end())
        {
            if(pos.find(b)==pos.end())
            {
                printf("ERROR: %d and %d are not found.\n",a,b);
            }
            else{
                printf("ERROR: %d is not found.\n",a);
            }
        }
        else if(pos.find(b)==pos.end())
        {
            printf("ERROR: %d is not found.\n",b);
        }
        else{
            if(a==b)
            {
                printf("%d is an ancestor of %d.\n",a,b);
                continue;
            }
            int aindex = pos[a];
            int bindex = pos[b];
            int ra = aindex;
            int rb = bindex;
            vector<int> afa, bfa;
            bool flag = true;
            while(ra!=-1)
            {
                afa.push_back(ra);
                if(node[ra].father == bindex)
                {
                    flag = false;
                    printf("%d is an ancestor of %d.\n",b, a);
                    break;
                }
                ra = node[ra].father;
            }
            while(flag&&rb!=-1)
            {
                bfa.push_back(rb);
                if(node[rb].father == aindex)
                {
                    printf("%d is an ancestor of %d.\n",a, b);
                    flag = false;
                    break;
                }
                rb = node[rb].father;
            }
            if(flag)
            {
                int ai = afa.size()-1;
                int bj = bfa.size()-1;
                while(ai>=0&&bj>=0&&afa[ai]==bfa[bj])
                {
                    ai--;
                    bj--;
                }
                printf("LCA of %d and %d is %d.\n",a, b, in[afa[ai+1]]);
            }
        }
    }
    return 0;
}
