#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 10100
using namespace std;
int N,K;
struct Person
{
    string name;
    int height;
    bool operator < (Person x)
    {
        if(height==x.height)
            return name<x.name;
        return height>x.height;
    }
}person[MAX];
vector<string> vec[MAX];
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        cin>>person[i].name>>person[i].height;
    }
    sort(person,person+N);
    int last = N%K + N/K;
    int ind = 1;
    if(last)
    {
        vec[0].resize(last);
        int center = last/2;
        vec[0][center] = person[0].name;
        int le = center-1;
        int ri = center+1;
        while(ind<last)
        {
            vec[0][le--] = person[ind++].name;
            if(ind>=last)
                break;
            vec[0][ri++] = person[ind++].name;
        }
    }
    int rows = K;
    int nums = N/K;
    for(int i=1;i<rows;i++)
    {
        vec[i].resize(nums);
        int center = nums/2;
        vec[i][center] = person[ind++].name;
        int le = center-1;
        int ri = center+1;
        while(ind<last+i*nums)
        {
            vec[i][le--] = person[ind++].name;
            if(ind>=last+i*nums)
                break;
            vec[i][ri++] = person[ind++].name;
        }
    }
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            if(j!=0)
                printf(" ");
            cout<<vec[i][j];
        }
        printf("\n");
    }
    return 0;
}

