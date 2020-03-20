#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#define MAX 10100
using namespace std;

int M,N;
int pre[MAX];
int in[MAX];
map<int,int> pos;
int main()
{
    scanf("%d%d",&M,&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&in[i]);
        pos[in[i]] = i;
    }
    for(int i=0;i<N;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<M;i++)
    {
        int U,V;
        scanf("%d%d",&U,&V);
        if(pos.find(U)==pos.end())
        {
            if(pos.find(V)==pos.end())
            {
                printf("ERROR: %d and %d are not found.\n",U,V);
            }
            else printf("ERROR: %d is not found.\n",U);
        }
        else if(pos.find(V)==pos.end())
            printf("ERROR: %d is not found.\n",V);
        else{
            int ans = 0;
            int posU = pos[U];
            int posV = pos[V];
            for(int i=0;i<N;i++)
            {
                int p = pos[pre[i]];
                if((p>=posU&&p<=posV)||(p>=posV&&p<=posU))
                {
                    ans = p;
                    break;
                }
            }
            ans = in[ans];
            if(ans==U)
                printf("%d is an ancestor of %d.\n",U,V);
            else if(ans==V)
                printf("%d is an ancestor of %d.\n",V,U);
            else printf("LCA of %d and %d is %d.\n",U,V,ans);
        }
    }
    return 0;
}
