class Solution {
public:
    int minNumberOfFrogs(string s) {
        int c=0,r=0,o=0,a=0,k=0;
        int maxi = 0;
        for(char x:s)
        {
            if(x=='c')
                c++;
            else if(x=='r')
                r++;
            else if(x=='o')
                o++;
            else if(x=='a')
                a++;
            else if(x=='k')
                k++;
            else return -1;
            if(r>c||o>r||a>o||k>a)
                return -1;
            if(k==1)
            {
                c--;
                r--;
                o--;
                a--;
                k--;
            }
            maxi = max(maxi,c);
        }
        if(c)
           return -1;
        return maxi;
    }
};
