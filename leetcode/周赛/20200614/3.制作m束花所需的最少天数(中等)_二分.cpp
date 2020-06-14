bool check(vector<int>& bloomyDay, int m, int k, int mid)
{
    int tmp = 0;
    for(int x:bloomyDay)
    {
        if(x<=mid)
            tmp++;
        else
            tmp=0;
        if(tmp>=k)
        {
            tmp-=k;
            m--;
        }
    }
    return m<=0;
}
class Solution {
public:

    int minDays(vector<int>& bloomDay, int m, int k) {
        int N = bloomDay.size();
        if(m*k>N)
            return -1;
        int le = 0;
        int ri = 1e9+1;
        int mid = (ri-le)/2+le;
        bool flag =false;
        while(le<ri)
        {
            mid = (ri-le)/2+le;
            if(check(bloomDay, m, k, mid)){
                ri = mid;
                flag =true;
            }
            else{
                le = mid+1;
            }
        }
        if(!flag)
            return -1;
        return le;
    }
};
