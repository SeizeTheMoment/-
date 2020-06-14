#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //从l到r花束的数目
    int get(int l,int r, int k)
    {
        return (r - l + 1) / k;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //x.first表示盛开的日子，x.second表示下标
        vector<pair<int,int> > vec;
        int N = bloomDay.size();
        for(int i=0;i<bloomDay.size();i++)
            vec.push_back({bloomDay[i],i+1});
        //l[i]表示从i到l[i]连续盛开
        //r[i]表示从i到r[i]连续盛开
        vector<int> l(N+2), r(N+2);
        sort(vec.begin(),vec.end());
        int sum = 0;
        for(auto x : vec)
        {
            int i = x.second;
            //如果左端有盛开的花&&右端有盛开的花
            if(l[i-1] && r[i+1])
            {
                sum = sum + get(l[i-1], r[i+1], k)- get(l[i-1],i-1,k) - get(i+1, r[i+1], k);
                r[l[i-1]] = r[i+1];
                l[r[i+1]] = l[i-1];
            }
            //如果只有左端有盛开的花
            else if(l[i-1])
            {
                sum = sum + get(l[i-1],i,k) - get(l[i-1],i-1,k) ;
                r[l[i-1]] = i;
                l[i] = l[i - 1];
            }
            //如果只有右端有盛开的花
            else if(r[i+1]){
                sum = sum + get(i,r[i+1],k) - get(i+1,r[i+1],k);
                r[i] = r[i+1];
                l[r[i+1]] = i;
            }
            //如果都没有花
            else{
                sum = sum + get(i,i,k);
                r[i] = l[i] = i;
            }
            if(sum>=m)
            {
                return x.first;
            }
        }
        return -1;
    }
};
