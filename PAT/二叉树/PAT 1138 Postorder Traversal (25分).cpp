#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 50010
using namespace std;
int pre[MAX];
int in[MAX];
int ans=-1;
int N;
void getPost(int pL,int pR,int iL,int iR)
{
    if(ans>0)
        return;
    if(pL>pR)
        return;
    int root = pre[pL];
    int pos = find(in,in+iR+1,root)-in;
    int cnt = pos-iL; 
    getPost(pL+1,pL+cnt,iL,iL+cnt-1);
    getPost(pL+cnt+1,pR,iL+cnt+1,iR);
    if(ans<0)
    {
        printf("%d\n",root);
        ans = 0;
        return;
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&in[i]);
    getPost(0,N-1,0,N-1);
    return 0;
}
