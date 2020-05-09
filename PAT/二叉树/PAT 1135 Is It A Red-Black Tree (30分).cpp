#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
int K;
struct Node
{
    int val;
    Node* lc,*rc;
};
Node* build(Node* root,int val)
{
    if(root==NULL)
    {
        root = new Node();
        root->val = val;
        root->lc = NULL;
        root->rc = NULL;
        return root;
    }
    else if(abs(val)<=abs(root->val))
        root->lc = build(root->lc,val);
    else root->rc = build(root->rc,val);
    return root;
}
bool judgeblk(Node* root)
{
    if(root==NULL)
        return true;
    if(root->val<0)
    {
        if(root->lc&&root->lc->val<0)
            return false;
        if(root->rc&&root->rc->val<0)
            return false;
    }
    return judgeblk(root->lc)&&judgeblk(root->rc);
}
int getblkNum(Node* root)
{
    if(root==NULL)
        return 0;
    int lc = getblkNum(root->lc);
    int rc = getblkNum(root->rc);
    return root->val > 0 ? max(lc,rc)+1:max(lc,rc); 
}
bool judgeblkNum(Node* root)
{
    if(root==NULL)
        return true;
    int lnum = getblkNum(root->lc);
    int rnum = getblkNum(root->rc);
    if(lnum!=rnum)
        return false;
    return judgeblkNum(root->lc) && judgeblkNum(root->rc);
}
int main()
{
    scanf("%d",&K);
    while(K--)
    {
        int N;
        scanf("%d",&N);
        vector<int> pre;
        pre.resize(N);
        Node* root = NULL;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&pre[i]);
            root = build(root,pre[i]);
        }
        if(pre[0]<0||!judgeblk(root)||!judgeblkNum(root))
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}