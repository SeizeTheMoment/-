class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int le = 0;
        int ri = x/2+1;
        int mid = ri-(ri-le)/2;
        while(le+1<ri)
        {
            mid = ri-(ri-le)/2;
            if(mid==x/mid)
                return mid;
            if(mid<x/mid)
            {
                le = mid+1;
            }
            else ri = mid;
        }
        if(le>x/le)
            return le-1;
        return le;
    }
};

