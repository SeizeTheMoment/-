#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX
using namespace std;

int N;
int pre[35];
int post[35];
int in[35];
int k=0;
bool flag = true;
void Inorder(int preL, int preR, int postL, int postR)
{
    if(preL>preR||postL>postR)
        return;
    if(preL==preR)
    {
        in[k++] = pre[preL];
        return;
    }
    int cnt = 0;
    while(post[postL+cnt]!=pre[preL+1])
        cnt++;
    cnt+=1;
    if(cnt==1&&preL+cnt==preR)
        flag = false;
    Inorder(preL+1,preL+cnt,postL,postL+cnt-1);
    in[k++] = pre[preL];
    Inorder(preL+cnt+1,preR,postL+cnt,postR-1);
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&post[i]);
    Inorder(0,N-1,0,N-1);
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    for(int i=0;i<N;i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",in[i]);
    }
    printf("\n");
    return 0;
}

