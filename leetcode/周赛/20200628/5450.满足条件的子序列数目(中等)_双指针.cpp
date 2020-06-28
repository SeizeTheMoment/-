const int MOD = 1e9+7;
int quickpow(int x,int n)
{
    if(n==0)
        return 1;
    if(n&1){
        return ((long)x*(long)quickpow(x,n-1))%MOD;
    }
    else{
        int tmp = quickpow(x,n/2)%MOD;
        return ((long)tmp*(long)tmp)%MOD;
    }
}
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int le = 0;
        int ri = nums.size()-1;
        int sum = 0;
        while(le<=ri){
            if(nums[le]+nums[ri]<=target)
            {
                sum += quickpow(2,ri-le);
                sum %= MOD;
                le++;
            }
            else{
                ri--;
            }
        }
        return sum;
    }
};
