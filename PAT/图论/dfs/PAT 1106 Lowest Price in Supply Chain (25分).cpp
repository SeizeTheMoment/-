#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 101000
using namespace std;
int N;
vector<int> children[MAX];
double P, r;
int mini = 0x3f3f3f3f;
int num = 0;
double quickpow(double x, int n)
{
    if(n==0)
        return 1.0;
    if(n==1)
        return x;
    if(n&1)
        return x*quickpow(x,n-1);
    else{
        double t = quickpow(x,n/2);
        return t*t;
    }
}
void dfs(int ind,int step)
{
    if(step>mini)
        return;
    if(children[ind].empty())
    {
        if(step<mini)
        {
            mini = step;
            num = 1;
        }
        else if(mini==step)
            num++;
        return;
    }
    for(int i=0;i<children[ind].size();i++)
    {
        dfs(children[ind][i],step+1);
    }
}
int main()
{
    scanf("%d",&N);
    scanf("%lf%lf",&P,&r);
    r = 1.0+0.01*r;
    for(int i=0;i<N;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int child;
            scanf("%d",&child);
            children[i].push_back(child);
        }
    }
    dfs(0,0);
    printf("%.4f %d\n",P*quickpow(r,mini),num);
    return 0;
}
