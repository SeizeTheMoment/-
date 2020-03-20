#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#define MAX 10100
using namespace std;
map<int, bool> mp;
int M,N;
int pre[MAX];
int main()
{

    scanf("%d%d",&M,&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&pre[i]);
        mp[pre[i]] = true;
    }
    for(int i=0;i<M;i++)
    {
        int U,V,ans;
        scanf("%d%d",&U,&V);
        for(int j=0;j<N;j++)
        {
            ans = pre[j];
            if((ans>=U&&ans<=V)||(ans>=V&&ans<=U))
                break;
        }
        if(!mp[U])
        {
            if(!mp[V])
                printf("ERROR: %d and %d are not found.\n",U,V);
            else printf("ERROR: %d is not found.\n",U);
        }
        else if(!mp[V])
            printf("ERROR: %d is not found.\n",V);
        else if(ans==U)
            printf("%d is an ancestor of %d.\n", ans, V);
        else if(ans==V)
            printf("%d is an ancestor of %d.\n",ans,U);
        else
            printf("LCA of %d and %d is %d.\n",U,V,ans);
    }
}
