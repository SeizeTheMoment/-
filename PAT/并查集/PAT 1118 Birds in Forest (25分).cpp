#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#define MAX 10100
using namespace std;
int N,Q;
int father[MAX];
set<int> birds;
int Find(int x)
{
    int r = x;
    while(father[r]!=r)
        r = father[r];
    int i = x;
    int j;
    while(father[i]!=i)
    {
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void Union(int x,int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if(fy<fx)
        father[fy] = fx;
    else father[fx] = fy;
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<MAX;i++)
        father[i] = i;
    for(int i=0;i<N;i++)
    {
        int K;
        int r;
        scanf("%d",&K);
        for(int j=0;j<K;j++)
        {
            int x;
            scanf("%d",&x);
            birds.insert(x);
            if(j==0)
            {
                r = x;
            }
            else{
                Union(x,r);
            }
        }
    }

    int cnt = 0;
    for(auto bird=birds.begin();bird!=birds.end();bird++)
    {
        int id = *bird;
        if(father[id]==id)
        {
            cnt++;
        }
    }
    printf("%d %d\n",cnt,birds.size());
    scanf("%d",&Q);
    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(Find(x)==Find(y))
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }

    return 0;
}

