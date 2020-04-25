#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 10010
using namespace std;
int N;
int ar[MAX];
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&ar[i]);
    }
    sort(ar, ar+N, greater<int>());
    int m=N;
    int n=1;
    int mm=m;
    int nn=n;
    while(mm>=nn)
    {
        if(mm*nn==N)
        {
            m = mm;
            n = nn;
        }
        mm--;
        if(mm>0)
           nn = N/mm;
        else break;
    }
    vector<vector<int> > ans;
    ans.resize(m);
    for(int i=0;i<m;i++)
        ans[i].resize(n);
    int k = 0;
    int ms = 0;
    int me = m-1;
    int ns = 0;
    int ne = n-1;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int cur = 0;
    int x = 0;
    int y = 0;
    while(k<N)
    {
        ans[x][y] = ar[k++];
        if(cur==0&&y==ne)
        {
            cur=1;
        }
        else if(cur==1&&x==me)
        {
            cur=2;
        }
        else if(cur==2&&y==ns)
        {
            cur=3;
        }
        else if(cur==3&&x==ms+1)
        {
            cur=0;
            ms++;
            me--;
            ns++;
            ne--;
        }
        x += dx[cur];
        y += dy[cur];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=0)
                printf(" ");
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
