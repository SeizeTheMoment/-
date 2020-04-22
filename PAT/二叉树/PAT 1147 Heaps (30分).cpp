#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int M,N;
bool space = false;
void postTraversal(int ar[1010], int r,int n)
{
    if(r>n)
        return;
    postTraversal(ar,2*r,n);
    postTraversal(ar,2*r+1,n);
    if(space)
        printf(" ");
    else space = true;
    printf("%d",ar[r]);
}
int main()
{
    scanf("%d%d",&M,&N);
    int ar[1010];
    for(int i=0;i<M;i++)
    {
        int flag;
        for(int j=1;j<=N;j++)
        {
            int x;
            scanf("%d",&x);
            ar[j] = x;
        }
        flag = ar[1] > ar[2] ? 1 : -1;
        for(int j=1;j<=N/2;j++)
        {
            int lc = 2*j;
            int rc = 2*j+1;
            if(flag==1&&(ar[j]<ar[lc]||(rc<=N&&ar[j]<ar[rc])))
                flag = 0;
            if(flag==-1&&(ar[j]>ar[lc]||(rc<=N&&ar[j]>ar[rc])))
                flag = 0;
        }
        if(flag==1)
            printf("Max Heap\n");
        else if(flag==-1)
            printf("Min Heap\n");
        else printf("Not Heap\n");
        space = false;
        postTraversal(ar,1,N);
        printf("\n");
    }

    return 0;
}
