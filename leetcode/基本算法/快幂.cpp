class Solution {
public:
    double quickPow(double x, long n)
    {
        double ans = 1.0;
        double mul = x;
        while(n)
        {
            if(n&1)
                ans*=mul;
            mul*=mul;
            n/=2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n>0)
            return quickPow(x,n);
        else return 1.0/(quickPow(x,-(long)n));
    }
};